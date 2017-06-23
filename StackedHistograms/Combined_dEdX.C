{

// ######################################################################################################
// ######################################################################################################
// ### To obtain these numbers first set them equal to 1.0 and then use the printed output in the file
// ###   as input into "PlotBreakDown.ods" spreadsheet found in this repository....the output of the 
// ###       spreadsheet goes into these catagories to scale the particle species appropriately
// ######################################################################################################
// ######################################################################################################
double PionPercentage     = 0.48438;
double MuonPercentage     = 10.7309;
double ElectronPercentage = 0.34232;
double PhotonPercentage   = 0.40644;
double KaonPercentage     = 266.606;

/*double PionPercentage     = 1.0;
double MuonPercentage     = 1.0;
double ElectronPercentage = 1.0;
double PhotonPercentage   = 1.0;
double KaonPercentage     = 1.0;*/


// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/Combined_RunI_RunII_HY_PiMuE_dataHisto.root");


// ###################################
// ### Load Pion Monte Carlo Plots ###
// ###################################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/PionMCDD_RunII_HY_OutOfTheBox.root");

// ###################################
// ### Load Muon Monte Carlo Plots ###
// ###################################
TFile *f3 = new TFile("../histoROOTfiles_forPlots/MuonMCDD_RunII_HY_OutOfTheBox.root");

// #######################################
// ### Load Electron Monte Carlo Plots ###
// #######################################
TFile *f4 = new TFile("../histoROOTfiles_forPlots/ElectronMCDD_RunII_HY_OutOfTheBox.root");

// ###################################
// ### Load Kaon Monte Carlo Plots ###
// ###################################
TFile *f5 = new TFile("../histoROOTfiles_forPlots/KaonMC_RunII_OutOfTheBox.root");

// #####################################
// ### Load Photon Monte Carlo Plots ###
// #####################################
TFile *f6 = new TFile("../histoROOTfiles_forPlots/PhotonMC_RunII_OutOfTheBox.root");


//--------------------------------------------------------------------------------------------------------------
//					dE/dX Plot
//--------------------------------------------------------------------------------------------------------------

// #########################################
// ### Getting the data Incident KE plot ###
// #########################################
TH1F *hDatadEdXPlot = (TH1F*)f1->Get("hdatadEdX");

// ### Labeling the axis ###
hDatadEdXPlot->GetXaxis()->SetTitle("dE/dX (MeV/cm)");
hDatadEdXPlot->GetXaxis()->CenterTitle();

hDatadEdXPlot->GetYaxis()->SetTitle("Events / 0.25 (MeV/cm)");
hDatadEdXPlot->GetYaxis()->CenterTitle(); 

// ########################################################
// ###      Scaling factor for through going muon       ###
// ### Note: If you have a 10% contamination than your  ###
// ###            scale factor should be 0.90           ###
// ########################################################
double MuonContaminationScaleFactor = 0.90;
    
// ===============================================================================================================
// 					SCALING FOR THE MUON CONTAMINATION
// ==========================================================================================================
    
hDatadEdXPlot->Scale(MuonContaminationScaleFactor);

// ############################################
// ### Getting the Pion MC Incident KE plot ###
// ############################################
TH1F *hPiondEdX = (TH1F*)f2->Get("hRecoMCdEdX");

// ### Labeling the axis ###
hPiondEdX->GetXaxis()->SetTitle("dE/dX (MeV/cm)");
hPiondEdX->GetXaxis()->CenterTitle();

hPiondEdX->GetYaxis()->SetTitle("Events / 0.25 (MeV/cm)");
hPiondEdX->GetYaxis()->CenterTitle(); 

// ############################################
// ### Getting the Muon MC Incident KE plot ###
// ############################################
TH1F *hMuonMCdEdX = (TH1F*)f3->Get("hRecoMCdEdX");

// ### Labeling the axis ###
hMuonMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV/cm)");
hMuonMCdEdX->GetXaxis()->CenterTitle();

hMuonMCdEdX->GetYaxis()->SetTitle("Events / 0.25 (MeV/cm)");
hMuonMCdEdX->GetYaxis()->CenterTitle(); 


// ################################################
// ### Getting the Electron MC Incident KE plot ###
// ################################################
TH1F *hElectronMCdEdX = (TH1F*)f4->Get("hRecoMCdEdX");

// ### Labeling the axis ###
hElectronMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV/cm)");
hElectronMCdEdX->GetXaxis()->CenterTitle();

hElectronMCdEdX->GetYaxis()->SetTitle("Events / 0.25 (MeV/cm)");
hElectronMCdEdX->GetYaxis()->CenterTitle(); 


// ############################################
// ### Getting the Kaon MC Incident KE plot ###
// ############################################
TH1F *hKaonMCdEdX = (TH1F*)f5->Get("hRecoMCdEdX");

// ### Labeling the axis ###
hKaonMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV/cm)");
hKaonMCdEdX->GetXaxis()->CenterTitle();

hKaonMCdEdX->GetYaxis()->SetTitle("Events / 0.25 (MeV/cm)");
hKaonMCdEdX->GetYaxis()->CenterTitle(); 


// ##############################################
// ### Getting the Photon MC Incident KE plot ###
// ##############################################
TH1F *hPhotonMCdEdX = (TH1F*)f6->Get("hRecoMCdEdX");

// ### Labeling the axis ###
hPhotonMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV/cm)");
hPhotonMCdEdX->GetXaxis()->CenterTitle();

hPhotonMCdEdX->GetYaxis()->SetTitle("Events / 0.25 (MeV/cm)");
hPhotonMCdEdX->GetYaxis()->CenterTitle();  

