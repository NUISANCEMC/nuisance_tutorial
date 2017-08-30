{
  TFile* infile_default = new TFile("exc3_modeldefault.root","READ");
  TH1D* data = infile_default->Get("MINERvA_CC1pip_XSec_1Dth_nu_data");
  data->SetLineColor(kBlack);
  data->SetTitle("data");

  TH1D* mc_default = infile_default->Get("MINERvA_CC1pip_XSec_1Dth_nu_MC");
  TH1D* shape_default = infile_default->Get("MINERvA_CC1pip_XSec_1Dth_nu_MC_SHAPE");
  mc_default->SetLineColor(kGreen);
  mc_default->SetTitle("Default");
  shape_default->SetLineColor(kGreen);
  shape_default->SetLineStyle(7);

  TFile* infile_valencia = new TFile("exc3_modelvalencia.root","READ");
  TH1D* mc_valencia = infile_valencia->Get("MINERvA_CC1pip_XSec_1Dth_nu_MC");
  TH1D* shape_valencia = infile_valencia->Get("MINERvA_CC1pip_XSec_1Dth_nu_MC_SHAPE");
  mc_valencia->SetLineColor(kRed);
  mc_valencia->SetTitle("Valencia");
  shape_valencia->SetLineColor(kRed);
  shape_valencia->SetLineStyle(7);

  data->Draw("E1");
  mc_default->Draw("SAME HIST C");
  mc_valencia->Draw("SAME HIST C");
  gPad->BuildLegend();
  shape_default->Draw("SAME HIST C");
  shape_valencia->Draw("SAME HIST C");
  gPad->Update();
}
