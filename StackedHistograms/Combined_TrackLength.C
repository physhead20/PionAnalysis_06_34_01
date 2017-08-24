{

// ######################################################################################################
// ######################################################################################################
// ### To obtain these numbers first set them equal to 1.0 and then use the printed output in the file
// ###   as input into "PlotBreakDown.ods" spreadsheet found in this repository....the output of the 
// ###       spreadsheet goes into these catagories to scale the particle species appropriately
// ######################################################################################################
// ######################################################################################################
double PionPercentage     = 0.53698;
double MuonPercentage     = 5.8586165259;
double ElectronPercentage = 1.475231193;
double PhotonPercentage   = 2.570039565;
double KaonPercentage     = 5.2180006881;

/*double PionPercentage     = 1.0;
double MuonPercentage     = 1.0;
double ElectronPercentage = 1.0;
double PhotonPercentage   = 1.0;
double KaonPercentage     = 1.0;*/


// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/Combined_RunI_RunII_HY_PiMuE_dataHisto_UpdateAugust2017.root");


// ###################################
// ### Load Pion Monte Carlo Plots ###
// ###################################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/DDMC_Pion_CombinedRuns_histo.root");

// ###################################
// ### Load Muon Monte Carlo Plots ###
// ###################################
TFile *f3 = new TFile("../histoROOTfiles_forPlots/DDMC_Muon_RunIIHY_histo.root");

// #######################################
// ### Load Electron Monte Carlo Plots ###
// #######################################
TFile *f4 = new TFile("../histoROOTfiles_forPlots/DDMC_Electron_RunIIHY_histo.root");

// ###################################
// ### Load Kaon Monte Carlo Plots ###
// ###################################
TFile *f5 = new TFile("../histoROOTfiles_forPlots/DDMC_Kaon_RunII_histo.root");

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
TH1F *hDataTrkLength = (TH1F*)f1->Get("hRecoLength");

// ### Labeling the axis ###
hDataTrkLength->GetXaxis()->SetTitle("Track Pitch (cm)");
hDataTrkLength->GetXaxis()->CenterTitle();

hDataTrkLength->GetYaxis()->SetTitle("Events / 0.005 cm");
hDataTrkLength->GetYaxis()->CenterTitle(); 

// ########################################################
// ###      Scaling factor for through going muon       ###
// ### Note: If you have a 10% contamination than your  ###
// ###            scale factor should be 0.90           ###
// ########################################################
double MuonContaminationScaleFactor = 1.0;
    
// ===============================================================================================================
// 					SCALING FOR THE MUON CONTAMINATION
// ==========================================================================================================
    
hDataTrkLength->Scale(MuonContaminationScaleFactor);

// ############################################
// ### Getting the Pion MC Incident KE plot ###
// ############################################
TH1F *hPionTrkLength = (TH1F*)f2->Get("hRecoLength");

// ### Labeling the axis ###
hPionTrkLength->GetXaxis()->SetTitle("Track Pitch (cm)");
hPionTrkLength->GetXaxis()->CenterTitle();

hPionTrkLength->GetYaxis()->SetTitle("Events / 0.005 cm");
hPionTrkLength->GetYaxis()->CenterTitle(); 

// ############################################
// ### Getting the Muon MC Incident KE plot ###
// ############################################
TH1F *hMuonMCTrkLength = (TH1F*)f3->Get("hRecoLength");

// ### Labeling the axis ###
hMuonMCTrkLength->GetXaxis()->SetTitle("Track Pitch (cm)");
hMuonMCTrkLength->GetXaxis()->CenterTitle();

hMuonMCTrkLength->GetYaxis()->SetTitle("Events / 0.005 cm");
hMuonMCTrkLength->GetYaxis()->CenterTitle(); 


// ################################################
// ### Getting the Electron MC Incident KE plot ###
// ################################################
TH1F *hElectronMCTrkLength = (TH1F*)f4->Get("hRecoLength");

// ### Labeling the axis ###
hElectronMCTrkLength->GetXaxis()->SetTitle("Track Pitch (cm)");
hElectronMCTrkLength->GetXaxis()->CenterTitle();

hElectronMCTrkLength->GetYaxis()->SetTitle("Events / 0.005 cm");
hElectronMCTrkLength->GetYaxis()->CenterTitle(); 


// ############################################
// ### Getting the Kaon MC Incident KE plot ###
// ############################################
TH1F *hKaonMCTrkLength = (TH1F*)f5->Get("hRecoLength");

// ### Labeling the axis ###
hKaonMCTrkLength->GetXaxis()->SetTitle("Track Pitch (cm)");
hKaonMCTrkLength->GetXaxis()->CenterTitle();

hKaonMCTrkLength->GetYaxis()->SetTitle("Events / 0.005 cm");
hKaonMCTrkLength->GetYaxis()->CenterTitle(); 


// ##############################################
// ### Getting the Photon MC Incident KE plot ###
// ##############################################
TH1F *hPhotonMCTrkLength = (TH1F*)f6->Get("hRecoLength");

// ### Labeling the axis ###
hPhotonMCTrkLength->GetXaxis()->SetTitle("Track Pitch (cm)");
hPhotonMCTrkLength->GetXaxis()->CenterTitle();

hPhotonMCTrkLength->GetYaxis()->SetTitle("Events / 0.005 cm");
hPhotonMCTrkLength->GetYaxis()->CenterTitle();  

// ============================================================================
// ======================= Normalizing MC to Data =============================
// ============================================================================

double PionMCIntegralTrkLength     = hPionTrkLength->Integral() ;
double MuonMCIntegralTrkLength     = hMuonMCTrkLength->Integral() ;
double ElectronMCIntegralTrkLength = hElectronMCTrkLength->Integral() ;
double KaonMCIntegralTrkTrkLength  = hKaonMCTrkLength->Integral();
double PhotonMCIntegralTrkTrkLength= hPhotonMCTrkLength->Integral();


// ### Overall MC scale factor ###
double MCIntegralTrkLength = PionMCIntegralTrkLength + MuonMCIntegralTrkLength + ElectronMCIntegralTrkLength + KaonMCIntegralTrkTrkLength + PhotonMCIntegralTrkTrkLength;
double DataIntegralTrkLength = hDataTrkLength->Integral();

double scaleMCTrkLength = DataIntegralTrkLength/MCIntegralTrkLength;




// == Scale Pions ===
hPionTrkLength->Sumw2();
hPionTrkLength->Scale(scaleMCTrkLength*(1/PionPercentage));

int pionNumber = hPionTrkLength->Integral();
std::cout<<"# of Pion = "<<pionNumber<<std::endl;

// == Scale Muons ===
hMuonMCTrkLength->Sumw2();
hMuonMCTrkLength->Scale(scaleMCTrkLength*(1/MuonPercentage));
int muonNumber = hMuonMCTrkLength->Integral();
std::cout<<"# of Muon = "<<muonNumber<<std::endl;

// == Scale Electron ===
hElectronMCTrkLength->Sumw2();
hElectronMCTrkLength->Scale(scaleMCTrkLength*(1/ElectronPercentage));
std::cout<<"# of Electron = "<<hElectronMCTrkLength->Integral()<<std::endl;

// == Scale Kaon ===
hKaonMCTrkLength->Sumw2();
hKaonMCTrkLength->Scale(scaleMCTrkLength*(1/KaonPercentage));
std::cout<<"# of Kaon = "<<hKaonMCTrkLength->Integral()<<std::endl;
std::cout<<std::endl;

// == Scale Photon ===
hPhotonMCTrkLength->Sumw2();
hPhotonMCTrkLength->Scale(scaleMCTrkLength*(1/PhotonPercentage));
std::cout<<"# of Photon = "<<hPhotonMCTrkLength->Integral()<<std::endl;
std::cout<<std::endl;

std::cout<<std::endl;

int dataNum = hDataTrkLength->Integral();
std::cout<<"# of data events = "<<dataNum<<std::endl;


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "Track Pitch");
c09->SetTicks();
c09->SetFillColor(kWhite);


