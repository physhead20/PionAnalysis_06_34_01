#define PionMCDD_RunIPickyTrk_cxx
#include "PionMCDD_RunIPickyTrk.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

// *********************************** GEANT INFORMATION ****************************************************************


/////////////////////////////////// Primary Particle Start X Position //////////////////////////////////////////
TH1D *hMCPrimaryStartX = new TH1D("hMCPrimaryStartX", "Primary Particle X_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Y Position //////////////////////////////////////////
TH1D *hMCPrimaryStartY = new TH1D("hMCPrimaryStartY", "Primary Particle Y_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Z Position //////////////////////////////////////////
TH1D *hMCPrimaryStartZ = new TH1D("hMCPrimaryStartZ", "Primary Particle Z_{0}", 600, -120 , 180);

/////////////////////////////////// Primary Projected Particle Start X Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartX = new TH1D("hMCPrimaryProjectedStartX", "Primary Particle X_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Projected Particle Start Y Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartY = new TH1D("hMCPrimaryProjectedStartY", "Primary Particle Y_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Projected Particle Start Z Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartZ = new TH1D("hMCPrimaryProjectedStartZ", "Primary Particle Z_{0}", 400, -50 , 150);

/////////////////////////////////// Primary Particle End X Position //////////////////////////////////////////
TH1D *hMCPrimaryEndX = new TH1D("hMCPrimaryEndX", "Primary Particle X_{f}", 400, -200 , 200);
/////////////////////////////////// Primary Particle End Y Position //////////////////////////////////////////
TH1D *hMCPrimaryEndY = new TH1D("hMCPrimaryEndY", "Primary Particle Y_{f}", 400, -200 , 200);
/////////////////////////////////// Primary Particle End Z Position //////////////////////////////////////////
TH1D *hMCPrimaryEndZ = new TH1D("hMCPrimaryEndZ", "Primary Particle Z_{f}", 600, -120 , 480);

/////////////////////////////////// Primary Particle Px  //////////////////////////////////////////
TH1D *hMCPrimaryPx = new TH1D("hMCPrimaryPx", "Primary Particle P_{x}", 300, -150 , 150);
/////////////////////////////////// Primary Particle Py  //////////////////////////////////////////
TH1D *hMCPrimaryPy = new TH1D("hMCPrimaryPy", "Primary Particle P_{y}", 300, -159 , 150);
/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *hMCPrimaryPz = new TH1D("hMCPrimaryPz", "Primary Particle P_{z}", 250, 0 , 2500);


/////////////////////////////////// Primary Particle Px (unweighted)  //////////////////////////////////////////
TH1D *hMCPrimaryPxUnWeighted = new TH1D("hMCPrimaryPxUnWeighted", "Primary Particle P_{x} UnWeighted", 300, -150 , 150);
/////////////////////////////////// Primary Particle Py  //////////////////////////////////////////
TH1D *hMCPrimaryPyUnWeighted = new TH1D("hMCPrimaryPyUnWeighted", "Primary Particle P_{y} UnWeighted", 300, -159 , 150);
/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *hMCPrimaryPzUnWeighted = new TH1D("hMCPrimaryPzUnWeighted", "Primary Particle P_{z} UnWeighted", 250, 0 , 2500);

/////////////////////////////////// Primary Particle Process //////////////////////////////////////////
TH1D *hMCPrimaryProcess = new TH1D("hMCPrimaryProcess", "Primary Particle Process", 100, 0 , 10);

/////////////////////////////////// Primary End X vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndXvsZ = new TH2D("hMCPrimaryEndXvsZ", "X_{f} vs Z_{f}", 600, -150, 450, 400, -200, 200);
/////////////////////////////////// Primary End Y vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndYvsZ = new TH2D("hMCPrimaryEndYvsZ", "Y_{f} vs Z_{f}", 600, -150, 450, 200, -200, 200);

/////////////////////////////////// Energy Loss in the upstream region of the beamline ///////////////////////
TH1D *hMCELossUpstream = new TH1D("hMCELossUpstream", "Energy loss prior to entering the TPC", 1000, 0, 1000);

/////////////////////////////////// True Length //////////////////////////////////////////
TH1D *hMCTrueLength = new TH1D("hMCTrueLength", "#True Length of the Primary Particle inside the TPC", 200, 0 , 100);


// **********************************************************************************************************************



// ********************************************** RECONSTRUCTED INFORMATION **********************************************


/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hRecoMCUpstreamZPos = new TH1D("hRecoMCUpstreamZPos", "Most upstream spacepoint of all TPC Tracks", 20, 0, 10);

/////////////////////////////////// TPC Track Theta at the upstream point //////////////////////////////////////
TH1D *hRecoMCTPCTheta = new TH1D("hRecoMCTPCTheta", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Theta at the upstream point unweighted //////////////////////////////////////
TH1D *hRecoMCTPCThetaUnWeighted = new TH1D("hRecoMCTPCThetaUnWeighted", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Phi at the upstream point ///////////////////////////////////////
TH1D *hRecoMCTPCPhi = new TH1D("hRecoMCTPCPhi", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// TPC Track Phi at the upstream point unweighted ///////////////////////////////////////
TH1D *hRecoMCTPCPhiUnWeighted = new TH1D("hRecoMCTPCPhiUnWeighted", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// Wire Chamber Theta ////////////////////////////////////////////////////////
TH1D *hRecoMCWCTheta = new TH1D("hRecoMCWCTheta", "WCTrack Theta", 180, 0, 90);

/////////////////////////////////// Wire Chamber Theta unweighted ////////////////////////////////////////////////////////
TH1D *hRecoMCWCThetaUnWeighted = new TH1D("hRecoMCWCThetaUnWeighted", "WCTrack Theta", 180, 0, 90);

/////////////////////////////////// Wire Chamber Phi //////////////////////////////////////////////////////////
TH1D *hRecoMChWCPhi = new TH1D("hRecoMChWCPhi", "WCTrack Phi", 360, 0, 360);

/////////////////////////////////// Wire Chamber Phi unweighted //////////////////////////////////////////////////////////
TH1D *hRecoMChWCPhiUnWeighted = new TH1D("hRecoMChWCPhiUnWeighted", "WCTrack Phi", 360, 0, 360);

/////////////////////////////////// Delta WCTrack X ///////////////////////////////////////////////////////////
TH1D *hRecoMCDeltaWCTrkX = new TH1D("hRecoMCDeltaWCTrkX", "#Delta X TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Delta WCTrack Y ///////////////////////////////////////////////////////////
TH1D *hRecoMCDeltaWCTrkY = new TH1D("hRecoMCDeltaWCTrkY", "#Delta Y TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Alpha Between WC and TPC Tracks //////////////////////////////////////////
TH1D *hRecoMCAlpha = new TH1D("hRecoMCAlpha", "#alpha between WC and TPC Track", 90, 0, 90);

/////////////////////////////////// Number of Matched Tracks ////////////////////////////////////////////////
TH1D *hRecoMCNMatchTPCWCTrk = new TH1D("hRecoMCNMatchTPCWCTrk", "Number of matched TPC/WC Tracks", 20, 0, 10);

/////////////////////////////////// WCTRK Momentum Histogram (MeV) //////////////////////////////////////////
TH1D *hRecoMCWCTRKMomentum = new TH1D("hRecoMCWCTRKMomentum", "WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Initial Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hRecoMCInitialKEMomentum = new TH1D("hRecoMCInitialKEMomentum", "Pion Initial Momentum (MeV)", 500, 0, 2500); 

/////////////////////////////////// Initial Kinetic Energy (MeV) Unweighted /////////////////////////////////////////////
TH1D *hRecoMCInitialKEMomentumUnWeighted = new TH1D("hRecoMCInitialKEMomentumUnWeighted", "Pion Initial Momentum (MeV)", 500, 0, 2500);

/////////////////////////////////// "Matched Track" dE/dX /////////////////////////////////////////////////////
TH1D *hRecoMCdEdX = new TH1D("hRecoMCdEdX", "Matched Track dE/dX", 500, 0, 50);

/////////////////////////////////// "Matched Track" dQ/dX /////////////////////////////////////////////////////
TH1D *hRecoMCdQdX = new TH1D("hRecoMCdQdX", "Matched Track dQ/dX", 2000, 0, 20000);

// -------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////// "Matched Track" dE/dX in Q1 /////////////////////////////////////////////////////
TH1D *hMCRecodEdXQ1 = new TH1D("hMCRecodEdXQ1", "Matched Track dE/dX Q1", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q2 /////////////////////////////////////////////////////
TH1D *hMCRecodEdXQ2 = new TH1D("hMCRecodEdXQ2", "Matched Track dE/dX Q2", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q3 /////////////////////////////////////////////////////
TH1D *hMCRecodEdXQ3 = new TH1D("hMCRecodEdXQ3", "Matched Track dE/dX Q3", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q4 /////////////////////////////////////////////////////
TH1D *hMCRecodEdXQ4 = new TH1D("hMCRecodEdXQ4", "Matched Track dE/dX Q4", 200, 0, 50);

/////////////////////////////////// "Matched Track" dQ/dX in Q1 /////////////////////////////////////////////////////
TH1D *hMCRecodQdXQ1 = new TH1D("hMCRecodQdXQ1", "Matched Track dQ/dX Q1", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q2 /////////////////////////////////////////////////////
TH1D *hMCRecodQdXQ2 = new TH1D("hMCRecodQdXQ2", "Matched Track dQ/dX Q2", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q3 /////////////////////////////////////////////////////
TH1D *hMCRecodQdXQ3 = new TH1D("hMCRecodQdXQ3", "Matched Track dQ/dX Q3", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q4 /////////////////////////////////////////////////////
TH1D *hMCRecodQdXQ4 = new TH1D("hMCRecodQdXQ4", "Matched Track dQ/dX Q4", 2000, 0, 20000);


// --------------------------------------------------------------------------------------------------------------------------


/////////////////////////////////// "Matched Track" dE/dX (Fixed) /////////////////////////////////////////////////////
TH1D *hRecoMCdEdXFixed = new TH1D("hRecoMCdEdXFixed", "Matched Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Matched Track" Residual Range //////////////////////////////////////////
TH1D *hRecoMCPionRR = new TH1D("hRecoMCPionRR", "Matched Track Residual Range", 400, -100, 100);

/////////////////////////////////// "Matched Track" Track Pitch //////////////////////////////////////////
TH1D *hRecoMCPionTrkPitch = new TH1D("hRecoMCPionTrkPitch", "Matched Track Pitch", 1000, 0, 5);

///////////////////////////////// "Matched Track" dE/dX vs RR ///////////////////////////////////////////////
TH2D *hRecoMCdEdXvsRR = new TH2D("hRecoMCdEdXvsRR", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

///////////////////////////////// "Matched Track" dE/dX vs RR (Fixed) ///////////////////////////////////////////////
TH2D *hRecoMCdEdXvsRRFix = new TH2D("hRecoMCdEdXvsRRFix", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

///////////////////////////////// "Matched Track" dE/dX vs RR (Fixed) ///////////////////////////////////////////////
TH2D *hRecoMCdEdXvsRRFixedDecCap = new TH2D("hRecoMCdEdXvsRRFixedDecCap", "dE/dX vs Residual Range for Capture/Decay",200, 0, 100, 200, 0, 50);

//////////////////////////////// "Low Momentum Track" PIDA (no cuts) ///////////////////////////////////////
TH1D *hRecoMCLowMomentumTrkPIDA = new TH1D("hRecoMCLowMomentumTrkPIDA", "Low Momentum PIDA", 30, 0, 30);

//////////////////////////////// "Low Momentum Track" PIDA (for stopping) ///////////////////////////////////////
TH1D *hRecoMCLowMomentumTrkPIDACapDec = new TH1D("hRecoMCLowMomentumTrkPIDACapDec", "Low Momentum PIDA", 30, 0, 30);


/////////////////////////////////// Reconstructed Length //////////////////////////////////////////
TH1D *hRecoLength = new TH1D("hRecoLength", "Reconstructed Length of the Primary Particle inside the TPC", 200, 0 , 100);


/////////////////////////////////// Initial Track X Position ////////////////////////////////////////////////////////
TH1D *hRecoMCTrkInitialX = new TH1D("hRecoMCTrkInitialX", "Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Initial Track X Position  Unweighted ////////////////////////////////////////////////////////
TH1D *hRecoMCTrkInitialXUnweighted = new TH1D("hRecoMCTrkInitialXUnweighted", "Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Initial Track Y Position ////////////////////////////////////////////////////////
TH1D *hRecoMCTrkInitialY = new TH1D("hRecoMCTrkInitialY", "Initial Y Position of the TPC Track", 100, -25, 25);

/////////////////////////////////// Initial Track Y Position Unweighted ////////////////////////////////////////////////////////
TH1D *hRecoMCTrkInitialYUnweighted = new TH1D("hRecoMCTrkInitialYUnweighted", "Initial Y Position of the TPC Track", 100, -25, 25);



TH2D *DeltaEvsPIDAAll = new TH2D("DeltaEvsPIDAAll", " #Delta E vs PIDA All", 30,0, 30, 100, 0, 100);
TH2D *DeltaEvsPIDADecayCap = new TH2D("DeltaEvsPIDADecayCap", " #Delta E vs PIDA All", 30,0, 30, 100, 0, 100);


// ###############################################################################
// ### Note: The binning (number and range) needs to match between these plots ###
// ###############################################################################

/////////////////////////////////// "Pion" Incident to the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hRecoMCIncidentKE = new TH1D("hRecoMCIncidentKE", "Incident Kinetic Energy (MeV)", 42, -100, 2000);

/////////////////////////////////// "Pion" Incident to the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hRecoMCIncidentKEunweighted = new TH1D("hRecoMCIncidentKEunweighted", "Incident Kinetic Energy (MeV) (unweighted)", 42, -100, 2000);

/////////////////////////////////// "Pion" Exiting the slab Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hRecoMCInteractingKE = new TH1D("hRecoMCInteractingKE", "Interacting Kinetic Energy (MeV)", 42, -100, 2000);

/////////////////////////////////// "Pion" Exiting the slab Kinetic Energy (MeV) (Unweighted) ////////////////////////////////
TH1D *hRecoMCInteractingKEunweighted = new TH1D("hRecoMCInteractingKEunweighted", "Interacting Kinetic Energy (MeV) (unweighted)", 42, -100, 2000);


/////////////////////////////////// Cross-Section ////////////////////////////////////////////////////////////////////////////
TH1F *fCrossSection = new TH1F("fCrossSection", "Cross-Section", 42, -100, 2000);



void PionMCDD_RunIPickyTrk::Loop()
{
if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// 					  Putting Flexible Cuts here
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// ### Putting in the particle mass that is being simulated here ###
// ###    which is used when calculating the energy loss before  ###
// ###                       entering the TPC                    ###

float particle_mass = 139.57; //<---Mass of Pion in MeV


// ##########################################################
// ### Preliminary TOF Cut (sets the bounds for TOF Reco) ###
// ##########################################################
double LowerTOFGoodReco = 0;
double UpperTOFGoodReco = 30;

// ###################################################
// ### Setting the Wire Chamber momentum range and ###
// ###     the TOF range for good particle ID      ###
// ###################################################
double LowerWCTrkMomentum = 100.0; //<--(MeV)
double HighWCTrkMomentum  = 1500.0;//<--(MeV)

double LowerTOF = 10.0; //<--(ns)
double HighTOF  = 25.0; //<--(ns)

// #####################################################
// ### Number of centimeters in Z we require a track ###
// ### to have a space point within (default = 2 cm) ###
// #####################################################
double FirstSpacePointZPos = 2.0;


// ########################################################
// ### Delta X Between Wire Chamber Track and TPC Track ###
// ########################################################
double DeltaXLowerBound = -4.0;
double DeltaXUpperBound = 6.0;

// ########################################################
// ### Delta Y Between Wire Chamber Track and TPC Track ###
// ########################################################
double DeltaYLowerBound = -5.0;
double DeltaYUpperBound = 5.0;


// ########################################################################
// ### Fiducial Boundry Cuts (used to determine if a track is stopping) ###
// ########################################################################
double XLowerFid = 0;
double XUpperFid = 47;

double YLowerFid = -20;
double YUpperFid = 20;

double ZLowerFid = 0;
double ZUpperFid = 90;


// ########################################################################
// ### Definition of the upstream part of the TPC where we restrict the ###
// ###             number of tracks which can be present                ###
// ########################################################################
int UpperPartOfTPC = 14.0;

// #####################################################
// ### Number of tracks allowed in the upstream part ###
// #####################################################
int nLowZTracksAllowed = 4;


// #################################################################################
// ### Making shower Cut (ShortTkLength) and the number of short tracks we allow ###
// #################################################################################
double ShortTkLength = 5.0;
int nShortTracksAllowed = 2;


// ############################
// ### Alpha Cut in degrees ###
// ############################
double alphaCut = 10;

// ### Setting the global event weight based on ###
// ###   open box WCTrack momentum spectrum     ###  
float EventWeight = 1.0;

// #################################################   
// ### True  = Use the momentum based weighting  ###
// ### False = Don't weight events               ###
// #################################################
bool UseEventWeight = false;


// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###  associated with ordering of the calo points   ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_Reordering = true; 


// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###   associated with large dE/dX fluctuations     ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_ExtremeFluctuation = true;     

// ########################################################
// ###   Choose whether or not to fix the calo problems ###
// ### associated with slightly large dE/dX fluctuations###
// ###                                                  ###
// ### True  = Use the fix                              ###
// ### False = Don't use the fix                        ###
// ########################################################
bool FixCaloIssue_LessExtremeFluctuation = false;  


// ##########################################################
// ### Choose whether to remove identified stopping pions ###
// ###                                                    ###
// ### True  = Remove stoppping tagged tracks             ###
// ### False = Don't remove stopping tagged tracks        ###
// ##########################################################
bool RemoveStopping = false;

// ###############################################
// ###  Only keeping through going reco Tracks ###
// ###  True = Only keep through going tracks  ###
// ###   False = Keep all types of tracks      ###
// ###############################################
bool SelectThroughGoing = false;
   


// ###################################################
// ### Setting a flag to print out bunch of checks ###
// ###################################################
bool VERBOSE = false; 



// ###############################################
// ### Creating a file to output my histograms ###
// ###############################################

TFile myfile("../histoROOTfiles_forPlots/PionMCDD_RunI_OutOfTheBox.root","RECREATE");

    

// ----------------------------------------------------------------
// Create the cross section from the incident and interaction plots
// ----------------------------------------------------------------

// ### The assumed energy loss between the cryostat and the TPC ###
float entryTPCEnergyLoss = 40.; //MeV

// ### The assumed mass of the incident particle (here we assume a pion) ###
float mass = 139.57;

float rho = 1396; //kg/m^3
//  float cm_per_m = 100;
float molar_mass = 39.95; //g/mol
float g_per_kg = 1000; 
float avogadro = 6.022e+23; //number/mol
float number_density = rho*g_per_kg/molar_mass*avogadro;
float slab_width = 0.0045;//in m

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsWCTrack = 0, nEvtsWCTrackMatch = 0, nEvtsTrackZPos = 0, nEvntsTPC = 0;
int nEvtsTOF = 0, nEvtsPID = 0, nLowZTrkEvents = 0;
int nNonShowerEvents = 0, nEvtsGoodMC = 0;

// ###############################
// ### Looping over all events ###
// ###############################
for (Long64_t jentry=0; jentry<nentries;jentry++) 
//for (Long64_t jentry=0; jentry<20000;jentry++)
   {
   
   // #########################
   // ### Loading the event ###
   // #########################
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   
   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 500 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;}
   
   //=======================================================================================================================
   //					      GEANT 4 Information
   //=======================================================================================================================
   // ##################################################
   // ### Defining some useful variables we will use ###
   // ##################################################
   int nG4Primary = 0;
   int nG4TrajPoints = 0;
   
   float g4Primary_X0[100] = {0.}, g4Primary_Y0[100] = {0.}, g4Primary_Z0[100] = {0.};
   float g4Primary_ProjX0[100] = {0.}, g4Primary_ProjY0[100] = {0.}, g4Primary_ProjZ0[100] = {0.};
   
   float g4Primary_Xf[100] = {0.}, g4Primary_Yf[100] = {0.}, g4Primary_Zf[100] = {0.};
   float g4Primary_Px[100] = {0.}, g4Primary_Py[100] = {0.}, g4Primary_Pz[100] = {0.};
   
   int g4Primary_TrkID[100] = {999}, g4PrimaryProcess[100] = {0};
   
   int nG4PriTrj = 0;
   float g4Primary_TrueTrjX[10][10000] = {0.}, g4Primary_TrueTrjY[10][10000] = {0.}, g4Primary_TrueTrjZ[10][10000] = {0.};
   float g4Primary_TrueTrjPx[10][10000] = {0.}, g4Primary_TrueTrjPy[10][10000] = {0.}, g4Primary_TrueTrjPz[10][10000] = {0.};
   
   
   float TrueLength = 0;
   float RecoLength = 0;
   // ##########################################
   // ### Loop over all the GEANT4 particles ###
   // ##########################################
   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      // #####################################################
      // ### If this is a primary particle then look at it ###
      // #####################################################
      if(process_primary[iG4] == 1)
         {

	 
	 // ### Recording information for use later ###
	 g4Primary_X0[nG4Primary] = StartPointx[iG4];
	 g4Primary_Y0[nG4Primary] = StartPointy[iG4];
	 g4Primary_Z0[nG4Primary] = StartPointz[iG4];
	 
	 g4Primary_Xf[nG4Primary] = EndPointx[iG4];
	 g4Primary_Yf[nG4Primary] = EndPointy[iG4];
	 g4Primary_Zf[nG4Primary] = EndPointz[iG4];
	 
	 g4Primary_Px[nG4Primary] = Px[iG4] * 1000; //<---Converting to MeV
	 g4Primary_Py[nG4Primary] = Py[iG4] * 1000; //<---Converting to MeV
	 g4Primary_Pz[nG4Primary] = Pz[iG4] * 1000; //<---Converting to MeV
	 
	
	 
	 // #############################################################
         // ### Calculating the momentum from the MC Primary Particle ###
         // #############################################################
         float momentumScale = sqrt( (g4Primary_Px[nG4Primary]*g4Primary_Px[nG4Primary]) + 
	                        (g4Primary_Py[nG4Primary]*g4Primary_Py[nG4Primary]) + 
				(g4Primary_Pz[nG4Primary]*g4Primary_Pz[nG4Primary]) );
				
	 float kineticEnergyScale = pow( (momentumScale*momentumScale) + (mass*mass) ,0.5) - mass;

TrueLength = sqrt( ((EndPointz[iG4]-StartPointz[iG4])*(EndPointz[iG4]-StartPointz[iG4])) + 
	                    ((EndPointy[iG4]-StartPointy[iG4])*(EndPointy[iG4]-StartPointy[iG4])) + 
	                    ((EndPointx[iG4]-StartPointx[iG4])*(EndPointx[iG4]-StartPointx[iG4])) );
			    
	 hMCTrueLength->Fill(TrueLength);
	 
	 // ------------------------------------------------------------------------------------
	 // ---------------        Extrapolate the X, Y, Z position of the primary         -----
	 // ---------------     if it started upstream of the front face of the TPC        -----
	 // ------------------------------------------------------------------------------------
	 
	 double b1 = StartPointz[iG4] - StartPointx[iG4]*Pz[iG4]/Px[iG4];
	 double b2 = StartPointz[iG4] - StartPointy[iG4]*Pz[iG4]/Py[iG4];
	 
	 g4Primary_ProjX0[nG4Primary] = -b1*Px[iG4]/Pz[iG4];
	 g4Primary_ProjY0[nG4Primary] = -b2*Py[iG4]/Pz[iG4];
	 g4Primary_ProjZ0[nG4Primary] = 0.0;
	 
	 // ### Setting the primary particles Track ID ###
	 g4Primary_TrkID[nG4Primary] = TrackId[iG4];
	 
	 
	 hMCPrimaryEndXvsZ->Fill(EndPointz[iG4], EndPointx[iG4]);
	 hMCPrimaryEndYvsZ->Fill(EndPointz[iG4], EndPointy[iG4]);
	 
	 // ##############################
	 // ### Filling the histograms ###
	 // ##############################
	 hMCPrimaryPx->Fill(g4Primary_Px[nG4Primary], EventWeight);
	 hMCPrimaryPy->Fill(g4Primary_Py[nG4Primary], EventWeight);
	 hMCPrimaryPz->Fill(g4Primary_Pz[nG4Primary], EventWeight);
	 
	 hMCPrimaryPxUnWeighted->Fill(g4Primary_Px[nG4Primary]);
	 hMCPrimaryPyUnWeighted->Fill(g4Primary_Py[nG4Primary]);
	 hMCPrimaryPzUnWeighted->Fill(g4Primary_Pz[nG4Primary]);

	 hMCPrimaryStartX->Fill(StartPointx[iG4]);
	 hMCPrimaryStartY->Fill(StartPointy[iG4]);
	 hMCPrimaryStartZ->Fill(StartPointz[iG4]);
	 
	 hMCPrimaryEndX->Fill(EndPointx[iG4]);
	 hMCPrimaryEndY->Fill(EndPointy[iG4]);
	 hMCPrimaryEndZ->Fill(EndPointz[iG4]);

	 hMCPrimaryProjectedStartX->Fill(g4Primary_ProjX0[nG4Primary]);
	 hMCPrimaryProjectedStartY->Fill(g4Primary_ProjY0[nG4Primary]);
	 hMCPrimaryProjectedStartZ->Fill(g4Primary_ProjZ0[nG4Primary]);
	 
	 nG4TrajPoints = 0;
	 
	 // ### Recording the primary particles trajectory points ###
	 for(int iG4Tr = 0; iG4Tr < NTrTrajPts[iG4]; iG4Tr++)
	    {
	    g4Primary_TrueTrjX[nG4Primary][nG4PriTrj] = MidPosX[iG4][iG4Tr];
	    g4Primary_TrueTrjY[nG4Primary][nG4PriTrj] = MidPosY[iG4][iG4Tr];
	    g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj] = MidPosZ[iG4][iG4Tr];
	    
	    //std::cout<<"g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj] = "<<g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj]<<std::endl;
	    
	    g4Primary_TrueTrjPx[nG4Primary][nG4PriTrj] = MidPx[iG4][iG4Tr]*1000;//<---Converting to MeV
	    g4Primary_TrueTrjPy[nG4Primary][nG4PriTrj] = MidPy[iG4][iG4Tr]*1000;//<---Converting to MeV
	    g4Primary_TrueTrjPz[nG4Primary][nG4PriTrj] = MidPz[iG4][iG4Tr]*1000;//<---Converting to MeV
	    
	    nG4PriTrj++;
	    }//<---end looping over this primary particles true trajectory points
	 
	 
	 // ### Bumping the counters ###
	 nG4Primary++;
	 
	 }//<---End Looking only at primaries

      }// <---End iG4 Loop
   
   // ################################################
   // ### Loop over all the GEANT4 particles again ###
   // ###  to get the process from the daughters   ###
   // ################################################
   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      
      // ### Looking for the Daughters of the primary ###
      if(Mother[iG4] == g4Primary_TrkID[nG4Primary - 1])
	 {
	 g4PrimaryProcess[nG4Primary - 1] = Process[iG4];
	 
	 
	 
	 
	 }//<---End matching daughters
      
      }//<---end iG4 loop
   hMCPrimaryProcess->Fill(g4PrimaryProcess[nG4Primary - 1]);

   //=======================================================================================================================
   //				Only looking at events where the primary particle enters the TPC
   //=======================================================================================================================
   
   bool GoodMCEventInTPC = true;
   
   // ##############################################
   // ### Looping over all the primary particles ###
   // ##############################################
   for(int npri = 0; npri < nG4Primary; npri++)
      {
      if(g4Primary_Zf[npri] < 0){GoodMCEventInTPC = false;}
      
      // ####################################################################
      // ### Calculating the energy loss for particles that enter the TPC ###
      // ####################################################################
      if(GoodMCEventInTPC)
         {
	 float DifferenceInEnergy = 0;
	 // ### Loop over the true trajectory points ###
	 for(int ntrj = 0; ntrj < nG4PriTrj; ntrj++)
	    {
\
	    // ### Only looking at point which are upstream of the TPC ###
	    if(g4Primary_TrueTrjZ[npri][ntrj] < 0)
	       {
	       
	       float Momentum_Point1 = sqrt((g4Primary_TrueTrjPx[npri][ntrj]*g4Primary_TrueTrjPx[npri][ntrj]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj]*g4Primary_TrueTrjPy[npri][ntrj]) +
				       (g4Primary_TrueTrjPz[npri][ntrj]*g4Primary_TrueTrjPz[npri][ntrj]));
				       
	       float Momentum_Point2 = sqrt((g4Primary_TrueTrjPx[npri][ntrj+1]*g4Primary_TrueTrjPx[npri][ntrj+1]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj+1]*g4Primary_TrueTrjPy[npri][ntrj+1]) +
				       (g4Primary_TrueTrjPz[npri][ntrj+1]*g4Primary_TrueTrjPz[npri][ntrj+1]));
				       
	       float Energy_Point1 = sqrt( (Momentum_Point1*Momentum_Point1) + (particle_mass*particle_mass)  );
	       
	       float Energy_Point2 = sqrt( (Momentum_Point2*Momentum_Point2) + (particle_mass*particle_mass)  );
	       
	       DifferenceInEnergy +=  Energy_Point1 - Energy_Point2;
	       
	       //std::cout<<"z = "<<g4Primary_TrueTrjZ[npri][ntrj]<<", DifferenceInEnergy = "<<DifferenceInEnergy<<std::endl;
	       
	       
	       }//<---End only look at points which are upstream of the TPC
	    
	    
	    }//<---End ntrj for loop
	 
	 
	 hMCELossUpstream->Fill(DifferenceInEnergy);
	 }//<---Only looking at events that actually make it into the TPC
      
      
      }//<---End npri loop
   
   if(!GoodMCEventInTPC){continue;}
   nEvtsGoodMC++;



   //=======================================================================================================================
   //						Low Z Spacepoint Track Cut
   //=======================================================================================================================
   
   // ### Boolian for events w/ track which ###
   // ###     starts at the front face      ###
   bool TrackSptsZCut = false;
   
   bool ThisTrackHasLowZPoint = false;
   
   // ### Recording the index of the track which ###
   // ###   starts at the front face of the TPC  ###
   bool PreLimTrackIndex[1000] = {false};
   
   // ###########################
   // ### Looping over tracks ###
   // ###########################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      float tempZpoint = 100;
      ThisTrackHasLowZPoint = false;
      // ########################################################
      // ### Looping over the trajectory points for the track ###
      // ########################################################
      for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	 // ################################################################################ 
         // ### Tracking the lowest Z point that is inside fiducial boundries of the TPC ###
	 // ################################################################################
	 if( trjPt_Z[nTPCtrk][ntrjpts] < tempZpoint  && trjPt_Z[nTPCtrk][ntrjpts] > ZLowerFid && 
	     trjPt_Z[nTPCtrk][ntrjpts] < ZUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && trjPt_X[nTPCtrk][ntrjpts] < XUpperFid &&
	     trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid )
	     
	    {tempZpoint = trjPt_Z[nTPCtrk][ntrjpts];}//<---End looking for the most upstream point
        
	 // ### Only passing events with a track that has ###
	 // ###  a spacepoint within the first N cm in Z  ### 
	 // ###    And requiring it to be inside the TPC  ###
	 if(tempZpoint < FirstSpacePointZPos)
	    {TrackSptsZCut = true;
	     ThisTrackHasLowZPoint = true;}
	 }//<---End looping over ntrjpts	
	 
      // ### Filling the most upstream spacepoint for this track ###
      hRecoMCUpstreamZPos->Fill(tempZpoint);
      
      // ### Recording that this track is a "good Track if ###
      // ###  it has a space point in the first N cm in Z  ###
      if(ThisTrackHasLowZPoint){ PreLimTrackIndex[nTPCtrk] = true;}
      	 
      }//<---End nTPCtrk loop
      
   // ###############################################
   // ### Skipping events that don't have a track ###
   // ###   in the front of the TPC (Z) Position  ###
   // ###############################################
   if(!TrackSptsZCut){continue;}
   // ### Counting Events w/ front face TPC Track ###
   nEvtsTrackZPos++;
   
   
   //=======================================================================================================================
   //					Cutting on the number of tracks in the upstream TPC
   //=======================================================================================================================
   
   int nLowZTracksInTPC = 0;
   // ################################################################
   // ### Initializing variables for study of low Z track location ###
   // ################################################################
   bool LowZTrackInTPC = false;
   
   
   // #################################################################
   // ### Only keeping events if there is less than N tracks in the ###
   // ###    first ## cm of the TPC (to help cut out EM Showers     ###
   // #################################################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
     {
     // ### Start by assuming this track is not in the ###
     // ###          low Z part of the TPC             ###
     LowZTrackInTPC = false;
           
     // ########################################################
     // ### Looping over the trajectory points for the track ###
     // ########################################################
     for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
        {
	 
	// ##################################################
	// ### Count this track if it has a spacepoint in ###
	// ###       the low Z region of the TPC          ###
	// ##################################################
	if(trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	   {  
	   if(trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && 
	      trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && trjPt_X[nTPCtrk][ntrjpts] < XUpperFid)
	       {LowZTrackInTPC = true;}
		
           }//<---End counting if 
	
        }//<---End ntrjpts loop
      
     // ##################################################################
     // ### If the track was in the "UpperPartOfTPC", bump the counter ###
     // ##################################################################
     if(LowZTrackInTPC)
        {
	
	nLowZTracksInTPC++;
	}//<---End counting track in the Upstream part

     }//<---End nTPCtrk
    
    
     
    // ### Skipping the event if there are too many ###
    // ###       low Z tracks in the event          ###
    if(nLowZTracksInTPC > nLowZTracksAllowed || nLowZTracksInTPC == 0){continue;}  
    
    // ### Counting the event if it passes ###
    nLowZTrkEvents++;



   // ===========================================================================================================================================
   // 						Vetoing Shower Like Events 
   // ===========================================================================================================================================   
   
   int nShortTrks = 0;
   // ###############################
   // ### Looping over TPC tracks ###
   // ###############################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      // ### If the track is shorter than our cut ###
      if(trklength[nTPCtrk] < ShortTkLength)
         {
	 nShortTrks++;
	 
	 }
	 
      }//<---End nTPCtrk
   
   // ### Skipping the event if there are too many short tracks ###
   if(nShortTrks > nShortTracksAllowed){continue;}
   
   // ### Bumping the counter ###
   nNonShowerEvents++;


   //=======================================================================================================================
   //						Uniquely matching one WC Track (For MC) to TPC Track
   //=======================================================================================================================
   
   // ### Keeping track of the number of matched tracks ###
   int nMatchedTracks = 0;
   
   // ### Variables for Delta WC and TPC tracks ###
   float DeltaX_WC_TPC_Track = 999;
   float DeltaY_WC_TPC_Track = 999;
   
   // ### Setting the index for the track which is ###
   // ### uniquely matched to a wire chamber track ###
   bool MatchTPC_WVTrack[500] = {false};
   
   
   // ################################################
   // ### Calculating the angles for the Geant4 MC ###
   // ################################################
   TVector3 z_hat_MC(0,0,1);
   TVector3 p_hat_0_MC;
   
   // ### Setting the vector for the MC using the ###
   // ###  extrapolated Momentum vector   ###
   p_hat_0_MC.SetX(g4Primary_Px[0]);
   p_hat_0_MC.SetY(g4Primary_Py[0]);
   p_hat_0_MC.SetZ(g4Primary_Pz[0]); 
   
   // ### Getting everything in the same convention ###
   float mcPhi = 0;
   float mcTheta = 0;
   
   // === Calculating Theta for MC ===
   mcTheta = acos(z_hat_MC.Dot(p_hat_0_MC)/p_hat_0_MC.Mag());
   
   // === Calculating Phi for MC ===
   //---------------------------------------------------------------------------------------------------------------------
   if( p_hat_0_MC.Y() > 0 && p_hat_0_MC.X() > 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X()); }
   else if( p_hat_0_MC.Y() > 0 && p_hat_0_MC.X() < 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+3.141592654; }
   else if( p_hat_0_MC.Y() < 0 && p_hat_0_MC.X() < 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+3.141592654; }
   else if( p_hat_0_MC.Y() < 0 && p_hat_0_MC.X() > 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+6.28318; }
   else if( p_hat_0_MC.Y() == 0 && p_hat_0_MC.X() == 0 ){ mcPhi = 0; }//defined by convention
   else if( p_hat_0_MC.Y() == 0 )
      {
      if( p_hat_0_MC.X() > 0 ){ mcPhi = 0; }

      else{ mcPhi = 3.141592654; }

      }
   else if( p_hat_0_MC.X() == 0 )
      {
      if( p_hat_0_MC.Y() > 0 ){ mcPhi = 3.141592654/2; }
      else{ mcPhi = 3.141592654*3/2; }

      }
   //---------------------------------------------------------------------------------------------------------------------
   
   // ### Grab the WCTrack Theta ###;
   hRecoMCWCTheta->Fill(mcTheta* (180.0/3.141592654), EventWeight);
   
   hRecoMCWCThetaUnWeighted->Fill(mcTheta* (180.0/3.141592654));
      
   // ### Grabbing the WCTrack Phi ###
   hRecoMChWCPhi->Fill(mcPhi* (180.0/3.141592654), EventWeight);
   
   hRecoMChWCPhiUnWeighted->Fill(mcPhi* (180.0/3.141592654));
      
   // ####################################
   // ### Loop over all the TPC Tracks ###
   // ####################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ############################################
      // ###   Only looking at tracks which have  ###
      // ### a point in the first N cm of the TPC ###
      // ############################################
      if(!PreLimTrackIndex[nTPCtrk]){continue;}
	 
      // === Set a dummy variables for the most upstream point ===
      float FirstSpacePointZ = 999;
      float FirstSpacePointY = 999;
      float FirstSpacePointX = 999;
	 
      float TempTrj_X = 999;
      float TempTrj_Y = 999;
      float TempTrj_Z = 999;
      // ###############################################################
      // ### Looping over the trajectory points for the prelim-track ###
      // ###############################################################
      for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	    
	 // ### Recording this tracks upstream most X, Y, Z location, ###
	 // ###       which is inside the fiducial boundary           ###
	 if(trjPt_Z[nTPCtrk][ntrjpts] < FirstSpacePointZ && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && 
	    trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && 
	    trjPt_X[nTPCtrk][ntrjpts] < XUpperFid && trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	    {
	       
	    // ######################################
	    // ### Record the most upstream point ###
	    // ######################################
	    FirstSpacePointZ = trjPt_Z[nTPCtrk][ntrjpts];
	    FirstSpacePointY = trjPt_Y[nTPCtrk][ntrjpts];
	    FirstSpacePointX = trjPt_X[nTPCtrk][ntrjpts];
	       
	    TempTrj_X = pHat0_X[nTPCtrk][ntrjpts];
	    TempTrj_Y = pHat0_Y[nTPCtrk][ntrjpts];
	    TempTrj_Z = pHat0_Z[nTPCtrk][ntrjpts];
	       
	       
	    }//<---End finding the most upstream point
         }//<---End ntrjpts loop
	 
      // ###################################################
      // ### Vectors for angles between TPC and WC Track ###
      // ###################################################
      TVector3 z_hat(0,0,1);
      TVector3 p_hat_0;
      
      // ### Setting the vector for the matched track ###
      // ###      most upstream trajectory point      ###
      p_hat_0.SetX(TempTrj_X);
      p_hat_0.SetY(TempTrj_Y);
      p_hat_0.SetZ(TempTrj_Z); //<--Note: since at this point we only have one unique match
       		               //         only having one entry should be fine
	 			  
      // ===============================================================================================================
      // 				Calculating Theta and Phi for this TPC Track
      // ===============================================================================================================
      // ### Calculating the Theta for the TPC Track ###
      float tpcTheta = acos(z_hat.Dot(p_hat_0)/p_hat_0.Mag());  
      hRecoMCTPCTheta->Fill(tpcTheta* (180.0/3.141592654), EventWeight);
      
      hRecoMCTPCThetaUnWeighted->Fill(tpcTheta* (180.0/3.141592654));
   
      // ### Using same convention as WCTrack to calculate phi ###
      float phi = 0;
      //Calculating phi (degeneracy elimination for the atan function)
      //----------------------------------------------------------------------------------------------
      if( p_hat_0.Y() > 0 && p_hat_0.X() > 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X()); }
      else if( p_hat_0.Y() > 0 && p_hat_0.X() < 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+3.141592654; }
      else if( p_hat_0.Y() < 0 && p_hat_0.X() < 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+3.141592654; }
      else if( p_hat_0.Y() < 0 && p_hat_0.X() > 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+6.28318; }
      else if( p_hat_0.Y() == 0 && p_hat_0.X() == 0 ){ phi = 0; }//defined by convention
      else if( p_hat_0.Y() == 0 )
         {
         if( p_hat_0.X() > 0 ){ phi = 0; }

         else{ phi = 3.141592654; }

         }
      else if( p_hat_0.X() == 0 )
         {
         if( p_hat_0.Y() > 0 ){ phi = 3.141592654/2; }
         else{ phi = 3.141592654*3/2; }

         }
      //----------------------------------------------------------------------------------------------
   
      // ### Using TPC Phi ###
      float tpcPhi = phi; 
      hRecoMCTPCPhi->Fill(tpcPhi* (180.0/3.141592654), EventWeight);
      
      hRecoMCTPCPhiUnWeighted->Fill(tpcPhi* (180.0/3.141592654));
      
      // ===============================================================================================================            
      // ===============================================================================================================
	 
      // #######################################################
      // ### Defining unit vectors for the WC and TPC tracks ###
      // #######################################################
      TVector3 theUnitVector_WCTrack;
      TVector3 theUnitVector_TPCTrack;
	 
      // === WCTrack Unit Vector ===
      theUnitVector_WCTrack.SetX(sin(mcTheta)*cos(mcPhi));
      theUnitVector_WCTrack.SetY(sin(mcTheta)*sin(mcPhi));
      theUnitVector_WCTrack.SetZ(cos(mcTheta));
    
      // === TPC Track Unit Vector ===
      theUnitVector_TPCTrack.SetX(sin(tpcTheta)*cos(tpcPhi));
      theUnitVector_TPCTrack.SetY(sin(tpcTheta)*sin(tpcPhi));
      theUnitVector_TPCTrack.SetZ(cos(tpcTheta));
	 
      // ##########################################################################
      // ### Calculating the Delta X and Delta Y between WC track and TPC track ###
      // ##########################################################################
      DeltaX_WC_TPC_Track = FirstSpacePointX - (g4Primary_ProjX0[0]);
      DeltaY_WC_TPC_Track = FirstSpacePointY - (g4Primary_ProjY0[0]);
      
      hRecoMCTrkInitialX->Fill(FirstSpacePointX, EventWeight);
      hRecoMCTrkInitialXUnweighted->Fill(FirstSpacePointX);
      
      hRecoMCTrkInitialY->Fill(FirstSpacePointY, EventWeight);
      hRecoMCTrkInitialYUnweighted->Fill(FirstSpacePointY);
	 
      // ###########################################################
      // ### Calculating the angle between WCTrack and TPC Track ###
      // ###########################################################
      float alpha = ( acos(theUnitVector_WCTrack.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
   
         
      // ### Filling the Delta X and Delta Y  and alpha between WC tracks and TPC Tracks ###
      hRecoMCDeltaWCTrkY->Fill(DeltaY_WC_TPC_Track);
      hRecoMCDeltaWCTrkX->Fill(DeltaX_WC_TPC_Track);
      hRecoMCAlpha->Fill(alpha);
	 
	 // ###########################################################################
	 // ### If this TPC track matches this Wire Chamber Track, bump the counter ###
	 // ###########################################################################
      if( DeltaX_WC_TPC_Track >  DeltaXLowerBound && DeltaX_WC_TPC_Track < DeltaXUpperBound && 
	  DeltaY_WC_TPC_Track > DeltaYLowerBound && DeltaY_WC_TPC_Track < DeltaYUpperBound &&
	  alpha < alphaCut )
         {
	 // ### Counting the matched tracks ###
	 nMatchedTracks++;
	 
	 // ### Setting the index of this track to true ###
	 MatchTPC_WVTrack[nTPCtrk] = true;

         }  
	 
      }//<---end nTPCtrk loop
      
      
   
   // ### Filling the number of matched WC and TPC Tracks ###
   hRecoMCNMatchTPCWCTrk->Fill(nMatchedTracks);
   
   // #####################################################
   // ### Skipping this event if no WC track is matched ###
   // ###    OR if more than one WC track is matched    ###
   // #####################################################
   if( (nMatchedTracks < 1 || nMatchedTracks > 1)){continue;}
   
   // ### Counting the number of events with ONE WC track matched ###
   nEvtsWCTrackMatch++;




   // =========================================================================================================================================
   //						Recording information about the Wire Chamber Track
   // =========================================================================================================================================
   
   // ---   First grab the tracks "initial" momentum which we take from ---
   // --- the momentum of the primary MC track which has been matched ---
   // ---  and correct for the "typical" energy loss for a track in the ---
   // ---   argon between the cryostat and the front face of the TPC    ---
   
   
   
   // #############################################################
   // ### Calculating the momentum from the MC Primary Particle ###
   // #############################################################
   float momentum = sqrt( (g4Primary_Px[0]*g4Primary_Px[0]) + (g4Primary_Py[0]*g4Primary_Py[0]) + (g4Primary_Pz[0]*g4Primary_Pz[0]) );
         
   
   // ###   Calculating the initial Kinetic Energy    ###
   // ### KE = Energy - mass = (p^2 + m^2)^1/2 - mass ###
   float kineticEnergy = pow( (momentum*momentum) + (mass*mass) ,0.5) - mass;
   
   // ### The kinetic energy is that which we calculated ###
   // ###       minus the calculated energy loss         ###
   kineticEnergy -= entryTPCEnergyLoss;
  
   double InitialKinEnAtTPC = 0.;
   InitialKinEnAtTPC = kineticEnergy;
   
   // ###############################################
   // ### Filling the initial kinetic energy plot ###
   // ###############################################
   hRecoMCInitialKEMomentum->Fill(kineticEnergy, EventWeight);
   hRecoMCInitialKEMomentumUnWeighted->Fill(kineticEnergy);



   // =========================================================================================================================================
   //							 Calorimetry Points
   // =========================================================================================================================================
   
   //Vectors with calo info of the matched tpc track
   double MCRecodEdX[1000]={0.};
   double MCRecodQdX[1000]={0.};
   double MCRecoResRange[1000]={0.};
   double MCRecoPitch[1000]={0.};
   int nMCRecoSpts = 0;
   
   double MCRecoSptsX[1000];
   double MCRecoSptsY[1000];
   double MCRecoSptsZ[1000];
   
   // ################################################
   // ### Creating a flag for through going tracks ###
   // ################################################
   bool ThroughGoingTrack[1000]={false};
   
   
   // ###########################################
   // ### Creating a flag for stopping tracks ###
   // ###########################################
   bool StoppingParticle[1000] = {false};
   
   // ############################
   // ### Loop over all tracks ###
   // ############################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ### Recording the track length ###
      hRecoLength->Fill(trklength[nTPCtrk]);
      
      // ###################################################
      // ### Check to see if this track is through going ###
      // ### by checking to see if it ends on a boundary ###
      // ###################################################
      if(trkendx[nTPCtrk] < 1   || trkendx[nTPCtrk] > 42.0 || trkendy[nTPCtrk] > 19 ||
         trkendy[nTPCtrk] < -19 || trkendz[nTPCtrk] > 89.0)
         {ThroughGoingTrack[nTPCtrk] = true;}
      
      // ####################################################### 
      // ### Adding an option to select through-going tracks ###
      // #######################################################
      if( (trkvtxz[nTPCtrk] > 5.0 || trkendz[nTPCtrk] < 88.0) && SelectThroughGoing){continue;}
      
      // ###############################################################
      // ### Looping over the calorimetry spacepoints for this track ###
      // ###############################################################
      for(int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 
	 // ###                 Note: Format for this variable is:             ###
	 // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
         MCRecodEdX[nMCRecoSpts]     = trkdedx[nTPCtrk][1][nspts];
	 MCRecodQdX[nMCRecoSpts]     = trkdqdx[nTPCtrk][1][nspts];
	 
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(MCRecodEdX[nMCRecoSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {MCRecodEdX[nMCRecoSpts] = ( (trkdedx[nTPCtrk][1][nspts - 1] + trkdedx[nTPCtrk][1][nspts + 1]) / 2);}
	 
	 // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	 if(MCRecodEdX[nMCRecoSpts] < 0)
	    {continue;}

	 
	 MCRecoResRange[nMCRecoSpts] = trkrr[nTPCtrk][1][nspts];
         MCRecoPitch[nMCRecoSpts] = trkpitchhit[nTPCtrk][1][nspts];
	 
	 MCRecoSptsX[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][0];
	 MCRecoSptsY[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][1];
	 MCRecoSptsZ[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][2];
	 
	 // ### Histogramming the dE/dX ###
	 hRecoMCdEdX->Fill(MCRecodEdX[nMCRecoSpts]);
	 
	 // ### Histogramming the dQ/dX ###
	 hRecoMCdQdX->Fill(MCRecodQdX[nMCRecoSpts]);
	 
	 // ### Histogramming the residual range ###
	 hRecoMCPionRR->Fill(MCRecoResRange[nMCRecoSpts]);
	 // ### Histogramming the Pitch ###
	 hRecoMCPionTrkPitch->Fill(MCRecoPitch[nMCRecoSpts]);
	 
	 // ### Filling 2d dE/dX vs RR ###
	 hRecoMCdEdXvsRR->Fill(MCRecoResRange[nMCRecoSpts], MCRecodEdX[nMCRecoSpts]);
	 
	 // =====================================================================
	 // === Breaking the TPC into 4 quadrants to analyze the dE/dX and dQ/dX
	 // ===               Q1: 0 cm    < z    < 22.5 cm
	 // ===               Q2: 22.5 cm < z    < 45 cm
	 // ===               Q3: 45 cm   < z    < 67.5 cm
	 // ===               Q4: 67.5 cm < z    < 90 cm
	 // =====================================================================
	 if(MCRecoSptsZ[nMCRecoSpts] > 0    && MCRecoSptsZ[nMCRecoSpts] < 22.5)
	    {
	    hMCRecodEdXQ1->Fill(MCRecodEdX[nMCRecoSpts]);
	    hMCRecodQdXQ1->Fill(MCRecodQdX[nMCRecoSpts]);
	    }
	 if(MCRecoSptsZ[nMCRecoSpts] > 22.5 && MCRecoSptsZ[nMCRecoSpts] < 45)
	    {
	    hMCRecodEdXQ2->Fill(MCRecodEdX[nMCRecoSpts]);
	    hMCRecodQdXQ2->Fill(MCRecodQdX[nMCRecoSpts]);
	    }
	 if(MCRecoSptsZ[nMCRecoSpts] > 45   && MCRecoSptsZ[nMCRecoSpts] < 67.5)
	    {
	    hMCRecodEdXQ3->Fill(MCRecodEdX[nMCRecoSpts]);
	    hMCRecodQdXQ3->Fill(MCRecodQdX[nMCRecoSpts]);
	    }
	 if(MCRecoSptsZ[nMCRecoSpts] > 67.5 && MCRecoSptsZ[nMCRecoSpts] < 90)
	    {
	    hMCRecodEdXQ4->Fill(MCRecodEdX[nMCRecoSpts]);
	    hMCRecodQdXQ4->Fill(MCRecodQdX[nMCRecoSpts]);
	    }
	 
	 
	 
	 nMCRecoSpts++;
	 
	 }//<---End spacepoints loop
      
      // #####################################################
      // ### Check to see if this track is consistent with ###
      // ###          being from a stopping track 	   ###
      // #####################################################
      if(InitialKinEnAtTPC < 300)
         {
	 // ### Filling the  tracks PIDA value ###
	 hRecoMCLowMomentumTrkPIDA->Fill(trkpida[nTPCtrk][1]);
	 
	 // ##########################################################
	 // ### Only fill if the MC truth is Pion Capture or Decay ###
	 // ##########################################################
	 if(g4PrimaryProcess[0] == 4 || g4PrimaryProcess[0] == 12 || g4PrimaryProcess[0] == 6)
	 	{hRecoMCLowMomentumTrkPIDACapDec->Fill(trkpida[nTPCtrk][1]);}
	 
	 
	 
	 
	//### Setting the last energy points variable ###
	double lastDeltaEAll = 0;
	    
	// ### Loop over the last five points of the track ###
	if(nMCRecoSpts >= 5)
	   {
           for(int nlastspts = nMCRecoSpts - 1; nlastspts > nMCRecoSpts - 5; nlastspts--)
	      {
	      if(MCRecodEdX[nlastspts] == -99999){continue;}
	      
	      //std::cout<<"nlastspts = "<<nlastspts<<std::endl;
	      // ### Add up the energy in the last 5 points ###
	      lastDeltaEAll += (MCRecoPitch[nlastspts] * MCRecodEdX[nlastspts]);
	      
	      //std::cout<<"lastDeltaEAll = "<<lastDeltaEAll<<std::endl;
	      }//<---End nlastspts loop

	 }//<---End only looking if the track has 5 points 
	 
	 if(g4PrimaryProcess[0] != 4 && g4PrimaryProcess[0] != 12 && g4PrimaryProcess[0] != 6)
	    {DeltaEvsPIDAAll->Fill(trkpida[nTPCtrk][1], lastDeltaEAll);}
	 
	 if(g4PrimaryProcess[0] == 4 || g4PrimaryProcess[0] == 12 || g4PrimaryProcess[0] == 6)
	    {DeltaEvsPIDADecayCap->Fill(trkpida[nTPCtrk][1], lastDeltaEAll);}
	 
	 
	 // ##########################################
	 // ###  If the PIDA is between 9 and 13   ###
	 // ##########################################
	 if(trkpida[nTPCtrk][1] >= 8 && trkpida[nTPCtrk][1] <= 13)
	    {
	    
	    //### Setting the last energy points variable ###
	    double lastDeltaE = 0;
	    
	    // ### Loop over the last five points of the track ###
	    if(nMCRecoSpts >= 5)
	       {
	       for(int nlastspts = nMCRecoSpts - 1; nlastspts > nMCRecoSpts - 5; nlastspts--)
	          {
		  
		  
		  // ### Add up the energy in the last 5 points ###
		  lastDeltaE += (MCRecoPitch[nlastspts] * MCRecodEdX[nlastspts]);

	          }//<---End nlastspts loop

	       }//<---End only looking if the track has 5 points
	    
	    // ### IF the Delta E is between 7 and 25, tag as a stopping track ###
	    if(lastDeltaE >= 10 && lastDeltaE <= 30)
	       // ### Only setting the flag if we are tagging events ###
	       {
	       if(RemoveStopping)
	          {StoppingParticle[nTPCtrk] = true;}
	       
	       }
	    
	    
	    }//<---End looking at 9 < PIDA < 13
	 }//<---End looking at low momentum tracks
      
      
      }//<---End nTPCtrk loop 
   
// ---------------------------------------------------------------------------------------------------------------------------------------
   bool HasToBeReordered = false;
   int ReorderedCount = 0;
   int bb = 0;
   // ############################################################
   // ### Fix the reordering problem of the calorimetry points ###
   // ############################################################
   if(FixCaloIssue_Reordering)
      {
      // ################################
      // ### Loop over the caloPoints ###
      // ################################
      for(int caloPoints = 0; caloPoints < nMCRecoSpts-1; caloPoints++)
         {
	 // ###           If this points Residual Range is smaller than the       ###
	 // ### next point, then things may be out of wack and we want to reorder ###
	 if(MCRecoResRange[caloPoints] < MCRecoResRange[caloPoints+1])
	    {
	    // #######################################################
	    // ### Set a flag that this might have to be reordered ###
	    // #######################################################
	    HasToBeReordered = true;
	    
	    // ### counting the points that are out of order ###
	    ReorderedCount++;
	    }

         }//<---End caloPoints
      }//<---End fixing the ordering problem
   
   // #####################################################
   // ### The things need to be reorderd for this track ###
   // #####################################################
   if(HasToBeReordered && ( (nMCRecoSpts - ReorderedCount) == 1))
      {
      
      // ### Temp Variables for fixing ###
      double tempRR[1000] = {0.};
      double tempdEdX[1000] = {0.};
      double tempPitch[1000] = {0.};
      
      // ### Start at the last point ###
      for(int aa = nMCRecoSpts; aa > -1; aa--)
         {
	 // ##########################################
	 // ### Skip the point if it is at the end ###
	 // ##########################################
	 if(MCRecoResRange[aa] == 0){continue;}
	 
	 // ### Reorder the points ###
	 tempRR[bb] = MCRecoResRange[aa];
	 tempdEdX[bb]     = MCRecodEdX[aa];
	 tempPitch[bb] = MCRecoPitch[aa];
	 
	 bb++;
	 }//<---end aa 
      
      // ###########################
      // ### Now swap the points ###
      // ###########################
      for(int reorder = 0; reorder < nMCRecoSpts; reorder++)
         {
	 MCRecoResRange[reorder] = tempRR[reorder];
	 MCRecodEdX[reorder]     = tempdEdX[reorder];
	 MCRecoPitch[reorder] = tempPitch[reorder];
	 
	 
	 }//<---End reorder loop
      
      
      }//<---End Has to be reordered

   // ##################################
   // ### Printing things as a check ###
   // ##################################
   if(HasToBeReordered && VERBOSE)
      {
      for(int caloPoints = 0; caloPoints < nMCRecoSpts; caloPoints++)
         {
	 std::cout<<"Run = "<<run<<", Event = "<<event<<" point = "<<caloPoints<<", RR = "<<MCRecoResRange[caloPoints]<<", dE/dX = "<<MCRecodEdX[caloPoints]<<std::endl;
      
      
         }//<---End caloPoints
      std::cout<<std::endl;	 
      }//<---Putting in a print to make sure things are reordered correctly   
   
// ---------------------------------------------------------------------------------------------------------------------------------------
   
   
   
   // ####################################################################
   // ### Fix the calorimetry issues associated with huge fluctuations ###
   // ###            by extrapolating through the points               ###
   // ####################################################################
   if(FixCaloIssue_ExtremeFluctuation)
      {
      // ################################
      // ### Loop over the caloPoints ###
      // ################################
      for(int caloPoints = 0; caloPoints < nMCRecoSpts; caloPoints++)
         {
	 
	 // ###################################################
	 // ### If the dE/dX is large and at the end of the ###
	 // ###  track as expected with a proton attached   ###
	 // ###################################################
	 if(MCRecodEdX[caloPoints] > 40. && caloPoints == (nMCRecoSpts-1) )
	    {
	    // ##########################################################
	    // ### Set this point equal to the previous point's dE/dX ###
	    // ##########################################################
	    MCRecodEdX[caloPoints] = MCRecodEdX[caloPoints - 1];
	    }//<---End large and at the end of the track
	 
	 // ############################################################
	 // ### Else, if it is a large dE/dX but not the first point ###
	 // ############################################################
	 else if(MCRecodEdX[caloPoints] > 40. && caloPoints < (nMCRecoSpts-1) && caloPoints > 0.)
	    {
	    
	    if(VERBOSE){std::cout<<"Large Fluctuation"<<std::endl;}
	    // #################################################################
	    // ### Then just average between the previous and the next point ###
	    // #################################################################
	    MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 1] + MCRecodEdX[caloPoints + 1]) / 2.);
	    
	    }//<--End large and not at the end of the track
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for big fluctuations

// ---------------------------------------------------------------------------------------------------------------------------------------
   
   // ##############################################################################
   // ### Fix the calorimetry issues associated with slightly large fluctuations ###
   // ###                 by extrapolating through the points                    ###
   // ##############################################################################
   if(FixCaloIssue_LessExtremeFluctuation)
      {
      for(int caloPoints = 0; caloPoints < nMCRecoSpts; caloPoints++)
         {
	 // ### If dE/dX > 15 and more than 10cm from the end of the track and isn't the first or last point ###
	 if(MCRecodEdX[caloPoints] > 15. && MCRecoResRange[caloPoints] > 10. && caloPoints > 0.&& caloPoints < (nMCRecoSpts-1) )
	    {
	    if(VERBOSE){std::cout<<"Small Fluctuation"<<std::endl;}
	    // ### Check to see if the previous point is greater than 15 ###
	    if(MCRecodEdX[caloPoints-1] > 15.)
	       {
	       // ### Check to see if the next point is greater than 15 ###
	       if(MCRecodEdX[caloPoints+1] > 15. )
	          {
		  // ### Go 2 points before and after ###
		  MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 2] + MCRecodEdX[caloPoints + 2]) / 2.);
		  }
	       else
	          {
		  // ### Go 2 points before and one point after ###
		  MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 2] + MCRecodEdX[caloPoints + 1]) / 2.);
		  }
	        }
	    else if(MCRecodEdX[caloPoints-1] <= 15.)
	       {
	       if(MCRecodEdX[caloPoints+1] > 15. )
	          {
		  MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 1] + MCRecodEdX[caloPoints+2]) / 2.);
		  }
	       else
	          {
		  MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 2] + MCRecodEdX[caloPoints + 1]) / 2.);
		  }
	       }
	   else MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 1] + MCRecodEdX[caloPoints+1]) / 2.);
	   }
	
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for less big fluctuations   
   
   // ##########################################
   // ### Filling the fixed dE/dX vs RR plot ###
   // ##########################################
   for(int caloPoints = 0; caloPoints < nMCRecoSpts; caloPoints++)
      {
      
      hRecoMCdEdXvsRRFix->Fill(MCRecoResRange[caloPoints], MCRecodEdX[caloPoints]);
      
      hRecoMCdEdXFixed->Fill(MCRecodEdX[caloPoints]);
      
      if(g4PrimaryProcess[0] == 4 || g4PrimaryProcess[0] == 12 && InitialKinEnAtTPC < 300 )
         { hRecoMCdEdXvsRRFixedDecCap->Fill(MCRecoResRange[caloPoints], MCRecodEdX[caloPoints]);}
      
      }//<---End Fix
   
   
   // =========================================================================================================================================
   //						Filling Incident and Interacting Histograms
   // =========================================================================================================================================
   
   // #########################################
   // ### Loop over the tracks in the event ###
   // #########################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ############################################
      // ### Loop over all the calorimetry points ###
      // ############################################
      for(int npoints = 0; npoints < nMCRecoSpts; npoints++)
         {
	 // ### Filling the incidient histogram weighted by beam profile ###
         hRecoMCIncidentKE->Fill(kineticEnergy, EventWeight);
	 
	 hRecoMCIncidentKEunweighted->Fill(kineticEnergy);
      
         // ###            Filling the interaction histogram for the last spt          ###
	 // ### As long as it isn't a through going track and isn't tagged as stopping ###
         if(npoints == nMCRecoSpts -1 && !ThroughGoingTrack[nTPCtrk] && !StoppingParticle[nTPCtrk] )
            {
	    
	    // ### Weighting the Interaction by the beam profile ###
	    hRecoMCInteractingKE->Fill(kineticEnergy, EventWeight);
	    
	    // ### Saving the unweighted interaction ###
	    hRecoMCInteractingKEunweighted->Fill(kineticEnergy);
	    }
         
	 // ################################################
	 // ### Subtracting the energy loss in this step ###
	 // ################################################
         float energyLossInStep = MCRecodEdX[npoints] * MCRecoPitch[npoints];
         
	 // #######################################################
	 // ### Removing that kinetic energy from the histogram ###
	 // #######################################################
         kineticEnergy -= energyLossInStep;
      
      
      
      
         }//<---End npoints loop
      }//<---End nTPCtrk loop





   }//<---End jentry loop


