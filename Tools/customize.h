#ifndef ANACONST_CUSTOMIZE_H
#define ANACONST_CUSTOMIZE_H

#include "TFile.h"
#include "TTree.h"
#include "TChain.h"
#include "TLorentzVector.h"
#include "Math/VectorUtil.h"

#include <iostream>
#include <cstdio>
#include <string>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <string>
/*
   This file is used to customize the NTupleReader and the flat ntuples for our baseline and search region definitions.
   Currently these include jet pt, eta requirements for counting, functions to calculate nJets, nbJets, deltaphi, and so on.
   The functions here have nothing to do with NTupleReader so that can be used in other cases independent of the reader.
   An example baseline cut flow is defined in a separate code, i.e., baselineDef.C.
*/

namespace AnaConsts
{    
  struct AccRec
  {
    double minAbsEta, maxAbsEta, minPt, maxPt;
  };

  struct MuIsoAccRec
  {
    float minAbsEta, maxAbsEta, minPt, maxPt;
  };

  struct ElIsoAccRec
  {
    float minAbsEta, maxAbsEta, minPt, maxPt;
  };
  const float defaultMETcut = 25.0;
  const float minMtW = 50.0, maxMtW = 250.0;
  const int nMusSel = 1, nElsSel = 1;

  const int nJetsSel = 4, nJetsSelPt30Eta24 = 4, nJetsSelPt50Eta24 = 2, nJetsSelPt70Eta24 = 2;
  //[low_nJetsSelBtagged, high_nJetsSelBtagged)
  const int low_nJetsSelBtagged = 1, high_nJetsSelBtagged = -1;
  //[low_nTopCandSortedSel, high_nTopCandSortedSel)
  const int low_nTopCandSortedSel = 1, high_nTopCandSortedSel = -1;
  const double minJetPt = 30;
  //                               minAbsEta, maxAbsEta, minPt, maxPt
  const AccRec      pt30Arr = {   -1,        -1,      30,    -1  };
  const AccRec pt30Eta24Arr = {   -1,       2.4,      30,    -1  };
  const AccRec pt50Eta24Arr = {   -1,       2.4,      50,    -1  };
  const AccRec      dphiArr = {   -1,       4.7,      30,    -1  };
  const AccRec     dphiNArr = {   -1,       2.4,      30,    -1  };
  const AccRec      bTagArr = {   -1,       2.4,      30,    -1  };
  const AccRec pt20Eta25Arr = {   -1,       2.5,      20,    -1  };

  //const double cutCSVS = 0.814, cutCSVSold = 0.679; // for T5tttt signals, currently old b-tagging was used
  //Note the new working points are for Spring15 samples & data: cutCSVS is the medium working point
  //According to https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation80X, the CSVv2M cut is 0.800
  const double cutCSVS = 0.8484, cutCSVL = 0.5426, cutCSVT = 0.9535, cutCSVSold = 0.800; // old is for ICHEP working point

  //                           minAbsEta, maxAbsEta, minPt, maxPt
  const MuIsoAccRec musArr = {   -1,       2.4,      25,     -1   };

  //                           minAbsEta, maxAbsEta, minPt, maxPt
  const ElIsoAccRec elsArr = {   -1,       2.5,      30,     -1,  };

  const double dPhi0_CUT = 0.5, dPhi1_CUT = 0.5, dPhi2_CUT = 0.3;

  const double MT2cut_ = 300, mTcombcut_ = 500;

  static std::set<std::string> activatedBranchNames_DataOnly = 
  { 
    "run", "lumi", "event", "evtWeight", 
    "jetsLVec", "recoJetsBtag_0", "muMatchedJetIdx", "eleMatchedJetIdx", "looseisoTrksMatchedJetIdx", "trksForIsoVetoMatchedJetIdx",
    "recoJetsJecUnc", "recoJetsJecScaleRawToFull",
    "muonsLVec", "muonsMtw", "muonsRelIso", "muonsMiniIso", "muonsFlagMedium", "muonsFlagTight", "muonspfActivity",
    "elesLVec", "elesMtw", "elesRelIso", "elesMiniIso", "elesisEB", "elesFlagVeto", "elesFlagMedium", "elespfActivity",
    "loose_isoTrksLVec", "loose_isoTrks_iso", "loose_isoTrks_mtw", "loose_isoTrks_pdgId",
    "met", "metphi", 
    "tru_npv", "vtxSize",
    "recoJetsBtag_0_LepCleaned", "jetsLVecLepCleaned",
    "recoJetschargedEmEnergyFraction", "recoJetsneutralEmEnergyFraction", "recoJetschargedHadronEnergyFraction", "recoJetsmuonEnergyFraction",
    //"looseJetID", "tightJetID", "looseJetID_NoLep", "tightJetID_NoLep", "CSCTightHaloFilter", "EcalDeadCellTriggerPrimitiveFilter", "HBHENoiseFilter", "HBHEIsoNoiseFilter",
    "looseJetID", "tightJetID", "looseJetID_NoLep", "tightJetID_NoLep", "EcalDeadCellTriggerPrimitiveFilter", "HBHENoiseFilter", "HBHEIsoNoiseFilter", "goodVerticesFilter", "eeBadScFilter", "eeBadScListFilter", "CSCTightHaloListFilter", "badResolutionTrackListFilter", "muonBadTrackListFilter",
    "TriggerNames", "PassTrigger", "TriggerPrescales", 
    "stored_weight",
    "globalTightHalo2016Filter", "BadChargedCandidateFilter", "BadPFMuonFilter",
    "calomet"
  };

