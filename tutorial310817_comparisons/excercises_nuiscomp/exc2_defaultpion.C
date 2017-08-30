{
  TFile* infile = new TFile("exc2_defaultpion.root","READ");

  TCanvas* c1 = new TCanvas("c1","c1",1200,600);
  c1->Divide(2,1);

  c1->cd(1);
  MINERvA_CC1pip_XSec_1Dth_nu_data->SetLineColor(kBlack);
  MINERvA_CC1pip_XSec_1Dth_nu_data->Draw("E1");

  MINERvA_CC1pip_XSec_1Dth_nu_MC->SetLineColor(kRed);
  MINERvA_CC1pip_XSec_1Dth_nu_MC->Draw("SAME HIST C");

  cout << "1Dth Likelihood = " << MINERvA_CC1pip_XSec_1Dth_nu_MC->GetTitle() << endl;
  cout << "1Dth NDOF = " << MINERvA_CC1pip_XSec_1Dth_nu_MC->GetNbinsX() << endl;

  c1->cd(2);
  MINERvA_CC1pip_XSec_1DTpi_nu_data->SetLineColor(kBlack);
  MINERvA_CC1pip_XSec_1DTpi_nu_data->Draw("E1");

  MINERvA_CC1pip_XSec_1DTpi_nu_MC->SetLineColor(kRed);
  MINERvA_CC1pip_XSec_1DTpi_nu_MC->Draw("SAME HIST C");

  cout << "1DTpi Likelihood = " << MINERvA_CC1pip_XSec_1DTpi_nu_MC->GetTitle() << endl;
  cout << "1DTpi NDOF = " << MINERvA_CC1pip_XSec_1DTpi_nu_MC->GetNbinsX() << endl;
  
}