// ===============================================================================================================
//					MAKING THE CROSS-SECTION PLOT
// ===============================================================================================================

// ###################################################################
// #### Looping over the exiting bins to extract the cross-section ###
// ###################################################################
for( int iBin = 1; iBin <= hRecoMCInteractingKE->GetNbinsX(); ++iBin )
   {
   // ### If an incident bin is equal to zero then skip that bin ###
   if( hRecoMCIncidentKE->GetBinContent(iBin) == 0 )continue; //Temporary fix to ensure that no Infinities are propagated to pad
   
   // ### Cross-section = (Exit Bins / Incident Bins) * (1/Density) * (1/slab width) ###
   float TempCrossSection = (hRecoMCInteractingKE->GetBinContent(iBin)/hRecoMCIncidentKE->GetBinContent(iBin)) * (1/number_density) * (1/slab_width);
   
   // ### Covert this into Barns ###
   float crossSection = TempCrossSection * (1/1e-28);
   
   // ### Putting the value on the plot
   fCrossSection->SetBinContent(iBin,crossSection);
   
   // ###########################################################
   // ### Calculating the error on the numerator of the ratio ###
   // ###########################################################
   float numError = pow(hRecoMCInteractingKE->GetBinContent(iBin),0.5);
   float num = hRecoMCInteractingKE->GetBinContent(iBin);

   // ### Putting in a protection against dividing by zero ###   
   if(num == 0){num = 1;}
   float term1 = numError/num;
   
   // #################################################
   // ### Calculating the error on the denomentator ###
   // #################################################
   float denomError = pow(hRecoMCIncidentKE->GetBinContent(iBin),0.5);
   float denom = hRecoMCIncidentKE->GetBinContent(iBin);
   if(denom == 0){denom = 1;}
   
   // ### Putting in a protection against dividing by zero ###
   float term2 = denomError/denom;
   
   float totalError = (TempCrossSection) * (pow( ( (term1*term1) + (term2*term2) ),0.5)) * (1/number_density) * (1/slab_width) * (1/1e-28) *(1e26);
   //std::cout<<"totalError = "<<totalError<<std::endl;
   fCrossSection->SetBinError(iBin,totalError);
   
   }//<---End iBin Loop