  static std::set<std::string> activatedBranchNames = 
  {
    // Only exist in MC samples
    "genDecayIdxVec", "genDecayLVec", "genDecayMomIdxVec", "genDecayPdgIdVec", "genDecayStrVec", "genDecayMomRefVec",
    "W_emuVec", "W_tau_emuVec", "W_tau_prongsVec", "W_tau_nuVec",
    "genHT", "PDFweights", "PDFids",
    "id1", "id2", "x1", "x2", "q",
    "W_emu_pfActivityVec", "W_tau_emu_pfActivityVec", "W_tau_prongs_pfActivityVec", "ScaleWeightsMiniAOD",
    "recoJetsJecUncLepCleaned", "metMagUp", "metMagDown", "metPhiUp", "metPhiDown",
    "SusyMotherMass", "SusyLSPMass", "recoJetsFlavor",
    "genjetsLVec", "genmet", "genmetphi",
    "NJetsISR",
    "specialFixtype", "specialFixMuonsCharge", "specialFixMuonsLVec"
  };
}

namespace AnaFunctions
{
  bool jetPassCuts(const TLorentzVector& jet, const AnaConsts::AccRec& jetCutsArr);
  int countJets(const std::vector<TLorentzVector> &inputJets, const AnaConsts::AccRec& jetCutsArr);
  int countCSVS(const std::vector<TLorentzVector> &inputJets, const std::vector<double> &inputCSVS, const double cutCSVS, const AnaConsts::AccRec& jetCutsArr);
  std::vector<double> calcDPhi(const std::vector<TLorentzVector> &inputJets, const double metphi, const int nDPhi, const AnaConsts::AccRec& jetCutsArr);
  double calcDeltaT(unsigned int pickedJetIdx, const std::vector<TLorentzVector> &inputJets, const AnaConsts::AccRec& jetCutsArr);
  std::vector<double> calcDPhiN(const std::vector<TLorentzVector> &inputJets, const TLorentzVector &metLVec, const int nDPhi, const AnaConsts::AccRec& jetCutsArr);
  
  //muon
  bool passMu(const TLorentzVector& muLvec, bool passId, bool passIso, const AnaConsts::MuIsoAccRec& musArr);
  int countMus(const std::vector<TLorentzVector> &muLvecVec, const std::vector<bool> &passmuId, const std::vector<bool> &passmuIso, const AnaConsts::MuIsoAccRec& musArr);
  
  //electron
  bool passEl(const TLorentzVector& elLvec, bool passId, bool passIso, const AnaConsts::ElIsoAccRec& elsArr);
  int countEls(const std::vector<TLorentzVector> &elLvecVec, const std::vector<bool> &passelId, const std::vector<bool> &passelIso, const AnaConsts::ElIsoAccRec& elsArr);
  
  void preparecntNJets(const std::vector<TLorentzVector> &inijetsLVec, const std::vector<double> &inirecoJetsBtag, const double cutCSVS, std::vector<int> &cntNJetsVec, std::vector<int> &cntNbJetsVec);
  void preparecalcDPhi(const std::vector<TLorentzVector> &inijetsLVec, const double metphi, std::vector<double> &outDPhiVec);
  void prepareForNtupleReader();
  double calcHT(const std::vector<TLorentzVector> &inputJets, const AnaConsts::AccRec& jetCutsArr);
  bool passBaseline();
  int jetLepdRMatch(const TLorentzVector& lep, const std::vector<TLorentzVector>& jetsLVec, const double jldRMax);
  TLorentzVector calcMHT(const std::vector<TLorentzVector> &inputJets, const AnaConsts::AccRec& jetCutsArr);
}

#endif
