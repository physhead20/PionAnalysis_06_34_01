{

// ######################################################################################################
// ######################################################################################################
// ### To obtain these numbers first set them equal to 1.0 and then use the printed output in the file
// ###   as input into "PlotBreakDown.ods" spreadsheet found in this repository....the output of the 
// ###       spreadsheet goes into these catagories to scale the particle species appropriately
// ######################################################################################################
// ######################################################################################################
double PionPercentage     = 0.48400;
double MuonPercentage     = 10.7226;
double ElectronPercentage = 0.34381;
double PhotonPercentage   = 0.44058;
double KaonPercentage     = 267.0803;

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
//					Incident Kinetic Energy Plot
//--------------------------------------------------------------------------------------------------------------

// #########################################
// ### Getting the data Incident KE plot ###
// #########################################
TH1F *hDataTrkPitch = (TH1F*)f1->Get("hdataTrkPitch");

// ### Labeling the axis ###
hDataTrkPitch->GetXaxis()->SetTitle("Track Pitch (cm)");
hDataTrkPitch->GetXaxis()->CenterTitle();

hDataTrkPitch->GetYaxis()->SetTitle("Events / 0.005 cm");
hDataTrkPitch->GetYaxis()->CenterTitle(); 

// ########################################################
// ###      Scaling factor for through going muon       ###
// ### Note: If you have a 10% contamination than your  ###
// ###            scale factor should be 0.90           ###
// ########################################################
double MuonContaminationScaleFactor = 0.90;
    
// ===============================================================================================================
// 					SCALING FOR THE MUON CONTAMINATION
// ==========================================================================================================
    
hDataTrkPitch->Scale(MuonContaminationScaleFactor);

// ############################################
// ### Getting the Pion MC Incident KE plot ###
// ############################################
TH1F *hPionTrkPitch = (TH1F*)f2->Get("hRecoMCPionTrkPitch");

// ### Labeling the axis ###
hPionTrkPitch->GetXaxis()->SetTitle("Track Pitch (cm)");
hPionTrkPitch->GetXaxis()->CenterTitle();

hPionTrkPitch->GetYaxis()->SetTitle("Events / 0.005 cm");
hPionTrkPitch->GetYaxis()->CenterTitle(); 

// ############################################
// ### Getting the Muon MC Incident KE plot ###
// ############################################
TH1F *hMuonMCTrkPitch = (TH1F*)f3->Get("hRecoMCPionTrkPitch");

// ### Labeling the axis ###
hMuonMCTrkPitch->GetXaxis()->SetTitle("Track Pitch (cm)");
hMuonMCTrkPitch->GetXaxis()->CenterTitle();

hMuonMCTrkPitch->GetYaxis()->SetTitle("Events / 0.005 cm");
hMuonMCTrkPitch->GetYaxis()->CenterTitle(); 


// ################################################
// ### Getting the Electron MC Incident KE plot ###
// ################################################
TH1F *hElectronMCTrkPitch = (TH1F*)f4->Get("hRecoMCPionTrkPitch");

// ### Labeling the axis ###
hElectronMCTrkPitch->GetXaxis()->SetTitle("Track Pitch (cm)");
hElectronMCTrkPitch->GetXaxis()->CenterTitle();

hElectronMCTrkPitch->GetYaxis()->SetTitle("Events / 0.005 cm");
hElectronMCTrkPitch->GetYaxis()->CenterTitle(); 


// ############################################
// ### Getting the Kaon MC Incident KE plot ###
// ############################################
TH1F *hKaonMCTrkPitch = (TH1F*)f5->Get("hRecoMCPionTrkPitch");

// ### Labeling the axis ###
hKaonMCTrkPitch->GetXaxis()->SetTitle("Track Pitch (cm)");
hKaonMCTrkPitch->GetXaxis()->CenterTitle();

hKaonMCTrkPitch->GetYaxis()->SetTitle("Events / 0.005 cm");
hKaonMCTrkPitch->GetYaxis()->CenterTitle(); 


// ##############################################
// ### Getting the Photon MC Incident KE plot ###
// ##############################################
TH1F *hPhotonMCTrkPitch = (TH1F*)f6->Get("hRecoMCPionTrkPitch");

// ### Labeling the axis ###
hPhotonMCTrkPitch->GetXaxis()->SetTitle("Track Pitch (cm)");
hPhotonMCTrkPitch->GetXaxis()->CenterTitle();

hPhotonMCTrkPitch->GetYaxis()->SetTitle("Events / 0.005 cm");
hPhotonMCTrkPitch->GetYaxis()->CenterTitle();  

// ============================================================================
// ======================= Normalizing MC to Data =============================
// ============================================================================

double PionMCIntegralTrkPitch     = hPionTrkPitch->Integral() ;
double MuonMCIntegralTrkPitch     = hMuonMCTrkPitch->Integral() ;
double ElectronMCIntegralTrkPitch = hElectronMCTrkPitch->Integral() ;
double KaonMCIntegralTrkTrkPitch  = hKaonMCTrkPitch->Integral();
double PhotonMCIntegralTrkTrkPitch= hPhotonMCTrkPitch->Integral();


// ### Overall MC scale factor ###
double MCIntegralTrkLength = PionMCIntegralTrkPitch + MuonMCIntegralTrkPitch + ElectronMCIntegralTrkPitch + KaonMCIntegralTrkTrkPitch + PhotonMCIntegralTrkTrkPitch;
double DataIntegralTrkLength = hDataTrkPitch->Integral();

double scaleMCTrkPitch = DataIntegralTrkLength/MCIntegralTrkLength;




// == Scale Pions ===
hPionTrkPitch->Sumw2();
hPionTrkPitch->Scale(scaleMCTrkPitch*(1/PionPercentage));

int pionNumber = hPionTrkPitch->Integral();
std::cout<<"# of Pion = "<<pionNumber<<std::endl;

// == Scale Muons ===
hMuonMCTrkPitch->Sumw2();
hMuonMCTrkPitch->Scale(scaleMCTrkPitch*(1/MuonPercentage));
int muonNumber = hMuonMCTrkPitch->Integral();
std::cout<<"# of Muon = "<<muonNumber<<std::endl;

// == Scale Electron ===
hElectronMCTrkPitch->Sumw2();
hElectronMCTrkPitch->Scale(scaleMCTrkPitch*(1/ElectronPercentage));
std::cout<<"# of Electron = "<<hElectronMCTrkPitch->Integral()<<std::endl;

// == Scale Kaon ===
hKaonMCTrkPitch->Sumw2();
hKaonMCTrkPitch->Scale(scaleMCTrkPitch*(1/KaonPercentage));
std::cout<<"# of Kaon = "<<hKaonMCTrkPitch->Integral()<<std::endl;
std::cout<<std::endl;

// == Scale Photon ===
hPhotonMCTrkPitch->Sumw2();
hPhotonMCTrkPitch->Scale(scaleMCTrkPitch*(1/PhotonPercentage));
std::cout<<"# of Photon = "<<hPhotonMCTrkPitch->Integral()<<std::endl;
std::cout<<std::endl;

std::cout<<std::endl;

int dataNum = hDataTrkPitch->Integral();
std::cout<<"# of data events = "<<dataNum<<std::endl;


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "Track Pitch");
c09->SetTicks();
c09->SetFillColor(kWhite);