hPionTrkLength->SetLineColor(kBlue);
hPionTrkLength->SetLineStyle(0);
hPionTrkLength->SetLineWidth(3);
hPionTrkLength->SetFillColor(kBlue);
hPionTrkLength->SetFillStyle(3006);

hElectronMCTrkLength->SetLineColor(kRed);
hElectronMCTrkLength->SetLineStyle(0);
hElectronMCTrkLength->SetLineWidth(3);
hElectronMCTrkLength->SetFillColor(kRed);
hElectronMCTrkLength->SetFillStyle(3006);

hMuonMCTrkLength->SetLineColor(kGreen+3);
hMuonMCTrkLength->SetLineStyle(0);
hMuonMCTrkLength->SetLineWidth(3);
hMuonMCTrkLength->SetFillColor(kGreen+3);
hMuonMCTrkLength->SetFillStyle(3006);

hKaonMCTrkLength->SetLineColor(kPink+3);
hKaonMCTrkLength->SetLineStyle(0);
hKaonMCTrkLength->SetLineWidth(3);
hKaonMCTrkLength->SetFillColor(kPink+3);
hKaonMCTrkLength->SetFillStyle(3006);

hPhotonMCTrkLength->SetLineColor(kAzure-9);
hPhotonMCTrkLength->SetLineStyle(0);
hPhotonMCTrkLength->SetLineWidth(3);
hPhotonMCTrkLength->SetFillColor(kAzure-9);
hPhotonMCTrkLength->SetFillStyle(3007);

hDataTrkLength->SetLineColor(kBlack);
hDataTrkLength->SetLineStyle(0);
hDataTrkLength->SetLineWidth(3);
hDataTrkLength->SetMarkerStyle(8);
hDataTrkLength->SetMarkerSize(0.9);


// ### Making a stacked histogram ###
THStack *hstacked = new THStack("hstacked","Stacked 1D histograms");

// ### Labeling the axis ###
//hstacked->GetXaxis()->SetTitle("Track Length (cm)");
//hstacked->GetXaxis()->CenterTitle();

//hstacked->GetYaxis()->SetTitle("Events / 0.5 cm");
//hstacked->GetYaxis()->CenterTitle(); 

hstacked->Add(hKaonMCTrkLength);
hstacked->Add(hPhotonMCTrkLength);
hstacked->Add(hMuonMCTrkLength);
hstacked->Add(hElectronMCTrkLength);
hstacked->Add(hPionTrkLength);

// ### Drawing the histograms ###
hstacked->Draw("histo");
hDataTrkLength->Draw("E1same");


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
leg->AddEntry(hDataTrkLength,"Data");
leg->AddEntry(hPionTrkLength,"Pion MC"); 
leg->AddEntry(hMuonMCTrkLength,"Muon MC");
leg->AddEntry(hElectronMCTrkLength,"Electron MC");
leg->AddEntry(hPhotonMCTrkLength, "Photon MC");
leg->AddEntry(hKaonMCTrkLength,"Kaon MC");
leg->Draw();




}//<---End File
