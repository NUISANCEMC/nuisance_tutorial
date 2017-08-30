{
  TFile* infile = new TFile(" genie.Default.flat.root","READ");
  infile->ls();
  TTree* flattree = (TTree*) infile->Get("FlatTree_VARS");
  flattree->Draw("Enu_true");
}
