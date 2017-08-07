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
double rho=1.396;  // density of LAr
double j=0.2;      // Landau's constant

// these functions are plotted in independent variable of units 
// MeV/c and can be easily converted by setting paramteter 5 to 1 
// and adjsuting the endpoints appropiately
void muPi_MPV_vs_dEdx()
{

// ##################################################################################
// ### Bethe formula for energy deposition in matter from theoretical calculation ###
// ##################################################################################


// ----------------------------------------------------------------------------
// 					Muons
// ----------------------------------------------------------------------------
  TF1 *dE_dxMu = new TF1("dE_dxMu","([0]*([5]*[5]/x/x+1)*(0.5*log([1]*pow(x/[5],4)/(2*sqrt(x*x/([5]*[5])+1)*[6]+1))-(1/([5]*[5]/x/x+1))-((x<[5]*exp(0.2*log(10)))*0+([5]*exp(0.2*log(10))<=x && x<[5]*exp(3.0*log(10)))*(2*log(x/[5])-[2]+[3]*pow([4]-log(x/[5])/log(10),3.))+(x>=[5]*exp(3.0*log(10)))*(2*log(x/[5])-[2]))/2)) * 1.396",50,6000);
  dE_dxMu->SetLineColor(kGreen+2);

  dE_dxMu->SetParameter(0,K*Z/A);
  dE_dxMu->SetParameter(1,4*m_e*m_e/I/I);
  dE_dxMu->SetParameter(2,Cbar);
  dE_dxMu->SetParameter(3,a);
  dE_dxMu->SetParameter(4,x1);
  dE_dxMu->SetParameter(5,M_mu);
  dE_dxMu->SetParameter(6,m_e/M_mu);
  dE_dxMu->SetNpx(100000);

 TF1 *E_mostProbMu = new TF1("E_mostProbMu","([0]*([6]*[6]/x/x+1)*(log([1]*(x*x/[6]/[6]))+log([0]/[7]*([6]*[6]/x/x+1))+0.2-(1/([6]*[6]/x/x+1))-((x<[6]*exp(0.2*log(10)))*0+([6]*exp(0.2*log(10))<=x && x<[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3]+[4]*pow([5]-log(x/[6])/log(10),3.))+(x>=[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3])))/[8]) * 1.396",50,6000);
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
  TF1 *dE_dxPi = new TF1("dE_dxPi","([0]*([5]*[5]/x/x+1)*(0.5*log([1]*pow(x/[5],4)/(2*sqrt(x*x/([5]*[5])+1)*[6]+1))-(1/([5]*[5]/x/x+1))-((x<[5]*exp(0.2*log(10)))*0+([5]*exp(0.2*log(10))<=x && x<[5]*exp(3.*log(10)))*(2*log(x/[5])-[2]+[3]*pow([4]-log(x/[5])/log(10),3))+(x>=[5]*exp(3*log(10)))*(2*log(x/[5])-[2]))/2)) * 1.396",50,6000);
  dE_dxPi->SetLineColor(kRed);

  dE_dxPi->SetParameter(0,K*Z/A);
  dE_dxPi->SetParameter(1,4*m_e*m_e/I/I);
  dE_dxPi->SetParameter(2,Cbar);
  dE_dxPi->SetParameter(3,a);
  dE_dxPi->SetParameter(4,x1);
  dE_dxPi->SetParameter(5,M_pi);
  dE_dxPi->SetParameter(6,m_e/M_pi);
  dE_dxPi->SetNpx(100000);

 TF1 *E_mostProbPi = new TF1("E_mostProbPi","([0]*([6]*[6]/x/x+1)*(log([1]*(x*x/[6]/[6]))+log([0]/[7]*([6]*[6]/x/x+1))+0.2-(1/([6]*[6]/x/x+1))-((x<[6]*exp(0.2*log(10)))*0+([6]*exp(0.2*log(10))<=x && x<[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3]+[4]*pow([5]-log(x/[6])/log(10),3.))+(x>=[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3])))/[8]) * 1.396",50,6000);
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
   TF1 *dE_dxKa = new TF1("dE_dxKa","([0]*([5]*[5]/x/x+1)*(0.5*log([1]*pow(x/[5],4)/(2*sqrt(x*x/([5]*[5])+1)*[6]+1))-(1/([5]*[5]/x/x+1))-((x<[5]*exp(0.2*log(10)))*0+([5]*exp(0.2*log(10))<=x && x<[5]*exp(3.*log(10)))*(2*log(x/[5])-[2]+[3]*pow([4]-log(x/[5])/log(10),3))+(x>=[5]*exp(3*log(10)))*(2*log(x/[5])-[2]))/2))*1.396",50,6000);
   dE_dxKa->SetLineColor(kBlue);

   dE_dxKa->SetParameter(0,K*Z/A);
   dE_dxKa->SetParameter(1,4*m_e*m_e/I/I);
   dE_dxKa->SetParameter(2,Cbar);
   dE_dxKa->SetParameter(3,a);
   dE_dxKa->SetParameter(4,x1);
   dE_dxKa->SetParameter(5,M_ka);
   dE_dxKa->SetParameter(6,m_e/M_ka);
   dE_dxKa->SetNpx(100000); 
   
   
 TF1 *E_mostProbKaon = new TF1("E_mostProbKaon","([0]*([6]*[6]/x/x+1)*(log([1]*(x*x/[6]/[6]))+log([0]/[7]*([6]*[6]/x/x+1))+0.2-(1/([6]*[6]/x/x+1))-((x<[6]*exp(0.2*log(10)))*0+([6]*exp(0.2*log(10))<=x && x<[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3]+[4]*pow([5]-log(x/[6])/log(10),3.))+(x>=[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3])))/[8]) * 1.396",50,6000);
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
   TF1 *dE_dxProton = new TF1("dE_dxProton","([0]*([5]*[5]/x/x+1)*(0.5*log([1]*pow(x/[5],4)/(2*sqrt(x*x/([5]*[5])+1)*[6]+1))-(1/([5]*[5]/x/x+1))-((x<[5]*exp(0.2*log(10)))*0+([5]*exp(0.2*log(10))<=x && x<[5]*exp(3.*log(10)))*(2*log(x/[5])-[2]+[3]*pow([4]-log(x/[5])/log(10),3))+(x>=[5]*exp(3*log(10)))*(2*log(x/[5])-[2]))/2)) *1.396",50,6000);
   dE_dxProton->SetLineColor(kMagenta);

   dE_dxProton->SetParameter(0,K*Z/A);
   dE_dxProton->SetParameter(1,4*m_e*m_e/I/I);
   dE_dxProton->SetParameter(2,Cbar);
   dE_dxProton->SetParameter(3,a);
   dE_dxProton->SetParameter(4,x1);
   dE_dxProton->SetParameter(5,M_proton);
   dE_dxProton->SetParameter(6,m_e/M_proton);
   dE_dxProton->SetNpx(100000); 



 TF1 *E_mostProbProton = new TF1("E_mostProbProton","([0]*([6]*[6]/x/x+1)*(log([1]*(x*x/[6]/[6]))+log([0]/[7]*([6]*[6]/x/x+1))+0.2-(1/([6]*[6]/x/x+1))-((x<[6]*exp(0.2*log(10)))*0+([6]*exp(0.2*log(10))<=x && x<[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3]+[4]*pow([5]-log(x/[6])/log(10),3.))+(x>=[6]*exp(3.0*log(10)))*(2*log(x/[6])-[3])))/[8]) *1.396",50,6000);
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




  //----------------------------------------------------------------------------------
  // plot functions
  dE_dxMu->SetTitle("#LTdE/dx#GT and #Delta_{p}/x for #pi and #mu in LAr; Momentum [MeV/c] ; Electronic Energy Loss [MeV/cm]");
  dE_dxMu->Draw();
  dE_dxPi->Draw("same");
  dE_dxKa->Draw("same");
  dE_dxProton->Draw("same");
  E_mostProbMu->Draw("same");
  E_mostProbPi->Draw("same");
  E_mostProbKaon->Draw("same");
  E_mostProbProton->Draw("same");

  //gPad->SetLogx();
  //gPad->SetLogy();
  gPad->SetGrid(1,1);
  dE_dxMu->GetYaxis()->SetMoreLogLabels();
  dE_dxMu->SetMinimum(1.3);
  dE_dxMu->SetMaximum(8);

 TLegend *legend = new TLegend(0.7,0.90,.95,0.65);
 legend->SetHeader("LArIAT Preliminary");
 //legend->AddEntry("dE_dxMu","#LTdE/dx#GT #mu (muon)","l");
 legend->AddEntry("E_mostProbMu","MPV #mu (muon)","l");
 //legend->AddEntry("dE_dxPi","#LTdE/dx#GT #pi (pion)","l");
 legend->AddEntry("E_mostProbPi","MPV #pi (pion)","l");
 //legend->AddEntry("dE_dxKa","#LTdE/dx#GT K (kaon)","l");
 legend->AddEntry("E_mostProbKaon","MPV K (kaon)","l");
 //legend->AddEntry("dE_dxProton","#LTdE/dx#GT p (proton)","l");
 legend->AddEntry("E_mostProbProton","MPV p (proton)","l");
 legend->Draw("same");
}

