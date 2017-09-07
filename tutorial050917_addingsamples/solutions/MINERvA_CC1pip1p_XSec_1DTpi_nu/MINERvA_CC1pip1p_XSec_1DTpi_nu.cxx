// Copyright 2016 L. Pickering, P Stowell, R. Terri, C. Wilkinson, C. Wret

/*******************************************************************************
*    This file is part of NUISANCE.
*
*    NUISANCE is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    NUISANCE is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with NUISANCE.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/
#include "MINERvA_CC1pip1p_XSec_1DTpi_nu.h"

//********************************************************************
MINERvA_CC1pip1p_XSec_1DTpi_nu::MINERvA_CC1pip1p_XSec_1DTpi_nu(nuiskey samplekey) {
//********************************************************************

  // Sample overview ---------------------------------------------------

  // Simple descriptor, put anything you want here. At least Target/Flux/Signal
  // are recommended.
  std::string descrip = "MINERvA_CC1pip1p_XSec_1DTpi_nu" \                        
    "\n Target: CH" \                        
    "\n Flux: MINERvA FHC numu"			\
    "\n Signal: CC1pi+/- 1p W<1.8 theta<20deg";  
  fSettings = LoadSampleSettings(samplekey);
  fSettings.SetDescription(descrip);

  // Simple default title settings for the data MC plots
  fSettings.SetTitle("MINERvA_CC1pip1p_XSec_1DTpi_nu");
  fSettings.SetXTitle("T_{#pi} (MeV)");  
  fSettings.SetYTitle("d#sigma/dT_{#pi} (cm^{2}/MeV/nucleon)");
  
  // We always have to have a specified energy range. If your sample
  // makes a cut on Enu_true, then put that here and it will automatically
  // be applied. If it does not, then instead put the energy range of your experiment
  // e.g. MINERvA ~ 0.0 - 100.0
  fSettings.SetEnuRange(0.0, 100.0);

  // The following commands tell people what targets to use.
  // We are eventually going to add automated checks that shout if you try
  // and load Pb into a CH sample for example, but for the time being
  // those checks aren't implemented.... (add these lines anyway)
  fSettings.DefineAllowedTargets("C,H");
  fSettings.DefineAllowedSpecies("numu");

  // Setting Types: This is the most awkward part of the constructor.
  // - The type XML field lets you pass additional options to the sample
  //   that usually define how the likelihoods are calculated. e.g. is it shape-only.
  // - Here you have to specify which ones are allowed. 
  //   SetAllowedTypes( all_allowed, default );
  // - all_allowed: This is a / seperated list of available options. 
  //   If you would like NUISANCE to register some options as conflicting
  //   e.g. You can't do a SHAPE fit and also a floating norm FREE fit
  //   then you can instead seperate those options with commas.
  // - default : What will be used by default if type not specified.
  // 
  // The following example is saying
  // - all_allowed : Allow all these options, but if someone passes
  //                 FIX FREE or SHAPE at the same time throw an error, and similarly
  //                 if someone passes DIAG and FULL at the same time throw an error.
  //
  // - default :     By default run with a fixed normalisation and the 
  //                 FULL covariance.
  fSettings.SetAllowedTypes("FIX,FREE,SHAPE/DIAG,FULL", "FIX/FULL");

  // Here we setup the data sources.
  // FitPar::GetDataBase() will point to our NUISANCE/data/ folder.
  // from their you can put a path to any input file.
 
  std::string base = FitPar::GetDataBase();
  fSettings.SetDataInput( base+"/MINERvA/CC1pi1p/Tpi/data.csv");      
  fSettings.SetCovarInput(base+"/MINERvA/CC1pi1p/Tpi/correlation.csv");

  // Once you've registered all your default settings, you should call FinaliseSampleSettings.
  // In this function NUISANCE will override the defaults with anything provided in the users
  // card file, and it will also automatically setup the InputHandlers the user requested
  // so that the scale factor can be calculated in the next line.
  FinaliseSampleSettings();

  // Scaling Setup ---------------------------------------------------

  // After each Reconfigure NUISANCE uses a scaling factor to convert the event spectrum
  // to a cross-section. It is simply a constant factor, that is automatically applied with
  // fMCHist->Scale( fScaleFactor, "width" );

  // Scaling factors are not automated because measurements can come in varied units. 
  // The most common units however are those of a differentical cross-section in cm^2 / nucleon.
  
  // If we bin up our events in a given distribution and divide by the number of
  // events we get an event spectrum S(T_pi)

  // The EventHistogram R(E_nu) inside the InputHandler is in units of (10E-38 * cm^2 / nucleon) * FluxUnits
  // so mutiplying our event spectrum by this histogram R(E_nu) gives us the predicted rate for our
  // alternative spectrum R(T_pi).
  
  // Finally if we divide by the integral of the flux and the bin width we get differential a cross-section. 

  // So to include all that in a single line, we have the following /nucleon differentical cross-section scaling
  // factor.
  //fScaleFactor = GetEventHistogram()->Integral("width") * double(1E-38) / double(fNEvents) / TotalIntegratedFlux("width");
  fScaleFactor = GetEventHistogram()->Integral("width") 
    * double(1E-38) 
    / double(fNEvents) 
    / TotalIntegratedFlux("width"); 

  // Plot Setup -------------------------------------------------------

  // Any data/covariance plots and non-standard MC histograms should be setup here.

  // Here we have a text file to load in, but alternative helper functions are available.
  SetDataFromTextFile( fSettings.GetDataInput() );

  // Similarily there are a number of covariance/correlation setting functions.
  // If you don't have a covariance use the function SetCovarFromDiagonal() instead.
  SetCorrelationFromTextFile( fSettings.GetCovarInput() );

  // Other setting functions are available. Look in
  // -- src/FitBase/Measurement1D.h
  // -- src/FitBase/Measurement2D.h

  // Alternative data covar functions
  // -- SetDataFromRootFile
  // -- SetPoissonErrors
  // -- SetCovarFromDiagonal
  // -- SetCovarFromTextFile
  // -- SetCovarFromMultipleTextFiles
  // -- SetCovarFromRootFile
  // -- SetCovarInvertFromTextFile
  // -- SetCovarInvertFromRootFile
  // -- SetCorrelationFromMultipleTextFiles
  // -- SetCorrelationFromRootFile
  // -- SetCholDecompFromTextFile
  // -- SetCholDecompFromRootFile

  // Sometimes you may want to convert units
  // -- ScaleData
  // -- ScaleDataErrors
  // -- ScaleCovar

  // Final setup ----------------------------------------------------
  
  // Each sample has to have a FinaliseMeasurement() call last, as this runs
  // a last set of histogram processing before it can begin.

  // If the fDataHist has been set then by default, when FinaliseMesaurement() is called
  // NUISANCE will generate all the standard MC histograms for you here that you
  // can use for direct comparisons to the data.
  FinaliseMeasurement();

};

//********************************************************************
void MINERvA_CC1pip1p_XSec_1DTpi_nu::FillEventVariables(FitEvent *event) {
//********************************************************************

  // FillEventVariables is called for each event, so that in rare cases
  // you have the ability quantities for background too. Therefore we can't 
  // rely on isSignal to remove events without particles we need.
  // First thing to do is cut ones we can't calculate quantities from.

  // e.g. when plotting Tpi, If there is no pion we can't get Tpi so we jsut return...
  int piPDG[] = {211, -211};
  if (event->NumFSParticle(piPDG) == 0) return;

  // All calculations should depend on the FitEvent object and
  // avoid trying to use raw generator level information.

  // For event level access functions look inside
  // -- src/InputHandler/FitEvent.h

  // For some common kinematic calculations (thetamu, Q2QE, etc)
  // -- src/Utils/FitUtils.h

  // Our data class wants to bin in some quantity so we have to calculate it from the event
  // e.g. double some_quantity = event->GetHMFSParticle(211)->fP.E();
  TLorentzVector ppi = event->GetHMFSParticle(piPDG)->fP;
  double Tpi = ppi.E() - ppi.Mag();
  
  // The last thing we have to do is tell NUISANCE what variable
  // it should treat as X/Y. This is done by filling the 
  // variables fXVar and fYVar
  //
  // If these are not filled, they are left as -999.9 and no filled into the MC
  // histogram by default.
  fXVar = Tpi;

  return;
};

//********************************************************************
bool MINERvA_CC1pip1p_XSec_1DTpi_nu::isSignal(FitEvent *event) {
//********************************************************************
  
  // This function should return True if a FitEvent object
  // can be classified as signal, and false if it is classified as
  // background.

  // All cuts should use the FitEvent object if possible and avoid
  // trying to use raw generator level information.

  // Example cut (require 1 final state muon)
  // if (event->NumFSParticle(13) != 1) return false;

  // For event level access functions look inside
  // -- src/InputHandler/FitEvent.h

  // For some common signal functions (CCINC,CC0pi)
  // -- src/Utils/SignalDef.h

  // For experiment specific signal functions look inside
  // -- src/{Experiment}/SignalDef.h

  // For some common kinematic calculations (thetamu, Q2QE, etc)
  // -- src/Utils/FitUtils.h

  // Cut 1
  if (!SignalDef::isCCINC(event, 14, EnuMin, EnuMax)) return false;

  // Cut 2 
  if (event->NumFSParticle(13) != 1) return false;

  // Cut 3 
  int piPDG[] = {211,-211};
  if (event->NumFSParticle(piPDG) != 1) return false;

  // Cut 4
  if (event->NumFSParticle(2212) < 1) return false;

  // Cut 5
  TLorentzVector pnu = event->GetHMISParticle(14)->fP;  
  TLorentzVector pmu = event->GetHMFSParticle(13)->fP;  

  double th_nu_mu = pmu.Vect().Angle(pnu.Vect()) * 180. / M_PI;  
  if (th_nu_mu >= 20) return false;

  // Cut 6
  double hadMass = FitUtils::Wrec(pnu, pmu);  
  if (hadMass > 1400.0) return false;

  // Return signal at the end 
  return true;
}
