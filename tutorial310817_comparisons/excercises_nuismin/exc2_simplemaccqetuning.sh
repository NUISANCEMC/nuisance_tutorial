ln -sf ../../mcfiles
nuiscomp -c exc2_simplemaccqetuning.xml -o exc2_simplemaccqenominal.root -n 100000 
nuismin -c exc2_simplemaccqetuning.xml -o exc2_simplemaccqetuning.root -n 100000 -q SignalReconfigures=1
root exc2_simplemaccqetuning.C