hPionTrkPitch->SetLineColor(kBlue);
hPionTrkPitch->SetLineStyle(0);
hPionTrkPitch->SetLineWidth(3);
hPionTrkPitch->SetFillColor(kBlue);
hPionTrkPitch->SetFillStyle(3006);

hElectronMCTrkPitch->SetLineColor(kRed);
hElectronMCTrkPitch->SetLineStyle(0);
hElectronMCTrkPitch->SetLineWidth(3);
hElectronMCTrkPitch->SetFillColor(kRed);
hElectronMCTrkPitch->SetFillStyle(3006);

hMuonMCTrkPitch->SetLineColor(kGreen+3);
hMuonMCTrkPitch->SetLineStyle(0);
hMuonMCTrkPitch->SetLineWidth(3);
hMuonMCTrkPitch->SetFillColor(kGreen+3);
hMuonMCTrkPitch->SetFillStyle(3006);

hKaonMCTrkPitch->SetLineColor(kPink+3);
hKaonMCTrkPitch->SetLineStyle(0);
hKaonMCTrkPitch->SetLineWidth(3);
hKaonMCTrkPitch->SetFillColor(kPink+3);
hKaonMCTrkPitch->SetFillStyle(3006);

hPhotonMCTrkPitch->SetLineColor(kAzure-9);
hPhotonMCTrkPitch->SetLineStyle(0);
hPhotonMCTrkPitch->SetLineWidth(3);
hPhotonMCTrkPitch->SetFillColor(kAzure-9);
hPhotonMCTrkPitch->SetFillStyle(3007);

hDataTrkPitch->SetLineColor(kBlack);
hDataTrkPitch->SetLineStyle(0);
hDataTrkPitch->SetLineWidth(3);
hDataTrkPitch->SetMarkerStyle(8);
hDataTrkPitch->SetMarkerSize(0.9);


// ### Making a stacked histogram ###
THStack *hstacked = new THStack("hstacked","Stacked 1D histograms");

// ### Labeling the axis ###
//hstacked->GetXaxis()->SetTitle("Track Length (cm)");
//hstacked->GetXaxis()->CenterTitle();

//hstacked->GetYaxis()->SetTitle("Events / 0.5 cm");
//hstacked->GetYaxis()->CenterTitle(); 

hstacked->Add(hKaonMCTrkPitch);
hstacked->Add(hPhotonMCTrkPitch);
hstacked->Add(hMuonMCTrkPitch);
hstacked->Add(hElectronMCTrkPitch);
hstacked->Add(hPionTrkPitch);

// ### Drawing the histograms ###
hstacked->Draw("histo");
hDataTrkPitch->Draw("E1same");


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
leg->AddEntry(hDataTrkPitch,"Data");
leg->AddEntry(hPionTrkPitch,"Pion MC"); 
leg->AddEntry(hMuonMCTrkPitch,"Muon MC");
leg->AddEntry(hElectronMCTrkPitch,"Electron MC");
leg->AddEntry(hPhotonMCTrkPitch, "Photon MC");
leg->AddEntry(hKaonMCTrkPitch,"Kaon MC");
leg->Draw();




}//<---End File
