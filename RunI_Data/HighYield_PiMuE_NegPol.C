#define HighYield_PiMuE_NegPol_cxx
#include "HighYield_PiMuE_NegPol.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>


// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

/////////////////////////////////// Events with and without WC Tracks //////////////////////////////////////////
///////////////////////////////  0 = No WCTrack Exists, 1 = WCTrack Exists   ///////////////////////////////////
TH1D *hdataWCTrackExist = new TH1D("hdataWCTrackExist", "Existance of WCTrack", 2, 0, 2);


/////////////////////////////////// Full TOF for the data sample, no cuts //////////////////////////////////////
TH1D *hdataTOFNoCuts = new TH1D("hdataTOFNoCuts", "Time of Flight (No Cuts)", 240, 0, 120);

/////////////////////////////////// Wire Chamber Track Momentum vs TOF, no cuts ////////////////////////////////
TH2D *hdataWCTrackMomentumVSTOF = new TH2D("hdataWCTrackMomentumVSTOF", "TOF vs WCTrack Momentum", 250, 0, 2500, 200, 0, 100);

/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hdataUpstreamZPos = new TH1D("hdataUpstreamZPos", "Most upstream spacepoint of all TPC Tracks", 20, 0, 10);

/////////////////////////////////// TPC Track Theta at the upstream point //////////////////////////////////////
TH1D *hdataTPCTheta = new TH1D("hdataTPCTheta", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Phi at the upstream point ///////////////////////////////////////
TH1D *hdataTPCPhi = new TH1D("hdataTPCPhi", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// Wire Chamber Theta ////////////////////////////////////////////////////////
TH1D *hdataWCTheta = new TH1D("hdataWCTheta", "WCTrack Theta", 180, 0, 90);

/////////////////////////////////// Wire Chamber Phi //////////////////////////////////////////////////////////
TH1D *hdataWCPhi = new TH1D("hdataWCPhi", "WCTrack Phi", 360, 0, 360);

/////////////////////////////////// Delta WCTrack X ///////////////////////////////////////////////////////////
TH1D *hdataDeltaWCTrkX = new TH1D("hdataDeltaWCTrkX", "#Delta X TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Delta WCTrack Y ///////////////////////////////////////////////////////////
TH1D *hdataDeltaWCTrkY = new TH1D("hdataDeltaWCTrkY", "#Delta Y TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Alpha Between WC and TPC Tracks //////////////////////////////////////////
TH1D *hdataAlpha = new TH1D("hdataAlpha", "#alpha between WC and TPC Track", 90, 0, 90);

/////////////////////////////////// Number of Matched Tracks ////////////////////////////////////////////////
TH1D *hdataNMatchTPCWCTrk = new TH1D("hdataNMatchTPCWCTrk", "Number of matched TPC/WC Tracks", 20, 0, 10);

/////////////////////////////////// WCTRK Momentum Histogram (MeV) //////////////////////////////////////////
TH1D *hdataWCTRKMomentum = new TH1D("hdataWCTRKMomentum", "WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// RAAW WCTRK MOMENTUM HISTORGRAM (MeV) ///////////////////////////////////
TH1D *hdataRawWCTRKMomentum = new TH1D("hdataRawWCTRKMomentum", "Raw WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Initial Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hdataInitialKineticEnergy = new TH1D("hdataInitialKineticEnergy", "Pion Initial Momentum (MeV)", 500, 0, 2500);

/////////////////////////////////// Reconstructed Length //////////////////////////////////////////
TH1D *hRecoLength = new TH1D("hRecoLength", "Reconstructed Length of the Primary Particle inside the TPC", 200, 0 , 100);

/////////////////////////////////// Initial Track X Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialX = new TH1D("hdataTrkInitialX", "Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Initial Track Y Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialY = new TH1D("hdataTrkInitialY", "Initial Y Position of the TPC Track", 100, -25, 25); 

/////////////////////////////////// "Matched Track" dE/dX /////////////////////////////////////////////////////
TH1D *hdatadEdX = new TH1D("hdatadEdX", "Matched Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Matched Track" dQ/dX /////////////////////////////////////////////////////
TH1D *hdatadQdX = new TH1D("hdatadQdX", "Matched Track dQ/dX", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" Residual Range //////////////////////////////////////////
TH1D *hdataResRange = new TH1D("hdataResRange", "Matched Track Residual Range", 400, -100, 100);

/////////////////////////////////// "Matched Track" Track Pitch //////////////////////////////////////////
TH1D *hdataTrkPitch = new TH1D("hdataTrkPitch", "Matched Track Pitch", 1000, 0, 5);

/////////////////////////////////// "Matched Track" dE/dX in Q1 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ1 = new TH1D("hdatadEdXQ1", "Matched Track dE/dX Q1", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q2 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ2 = new TH1D("hdatadEdXQ2", "Matched Track dE/dX Q2", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q3 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ3 = new TH1D("hdatadEdXQ3", "Matched Track dE/dX Q3", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q4 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ4 = new TH1D("hdatadEdXQ4", "Matched Track dE/dX Q4", 200, 0, 50);

/////////////////////////////////// "Matched Track" dQ/dX in Q1 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ1 = new TH1D("hdatadQdXQ1", "Matched Track dQ/dX Q1", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q2 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ2 = new TH1D("hdatadQdXQ2", "Matched Track dQ/dX Q2", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q3 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ3 = new TH1D("hdatadQdXQ3", "Matched Track dQ/dX Q3", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q4 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ4 = new TH1D("hdatadQdXQ4", "Matched Track dQ/dX Q4", 2000, 0, 20000);

///////////////////////////////// "Matched Track" dE/dX vs RR ///////////////////////////////////////////////
TH2D *hdatadEdXvsRR = new TH2D("hdatadEdXvsRR", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

// ###############################################################################
// ### Note: The binning (number and range) needs to match between these plots ###
// ###############################################################################

/////////////////////////////////// "Pion" Incident to the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hdataIncidentKE = new TH1D("hdataIncidentKE", "Incident Kinetic Energy (MeV)", 42, -100, 2000);

/////////////////////////////////// "Pion" Exiting the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hdataInteractingKE = new TH1D("hdataInteractingKE", "Interacting Kinetic Energy (MeV)", 42, -100, 2000);


/////////////////////////////////// Cross-Section //////////////////////////////////////////////////////////////////////
TH1F *fCrossSection = new TH1F("fCrossSection", "Cross-Section", 42, -100, 2000);


// ===================================================================================================================
// ===================================================================================================================

void HighYield_PiMuE_NegPol::Loop()
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
double UpperTOFGoodReco = 90;

// ###################################################
// ### Setting the Wire Chamber momentum range and ###
// ###     the TOF range for good particle ID      ###
// ###################################################
double LowerWCTrkMomentum = 100.0; //<--(MeV)
double HighWCTrkMomentum  = 2000.0;//<--(MeV)

double LowerTOF = 10.0; //<--(ns)
double HighTOF  = 30.0; //<--(ns)

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


// ###############################################
// ###  Only keeping through going reco Tracks ###
// ###  True = Only keep through going tracks  ###
// ###   False = Keep all types of tracks      ###
// ###############################################
bool SelectThroughGoing = false;

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


// ####################################################
// ### Choose whether or not to use the 3d distance ###
// ### between points for the pitch and recalculate ###
// ###    the dE/dX distribution based on this      ###
// ###                                              ###
// ### True = Recalculate                           ###
// ### False = Use the existing dE/dX               ###
// ####################################################
bool Calculate3dPitch = false;


// ####################################################
// ### Choose whether we calculate dE/dX using info ###
// ###    stored in the hits instead of the info    ###
// ###           stored in the spacepoints          ###
// ###                                              ###
// ### True  = Use 2d Hits                          ###
// ### False = Use Spacepoints                      ###
// ####################################################
bool CalculateUsingHits = false;

// ###################################################
// ### Setting a flag to print out bunch of checks ###
// ###################################################
bool VERBOSE = false; 


// ###                 Note: Format for this variable is:             ###
// ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
int plane = 1;

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


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsWCTrack = 0, nEvtsWCTrackMatch = 0, nEvtsTrackZPos = 0, nEvntsTPC = 0;
int nEvtsTOF = 0, nEvtsPID = 0, nLowZTrkEvents = 0;
int nNonShowerEvents = 0, nTOFHits = 0;;

// #######################################################
// ### Providing an index for the Matched WC/TPC track ###
// #######################################################
int MatchWCTrackIndex[10] = {0};





// ====================================================
// ======  Make histogram file for data sample  ======= 
TFile myfile("../histoROOTfiles_forPlots/RunINeg_HighYield_PiMuE_dataHisto.root","RECREATE");



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
   //						Wire Chamber Track Cuts
   //=======================================================================================================================
   // ########################################
   // ### Skipping events with no WC Track ###
   // ########################################
   if(nwctrks < 1){ hdataWCTrackExist->Fill(0); continue;}
   
   // ### Loop over the WCTracks and TOF Objects ###
   for (int numWCTrk = 0; numWCTrk < nwctrks; numWCTrk++)
      {
      hdataRawWCTRKMomentum->Fill(wctrk_momentum[numWCTrk]);
      
      }//<---End loop over WCTrk
      
   // ### Counting Events w/ WC Track ###
   hdataWCTrackExist->Fill(1);
   nEvtsWCTrack++;
   
   //=======================================================================================================================
   //						 TOF Event Selection (ns)
   //=======================================================================================================================
   
   bool tofGood = true;
   // ################################################
   // ### If no TOF obeject exists, skip the event ###
   // ################################################
   if(ntof < 1){continue;}
   // ### Loop over all the TOF objects ###
   for(int mmtof = 0; mmtof < ntof; mmtof++)
      {
      // ### Requiring there exists a good TOF recorded ###
      if(tofObject[mmtof] < LowerTOFGoodReco || tofObject[mmtof] > UpperTOFGoodReco)
         {tofGood = false;}
      
      hdataTOFNoCuts->Fill(tofObject[mmtof]);
      
      
      }//<---End mmtof
   if(ntof>0){nTOFHits++;}
   
   if(!tofGood){continue;}
   nEvtsTOF++;
   
   
   //=======================================================================================================================
   //						 Putting in a GOOD TPC Cut (looking for nhits > 0
   //=======================================================================================================================
   
   // ### Skip the event if no hits are reconstructed in the TPC ###
   if(nhits < 1){continue;}
   nEvntsTPC++;
   
   
   // ======================================================================================================================
   //						  Particle ID Filter
   // ======================================================================================================================
   
   bool GoodPID = false;
   bool newEvents = false;
       
   // ### Loop over the WCTracks and TOF Objects ###
   for (int numWCTrk = 0; numWCTrk < nwctrks; numWCTrk++)
      {
      
      // ### Checking the number of TOF objects ###
      int TOFObject = numWCTrk;
      hdataWCTrackMomentumVSTOF->Fill(wctrk_momentum[numWCTrk] , tofObject[TOFObject]);
      // ### If we have more WCObjects the TOF, put in protection ### 
      if(TOFObject > ntof){TOFObject = ntof -1;}
      
      // ### Only keeping events that fall into the WCTrk Momentum and TOF range ###
      if(wctrk_momentum[numWCTrk] > LowerWCTrkMomentum && wctrk_momentum[numWCTrk] < HighWCTrkMomentum && 
         tofObject[TOFObject] > LowerTOF && tofObject[TOFObject] < HighTOF)
         {GoodPID = true;}
      
      if(tofObject[TOFObject] > 25  || wctrk_momentum[numWCTrk] > 2000)
         {
	 newEvents = true;
	 
	 }
      
      }//<---end numWCTrk
   if(!GoodPID){continue;}
   
   nEvtsPID++;   


   //=======================================================================================================================
   //						Low Z Spacepoint Track Cut
   //=======================================================================================================================
   
   // ### Boolian for events w/ track which ###
   // ###     starts at the front face      ###
   bool TrackSptsZCut = false;
   
   bool ThisTrackHasLowZPoint = false;
   
   // ### Recording the index of the track which ###
   // ###   starts at the front face of the TPC  ###
   bool PreLimTrackIndex[500] = {false};
   
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
      hdataUpstreamZPos->Fill(tempZpoint);
      
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
   //						Uniquely matching one WC Track to TPC Track
   //=======================================================================================================================
   
   // ### Keeping track of the number of matched tracks ###
   int nMatchedTracks = 0;
   
   // ### Variables for Delta WC and TPC tracks ###
   float DeltaX_WC_TPC_Track = 999;
   float DeltaY_WC_TPC_Track = 999;
   
   // ### Setting the index for the track which is ###
   // ### uniquely matched to a wire chamber track ###
   bool MatchTPC_WVTrack[500] = {false};
   
   MatchWCTrackIndex[0] = 0;
   MatchWCTrackIndex[1] = 0;
   MatchWCTrackIndex[2] = 0;
   MatchWCTrackIndex[3] = 0;
   MatchWCTrackIndex[4] = 0;
   MatchWCTrackIndex[5] = 0;
   MatchWCTrackIndex[6] = 0;
   MatchWCTrackIndex[7] = 0;
   MatchWCTrackIndex[8] = 0;
   
   // #############################################
   // ### Loop over all the wire chamber tracks ###
   // #############################################
   for(int mwctrk = 0; mwctrk < nwctrks; mwctrk++)
      {
      
      // ### Grab the WCTrack Theta ###;
      hdataWCTheta->Fill(wctrk_theta[mwctrk]* (180.0/3.141592654));
      
      // ### Grabbing the WCTrack Phi ###
      hdataWCPhi->Fill(wctrk_phi[mwctrk]* (180.0/3.141592654));
      
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
         hdataTPCTheta->Fill(tpcTheta* (180.0/3.141592654));
   
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
         hdataTPCPhi->Fill(tpcPhi* (180.0/3.141592654));
      
         // ===============================================================================================================            
         // ===============================================================================================================
	 
	 // #######################################################
	 // ### Defining unit vectors for the WC and TPC tracks ###
	 // #######################################################
	 TVector3 theUnitVector_WCTrack;
         TVector3 theUnitVector_TPCTrack;
	 
	 // === WCTrack Unit Vector ===
         theUnitVector_WCTrack.SetX(sin(wctrk_theta[mwctrk])*cos(wctrk_phi[mwctrk]));
         theUnitVector_WCTrack.SetY(sin(wctrk_theta[mwctrk])*sin(wctrk_phi[mwctrk]));
         theUnitVector_WCTrack.SetZ(cos(wctrk_theta[mwctrk]));
    
         // === TPC Track Unit Vector ===
         theUnitVector_TPCTrack.SetX(sin(tpcTheta)*cos(tpcPhi));
         theUnitVector_TPCTrack.SetY(sin(tpcTheta)*sin(tpcPhi));
         theUnitVector_TPCTrack.SetZ(cos(tpcTheta));
	 
	 // ##########################################################################
	 // ### Calculating the Delta X and Delta Y between WC track and TPC track ###
	 // ##########################################################################
	 DeltaX_WC_TPC_Track = FirstSpacePointX - (wctrk_XFaceCoor[mwctrk]);
	 DeltaY_WC_TPC_Track = FirstSpacePointY - (wctrk_YFaceCoor[mwctrk]);
	 
	 
	 // ### Filling the tracks initial X and Y position ###
	 hdataTrkInitialX->Fill(FirstSpacePointX);
         hdataTrkInitialY->Fill(FirstSpacePointY);
	 
	 
	 // ###########################################################
         // ### Calculating the angle between WCTrack and TPC Track ###
         // ###########################################################
         float alpha = ( acos(theUnitVector_WCTrack.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
   
         
	 // ### Filling the Delta X and Delta Y  and alpha between WC tracks and TPC Tracks ###
	 hdataDeltaWCTrkY->Fill(DeltaY_WC_TPC_Track);
	 hdataDeltaWCTrkX->Fill(DeltaX_WC_TPC_Track);
	 hdataAlpha->Fill(alpha);
	 
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
	    
	    // ### Setting the WCTrack Index = 1 if this WCTrack was matched ###
	    MatchWCTrackIndex[mwctrk] = 1;
	    }  
	 
	 }//<---end nTPCtrk loop
      
      
      }//<---End loop over wire chamber tracks
   
   // ### Filling the number of matched WC and TPC Tracks ###
   hdataNMatchTPCWCTrk->Fill(nMatchedTracks);
   
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
   // --- the momentum of the wire chamber track which has been matched ---
   // ---  and correct for the "typical" energy loss for a track in the ---
   // ---   argon between the cryostat and the front face of the TPC    ---
   
   
   float momentum = 999;
   
   // ###################################################
   // ### Grabbing the Wire Chamber Track Information ###
   // ###################################################
   for(int mwctrk = 0; mwctrk < nwctrks; mwctrk++)
      {
      // ### Skip this WCTrack if it isn't the matched one ###
      if(MatchWCTrackIndex[mwctrk] < 1 || MatchWCTrackIndex[mwctrk] > 1){continue;}
      
      
      hdataWCTRKMomentum->Fill(wctrk_momentum[mwctrk]);//Momentum of the matched track
      momentum =wctrk_momentum[mwctrk];
      
      }//<---End mwctrk
   
   
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
   hdataInitialKineticEnergy->Fill(kineticEnergy);


   // =========================================================================================================================================
   //							 Calorimetry Points
   // =========================================================================================================================================
   
   //Vectors with calo info of the matched tpc track
   double DatadEdX[20][1000]={0.};
   double DatadQdX[20][1000]={0.};
   double DataResRange[20][1000]={0.};
   double DataSptPitch[20][1000]={0.};
   int nDataTrks = 0;
   int nDataSpts = 0;
   int nSpacePoints[1000] = {0};
   
   float DataSptsX[20][1000];
   float DataSptsY[20][1000];
   float DataSptsZ[20][1000];
   
   
   bool AtLeastOneThroughGoingTrack = false;
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
      
      // ### Skipping all the tracks which ARE NOT well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ### Recording the track length ###
      hRecoLength->Fill(trklength[nTPCtrk]);

      // ###################################################
      // ### Check to see if this track is through going ###
      // ### by checking to see if it ends on a boundary ###
      // ###################################################
      if(trkendx[nTPCtrk] < 1   || trkendx[nTPCtrk] > 42.0 || trkendy[nTPCtrk] > 19 ||
         trkendy[nTPCtrk] < -19 || trkendz[nTPCtrk] > 88.0)
         {ThroughGoingTrack[nTPCtrk] = true;}
             
      
      float average_dEdX = 0;
      
      if(SelectThroughGoing && !ThroughGoingTrack[nTPCtrk]){continue;}
      
      // ### Loop over the hits ###
      
      if(CalculateUsingHits)
         {
         for (int ihit = 0; ihit<nhits; ++ihit)
            {
	    // ##################################
	    // ### Match the track to the hit ###
	    // ##################################
	    if (hit_trkkey[ihit]==nTPCtrk)
	       {
	       // #################################################
	       // ### Require the hits to be in the right plane ###
	       // #################################################
	       if (hit_plane[ihit] == plane)
	          {
	          //DatadEdX[nDataTrks][nDataSpts]     = corrdEdx(hit_dEds[ihit]);
	          DatadEdX[nTPCtrk][nDataSpts]     = hit_dEds[ihit];
	          DatadQdX[nTPCtrk][nDataSpts]     = hit_dQds[ihit];
	       
	          DataResRange[nTPCtrk][nDataSpts] = hit_resrange[ihit];
	          DataSptPitch[nTPCtrk][nDataSpts] = hit_ds[ihit];
	          DataSptsX[nTPCtrk][nDataSpts] = hit_x[ihit];
	          DataSptsY[nTPCtrk][nDataSpts] = hit_y[ihit];
	          DataSptsZ[nTPCtrk][nDataSpts] = hit_z[ihit];
	       
	          // ###################################################
	          // ### Adding an option to calculate the 3-d pitch ###
	          // ###################################################
	          if(Calculate3dPitch && ihit > 0)
	             {
		     float dE = DatadEdX[nTPCtrk][nDataSpts] * DataSptPitch[nTPCtrk][nDataSpts];
		  
		     float dX = (DataSptsX[nTPCtrk][nDataSpts] - DataSptsX[nTPCtrk][nDataSpts - 1]);
		     float dY = (DataSptsY[nTPCtrk][nDataSpts] - DataSptsY[nTPCtrk][nDataSpts - 1]);
		     float dZ = (DataSptsZ[nTPCtrk][nDataSpts] - DataSptsZ[nTPCtrk][nDataSpts - 1]);
		  
		     float ds = sqrt( (dX*dX) + (dY*dY) + (dZ*dZ) );
		  
		     DatadEdX[nTPCtrk][nDataSpts] = dE/ds;
		     DataSptPitch[nTPCtrk][nDataSpts] = ds;
		  
		     }//<---end calculate 3-d pitch
	       
	       
	          nDataSpts++;
	          }//<---end matching hit plane
	       }//<---end matching hit to track
	 
	    }//<---End ihit loop 
         }//<---End Calculate using hits
      
      
      
      // ###############################################################
      // ### Looping over the calorimetry spacepoints for this track ###
      // ###############################################################
      for(int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 // ###                 Note: Format for this variable is:             ###
	 // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
         DatadEdX[nTPCtrk][nDataSpts]     = trkdedx[nTPCtrk][plane][nspts];
	 DatadQdX[nTPCtrk][nDataSpts]     = trkdqdx[nTPCtrk][plane][nspts];
	 
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(DatadEdX[nTPCtrk][nDataSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {DatadEdX[nTPCtrk][nDataSpts] = ( (trkdedx[nTPCtrk][plane][nspts - 1] + trkdedx[nTPCtrk][plane][nspts + 1]) / 2);}
	 
	 // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	 if(DatadEdX[nTPCtrk][nDataSpts] < 0)
	    {continue;}
	    
	 DataResRange[nTPCtrk][nDataSpts] = trkrr[nTPCtrk][plane][nspts];
	 
	 // ### Put in a flag to look for through going tracks ###
	 if(trkrr[nTPCtrk][plane][nspts] > 88){AtLeastOneThroughGoingTrack = true;}
	 
	 
         DataSptPitch[nTPCtrk][nDataSpts] = trkpitchhit[nTPCtrk][plane][nspts];
	 
	 DataSptsX[nTPCtrk][nDataSpts] = trkxyz[nTPCtrk][plane][nspts][0];
	 DataSptsY[nTPCtrk][nDataSpts] = trkxyz[nTPCtrk][plane][nspts][1];
	 DataSptsZ[nTPCtrk][nDataSpts] = trkxyz[nTPCtrk][plane][nspts][2];

	 
	 // ### Bump the nDataSpts counter ###
	 nDataSpts++;

	 
	 }//<---End spacepoints loop
      	 
      nSpacePoints[nTPCtrk] = nDataSpts;	 
      nDataSpts = 0;	 
      nDataTrks++;
      AtLeastOneThroughGoingTrack = true;
      }//<---End nTPCtrk loop 


   
// ---------------------------------------------------------------------------------------------------------------------------------------
   bool HasToBeReordered[20] = {false};
   int ReorderedCount = 0;
   int ReorderTrkCount[20] = {0};
   int bb = 0;
   // ############################################################
   // ### Fix the reordering problem of the calorimetry points ###
   // ############################################################
   if(FixCaloIssue_Reordering)
      {
      
      for( int trkPoints = 0; trkPoints < ntracks_reco; trkPoints++)
         {
	 // ### Skipping all the tracks which ARE NOT well matched ###
         if(!MatchTPC_WVTrack[trkPoints]){continue;}
         // ################################
         // ### Loop over the caloPoints ###
         // ################################
         for(int caloPoints = 0; caloPoints < nSpacePoints[trkPoints]-1; caloPoints++)
            {
	    // ###           If this points Residual Range is smaller than the       ###
	    // ### next point, then things may be out of wack and we want to reorder ###
	    if(DataResRange[trkPoints][caloPoints] < DataResRange[trkPoints][caloPoints+1])
	       {
	       // #######################################################
	       // ### Set a flag that this might have to be reordered ###
	       // #######################################################
	       HasToBeReordered[trkPoints] = true;
	    
	       // ### counting the points that are out of order ###
	       ReorderedCount++;
	       }

            }//<---End caloPoints
	 ReorderTrkCount[trkPoints] = ReorderedCount;
	 ReorderedCount = 0;   
	 }//<---End trkPoints
      }//<---End fixing the ordering problem
   
   // #####################################################
   // ### The things need to be reorderd for this track ###
   // #####################################################
   
   for(int trkpt = 0; trkpt < ntracks_reco; trkpt++)
      {
      // ### Skipping all the tracks which ARE NOT well matched ###
      if(!MatchTPC_WVTrack[trkpt]){continue;}
      
      if(HasToBeReordered[trkpt] && ( (nSpacePoints[trkpt] -  ReorderTrkCount[trkpt]) == 1))
         {
      
         // ### Temp Variables for fixing ###
         double tempRR[20][1000] = {0.};
         double tempdEdX[20][1000] = {0.};
         double tempdQdX[20][1000] = {0.};
         double tempPitch[20][1000] = {0.};
      
         double tempx[20][1000] = {0.};
         double tempy[20][1000] = {0.};
         double tempz[20][1000] = {0.};
      
         // ### Start at the last point ###
         for(int aa = nSpacePoints[trkpt]; aa > -1; aa--)
            {
	    // ##########################################
	    // ### Skip the point if it is at the end ###
	    // ##########################################
	    if(DataResRange[trkpt][aa] == 0){continue;}
	 
	    // ### Reorder the points ###
	    tempRR[trkpt][bb]       = DataResRange[trkpt][aa];
	    tempdEdX[trkpt][bb]     = DatadEdX[trkpt][aa];
	    tempdQdX[trkpt][bb]     = DatadQdX[trkpt][aa];
	    tempPitch[trkpt][bb]    = DataSptPitch[trkpt][aa];
	 
	    tempx[trkpt][bb] = DataSptsX[trkpt][aa];
	    tempy[trkpt][bb] = DataSptsY[trkpt][aa];
	    tempz[trkpt][bb] = DataSptsZ[trkpt][aa];
	 
	    bb++;
	    }//<---end aa 
      
         // ###########################
         // ### Now swap the points ###
         // ###########################
         for(int reorder = 0; reorder < nSpacePoints[trkpt]; reorder++)
            {
	    DataResRange[trkpt][reorder] = tempRR[trkpt][reorder];
	    DatadEdX[trkpt][reorder]     = tempdEdX[trkpt][reorder];
	    DatadQdX[trkpt][reorder]     = tempdQdX[trkpt][reorder];
	    DataSptPitch[trkpt][reorder] = tempPitch[trkpt][reorder];
	 
	    DataSptsX[trkpt][reorder] = tempx[trkpt][reorder];
	    DataSptsY[trkpt][reorder] = tempy[trkpt][reorder];
	    DataSptsZ[trkpt][reorder] = tempz[trkpt][reorder];
	 
	    }//<---End reorder loop
      
         }//<---End Has to be reordered
      }//<<----End trkpt loop

   // ##################################
   // ### Printing things as a check ###
   // ##################################
   if(HasToBeReordered[0] && VERBOSE)
      {
      for(int trackPoint = 0; trackPoint < ntracks_reco; trackPoint++)
         {
	 if(!MatchTPC_WVTrack[trackPoint]){continue;}
	 
	 std::cout<<"===== Track "<<trackPoint<<"  ========"<<std::endl;
         for(int caloPoints = 0; caloPoints < nSpacePoints[trackPoint]; caloPoints++)
            {
	    std::cout<<"Run = "<<run<<", Event = "<<event<<" point = "<<caloPoints<<", RR = "<<DataResRange[trackPoint][caloPoints]<<", dE/dX = "<<DatadEdX[trackPoint][caloPoints]<<std::endl;
      
      
            }//<---End caloPoints
      std::cout<<std::endl;
         }//<---End track  Piont	 
      }//<---Putting in a print to make sure things are reordered correctly

   // ####################################################################
   // ### Fix the calorimetry issues associated with huge fluctuations ###
   // ###            by extrapolating through the points               ###
   // ####################################################################
   if(FixCaloIssue_ExtremeFluctuation)
      {
      // ############################
      // ### Loop over the tracks ###
      // ############################
      for( int trkPoints = 0; trkPoints < ntracks_reco; trkPoints++)
         {
	 if(!MatchTPC_WVTrack[trkPoints]){continue;}
	 
         // ################################
         // ### Loop over the caloPoints ###
         // ################################
         for(int caloPoints = 0; caloPoints < nSpacePoints[trkPoints]; caloPoints++)
            {
	    
	    // ###################################################
	    // ### If the dE/dX is large and at the end of the ###
	    // ###  track as expected with a proton attached   ###
	    // ###################################################
	    if(DatadEdX[trkPoints][caloPoints] > 40. && caloPoints == (nSpacePoints[trkPoints]) )
	       {
	       // ##########################################################
	       // ### Set this point equal to the previous point's dE/dX ###
	       // ##########################################################
	    
	       DatadEdX[trkPoints][caloPoints] =DatadEdX[trkPoints][caloPoints - 1];
	       
	       }//<---End remove the large point at the end of a track
            // ############################################################
	    // ### Else, if it is a large dE/dX but not the first point ###
	    // ############################################################
	    else if(DatadEdX[trkPoints][caloPoints] > 40. && caloPoints < (nSpacePoints[trkPoints] - 1 ) && nSpacePoints[trkPoints] > 0.)
	       {
	       
	       // #################################################################
	       // ### Then just average between the previous and the next point ###
	       // #################################################################

	       DatadEdX[trkPoints][caloPoints] = ( (DatadEdX[trkPoints][caloPoints - 1] + DatadEdX[trkPoints][caloPoints + 1]) / 2.);
	    
	       }//<--End large and not at the end of the track
      
      
      
            }//<---end caloPoints
	    
	 }//<---End trkPoints
      
      
      }//<---End Fix Extreme Fluctuations
   
   
   // ####################################
   // ### Loop over all the TPC Tracks ###
   // ####################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      // ### Skipping all the tracks which ARE NOT well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ###########################################################
      // ### Loop over all the spacepoints for the matched track ###
      // ###########################################################
      for(int nspts = 0; nspts < nSpacePoints[nTPCtrk]; nspts++)
         {
	 
	 // ### Histogramming the dE/dX ###
	 hdatadEdX->Fill(DatadEdX[nTPCtrk][nspts]);
	 
	 // ### Histogramming the dQ/dX ###
	 hdatadQdX->Fill(DatadQdX[nTPCtrk][nspts]);
	 
	 // ### Histogramming the residual range ###
	 hdataResRange->Fill(DataResRange[nTPCtrk][nspts]);
	 // ### Histogramming the Pitch ###
	 hdataTrkPitch->Fill(DataSptPitch[nTPCtrk][nspts]);
	 
	 // ### Filling 2d dE/dX vs RR ###
	 hdatadEdXvsRR->Fill(DataResRange[nTPCtrk][nspts], DatadEdX[nTPCtrk][nspts]);
	 
	 // =====================================================================
	 // === Breaking the TPC into 4 quadrants to analyze the dE/dX and dQ/dX
	 // ===               Q1: 0 cm    < z    < 22.5 cm
	 // ===               Q2: 22.5 cm < z    < 45 cm
	 // ===               Q3: 45 cm   < z    < 67.5 cm
	 // ===               Q4: 67.5 cm < z    < 90 cm
	 // =====================================================================
	 if(DataSptsZ[nTPCtrk][nspts] > 0    && DataSptsZ[nTPCtrk][nspts] < 22.5)
	    {
	    hdatadEdXQ1->Fill(DatadEdX[nTPCtrk][nspts]);
	    hdatadQdXQ1->Fill(DatadQdX[nTPCtrk][nspts]);
	    }
	 if(DataSptsZ[nTPCtrk][nspts] > 22.5 && DataSptsZ[nTPCtrk][nspts] < 45)
	    {
	    hdatadEdXQ2->Fill(DatadEdX[nTPCtrk][nspts]);
	    hdatadQdXQ2->Fill(DatadQdX[nTPCtrk][nspts]);
	    }
	 if(DataSptsZ[nTPCtrk][nspts] > 45   && DataSptsZ[nTPCtrk][nspts] < 67.5)
	    {
	    hdatadEdXQ3->Fill(DatadEdX[nTPCtrk][nspts]);
	    hdatadQdXQ3->Fill(DatadQdX[nTPCtrk][nspts]);
	    }
	 if(DataSptsZ[nTPCtrk][nspts] > 67.5 && DataSptsZ[nTPCtrk][nspts] < 90)
	    {
	    hdatadEdXQ4->Fill(DatadEdX[nTPCtrk][nspts]);
	    hdatadQdXQ4->Fill(DatadQdX[nTPCtrk][nspts]);
	    }

	 }//<---End nspts loop
      }//<---End nTPCtrk loop
   
   
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
      for(int npoints = 0; npoints < nSpacePoints[nTPCtrk]; npoints++)
         {
	 // ### Filling the incidient histogram ###
         hdataIncidentKE->Fill(kineticEnergy);
      
         // ###            Filling the interaction histogram for the last spt          ###
	 // ### As long as it isn't a through going track and isn't tagged as stopping ###
         if(npoints == nSpacePoints[nTPCtrk] -1 && !ThroughGoingTrack[nTPCtrk] && !StoppingParticle[nTPCtrk] )
            {hdataInteractingKE->Fill(kineticEnergy);}
         
	 // ################################################
	 // ### Subtracting the energy loss in this step ###
	 // ################################################
         float energyLossInStep = DatadEdX[nTPCtrk][npoints] * DataSptPitch[nTPCtrk][npoints];
         
	 // #######################################################
	 // ### Removing that kinetic energy from the histogram ###
	 // #######################################################
         kineticEnergy -= energyLossInStep;
      
      
      
      
         }//<---End npoints loop
      }//<---End nTPCtrk loop   
   
   
   
   
   }//<----End jentry loop
   
   
   
// ===============================================================================================================
//					MAKING THE CROSS-SECTION PLOT
// ===============================================================================================================

// ###################################################################
// #### Looping over the exiting bins to extract the cross-section ###
// ###################################################################
for( int iBin = 1; iBin <= hdataInteractingKE->GetNbinsX(); ++iBin )
   {
   // ### If an incident bin is equal to zero then skip that bin ###
   if( hdataIncidentKE->GetBinContent(iBin) == 0 )continue; //Temporary fix to ensure that no Infinities are propagated to pad
   
   // ### Cross-section = (Exit Bins / Incident Bins) * (1/Density) * (1/slab width) ###
   float TempCrossSection = (hdataInteractingKE->GetBinContent(iBin)/hdataIncidentKE->GetBinContent(iBin)) * (1/number_density) * (1/slab_width);
   
   // ### Covert this into Barns ###
   float crossSection = TempCrossSection * (1/1e-28);
   
   // ### Putting the value on the plot
   fCrossSection->SetBinContent(iBin,crossSection);
   
   // ###########################################################
   // ### Calculating the error on the numerator of the ratio ###
   // ###########################################################
   float numError = pow(hdataInteractingKE->GetBinContent(iBin),0.5);
   float num = hdataInteractingKE->GetBinContent(iBin);

   // ### Putting in a protection against dividing by zero ###   
   if(num == 0){num = 1;}
   float term1 = numError/num;
   
   // #################################################
   // ### Calculating the error on the denomentator ###
   // #################################################
   float denomError = pow(hdataIncidentKE->GetBinContent(iBin),0.5);
   float denom = hdataIncidentKE->GetBinContent(iBin);
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
std::cout<<"### Number of Events w/ TOF Object                               = "<<nTOFHits<<std::endl;
std::cout<<"### Number of Events w/ TOF > "<<LowerTOFGoodReco<<" ns and < "<<UpperTOFGoodReco<<" ns                   = "<<nEvtsTOF<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Good TPC info (nHits > 0)		     = "<<nEvntsTPC<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 1   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ PID consistent with Pi/Mu                = "<<nEvtsPID<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 2   ----------------------------"<<std::endl;
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

hdataWCTrackExist->Write();
hdataTOFNoCuts->Write();
hdataWCTrackMomentumVSTOF->Write();
hdataUpstreamZPos->Write();
hdataTPCTheta->Write();
hdataTPCPhi->Write();
hdataWCTheta->Write();
hdataWCPhi->Write();
hdataDeltaWCTrkX->Write();
hdataDeltaWCTrkY->Write();
hdataAlpha->Write();
hdataNMatchTPCWCTrk->Write();
hdataWCTRKMomentum->Write();
hdataRawWCTRKMomentum->Write();
hdataInitialKineticEnergy->Write();
hdataTrkInitialX->Write();
hdataTrkInitialY->Write();

hdatadEdX->Write();
hdataResRange->Write();
hdataTrkPitch->Write();
hdatadEdXvsRR->Write();


hdatadEdXQ1->Write();
hdatadQdXQ1->Write();
hdatadEdXQ2->Write();
hdatadQdXQ2->Write();
hdatadEdXQ3->Write();
hdatadQdXQ3->Write();
hdatadEdXQ4->Write();
hdatadQdXQ4->Write();

hdataIncidentKE->Write();
hdataInteractingKE->Write();
fCrossSection->Write();
hRecoLength->Write();

}//<---End Loop() function
