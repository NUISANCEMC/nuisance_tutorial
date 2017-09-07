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
#include "Template1D.h"

//********************************************************************
Template1D::Template1D(nuiskey samplekey) {
//********************************************************************

  // Sample overview ---------------------------------------------------

  // The sample overview is where all the settings are defined and the data 
  // sources are listed. Everything is set using the fSettings class,
  // which is really just a simple wrapper around the sample XML key.
  // That means that fSettings has access to anything you include in the XML
  // key at run time.
  // For instance, fSettings.SetDataInput("") sets the default key value "data" 
  // the XML, but then it is possible for a user to override this by inserting
  // <sample name="Template1D" data="myalternativedata.txt" />
  // in their card file at run time.

  std::string descrip = "Template1D sample." \
                        "\n Target: UNKNOWN" \
                        "\n Flux:   UNKNOWN" \
                        "\n Signal: UNKNOWN";

  fSettings = LoadSampleSettings(samplekey);
  fSettings.SetDescription(descrip);

  // Set plot titles
  fSettings.SetTitle("UNKNOWN");
  fSettings.SetXTitle("UNKNOWN");
  fSettings.SetYTitle("UNKNOWN");

  // Set energy range
  fSettings.SetEnuRange(-999.9, -999.9);

  // Set input definitions
  fSettings.DefineAllowedTargets("C,H");
  fSettings.DefineAllowedSpecies("numu");

  // Set allowed types (Recommended : "FIX,FREE,SHAPE/FULL,DIAG","FIX/FULL"
  fSettings.SetAllowedTypes("UNKNOWN", "UNKNOWN");

  // Here we setup the data sources.
  fSettings.SetDataInput(  FitPar::GetDataBase() + "/UNKNOWN");
  fSettings.SetCovarInput( FitPar::GetDataBase() + "/UNKNOWN");

  // Final Settings
  FinaliseSampleSettings();

  // Scaling Setup ---------------------------------------------------

  // After each Reconfigure NUISANCE uses a scaling factor to convert the event spectrum
  // to a cross-section. It is simply a constant factor, that is automatically applied with
  // fMCHist->Scale( fScaleFactor, "width" );

  // Recommended Factor DiffXsec cm^2/nucleon
  //fScaleFactor = GetEventHistogram()->Integral("width") * double(1E-38) / double(fNEvents) / TotalIntegratedFlux("width");
  fScaleFactor = 0.0;

  // Plot Setup -------------------------------------------------------

  // Any data/covariance plots and non-standard MC histograms should be setup here.
  SetDataFromTextFile( fSettings.GetDataInput() );
  SetCorrelationFromTextFile( fSettings.GetCovarInput() );

  // Final setup ----------------------------------------------------
  
  // Each sample has to have a FinaliseMeasurement() call last, as this runs
  // a last set of histogram processing before it can begin.
  FinaliseMeasurement();

};

//********************************************************************
void Template1D::FillEventVariables(FitEvent *event) {
//********************************************************************

  // FillEventVariables is called for each event, so that in rare cases
  // you have the ability quantities for background too. Therefore we can't 
  // rely on isSignal to remove events without particles we need.
  // First thing to do is cut ones we can't calculate quantities from.
  fXVar = 0.0;

  return;
};

//********************************************************************
bool Template1D::isSignal(FitEvent *event) {
//********************************************************************
  
  // This function should return True if a FitEvent object
  // can be classified as signal, and false if it is classified as
  // background.

  // Return signal at the end 
  return true;
}
