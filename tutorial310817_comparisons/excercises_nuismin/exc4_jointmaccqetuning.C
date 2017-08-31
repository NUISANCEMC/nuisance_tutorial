{
  TFile* infile_nominal = new TFile("exc4_jointmaccqenominal.root","READ");
  TFile* infile_tuned   = new TFile("exc4_jointmaccqetuning.root","READ");

  // Draw Result
  TCanvas* c1 = new TCanvas("c1","c1",800,600);
  c1->cd(1);
  // Convert to GeV
  fit_dials->Draw();

}