// ========================================================================================================
// ===					EVENT REDUCTION TABLE						===
// ========================================================================================================
std::cout<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<"### Number of Events in AnaModule                                = "<<nTotalEvents<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 0   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ WC Track                                 = "<<nEvtsWCTrack<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ TOF > "<<LowerTOFGoodReco<<" ns and < "<<UpperTOFGoodReco<<" ns                   = "<<nEvtsTOF<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Good TPC info (nHits > 0)		     = "<<nEvntsTPC<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 1   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ PID consistent with Pi/Mu                = "<<nEvtsPID<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 2   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ Primary MC which enters the TPC                   = "<<nEvtsGoodMC<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Trk Z < "<<FirstSpacePointZPos<<"                                = "<<nEvtsTrackZPos<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ < "<<nLowZTracksAllowed<<" tracks in the first "<<UpperPartOfTPC<<" cm of the TPC = "<<nLowZTrkEvents<<" ###"<<std::endl;
std::cout<<"### Number of Events that are not Shower Like                        = "<<nNonShowerEvents<<std::endl;
std::cout<<"### Number of Events w/ ONE WC Track Matched                     = "<<nEvtsWCTrackMatch<<" ###"<<std::endl;
std::cout<<"###              ( "<<DeltaXLowerBound<<" < Delta X < "<<DeltaXUpperBound<<" , "<<DeltaYLowerBound<<" < Delta Y < "<<DeltaYUpperBound<<" )              ###"<<std::endl;
std::cout<<"###                 and alpha less the "<<alphaCut<<" degrees                      ###"<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<std::endl;   
   
