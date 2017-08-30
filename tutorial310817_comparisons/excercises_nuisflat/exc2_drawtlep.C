{
  TFile* infile = new TFile(" genie.Default.flat.root","READ");
  infile->ls();
  TTree* flattree = (TTree*) infile->Get("FlatTree_VARS");
  flattree->Draw("TLep/1.E3 >> hist(20,0.0,10.0)","fScaleFactor");

  // Divide by bin width
  hist->Scale(1.0,"width");
  hist->SetTitle("Diff XSec;T_{l} (GeV);d#sigma/dT_{l} (cm^{2}/nucleon/GeV)");
  hist->Draw();
}
