#!/bin/sh

# Run Nuisflat
nuisflat \
    -i NUWRO:mcfiles/nuwroev.LocalFGNievesQEAndMEC.MINERvA_fhc_numu.CH.2500000.root \
    -o nuwro.LocalFGNievesQEAndMEC.flat.root \
    -f GenericFlux \
    -n 50000

root exc4_drawcc0pi.C