// ============================================================================
// ======================= Normalizing MC to Data =============================
// ============================================================================

double PionMCIntegraldEdX     = hPiondEdX->Integral() ;
double MuonMCIntegraldEdX     = hMuonMCdEdX->Integral() ;
double ElectronMCIntegraldEdX = hElectronMCdEdX->Integral() ;
double KaonMCIntegralTrkdEdX  = hKaonMCdEdX->Integral();
double PhotonMCIntegralTrkdEdX= hPhotonMCdEdX->Integral();


// ### Overall MC scale factor ###
double MCIntegralTrkLength = PionMCIntegraldEdX + MuonMCIntegraldEdX + ElectronMCIntegraldEdX + KaonMCIntegralTrkdEdX + PhotonMCIntegralTrkdEdX;
double DataIntegralTrkLength = hDatadEdXPlot->Integral();

double scaleMCdEdX = DataIntegralTrkLength/MCIntegralTrkLength;




// == Scale Pions ===
hPiondEdX->Sumw2();
hPiondEdX->Scale(scaleMCdEdX*(1/PionPercentage));

int pionNumber = hPiondEdX->Integral();
std::cout<<"# of Pion = "<<pionNumber<<std::endl;

// == Scale Muons ===
hMuonMCdEdX->Sumw2();
hMuonMCdEdX->Scale(scaleMCdEdX*(1/MuonPercentage));
int muonNumber = hMuonMCdEdX->Integral();
std::cout<<"# of Muon = "<<muonNumber<<std::endl;

// == Scale Electron ===
hElectronMCdEdX->Sumw2();
hElectronMCdEdX->Scale(scaleMCdEdX*(1/ElectronPercentage));
std::cout<<"# of Electron = "<<hElectronMCdEdX->Integral()<<std::endl;

// == Scale Kaon ===
hKaonMCdEdX->Sumw2();
hKaonMCdEdX->Scale(scaleMCdEdX*(1/KaonPercentage));
std::cout<<"# of Kaon = "<<hKaonMCdEdX->Integral()<<std::endl;
std::cout<<std::endl;

// == Scale Photon ===
hPhotonMCdEdX->Sumw2();
hPhotonMCdEdX->Scale(scaleMCdEdX*(1/PhotonPercentage));
std::cout<<"# of Photon = "<<hPhotonMCdEdX->Integral()<<std::endl;
std::cout<<std::endl;

std::cout<<std::endl;

int dataNum = hDatadEdXPlot->Integral();
std::cout<<"# of data events = "<<dataNum<<std::endl;


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "Track Pitch");
c09->SetTicks();
c09->SetFillColor(kWhite);


hPiondEdX->SetLineColor(kBlue);
hPiondEdX->SetLineStyle(0);
hPiondEdX->SetLineWidth(3);
hPiondEdX->SetFillColor(kBlue);
hPiondEdX->SetFillStyle(3006);

hElectronMCdEdX->SetLineColor(kRed);
hElectronMCdEdX->SetLineStyle(0);
hElectronMCdEdX->SetLineWidth(3);
hElectronMCdEdX->SetFillColor(kRed);
hElectronMCdEdX->SetFillStyle(3006);

hMuonMCdEdX->SetLineColor(kGreen+3);
hMuonMCdEdX->SetLineStyle(0);
hMuonMCdEdX->SetLineWidth(3);
hMuonMCdEdX->SetFillColor(kGreen+3);
hMuonMCdEdX->SetFillStyle(3006);

hKaonMCdEdX->SetLineColor(kPink+3);
hKaonMCdEdX->SetLineStyle(0);
hKaonMCdEdX->SetLineWidth(3);
hKaonMCdEdX->SetFillColor(kPink+3);
hKaonMCdEdX->SetFillStyle(3006);

hPhotonMCdEdX->SetLineColor(kAzure-9);
hPhotonMCdEdX->SetLineStyle(0);
hPhotonMCdEdX->SetLineWidth(3);
hPhotonMCdEdX->SetFillColor(kAzure-9);
hPhotonMCdEdX->SetFillStyle(3007);

hDatadEdXPlot->SetLineColor(kBlack);
hDatadEdXPlot->SetLineStyle(0);
hDatadEdXPlot->SetLineWidth(3);
hDatadEdXPlot->SetMarkerStyle(8);
hDatadEdXPlot->SetMarkerSize(0.9);


// ### Making a stacked histogram ###
THStack *hstacked = new THStack("hstacked","Stacked 1D histograms");

// ### Labeling the axis ###
//hstacked->GetXaxis()->SetTitle("Track Length (cm)");
//hstacked->GetXaxis()->CenterTitle();

//hstacked->GetYaxis()->SetTitle("Events / 0.5 cm");
//hstacked->GetYaxis()->CenterTitle(); 

hstacked->Add(hKaonMCdEdX);
hstacked->Add(hPhotonMCdEdX);
hstacked->Add(hMuonMCdEdX);
hstacked->Add(hElectronMCdEdX);
hstacked->Add(hPiondEdX);

// ### Drawing the histograms ###
hstacked->Draw("histo");
hDatadEdXPlot->Draw("E1same");


// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,"");

TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I/II Negative Polarity");
leg->AddEntry(hDatadEdXPlot,"Data");
leg->AddEntry(hPiondEdX,"Pion MC"); 
leg->AddEntry(hMuonMCdEdX,"Muon MC");
leg->AddEntry(hElectronMCdEdX,"Electron MC");
leg->AddEntry(hPhotonMCdEdX, "Photon MC");
leg->AddEntry(hKaonMCdEdX,"Kaon MC");
leg->Draw();




}//<---End File
