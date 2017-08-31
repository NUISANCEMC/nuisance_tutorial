ln -sf ../../mcfiles
nuiscomp -c exc3_priormaccrestuning.xml -o exc3_priormaccresnominal.root -n 100000 
nuismin -c exc3_priormaccrestuning.xml -o exc3_priormaccrestuning.root -n 100000 -q SignalReconfigures=1
root exc3_priormaccrestuning.C