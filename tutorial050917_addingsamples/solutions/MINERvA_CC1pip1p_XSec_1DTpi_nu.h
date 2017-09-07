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
#ifndef MINERVA_CC1PIP1P_XSEC_1DTPI_NU_H_SEEN
#define MINERVA_CC1PIP1P_XSEC_1DTPI_NU_H_SEEN
#include "Measurement1D.h"

class MINERvA_CC1pip1p_XSec_1DTpi_nu : public Measurement1D {
public:

  // Main Constructor
  MINERvA_CC1pip1p_XSec_1DTpi_nu(nuiskey samplekey);

  // Destructor
  virtual ~MINERvA_CC1pip1p_XSec_1DTpi_nu() {};

  // Function to calculate event kinematics we need
  void FillEventVariables(FitEvent *event);

  // Function to figure out whether an event
  // is a signal event for this sample.
  bool isSignal(FitEvent *event);

  private:

  // If you would like to include any extra objects
  // or histograms to process include them here.

};
#endif
