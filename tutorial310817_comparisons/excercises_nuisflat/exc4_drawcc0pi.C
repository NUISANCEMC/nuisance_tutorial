{
  TFile* infile_default = new TFile("genie.Default.flat.root","READ");
  TTree* flattree_default = (TTree*) infile_default->Get("FlatTree_VARS");
  
  flattree_default->Draw("Q2_QE/1.E6 >> hist_default(20,0.0,2.0)", "fScaleFactor * flagCC0pi");
  hist_default = (TH1D*) flattree_default->GetHistogram();
  hist_default->Scale(1.0,"width");
  hist_default->SetTitle("Default;Q^{2}_{QE} (GeV^{2};d#sigma/dQ^{2}_{QE} (cm^{2}/nucleon/GeV^{2})");
  hist_default->SetLineColor(kRed);
  
  TFile* infile_valencia = new TFile("genie.ValenciaQEBergerSehgalCOHRES.flat.root","READ");
  TTree* flattree_valencia = (TTree*) infile_valencia->Get("FlatTree_VARS");

  flattree_valencia->Draw("Q2_QE/1.E6 >> hist_valencia(20,0.0,2.0)", "fScaleFactor * flagCC0pi");
  hist_valencia = (TH1D*) flattree_valencia->GetHistogram();
  hist_valencia->Scale(1.0,"width");
  hist_valencia->SetTitle("Valencia;Q^{2}_{QE} (GeV^{2};d#sigma/dQ^{2}_{QE} (cm^{2}/nucleon/GeV^{2})");
  hist_valencia->SetLineColor(kGreen);

  TFile* infile_nuwro = new TFile("nuwro.LocalFGNievesQEAndMEC.flat.root","READ");
  TTree* flattree_nuwro = (TTree*) infile_nuwro->Get("FlatTree_VARS");

  flattree_nuwro->Draw("Q2_QE/1.E6 >> hist_nuwro(20,0.0,2.0)", "fScaleFactor * flagCC0pi");
  hist_nuwro = (TH1D*) flattree_nuwro->GetHistogram();
  hist_nuwro->Scale(1.0,"width");
  hist_nuwro->SetTitle("Nuwro;Q^{2}_{QE} (GeV^{2};d#sigma/dQ^{2}_{QE} (cm^{2}/nucleon/GeV^{2})");
  hist_nuwro->SetLineColor(kBlue);

  hist_valencia.Draw();
  hist_default->Draw("SAME HIST");
  hist_nuwro->Draw("SAME HIST");
  gPad->BuildLegend();

}
