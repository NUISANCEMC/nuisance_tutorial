git clone http://nuisance.hepforge.org/git/nuisance.git 
cd nuisance
git checkout v2r8 -b v2r8
mkdir builds
cd builds
mkdir genie2126-nuwrorw
cd genie2126-nuwrorw
cmake ../../ $NUISANCE_BUILD_FLAGS -DNO_EXPERIMENTS=1 -DNO_MINERvA=0 -DGENIE_VERSION=212
make install