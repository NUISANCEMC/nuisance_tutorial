#!/bin/sh

# Run Nuisflat
nuisflat \
    -i GENIE:mcfiles/gntp.ValenciaQEBergerSehgalCOHRES.MINERvA_fhc_numu.CH.2500000.root \
    -o genie.ValenciaQEBergerSehgalCOHRES.flat.root \
    -f GenericFlux \
    -n 50000

root exc3_drawpip.C
