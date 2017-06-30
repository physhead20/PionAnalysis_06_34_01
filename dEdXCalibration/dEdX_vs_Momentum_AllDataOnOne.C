{
#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TMath.h>

double MuonMomentumError[49] = {0.};
double MuonMomentum[49] = {
27.42,
29.35,
31.16,
32.89,
34.53,
36.11,
39.09,
41.89,
44.53,
47.04,
51.77,
56.16,
62.3,
68.02,
76.86,
85.09,
92.85,
100.3,
107.4,
114.3,
121,
127.6,
140.3,
152.7,
164.7,
176.4,
199.4,
221.8,
254.6,
286.8,
339.6,
356.7,
391.7,
443.2,
494.5,
545.5,
596.4,
647.1,
697.7,
798.7,
899.5,
1000,
1101,
1301,
1502,
1803,
2103,
2604};

double PionMomentumError[49] = {0.};
double PionMomentum[49] = {
35.646,
38.155,
40.508,
42.757,
44.889,
46.943,
50.817,
54.457,
57.889,
61.152,
67.301,
73.008,
80.99,
88.426,
99.918,
110.617,
120.705,
130.39,
139.62,
148.59,
157.3,
165.88,
182.39,
198.51,
214.11,
229.32,
259.22,
288.34,
330.98,
372.84,
441.48,
463.71,
509.21,
576.16,
642.85,
709.15,
775.32,
841.23,
907.01,
1038.31,
1169.35,
1300,
1431.3,
1691.3,
1952.6,
2343.9,
2733.9,
3385.2};

double ProtonMomentumError[49] = {0.};
double ProtonMomentum[49] = {
304.362,
325.785,
345.876,
365.079,
383.283,
400.821,
433.899,
464.979,
494.283,
522.144,
574.647,
623.376,
691.53,
755.022,
853.146,
944.499,
1030.635,
1113.33,
1192.14,
1268.73,
1343.1,
1416.36,
1557.33,
1694.97,
1828.17,
1958.04,
2213.34,
2461.98,
2826.06,
3183.48,
3769.56,
3959.37,
4347.87,
4919.52,
5488.95,
6055.05,
6620.04,
7182.81,
7744.47,
8865.57,
9984.45,
11100,
12221.1,
14441.1,
16672.2,
20013.3,
23343.3,
28904.4};

double TheorydEdXError[49] = {0.};
double TheorydEdX[49] = {
12.72,
11.46,
10.46,
9.635,
8.949,
8.368,
7.435,
6.719,
6.15,
5.687,
4.979,
4.461,
3.902,
3.502,
3.042,
2.731,
2.508,
2.34,
2.21,
2.107,
2.023,
1.954,
1.848,
1.771,
1.713,
1.67,
1.609,
1.57,
1.536,
1.519,
1.508,
1.51,
1.51,
1.517,
1.526,
1.537,
1.548,
1.559,
1.57,
1.591,
1.61,
1.628,
1.645,
1.675,
1.7,
1.733,
1.761,
1.799};

// =================================================================================================================
// =================================================================================================================
// =================================================================================================================
double dEdXPionData[21] = {0.};
double dEdXErrorPionData[21] = {0.};

double dEdXLessbinPionData[11] = {0.};
double dEdXErrorLessbinPionData[11] = {0.};


// ########################
// ### Collection Plane ###
// ########################

TFile *f1 = new TFile("../histoROOTfiles_forPlots/dEdXCalib_RunIPos_Picky_PiMuE.root");


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h150_200 = (TH1F*)f1->Get("hdatadEdX_150_200");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h150_200->Fit(data_gaus,"R+0LLi","0",1.0, 5.00);

dEdXPionData[0]       = data_gaus->GetParameter(1);
dEdXErrorPionData[0]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h200_250 = (TH1F*)f1->Get("hdatadEdX_200_250");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h200_250->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[1]       = data_gaus->GetParameter(1);
dEdXErrorPionData[1]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionData[0] = (dEdXPionData[0] + dEdXPionData[1]) / 2;
dEdXErrorLessbinPionData[0] = sqrt( (dEdXErrorPionData[0]*dEdXErrorPionData[0])+(dEdXErrorPionData[1]*dEdXErrorPionData[1]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h250_300 = (TH1F*)f1->Get("hdatadEdX_250_300");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h250_300->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[2]       = data_gaus->GetParameter(1);
dEdXErrorPionData[2]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h300_350 = (TH1F*)f1->Get("hdatadEdX_300_350");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h300_350->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[3]       = data_gaus->GetParameter(1);
dEdXErrorPionData[3]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionData[1] = (dEdXPionData[2] + dEdXPionData[3]) / 2;
dEdXErrorLessbinPionData[1] = sqrt( (dEdXErrorPionData[2]*dEdXErrorPionData[2])+(dEdXErrorPionData[3]*dEdXErrorPionData[3]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h350_400 = (TH1F*)f1->Get("hdatadEdX_350_400");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h350_400->Fit(data_gaus,"R+0LLi","0",1.25, 5.25);

dEdXPionData[4]       = data_gaus->GetParameter(1);
dEdXErrorPionData[4]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h400_450 = (TH1F*)f1->Get("hdatadEdX_400_450");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h400_450->Fit(data_gaus,"R+0LLi","0",1.25, 3.0);

dEdXPionData[5]       = data_gaus->GetParameter(1);
dEdXErrorPionData[5]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionData[2] = (dEdXPionData[4] + dEdXPionData[5]) / 2;
dEdXErrorLessbinPionData[2] = sqrt( (dEdXErrorPionData[4]*dEdXErrorPionData[4])+(dEdXErrorPionData[5]*dEdXErrorPionData[5]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h450_500 = (TH1F*)f1->Get("hdatadEdX_450_500");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h450_500->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[6]       = data_gaus->GetParameter(1);
dEdXErrorPionData[6]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h500_550 = (TH1F*)f1->Get("hdatadEdX_500_550");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h500_550->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[7]       = data_gaus->GetParameter(1);
dEdXErrorPionData[7]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionData[3] = (dEdXPionData[6] + dEdXPionData[7]) / 2;
dEdXErrorLessbinPionData[3] = sqrt( (dEdXErrorPionData[6]*dEdXErrorPionData[6])+(dEdXErrorPionData[7]*dEdXErrorPionData[7]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h550_600 = (TH1F*)f1->Get("hdatadEdX_550_600");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h550_600->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[8]       = data_gaus->GetParameter(1);
dEdXErrorPionData[8]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h600_650 = (TH1F*)f1->Get("hdatadEdX_600_650");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h600_650->Fit(data_gaus,"R+0LLi","0",1.25, 4.00);

dEdXPionData[9]       = data_gaus->GetParameter(1);
dEdXErrorPionData[9]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionData[4] = (dEdXPionData[8] + dEdXPionData[9]) / 2;
dEdXErrorLessbinPionData[4] = sqrt( (dEdXErrorPionData[8]*dEdXErrorPionData[8])+(dEdXErrorPionData[9]*dEdXErrorPionData[9]) );

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h650_700 = (TH1F*)f1->Get("hdatadEdX_650_700");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h650_700->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[10]       = data_gaus->GetParameter(1);
dEdXErrorPionData[10]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h700_750 = (TH1F*)f1->Get("hdatadEdX_700_750");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h700_750->Fit(data_gaus,"R+0LLi","0",1.25, 6.00);

dEdXPionData[11]       = data_gaus->GetParameter(1);
dEdXErrorPionData[11]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbinPionData[5] = (dEdXPionData[10] + dEdXPionData[11]) / 2;
dEdXErrorLessbinPionData[5] = sqrt( (dEdXErrorPionData[10]*dEdXErrorPionData[10])+(dEdXErrorPionData[11]*dEdXErrorPionData[11]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h750_800 = (TH1F*)f1->Get("hdatadEdX_750_800");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h750_800->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[12]       = data_gaus->GetParameter(1);
dEdXErrorPionData[12]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h800_850 = (TH1F*)f1->Get("hdatadEdX_800_850");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h800_850->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[13]       = data_gaus->GetParameter(1);
dEdXErrorPionData[13]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionData[6] = (dEdXPionData[12] + dEdXPionData[13]) / 2;
dEdXErrorLessbinPionData[6] = sqrt( (dEdXErrorPionData[12]*dEdXErrorPionData[12])+(dEdXErrorPionData[13]*dEdXErrorPionData[13]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h850_900 = (TH1F*)f1->Get("hdatadEdX_850_900");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h850_900->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[14]       = data_gaus->GetParameter(1);
dEdXErrorPionData[14]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h900_950 = (TH1F*)f1->Get("hdatadEdX_900_950");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h900_950->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[15]       = data_gaus->GetParameter(1);
dEdXErrorPionData[15]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionData[7] = (dEdXPionData[14] + dEdXPionData[15]) / 2;
dEdXErrorLessbinPionData[7] = sqrt( (dEdXErrorPionData[14]*dEdXErrorPionData[14])+(dEdXErrorPionData[15]*dEdXErrorPionData[15]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h950_1000 = (TH1F*)f1->Get("hdatadEdX_950_1000");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h950_1000->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[16]       = data_gaus->GetParameter(1);
dEdXErrorPionData[16]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1000_1050 = (TH1F*)f1->Get("hdatadEdX_1000_1050");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1000_1050->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[17]       = data_gaus->GetParameter(1);
dEdXErrorPionData[17]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionData[8] = (dEdXPionData[16] + dEdXPionData[17]) / 2;
dEdXErrorLessbinPionData[8] = sqrt( (dEdXErrorPionData[16]*dEdXErrorPionData[16])+(dEdXErrorPionData[17]*dEdXErrorPionData[17]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1050_1100 = (TH1F*)f1->Get("hdatadEdX_1050_1100");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1050_1100->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[18]       = data_gaus->GetParameter(1);
dEdXErrorPionData[18]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1100_1150 = (TH1F*)f1->Get("hdatadEdX_1100_1150");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1100_1150->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[19]       = data_gaus->GetParameter(1);
dEdXErrorPionData[19]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1150_1200 = (TH1F*)f1->Get("hdatadEdX_1150_1200");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1150_1200->Fit(data_gaus,"R+0LLi","0",1.25, 5.00);

dEdXPionData[20]       = data_gaus->GetParameter(1);
dEdXErrorPionData[20]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbinPionData[9] = (dEdXPionData[18] + dEdXPionData[19] + dEdXPionData[20]) / 3;
dEdXErrorLessbinPionData[9] = sqrt( (dEdXErrorPionData[18]*dEdXErrorPionData[18])+(dEdXErrorPionData[19]*dEdXErrorPionData[19]) + (dEdXErrorPionData[20]*dEdXErrorPionData[20]));


// ##########################
// ### Finely binned Data ###
// ##########################
const Int_t nPionData = 20;

double binXLessbin[20] = {0, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000};
double binXErrorLessbin[20] = {0.};

for(int a = 0; a < nPionData; a++){binXErrorLessbin[a] = 50.;}


grPionData  = new TGraphErrors(nPionData,binXLessbin,dEdXLessbinPionData,binXErrorLessbin,dEdXErrorLessbinPionData);
grPionData->SetFillColor(kWhite);
grPionData->SetFillStyle(3005);
grPionData->SetLineColor(kBlack);
grPionData->SetLineWidth(2);



// =================================================================================================================
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
dEdXLessbin[1] = (dEdX[2] + dEdX[3]) / 2;
dEdXErrorLessbin[1] = sqrt( (dEdXError[2]*dEdXError[2])+(dEdXError[3]*dEdXError[3]));


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
dEdXLessbin[2] = (dEdX[4] + dEdX[5]) / 2;
dEdXErrorLessbin[2] = sqrt( (dEdXError[4]*dEdXError[4])+(dEdXError[5]*dEdXError[5]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton450_500 = (TH1F*)f2->Get("hdatadEdX_450_500");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton450_500->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

// !!!! This bin has too little data for consideration !!!!
dEdX[6]       = 0;//data_gaus->GetParameter(1);
dEdXError[6]  = 0;//data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton500_550 = (TH1F*)f2->Get("hdatadEdX_500_550");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton500_550->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);


// !!!! This bin has too little data for consideration !!!!
dEdX[7]       = 0;//data_gaus->GetParameter(1);
dEdXError[7]  = 0;//data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[3] = (dEdX[6] + dEdX[7]) / 2;
dEdXErrorLessbin[3] = sqrt( (dEdXError[6]*dEdXError[6])+(dEdXError[7]*dEdXError[7]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton550_600 = (TH1F*)f2->Get("hdatadEdX_550_600");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton550_600->Fit(data_gaus,"R+0LLi","0",4.5, 10.00);

dEdX[8]       = data_gaus->GetParameter(1);
dEdXError[8]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton600_650 = (TH1F*)f2->Get("hdatadEdX_600_650");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton600_650->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[9]       = data_gaus->GetParameter(1);
dEdXError[9]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[4] = (dEdX[8] + dEdX[9]) / 2;
dEdXErrorLessbin[4] = sqrt( (dEdXError[8]*dEdXError[8])+(dEdXError[9]*dEdXError[9]) );

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton650_700 = (TH1F*)f2->Get("hdatadEdX_650_700");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton650_700->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[10]       = data_gaus->GetParameter(1);
dEdXError[10]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton700_750 = (TH1F*)f2->Get("hdatadEdX_700_750");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton700_750->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[11]       = data_gaus->GetParameter(1);
dEdXError[11]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[5] = (dEdX[10] + dEdX[11]) / 2;
dEdXErrorLessbin[5] = sqrt( (dEdXError[10]*dEdXError[10])+(dEdXError[11]*dEdXError[11]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton750_800 = (TH1F*)f2->Get("hdatadEdX_750_800");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton750_800->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[12]       = data_gaus->GetParameter(1);
dEdXError[12]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton800_850 = (TH1F*)f2->Get("hdatadEdX_800_850");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton800_850->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[13]       = data_gaus->GetParameter(1);
dEdXError[13]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[6] = (dEdX[12] + dEdX[13]) / 2;
dEdXErrorLessbin[6] = sqrt( (dEdXError[12]*dEdXError[12])+(dEdXError[13]*dEdXError[13]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton850_900 = (TH1F*)f2->Get("hdatadEdX_850_900");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton850_900->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[14]       = data_gaus->GetParameter(1);
dEdXError[14]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *hProton900_950 = (TH1F*)f2->Get("hdatadEdX_900_950");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
hProton900_950->Fit(data_gaus,"R+0LLi","0",2.5, 10.00);

dEdX[15]       = data_gaus->GetParameter(1);
dEdXError[15]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[7] = (dEdX[14] + dEdX[15]) / 2;
dEdXErrorLessbin[7] = sqrt( (dEdXError[14]*dEdXError[14])+(dEdXError[15]*dEdXError[15]));


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
dEdXLessbin[8] = (dEdX[16] + dEdX[17]) / 2;
dEdXErrorLessbin[8] = sqrt( (dEdXError[16]*dEdXError[16])+(dEdXError[17]*dEdXError[17]));

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
dEdXLessbin[9] = (dEdX[18] + dEdX[19] + dEdX[20]) / 3;
dEdXErrorLessbin[9] = sqrt( (dEdXError[18]*dEdXError[18])+(dEdXError[19]*dEdXError[19]) + (dEdXError[20]*dEdXError[20]));


double binXLessbinProton[11] = {200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100};
double binXErrorLessbinProton[11] = {0.};

for(int a = 0; a < 11; a++){binXErrorLessbinProton[a] = 50.;}

const Int_t nproton = 10;

// ### Finely binned Data ###
grprotondata  = new TGraphErrors(nproton,binXLessbinProton,dEdXLessbin,binXErrorLessbinProton,dEdXErrorLessbin);
grprotondata->SetFillColor(kWhite);
grprotondata->SetFillStyle(3005);
grprotondata->SetLineColor(kRed+2);
grprotondata->SetLineWidth(2);


// =================================================================================================================
// =================================================================================================================
// ===================================================================================================================




const Int_t m = 49;


// ### Muon Lines ###
grMuon = new TGraphErrors(m,MuonMomentum,TheorydEdX,MuonMomentumError,TheorydEdXError);
grMuon->SetFillColor(kWhite);
grMuon->SetFillStyle(3005);
grMuon->SetLineColor(kBlue);
grMuon->SetLineWidth(2);

// ### Pion Lines ###
grPion = new TGraphErrors(m,PionMomentum,TheorydEdX,PionMomentumError,TheorydEdXError);
grPion->SetFillColor(kWhite);
grPion->SetFillStyle(3005);
grPion->SetLineColor(kRed);
grPion->SetLineWidth(2);

// ### Proton Lines ###
grProton = new TGraphErrors(m,ProtonMomentum,TheorydEdX,ProtonMomentumError,TheorydEdXError);
grProton->SetFillColor(kWhite);
grProton->SetFillStyle(3005);
grProton->SetLineColor(kPink+5);
grProton->SetLineWidth(2);

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Low bin data");
c01->SetTicks();
c01->SetFillColor(kWhite);

grMuon->Draw("");
grPion->Draw("Csame");
grProton->Draw("Csame");
grPionData->Draw("same");
grprotondata->Draw("same");

// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");

TLegend *leg = new TLegend();
leg = new TLegend(0.48,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I Positive Polarity");
leg->AddEntry(grPionData,"e/#pi/#mu Data");
leg->AddEntry(grprotondata,"Proton Data");
leg->AddEntry(grMuon,"Muon"); 
leg->AddEntry(grPion,"Pion");
leg->AddEntry(grProton,"Proton");
leg->Draw();


}//<---End file
