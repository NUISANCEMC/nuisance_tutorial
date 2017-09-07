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
  std::string descrip = "Template1D sample." \
                        "\n Target: UNKNOWN" \
                        "\n Flux:   UNKNOWN" \
                        "\n Signal: UNKNOWN";
  fSettings = LoadSampleSettings(samplekey);
  fSettings.SetDescription(descrip);

  fSettings.SetTitle("UNKNOWN");
  fSettings.SetXTitle("UNKNOWN");
  fSettings.SetYTitle("UNKNOWN");
  fSettings.SetEnuRange(-999.9, -999.9);
  fSettings.DefineAllowedTargets("C,H");
  fSettings.DefineAllowedSpecies("numu");
  fSettings.SetAllowedTypes("UNKNOWN", "UNKNOWN");
  fSettings.SetDataInput(  FitPar::GetDataBase() + "/UNKNOWN");
  fSettings.SetCovarInput( FitPar::GetDataBase() + "/UNKNOWN");

  FinaliseSampleSettings();

  // Scaling Setup ---------------------------------------------------
  fScaleFactor = 0.0;

  // Plot Setup -------------------------------------------------------
  // SetDataFromTextFile( fSettings.GetDataInput() );
  // SetCorrelationFromTextFile( fSettings.GetCovarInput() );

  // Final setup ----------------------------------------------------
  FinaliseMeasurement();
};

//********************************************************************
void Template1D::FillEventVariables(FitEvent *event) {
//********************************************************************
  fXVar = 0.0;
  return;
};

//********************************************************************
bool Template1D::isSignal(FitEvent *event) {
//********************************************************************
  return true;
}
