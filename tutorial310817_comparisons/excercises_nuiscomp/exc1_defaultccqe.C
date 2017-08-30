{
  TFile* infile = new TFile("exc1_defaultccqe.root","READ");

  MINERvA_CCQE_XSec_1DQ2_nu_data->SetLineColor(kBlack);
  MINERvA_CCQE_XSec_1DQ2_nu_data->Draw("E1");

  MINERvA_CCQE_XSec_1DQ2_nu_MC->SetLineColor(kRed);
  MINERvA_CCQE_XSec_1DQ2_nu_MC->Draw("SAME HIST C");

  cout << "Likelihood = " << MINERvA_CCQE_XSec_1DQ2_nu_MC->GetTitle() << endl;
  cout << "NDOF = " << MINERvA_CCQE_XSec_1DQ2_nu_MC->GetNbinsX() << endl;
}
