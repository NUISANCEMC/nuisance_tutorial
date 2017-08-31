ln -sf ../../mcfiles
nuiscomp -c exc1_simplemaccrestuning.xml -o exc1_simplemaccresnominal.root -n 100000 
nuismin -c exc1_simplemaccrestuning.xml -o exc1_simplemaccrestuning.root -n 100000 -q SignalReconfigures=1
root exc1_simplemaccrestuning.C