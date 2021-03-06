#!/bin/sh

# Read in options
FILES=$1
URLS=""
ALLOWED=""

# Append Default to list
if [[ "$FILES" == "gntp.Default.MINERvA_fhc_numu" || "$FILES" == "ALL" ]]
then
    echo "Wanted File : gntp.Default.MINERvA_fhc_numu.CH.2500000.root"
    URLS="$URLS https://www.dropbox.com/s/79acd20tnx02kc4/gntp.Default.MINERvA_fhc_numu.CH.2500000.root?dl=0"
else
    ALLOWED="$ALLOWED gntp.Default.MINERvA_fhc_numu"
fi
# Append Default to list
if [[ "$FILES" == "gntp.Default.MiniBooNE_fhc_numu" || "$FILES" == "ALL" ]]
then
    echo "Wanted File : gntp.Default.MiniBooNE_fhc_numu.CH2.2500000.root"
    URLS="$URLS https://www.dropbox.com/s/yfhcyxlvjhp3re4/gntp.Default.MiniBooNE_fhc_numu.CH2.2500000.root?dl=0"
else
    ALLOWED="$ALLOWED gntp.Default.MiniBooNE_fhc_numu"
fi
# Append Default to list
if [[ "$FILES" == "gntp.ValenciaQEBergerSehgalCOHRES.MINERvA_fhc_numu" || "$FILES" == "ALL" ]]
then
    echo "Wanted File : gntp.ValenciaQEBergerSehgalCOHRES.MINERvA_fhc_numu.CH.2500000.root"
    URLS="$URLS https://www.dropbox.com/s/9ekj5sdlfmfpqkn/gntp.ValenciaQEBergerSehgalCOHRES.MINERvA_fhc_numu.CH.2500000.root?dl=0"
else
    ALLOWED="$ALLOWED gntp.ValenciaQEBergerSehgalCOHRES.MINERvA_fhc_numu"
fi
# Append Default to list
if [[ "$FILES" == "nuwroev.LocalFGNievesQEAndMEC.MINERvA_fhc_numu" || "$FILES" == "ALL" ]]
then
    echo "Wanted File : nuwroev.LocalFGNievesQEAndMEC.MINERvA_fhc_numu.CH.2500000.root"
    URLS="$URLS https://www.dropbox.com/s/osnojptg2sreenm/nuwroev.LocalFGNievesQEAndMEC.MINERvA_fhc_numu.CH.2500000.root?dl=0"
else
    ALLOWED="$ALLOWED nuwroev.LocalFGNievesQEAndMEC.MINERvA_fhc_numu"
fi

# If none given print list
if [[ "$URLS" == "" ]]
then
    echo "No Tags given!"
    echo "Allowed FileTags:"
    echo "ALL"
    for opt in $ALLOWED
    do
	echo "$opt"
    done
else
    for url in $URLS
    do
	base=$(basename $url)
	basename=${base/\?dl=0/}
	echo "Downloading file $base"
	wget $url
	mv $base $basename
    done
fi
