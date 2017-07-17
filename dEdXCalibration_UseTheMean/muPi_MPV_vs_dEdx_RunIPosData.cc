  // the Sternheimer parameterization for the density effect is used
  // values are obtained from Mokhov (2001) in atomic data
double x0=0.2;
double x1=3.0;
double Cbar=5.2146;
double a=0.19559;
double k=3.0;

  // most probable energy loss and bethe-bloch  constants
double K=0.307075;
int z=1;           // number of electrons
int Z=18;          // atomic number
double A=39.948;   // atomic mass
double m_e=0.511;  // electron mass [MeV]
double M_mu=105.6; // muon mass [MeV]
double M_pi=139.6; // pion mass [MeV]
double M_ka=493.7; // kaon mass [MeV]
double M_proton=938.3;
double I=188e-6;   // ionization energy for LAr [MeV]
double width=0.47;     // wire pitch, detector width [cm]
double rho=2.329;  // density of LAr
double j=0.2;      // Landau's constant

// these functions are plotted in independent variable of units 
// MeV/c and can be easily converted by setting paramteter 5 to 1 
// and adjsuting the endpoints appropiately
void muPi_MPV_vs_dEdx_RunIPosData()
{

// ##################################################################################
// ### Bethe formula for energy deposition in matter from theoretical calculation ###
// ##################################################################################


// ----------------------------------------------------------------------------
// 					Muons
// ----------------------------------------------------------------------------
  TF1 *dE_dxMu = new TF1("dE_dxMu","([0]*([5]*[5]/x/x+1)*(0.5*log([1]*pow(x/[5],4)/(2*sqrt(x*x/([5]*[5])+1)*[6]+1))-(1/([5]*[5]/x/x+1))-((x<[5]*exp(0.2*log(10)))*0+([5]*exp(0.2*log(10))<=x && x<[5]*exp(3.0*log(10)))*(2*log(x/[5])-[2]+[3]*pow([4]-log(x/[5])/log(10),3.))+(x>=[5]*exp(3.0*log(10)))*(2*log(x/[5])-[2]))/2)) * 1.396",50,2000);
  dE_dxMu->SetLineColor(kGreen+2);

  dE_dxMu->SetParameter(0,K*Z/A);
  dE_dxMu->SetParameter(1,4*m_e*m_e/I/I);
  dE_dxMu->SetParameter(2,Cbar);
  dE_dxMu->SetParameter(3,a);
  dE_dxMu->SetParameter(4,x1);
  dE_dxMu->SetParameter(5,M_mu);
  dE_dxMu->SetParameter(6,m_e/M_mu);
  dE_dxMu->SetNpx(100000);

 TF1 *E_mostProbMu = new TF1("E_mostProbMu","([0]*([6]*[6]/x/x+1)*(log([1]*(x*x/[6]/[6]))+log([0]/[7]*([6]*[6]/x/x+1))+0.2-(1/([6]*[6]/x/x+1))-((x<[6]*exp(0.2*log(10)))*0+([6]*exp(0.2*log(10))<=x && x<[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3]+[4]*pow([5]-log(x/[6])/log(10),3.))+(x>=[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3])))/[8]) * 1.396",50,2000);
  E_mostProbMu->SetLineColor(kGreen+1);
  E_mostProbMu->SetLineStyle(7);
  
  E_mostProbMu->SetParameter(0,(K/2)*(Z/A)*width*rho);
  E_mostProbMu->SetParameter(1,2*m_e/I);
  E_mostProbMu->SetParameter(3,Cbar);
  E_mostProbMu->SetParameter(4,a);
  E_mostProbMu->SetParameter(5,x1);
  E_mostProbMu->SetParameter(6,M_mu);
  E_mostProbMu->SetParameter(7,I);
  E_mostProbMu->SetParameter(8,width*rho);


//-------------------------------------------------------------------------------
// 					Pions
//-------------------------------------------------------------------------------
  TF1 *dE_dxPi = new TF1("dE_dxPi","([0]*([5]*[5]/x/x+1)*(0.5*log([1]*pow(x/[5],4)/(2*sqrt(x*x/([5]*[5])+1)*[6]+1))-(1/([5]*[5]/x/x+1))-((x<[5]*exp(0.2*log(10)))*0+([5]*exp(0.2*log(10))<=x && x<[5]*exp(3.*log(10)))*(2*log(x/[5])-[2]+[3]*pow([4]-log(x/[5])/log(10),3))+(x>=[5]*exp(3*log(10)))*(2*log(x/[5])-[2]))/2)) * 1.396",50,2000);
  dE_dxPi->SetLineColor(kRed);

  dE_dxPi->SetParameter(0,K*Z/A);
  dE_dxPi->SetParameter(1,4*m_e*m_e/I/I);
  dE_dxPi->SetParameter(2,Cbar);
  dE_dxPi->SetParameter(3,a);
  dE_dxPi->SetParameter(4,x1);
  dE_dxPi->SetParameter(5,M_pi);
  dE_dxPi->SetParameter(6,m_e/M_pi);
  dE_dxPi->SetNpx(100000);

 TF1 *E_mostProbPi = new TF1("E_mostProbPi","([0]*([6]*[6]/x/x+1)*(log([1]*(x*x/[6]/[6]))+log([0]/[7]*([6]*[6]/x/x+1))+0.2-(1/([6]*[6]/x/x+1))-((x<[6]*exp(0.2*log(10)))*0+([6]*exp(0.2*log(10))<=x && x<[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3]+[4]*pow([5]-log(x/[6])/log(10),3.))+(x>=[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3])))/[8]) * 1.396",50,2000);
  E_mostProbPi->SetLineColor(kRed);
  E_mostProbPi->SetLineStyle(7);
  
  E_mostProbPi->SetParameter(0,(K/2)*(Z/A)*width*rho);
  E_mostProbPi->SetParameter(1,2*m_e/I);
  E_mostProbPi->SetParameter(3,Cbar);
  E_mostProbPi->SetParameter(4,a);
  E_mostProbPi->SetParameter(5,x1);
  E_mostProbPi->SetParameter(6,M_pi);
  E_mostProbPi->SetParameter(7,I);
  E_mostProbPi->SetParameter(8,width*rho);


//--------------------------------------------------------------------------------
// 					Kaons
//--------------------------------------------------------------------------------
   TF1 *dE_dxKa = new TF1("dE_dxKa","([0]*([5]*[5]/x/x+1)*(0.5*log([1]*pow(x/[5],4)/(2*sqrt(x*x/([5]*[5])+1)*[6]+1))-(1/([5]*[5]/x/x+1))-((x<[5]*exp(0.2*log(10)))*0+([5]*exp(0.2*log(10))<=x && x<[5]*exp(3.*log(10)))*(2*log(x/[5])-[2]+[3]*pow([4]-log(x/[5])/log(10),3))+(x>=[5]*exp(3*log(10)))*(2*log(x/[5])-[2]))/2))*1.396",50,2000);
   dE_dxKa->SetLineColor(kBlue);

   dE_dxKa->SetParameter(0,K*Z/A);
   dE_dxKa->SetParameter(1,4*m_e*m_e/I/I);
   dE_dxKa->SetParameter(2,Cbar);
   dE_dxKa->SetParameter(3,a);
   dE_dxKa->SetParameter(4,x1);
   dE_dxKa->SetParameter(5,M_ka);
   dE_dxKa->SetParameter(6,m_e/M_ka);
   dE_dxKa->SetNpx(100000); 
   
   
 TF1 *E_mostProbKaon = new TF1("E_mostProbKaon","([0]*([6]*[6]/x/x+1)*(log([1]*(x*x/[6]/[6]))+log([0]/[7]*([6]*[6]/x/x+1))+0.2-(1/([6]*[6]/x/x+1))-((x<[6]*exp(0.2*log(10)))*0+([6]*exp(0.2*log(10))<=x && x<[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3]+[4]*pow([5]-log(x/[6])/log(10),3.))+(x>=[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3])))/[8]) * 1.396",50,2000);
  E_mostProbKaon->SetLineColor(kBlue);
  E_mostProbKaon->SetLineStyle(7);
  
  E_mostProbKaon->SetParameter(0,(K/2)*(Z/A)*width*rho);
  E_mostProbKaon->SetParameter(1,2*m_e/I);
  E_mostProbKaon->SetParameter(3,Cbar);
  E_mostProbKaon->SetParameter(4,a);
  E_mostProbKaon->SetParameter(5,x1);
  E_mostProbKaon->SetParameter(6,M_ka);
  E_mostProbKaon->SetParameter(7,I);
  E_mostProbKaon->SetParameter(8,width*rho);   
   
   
   
//---------------------------------------------------------------------------------
//					Proton
//---------------------------------------------------------------------------------
   TF1 *dE_dxProton = new TF1("dE_dxProton","([0]*([5]*[5]/x/x+1)*(0.5*log([1]*pow(x/[5],4)/(2*sqrt(x*x/([5]*[5])+1)*[6]+1))-(1/([5]*[5]/x/x+1))-((x<[5]*exp(0.2*log(10)))*0+([5]*exp(0.2*log(10))<=x && x<[5]*exp(3.*log(10)))*(2*log(x/[5])-[2]+[3]*pow([4]-log(x/[5])/log(10),3))+(x>=[5]*exp(3*log(10)))*(2*log(x/[5])-[2]))/2)) *1.396",50,2000);
   dE_dxProton->SetLineColor(kMagenta);

   dE_dxProton->SetParameter(0,K*Z/A);
   dE_dxProton->SetParameter(1,4*m_e*m_e/I/I);
   dE_dxProton->SetParameter(2,Cbar);
   dE_dxProton->SetParameter(3,a);
   dE_dxProton->SetParameter(4,x1);
   dE_dxProton->SetParameter(5,M_proton);
   dE_dxProton->SetParameter(6,m_e/M_proton);
   dE_dxProton->SetNpx(100000); 



 TF1 *E_mostProbProton = new TF1("E_mostProbProton","([0]*([6]*[6]/x/x+1)*(log([1]*(x*x/[6]/[6]))+log([0]/[7]*([6]*[6]/x/x+1))+0.2-(1/([6]*[6]/x/x+1))-((x<[6]*exp(0.2*log(10)))*0+([6]*exp(0.2*log(10))<=x && x<[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3]+[4]*pow([5]-log(x/[6])/log(10),3.))+(x>=[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3])))/[8]) *1.396",50,2000);
  E_mostProbProton->SetLineColor(kMagenta);
  E_mostProbProton->SetLineStyle(7);
  
  E_mostProbProton->SetParameter(0,(K/2)*(Z/A)*width*rho);
  E_mostProbProton->SetParameter(1,2*m_e/I);
  E_mostProbProton->SetParameter(3,Cbar);
  E_mostProbProton->SetParameter(4,a);
  E_mostProbProton->SetParameter(5,x1);
  E_mostProbProton->SetParameter(6,M_proton);
  E_mostProbProton->SetParameter(7,I);
  E_mostProbProton->SetParameter(8,width*rho);  





//						END THEORY PORTION
// #############################################################################################################






// =================================================================================================================
// =================================================================================================================
// =================================================================================================================
double dEdXPionMC[21] = {0.};
double dEdXErrorPionMC[21] = {0.};

double dEdXLessbinPionMC[11] = {0.};
double dEdXErrorLessbinPionMC[11] = {0.};


// ########################
// ### Collection Plane ###
// ########################


TFile *f1 = new TFile("../histoROOTfiles_forPlots/dEdXCalib_RunIPos_Picky_PiMuE.root");

// #######################
// ### Induction Plane ###
// #######################

//TFile *f1 = new TFile("../histoROOTfiles_forPlots/dEdXCalib_RunIPos_Picky_PiMuE_Induction.root");


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h150_200 = (TH1F*)f1->Get("hdatadEdX_150_200");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h150_200->Fit(data_gaus,"R+0LLi","0",1.0, 5.00);
h150_200->GetXaxis()->SetRangeUser(1,15);

dEdXPionMC[0]       = data_gaus->GetParameter(1);
//dEdXPionMC[0]       = h150_200->GetMean(1);
dEdXErrorPionMC[0]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[0]  = h150_200->GetMeanError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h200_250 = (TH1F*)f1->Get("hdatadEdX_200_250");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h200_250->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h200_250->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[1]       = data_gaus->GetParameter(1);
//dEdXPionMC[1]       = h200_250->GetMean(1);
dEdXErrorPionMC[1]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[1]  = h200_250->GetMeanError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionMC[0] = (dEdXPionMC[0] + dEdXPionMC[1]) / 2;
dEdXErrorLessbinPionMC[0] = sqrt( (dEdXErrorPionMC[0]*dEdXErrorPionMC[0])+(dEdXErrorPionMC[1]*dEdXErrorPionMC[1]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h250_300 = (TH1F*)f1->Get("hdatadEdX_250_300");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h250_300->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h250_300->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[2]       = data_gaus->GetParameter(1);
//dEdXPionMC[2]       = h250_300->GetMean(1);
dEdXErrorPionMC[2]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[2]  = h250_300->GetMeanError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h300_350 = (TH1F*)f1->Get("hdatadEdX_300_350");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h300_350->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h300_350->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[3]       = data_gaus->GetParameter(1);
//dEdXPionMC[3]       = h300_350->GetMean(1);
dEdXErrorPionMC[3]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[3]  = h300_350->GetMeanError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionMC[1] = (dEdXPionMC[2] + dEdXPionMC[3]) / 2;
dEdXErrorLessbinPionMC[1] = sqrt( (dEdXErrorPionMC[2]*dEdXErrorPionMC[2])+(dEdXErrorPionMC[3]*dEdXErrorPionMC[3]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h350_400 = (TH1F*)f1->Get("hdatadEdX_350_400");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h350_400->Fit(data_gaus,"R+0LLi","0",1.25, 5.25);
h350_400->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[4]       = data_gaus->GetParameter(1);
//dEdXPionMC[4]       = h350_400->GetMean(1);
dEdXErrorPionMC[4]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[4]  = h350_400->GetMeanError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h400_450 = (TH1F*)f1->Get("hdatadEdX_400_450");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h400_450->Fit(data_gaus,"R+0LLi","0",1.25, 3.0);
h400_450->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[5]       = data_gaus->GetParameter(1);
//dEdXPionMC[5]       = h400_450->GetMean(1);
dEdXErrorPionMC[5]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[5]  = h400_450->GetMeanError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionMC[2] = (dEdXPionMC[4] + dEdXPionMC[5]) / 2;
dEdXErrorLessbinPionMC[2] = sqrt( (dEdXErrorPionMC[4]*dEdXErrorPionMC[4])+(dEdXErrorPionMC[5]*dEdXErrorPionMC[5]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h450_500 = (TH1F*)f1->Get("hdatadEdX_450_500");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h450_500->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);
h450_500->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[6]       = data_gaus->GetParameter(1);
//dEdXPionMC[6]       = h450_500->GetMean(1);
dEdXErrorPionMC[6]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[6]  = h450_500->GetMeanError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h500_550 = (TH1F*)f1->Get("hdatadEdX_500_550");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h500_550->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h500_550->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[7]       = data_gaus->GetParameter(1);
//dEdXPionMC[7]       = h500_550->GetMean(1);
dEdXErrorPionMC[7]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[7]  = h500_550->GetMeanError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionMC[3] = (dEdXPionMC[6] + dEdXPionMC[7]) / 2;
dEdXErrorLessbinPionMC[3] = sqrt( (dEdXErrorPionMC[6]*dEdXErrorPionMC[6])+(dEdXErrorPionMC[7]*dEdXErrorPionMC[7]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h550_600 = (TH1F*)f1->Get("hdatadEdX_550_600");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h550_600->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h550_600->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[8]       = data_gaus->GetParameter(1);
//dEdXPionMC[8]       = h550_600->GetMean(1);
dEdXErrorPionMC[8]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[8]  = h550_600->GetMeanError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h600_650 = (TH1F*)f1->Get("hdatadEdX_600_650");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h600_650->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h600_650->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[9]       = data_gaus->GetParameter(1);
//dEdXPionMC[9]       = h600_650->GetMean(1);
dEdXErrorPionMC[9]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[9]  = h600_650->GetMeanError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionMC[4] = (dEdXPionMC[8] + dEdXPionMC[9]) / 2;
dEdXErrorLessbinPionMC[4] = sqrt( (dEdXErrorPionMC[8]*dEdXErrorPionMC[8])+(dEdXErrorPionMC[9]*dEdXErrorPionMC[9]) );

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h650_700 = (TH1F*)f1->Get("hdatadEdX_650_700");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h650_700->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h650_700->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[10]       = data_gaus->GetParameter(1);
//dEdXPionMC[10]       = h650_700->GetMean(1);
dEdXErrorPionMC[10]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[10]  = h650_700->GetMeanError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h700_750 = (TH1F*)f1->Get("hdatadEdX_700_750");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h700_750->Fit(data_gaus,"R+0LLi","0",1.25, 6.00);
h700_750->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[11]       = data_gaus->GetParameter(1);
//dEdXPionMC[11]       = h700_750->GetMean(1);
dEdXErrorPionMC[11]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[11]  = h700_750->GetMeanError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionMC[5] = (dEdXPionMC[10] + dEdXPionMC[11]) / 2;
dEdXErrorLessbinPionMC[5] = sqrt( (dEdXErrorPionMC[10]*dEdXErrorPionMC[10])+(dEdXErrorPionMC[11]*dEdXErrorPionMC[11]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h750_800 = (TH1F*)f1->Get("hdatadEdX_750_800");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h750_800->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h750_800->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[12]       = data_gaus->GetParameter(1);
//dEdXPionMC[12]       = h750_800->GetMean(1);
dEdXErrorPionMC[12]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[12]  = h750_800->GetMeanError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h800_850 = (TH1F*)f1->Get("hdatadEdX_800_850");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h800_850->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h800_850->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[13]       = data_gaus->GetParameter(1);
//dEdXPionMC[13]       = h800_850->GetMean(1);
dEdXErrorPionMC[13]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[13]  = h800_850->GetMeanError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionMC[6] = (dEdXPionMC[12] + dEdXPionMC[13]) / 2;
dEdXErrorLessbinPionMC[6] = sqrt( (dEdXErrorPionMC[12]*dEdXErrorPionMC[12])+(dEdXErrorPionMC[13]*dEdXErrorPionMC[13]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h850_900 = (TH1F*)f1->Get("hdatadEdX_850_900");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h850_900->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h850_900->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[14]       = data_gaus->GetParameter(1);
//dEdXPionMC[14]       = h850_900->GetMean(1);
dEdXErrorPionMC[14]  = data_gaus->GetParError(1);
//dEdXErrorPionMC[14]  = h850_900->GetMeanError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h900_950 = (TH1F*)f1->Get("hdatadEdX_900_950");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h900_950->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h900_950->GetXaxis()->SetRangeUser(1.00,15);

dEdXPionMC[15]       = data_gaus->GetParameter(1);
dEdXErrorPionMC[15]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionMC[7] = (dEdXPionMC[14] + dEdXPionMC[15]) / 2;
dEdXErrorLessbinPionMC[7] = sqrt( (dEdXErrorPionMC[14]*dEdXErrorPionMC[14])+(dEdXErrorPionMC[15]*dEdXErrorPionMC[15]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h950_1000 = (TH1F*)f1->Get("hdatadEdX_950_1000");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h950_1000->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h950_1000->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[16]       = data_gaus->GetParameter(1);
dEdXErrorPionMC[16]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1000_1050 = (TH1F*)f1->Get("hdatadEdX_1000_1050");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1000_1050->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h1000_1050->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[17]       = data_gaus->GetParameter(1);
dEdXErrorPionMC[17]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionMC[8] = (dEdXPionMC[16] + dEdXPionMC[17]) / 2;
dEdXErrorLessbinPionMC[8] = sqrt( (dEdXErrorPionMC[16]*dEdXErrorPionMC[16])+(dEdXErrorPionMC[17]*dEdXErrorPionMC[17]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1050_1100 = (TH1F*)f1->Get("hdatadEdX_1050_1100");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1050_1100->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h1050_1100->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[18]       = data_gaus->GetParameter(1);
dEdXErrorPionMC[18]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1100_1150 = (TH1F*)f1->Get("hdatadEdX_1100_1150");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1100_1150->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h1100_1150->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[19]       = data_gaus->GetParameter(1);
dEdXErrorPionMC[19]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1150_1200 = (TH1F*)f1->Get("hdatadEdX_1150_1200");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1150_1200->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);
h1150_1200->GetXaxis()->SetRangeUser(1.25,15);

dEdXPionMC[20]       = data_gaus->GetParameter(1);
dEdXErrorPionMC[20]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionMC[9] = (dEdXPionMC[18] + dEdXPionMC[19] + dEdXPionMC[20]) / 3;
dEdXErrorLessbinPionMC[9] = sqrt( (dEdXErrorPionMC[18]*dEdXErrorPionMC[18])+(dEdXErrorPionMC[19]*dEdXErrorPionMC[19]) + (dEdXErrorPionMC[20]*dEdXErrorPionMC[20]));


// ##########################
// ### Finely binned Data ###
// ##########################
const Int_t nPionData = 20;

double binXLessbin[20] = {200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100};
double binXErrorLessbin[20] = {0.};

for(int a = 0; a < nPionData; a++){binXErrorLessbin[a] = 50.;}


grPionData  = new TGraphErrors(nPionData,binXLessbin,dEdXLessbinPionMC,binXErrorLessbin,dEdXErrorLessbinPionMC);
grPionData->SetFillColor(kWhite);
grPionData->SetFillStyle(3005);
grPionData->SetLineColor(kBlack);
grPionData->SetLineWidth(2);
grPionData->SetMarkerStyle(20);
grPionData->SetMarkerColor(kRed+2);

// ================================================================================================================
// =================================================================================================================
// ===================================================================================================================






// =================================================================================================================
// =================================================================================================================
// ===================================================================================================================

double dEdX[21] = {0.};
double dEdXError[21] = {0.};

double dEdXLessbin[11] = {0.};
double dEdXErrorLessbin[11] = {0.};

// ########################
// ### Collection Plane ###
// ########################

TFile *f2 = new TFile("../histoROOTfiles_forPlots/dEdXCalib_RunIPos_Picky_Proton.root");

// #######################
// ### Induction Plane ###
// #######################

//TFile *f2 = new TFile("../histoROOTfiles_forPlots/dEdXCalib_RunIPos_Picky_Proton_Induction.root");


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton150_200 = (TH1F*)f2->Get("hdatadEdX_150_200");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton150_200->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[0]       = data_gaus->GetParameter(1);
dEdXError[0]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton200_250 = (TH1F*)f2->Get("hdatadEdX_200_250");
TF1 *data_gaus = new TF1("data_gaus","landau",2.5, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton200_250->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[1]       = data_gaus->GetParameter(1);
dEdXError[1]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[0] = (dEdX[0] + dEdX[1]) / 2;
dEdXErrorLessbin[0] = sqrt( (dEdXError[0]*dEdXError[0])+(dEdXError[1]*dEdXError[1]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton250_300 = (TH1F*)f2->Get("hdatadEdX_250_300");
TF1 *data_gaus = new TF1("data_gaus","landau",2.5, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton250_300->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[2]       = data_gaus->GetParameter(1);
dEdXError[2]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton300_350 = (TH1F*)f2->Get("hdatadEdX_300_350");
TF1 *data_gaus = new TF1("data_gaus","landau",2.5, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton300_350->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[3]       = data_gaus->GetParameter(1);
dEdXError[3]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[0] = (dEdX[2] + dEdX[3]) / 2;
dEdXErrorLessbin[0] = sqrt( (dEdXError[2]*dEdXError[2])+(dEdXError[3]*dEdXError[3]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton350_400 = (TH1F*)f2->Get("hdatadEdX_350_400");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton350_400->Fit(data_gaus,"R+0LLi","0",1.25, 5.25);

dEdX[4]       = data_gaus->GetParameter(1);
dEdXError[4]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton400_450 = (TH1F*)f2->Get("hdatadEdX_400_450");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton400_450->Fit(data_gaus,"R+0LLi","0",1.25, 3.0);

dEdX[5]       = data_gaus->GetParameter(1);
dEdXError[5]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[1] = (dEdX[4] + dEdX[5]) / 2;
dEdXErrorLessbin[1] = sqrt( (dEdXError[4]*dEdXError[4])+(dEdXError[5]*dEdXError[5]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton450_500 = (TH1F*)f2->Get("hdatadEdX_450_500");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton450_500->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

// !!!! This bin has too little data for consideration !!!!
dEdX[6]       = 0;//hProton450_500->GetMean(1);
dEdXError[6]  = 0;//hProton450_500->GetMeanError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton500_550 = (TH1F*)f2->Get("hdatadEdX_500_550");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton500_550->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);


// !!!! This bin has too little data for consideration !!!!
dEdX[7]       = data_gaus->GetParameter(1);
dEdXError[7]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[2] = (dEdX[6] + dEdX[7]) *2 ;
dEdXErrorLessbin[2] = sqrt( (dEdXError[6]*dEdXError[6])+(dEdXError[7]*dEdXError[7]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton550_600 = (TH1F*)f2->Get("hdatadEdX_550_600");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton550_600->Fit(data_gaus,"R+0LLi","0",4.5, 10.00);
//hProton550_600->GetXaxis()->SetRangeUser(3,15);
dEdX[8]       = data_gaus->GetParameter(1);
dEdXError[8]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton600_650 = (TH1F*)f2->Get("hdatadEdX_600_650");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton600_650->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);
hProton600_650->GetXaxis()->SetRangeUser(2.5,15);

dEdX[9]       = data_gaus->GetParameter(1);
dEdXError[9]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[3] = (dEdX[8] + dEdX[9]) / 2;
dEdXErrorLessbin[3] = sqrt( (dEdXError[8]*dEdXError[8])+(dEdXError[9]*dEdXError[9]) );

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton650_700 = (TH1F*)f2->Get("hdatadEdX_650_700");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton650_700->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);
hProton650_700->GetXaxis()->SetRangeUser(2.5,15);

dEdX[10]       = data_gaus->GetParameter(1);
dEdXError[10]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton700_750 = (TH1F*)f2->Get("hdatadEdX_700_750");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton700_750->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);
hProton700_750->GetXaxis()->SetRangeUser(2.5,15);

dEdX[11]       = data_gaus->GetParameter(1);
dEdXError[11]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[4] = (dEdX[10] + dEdX[11]) / 2;
dEdXErrorLessbin[4] = sqrt( (dEdXError[10]*dEdXError[10])+(dEdXError[11]*dEdXError[11]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton750_800 = (TH1F*)f2->Get("hdatadEdX_750_800");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton750_800->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);
hProton750_800->GetXaxis()->SetRangeUser(3,15);

dEdX[12]       = data_gaus->GetParameter(1);
dEdXError[12]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton800_850 = (TH1F*)f2->Get("hdatadEdX_800_850");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton800_850->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);
hProton800_850->GetXaxis()->SetRangeUser(3,15);

dEdX[13]       = data_gaus->GetParameter(1);
dEdXError[13]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[5] = (dEdX[12] + dEdX[13]) / 2;
dEdXErrorLessbin[5] = sqrt( (dEdXError[12]*dEdXError[12])+(dEdXError[13]*dEdXError[13]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton850_900 = (TH1F*)f2->Get("hdatadEdX_850_900");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton850_900->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);
hProton850_900->GetXaxis()->SetRangeUser(3,15);

dEdX[14]       = data_gaus->GetParameter(1);
dEdXError[14]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton900_950 = (TH1F*)f2->Get("hdatadEdX_900_950");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton900_950->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);
hProton900_950->GetXaxis()->SetRangeUser(3,15);

dEdX[15]       = data_gaus->GetParameter(1);
dEdXError[15]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[6] = (dEdX[14] + dEdX[15]) / 2;
dEdXErrorLessbin[6] = sqrt( (dEdXError[14]*dEdXError[14])+(dEdXError[15]*dEdXError[15]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton950_1000 = (TH1F*)f2->Get("hdatadEdX_950_1000");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton950_1000->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[16]       = data_gaus->GetParameter(1);
dEdXError[16]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton1000_1050 = (TH1F*)f2->Get("hdatadEdX_1000_1050");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton1000_1050->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[17]       = data_gaus->GetParameter(1);
dEdXError[17]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[7] = (dEdX[16] + dEdX[17]) / 2;
dEdXErrorLessbin[7] = sqrt( (dEdXError[16]*dEdXError[16])+(dEdXError[17]*dEdXError[17]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton1050_1100 = (TH1F*)f2->Get("hdatadEdX_1050_1100");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton1050_1100->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[18]       = data_gaus->GetParameter(1);
dEdXError[18]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton1100_1150 = (TH1F*)f2->Get("hdatadEdX_1100_1150");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton1100_1150->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[19]       = data_gaus->GetParameter(1);
dEdXError[19]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton1150_1200 = (TH1F*)f2->Get("hdatadEdX_1150_1200");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton1150_1200->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[20]       = data_gaus->GetParameter(1);
dEdXError[20]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[8] = (dEdX[18] + dEdX[19] + dEdX[20]) / 3;
dEdXErrorLessbin[8] = sqrt( (dEdXError[18]*dEdXError[18])+(dEdXError[19]*dEdXError[19]) + (dEdXError[20]*dEdXError[20]));


double binXLessbinProton[11] = {200, 300, 350, 450, 600, 700, 800, 900, 1000, 1100};
double binXErrorLessbinProton[11] = {0.};

for(int a = 0; a < 11; a++){binXErrorLessbinProton[a] = 50.;}
binXErrorLessbinProton[3] = 100.;

const Int_t nproton = 10;

// ### Finely binned Data ###
grprotondata  = new TGraphErrors(nproton,binXLessbinProton,dEdXLessbin,binXErrorLessbinProton,dEdXErrorLessbin);
grprotondata->SetFillColor(kWhite);
grprotondata->SetFillStyle(3005);
grprotondata->SetLineColor(kBlack);
grprotondata->SetLineWidth(2);
grprotondata->SetMarkerStyle(20);
grprotondata->SetMarkerColor(kPink-3);


// =================================================================================================================
// =================================================================================================================
// ===================================================================================================================



















  //----------------------------------------------------------------------------------
  // plot functions
  dE_dxMu->SetTitle("#LTdE/dx#GT and MPV in LAr; Momentum [MeV/c] ; Energy Loss [MeV/cm]");
  dE_dxMu->Draw();
  dE_dxPi->Draw("same");
  dE_dxKa->Draw("same");
  dE_dxProton->Draw("same");
  E_mostProbMu->Draw("same");
  E_mostProbPi->Draw("same");
  E_mostProbKaon->Draw("same");
  E_mostProbProton->Draw("same");
  //grPionData->Draw("CPSAME");
  //grprotondata->Draw("CPSAME");

  //gPad->SetLogx();
  //gPad->SetLogy();
  gPad->SetGrid(1,1);
  dE_dxMu->GetYaxis()->SetMoreLogLabels();
  dE_dxMu->SetMinimum(1.3);
  dE_dxMu->SetMaximum(10);

 TLegend *legend = new TLegend(0.7,0.90,.95,0.65);
 legend->SetHeader("LArIAT Run-I Positive Polarity");
 legend->AddEntry("dE_dxMu","#mu #LTdE/dx#GT","l");
 legend->AddEntry("E_mostProbMu","#mu MPV/width","l");
 legend->AddEntry("dE_dxPi","#pi #LTdE/dx#GT","l");
 legend->AddEntry("E_mostProbPi","#pi MPV/width","l");
 //legend->AddEntry("grPionData","Run-I #pi^{+} Data","l");
 legend->AddEntry("dE_dxKa","Kaon #LTdE/dx#GT","l");
 legend->AddEntry("E_mostProbKaon","Kaon MPV/width","l");
 legend->AddEntry("dE_dxProton","Proton #LTdE/dx#GT","l");
 legend->AddEntry("E_mostProbProton","Proton MPV/width","l");
 //legend->AddEntry("grprotondata","Run-I proton Data","l");
 legend->Draw("same");
}