// ===========================================================================================
// ============================  Writing out histograms to ROOT File =========================
// ===========================================================================================


// ### MC Info ###
hMCPrimaryStartX->Write();
hMCPrimaryStartY->Write();
hMCPrimaryStartZ->Write();
hMCPrimaryProjectedStartX->Write();
hMCPrimaryProjectedStartY->Write();
hMCPrimaryProjectedStartZ->Write();
hMCPrimaryEndX->Write();
hMCPrimaryEndY->Write();
hMCPrimaryEndZ->Write();
hMCPrimaryEndXvsZ->Write();
hMCPrimaryEndYvsZ->Write();
hMCPrimaryProcess->Write();
hMCPrimaryPx->Write();
hMCPrimaryPy->Write();
hMCPrimaryPz->Write();
hMCTrueLength->Write();

hMCPrimaryPxUnWeighted->Write();
hMCPrimaryPyUnWeighted->Write();
hMCPrimaryPzUnWeighted->Write();

hRecoMCUpstreamZPos->Write();
hRecoMCTPCTheta->Write();
hRecoMCTPCPhi->Write();
hRecoMCTPCPhiUnWeighted->Write();
hRecoMCTPCThetaUnWeighted->Write();
hRecoMCWCTheta->Write();
hRecoMCWCThetaUnWeighted->Write();
hRecoMChWCPhi->Write();
hRecoMChWCPhiUnWeighted->Write();
hRecoMCDeltaWCTrkX->Write();
hRecoMCDeltaWCTrkY->Write();
hRecoMCAlpha->Write();
hRecoMCNMatchTPCWCTrk->Write();
hRecoMCWCTRKMomentum->Write();
hRecoMCInitialKEMomentum->Write();
hRecoMCInitialKEMomentumUnWeighted->Write();
hRecoMCdEdX->Write();
hRecoMCdQdX->Write();

