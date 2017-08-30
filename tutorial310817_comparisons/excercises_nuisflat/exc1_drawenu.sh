#!/bin/sh

# Run Nuisflat
nuisflat \
    -i GENIE:mcfiles/gntp.Default.MINERvA_fhc_numu.CH.2500000.root \
    -o genie.Default.flat.root \
    -f GenericFlux \
    -n 50000

root exc1_drawenu.C
