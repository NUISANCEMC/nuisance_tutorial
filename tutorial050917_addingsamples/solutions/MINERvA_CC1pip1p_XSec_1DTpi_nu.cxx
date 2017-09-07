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
#include "MINERvA_SignalDef.h"
#include "MINERvA_CC1pip1p_XSec_1DTpi_nu.h"

//********************************************************************
MINERvA_CC1pip1p_XSec_1DTpi_nu::MINERvA_CC1pip1p_XSec_1DTpi_nu(nuiskey samplekey) {
//********************************************************************

  // Sample overview ---------------------------------------------------

  // The sample overview is where all the settings are defined and the data 
  // sources are listed. Everything is set using the fSettings class,
  // which is really just a simple wrapper around the sample XML key.
  // That means that fSettings has access to anything you include in the XML
  // key at run time.
  // For instance, fSettings.SetDataInput("") sets the default key value "data" 
  // the XML, but then it is possible for a user to override this by inserting
  // <sample name="MINERvA_CC1pip1p_XSec_1DTpi_nu" data="myalternativedata.txt" />
  // in their card file at run time.


  // Simple descriptor, put anything you want here. At least Target/Flux/Signal
  // are recommended.
  std::string descrip = "MINERvA_CC1pip1p_XSec_1DTpi_nu sample. \n" \
                        "Target: CH \n" \
                        "Flux: MINERvA Forward Horn Current nue + nuebar \n" \
                        "Signal: Any event with 1 electron, any nucleons, and no other FS particles \n";

  // Setup common settings
  fSettings = LoadSampleSettings(samplekey);
  fSettings.SetDescription(descrip);

  // Simple title settings for the data MC plots
  fSettings.SetTitle("MINERvA_CC1pip1p_XSec_1DTpi_nu");
  fSettings.SetXTitle("T_{#pi} (MeV)");
  fSettings.SetYTitle("d#sigma/dT_{#pi} (cm^{2}/MeV/nucleon)");

  // We always have to have a specified energy range. If your sample
  // makes a cut on Enu_true, then put that here and it will automatically
  // be applied. If it does not, then instead put the energy range of your experiment
  // e.g. MINERvA ~ 0.0 - 100.0
  fSettings.SetEnuRange(1.5, 10.0);

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

  // The following commands tell people what targets to use.
  // We are eventually going to add automated checks that shout if you try
  // and load Pb into a CH sample for example, but for the time being
  // those checks aren't implemented....
  fSettings.DefineAllowedTargets("C,H");
  fSettings.DefineAllowedSpecies("numu");

  // Here we setup the data sources.
  // FitPar::GetDataBase() will point to our NUISANCE/data/ folder.
  // from their you can put a path to any input file.
  fSettings.SetDataInput(  FitPar::GetDataBase() + "/MINERvA/CC1pip1p/ccpip_Tpi.csv");
  fSettings.SetCovarInput( FitPar::GetDataBase() + "/MINERvA/CC1pip1p/ccpip_Tpi_cov.csv");

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

  fScaleFactor = GetEventHistogram()->Integral("width") * double(1E-38) / double(fNEvents) / TotalIntegratedFlux("width");

  // Plot Setup -------------------------------------------------------

  // Any data/covariance plots and non-standard MC histograms should be setup here.

  // Here we have a text file to load in, but alternative helper functions are available.
  SetDataFromTextFile( fSettings.GetDataInput() );

  // Similarily there are a number of covariance setting functions.
  // If you don't have a covariance use the function SetCovarFromDiagonal() instead.
  SetCorrelationFromTextFile( fSettings.GetCovarInput() );

  // Final setup  ---------------------------------------------------
  
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
  // If there is no pion we can't...
  int piPDG[] = {211, -211};
  if (event->NumFSParticle(piPDG) == 0) return;

  // Now Extract Pion Vector
  // - GetHMFSParticle Following function FitParticle with the chosen PDG in 
  //   the Final State with the highest momentum.
  TLorentzVector Ppip = event->GetHMFSParticle(piPDG)->fP;
  double Tpi = Ppip.E() - Ppip.Mag();

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
  
  // First, make sure it's CCINC
  if (!SignalDef::isCCINC(event, 14, EnuMin, EnuMax)) return false;

  // Now our signal requires :
  // 1 Initial State Muon Neutrino (covered by PDG in isCCINC above)
  // 1 Final State Muon
  // At least 1 Final State Proton
  
  // Use event helper functions to get counts
  // Check only one FS lepton
  int nLeptons = event->NumFSLeptons(); // FS means final state, IS means initial state
  if (nLeptons != 1) return false;

  // Check for only one pi+ or pi-
  int piPDG[] = {211, -211}; // can pass multiple PDG's to some event functions
  int nPion    = event->NumFSParticle(piPDG);
  if (nPion != 1) return false;
  
  // Require at least one proton
  int nProtons = event->NumFSProton();
  if (nProtons < 1) return false;

  
  // Cuts also depend on theta and W
  // We put these at the bottom, so they are only
  // calculated if the events passed the other cuts.

  // Restricted angle theta_mu < 20 degrees
  // - Get the neutrino and muon vectors
  TLorentzVector pnu = event->GetHMISParticle(14)->fP;
  TLorentzVector pmu = event->GetHMFSParticle(13)->fP;
  // - Cut on their angle
  double th_nu_mu = FitUtils::th(pmu, pnu) * 180. / M_PI;
  if (th_nu_mu >= 20) return false;

  // W experimental < 1400.0
  double hadMass = FitUtils::Wrec(pnu, pmu);
  if (hadMass > 1400.0) return false;
}
