
ln -sf ../../mcfile/ 
nuiscomp -c exc4_jointmaccqetuning.xml -o exc4_jointmaccqenominal.root -n 100000
nuismin -c exc4_jointmaccqetuning.xml -o exc4_jointmaccqetuning.root -n 100000 -q SignalReconfigures=1

root exc4_jointmaccqetuning.C
