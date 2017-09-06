#!/bin/bash

# EXTERNAL REQS
export CMAKEBINDIR=/cvmfs/minerva.opensciencegrid.org/minerva/NUISANCE_080117/external/GENIESupport/
export PATH=$CMAKEBINDIR/cmake-3.6.1/bin:$PATH
export PYTHIA6=$CMAKEBINDIR/pythia6/v6_424/lib
export LD_LIBRARY_PATH=$CMAKEBINDIR/pythia6/v6_424/lib:$LD_LIBRARY_PATH
export GSLLIB=$CMAKEBINDIR/gsl/lib
export GSLINC=$CMAKEBINDIR/gsl/include
export LD_LIBRARY_PATH=$CMAKEBINDIR/gsl/lib:$LD_LIBRARY_PATH
export ROOTSYS=$CMAKEBINDIR/build_root
export PATH=$CMAKEBINDIR/build_root/bin:$PATH
export LD_LIBRARY_PATH=$CMAKEBINDIR/build_root/lib:$LD_LIBRARY_PATH
export LOG4CPP_INC=$CMAKEBINDIR/log4cpp/include
export LOG4CPP_LIB=$CMAKEBINDIR/log4cpp/lib
export LD_LIBRARY_PATH=$CMAKEBINDIR/log4cpp/lib:$LD_LIBRARY_PATH
export LHAPATH=$CMAKEBINDIR/lhapdf
export LHAPDF_INC=$CMAKEBINDIR/lhapdf/include
export LHAPDF_LIB=$CMAKEBINDIR/lhapdf/lib
export LD_LIBRARY_PATH=$CMAKEBINDIR/lhapdf/lib:$LD_LIBRARY_PATH
export LIBXML2_LIB=/usr/lib/
export LIBXML2_INC=/usr/include/libxml2/
export NUISANCE_BUILD_FLAGS="-DUSE_MINIMIZER=1"

# GENIE REQS
export GENIE=/cvmfs/minerva.opensciencegrid.org/minerva/NUISANCE_080117/genie/R-2_12_6/genie-R-2_12_6-build-2017-08-01/
export LD_LIBRARY_PATH=$GENIE/lib::$LD_LIBRARY_PATH
export PATH=$GENIE/bin:$PATH
export GENIE_LIBS=$GENIE/lib
export NUISANCE_BUILD_FLAGS="$NUISANCE_BUILD_FLAGS -DUSE_GENIE=1 -DBUILD_GEVGEN=1"

# NUWRO REQS
export NUWRO=/cvmfs/minerva.opensciencegrid.org/minerva/NUISANCE_080117/nuwro/v11q-reweight/nuwro-v11q-reweight-build-2017-08-01/
export NUWRO_INC=$NUWRO/build/Linux/include/
export PATH=$NUWRO/build/Linux/bin:${PATH}
export LD_LIBRARY_PATH=$NUWRO/build/Linux/lib:${LD_LIBRARY_PATH}
export NUISANCE_BUILD_FLAGS="$NUISANCE_BUILD_FLAGS -DUSE_NuWro=1 -DUSE_NuWro_RW=1"
