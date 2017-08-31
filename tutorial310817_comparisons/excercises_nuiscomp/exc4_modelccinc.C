{
  TFile* infile_genie = new TFile("exc4_modelgenie.root","READ");
  TH1D* data = infile_genie->Get("MINERvA_CCinc_XSec_2DEavq3_nu_data_1D");
  data->SetLineColor(kBlack);
  data->SetTitle("data");

  TH1D* mc_genie = infile_genie->Get("MINERvA_CCinc_XSec_2DEavq3_nu_MC_1D");
  mc_genie->SetLineColor(kGreen);
  mc_genie->SetTitle("Genie");

  TFile* infile_nuwro = new TFile("exc4_modelnuwro.root","READ");
  TH1D* mc_nuwro = infile_nuwro->Get("MINERvA_CCinc_XSec_2DEavq3_nu_MC_1D");
  mc_nuwro->SetLineColor(kRed);
  mc_nuwro->SetTitle("Nuwro");

  data->Draw("E1");
  mc_genie->Draw("SAME HIST");
  mc_nuwro->Draw("SAME HIST");
  gPad->BuildLegend();
  gPad->Update();
}
