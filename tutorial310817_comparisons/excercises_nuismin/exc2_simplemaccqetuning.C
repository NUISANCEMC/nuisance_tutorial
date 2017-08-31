{
  TFile* infile_nominal = new TFile("exc2_simplemaccqenominal.root","READ");
  TFile* infile_tuned   = new TFile("exc2_simplemaccqetuning.root","READ");

  // Draw Result
  TCanvas* c1 = new TCanvas("c1","c1",1000,600);
  c1->Divide(2,1);
  c1->cd(1);
  // Convert to GeV
  fit_dials->Draw();

  // Calculate MA
  cout << "MA = " << 0.99 * (1.0 + (fit_dials->GetBinContent(1)*0.2)) << " GeV" << endl;

  // Draw Nominal Vs Tuned
  c1->cd(2);
  TH1D* data = infile_tuned->Get("MiniBooNE_CCQE_XSec_1DQ2_nu_data");
  TH1D* mc   = infile_tuned->Get("MiniBooNE_CCQE_XSec_1DQ2_nu_MC");
  TH1D* mcnom= infile_nominal->Get("MiniBooNE_CCQE_XSec_1DQ2_nu_MC");

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
