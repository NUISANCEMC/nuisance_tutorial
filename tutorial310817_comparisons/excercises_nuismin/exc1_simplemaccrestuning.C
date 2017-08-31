{
  TFile* infile_nominal = new TFile("exc1_simplemaccresnominal.root","READ");
  TFile* infile_tuned   = new TFile("exc1_simplemaccrestuning.root","READ");

  // Draw Result
  TCanvas* c1 = new TCanvas("c1","c1",1000,600);
  c1->Divide(2,1);
  c1->cd(1);
  fit_dials->Draw();

  // Draw Nominal Vs Tuned
  c1->cd(2);
  TH1D* data = infile_tuned->Get("MINERvA_CC1pip_XSec_1DQ2_nu_2017_data");
  TH1D* mc   = infile_tuned->Get("MINERvA_CC1pip_XSec_1DQ2_nu_2017_MC");
  TH1D* mcnom= infile_nominal->Get("MINERvA_CC1pip_XSec_1DQ2_nu_2017_MC");

  data->SetTitle("Data");
  data->SetLineColor(kBlack);
  data->Draw("E1");

  mcnom->SetTitle( ("Nominal " + std::string(mcnom->GetTitle())).c_str() );
  mcnom->SetLineColor(kRed);
  mcnom->Draw("SAME HIST C");

  mc->SetTitle( ("Tuned " + std::string(mc->GetTitle())).c_str() );
  mc->SetLineColor(kGreen);
  mc->Draw("SAME HIST C");

  gPad->BuildLegend();
  gPad->Update();

}