hRecoMCPionRR->Write();
hRecoMCPionTrkPitch->Write();
hRecoMCdEdXvsRR->Write();
hRecoMCLowMomentumTrkPIDA->Write();
hRecoMCIncidentKE->Write();
hRecoMCIncidentKEunweighted->Write();
hRecoMCInteractingKE->Write();
hRecoMCInteractingKEunweighted->Write();
fCrossSection->Write();   
hRecoLength->Write();
hRecoMCTrkInitialX->Write();
hRecoMCTrkInitialXUnweighted->Write();
hRecoMCTrkInitialY->Write();
hRecoMCTrkInitialYUnweighted->Write();
hRecoMCdEdXvsRRFix->Write();
hRecoMCdEdXFixed->Write();
hRecoMCLowMomentumTrkPIDACapDec->Write();
hRecoMCdEdXvsRRFixedDecCap->Write();

DeltaEvsPIDAAll->Write();
DeltaEvsPIDADecayCap->Write();


hMCRecodEdXQ1->Write();
hMCRecodQdXQ1->Write();
hMCRecodEdXQ2->Write();
hMCRecodQdXQ2->Write();
hMCRecodEdXQ3->Write();
hMCRecodQdXQ3->Write();
hMCRecodEdXQ4->Write();
hMCRecodQdXQ4->Write();

   
}//<---End Loop() Function
