{
  TFile* infile_default = new TFile("genie.Default.flat.root","READ");
  TTree* flattree_default = (TTree*) infile_default->Get("FlatTree_VARS");

  flattree_default->Draw("EPiP/1.E3 >> hist_default(20,0.0,3.0)", "fScaleFactor");
  hist_default = (TH1D*) flattree_default->GetHistogram();
  hist_default->Scale(1.0,"width");
  hist_default->SetTitle("Default;E_{#pi^{+}} (GeV);d#sigma/dE_{#pi^{+}} (cm^{2}/nucleon/GeV)");
  hist_default->SetLineColor(kRed);
  
  TFile* infile_valencia = new TFile("genie.ValenciaQEBergerSehgalCOHRES.flat.root","READ");
  TTree* flattree_valencia = (TTree*) infile_valencia->Get("FlatTree_VARS");

  flattree_valencia->Draw("EPiP/1.E3 >> hist_valencia(20,0.0,3.0)", "fScaleFactor");
  hist_valencia = (TH1D*) flattree_valencia->GetHistogram();
  hist_valencia->Scale(1.0,"width");
  hist_valencia->SetTitle("Valencia;E_{#pi^{+}} (GeV);d#sigma/dE_{#pi^{+}} (cm^{2}/nucleon/GeV)");
  hist_valencia->SetLineColor(kGreen);

  hist_valencia.Draw();
  hist_default->Draw("SAME HIST");
  gPad->BuildLegend();

}
