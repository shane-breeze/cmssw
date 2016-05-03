#include "FWCore/Framework/interface/ConsumesCollector.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "EMTFTokens.h"

namespace l1t {
  namespace stage2 {
    EMTFTokens::EMTFTokens(const edm::ParameterSet& cfg, edm::ConsumesCollector& cc) 
    {
      // std::cout << "Inside EMTFTokens.cc: EMTFTokens" << std::endl;
      auto tag = cfg.getParameter<edm::InputTag>("InputLabel");

      regionalMuonCandToken_ = cc.consumes<RegionalMuonCandBxCollection>(tag);
      EMTFOutputToken_   = cc.consumes<EMTFOutputCollection>(tag);
      EMTFHitToken_   = cc.consumes<EMTFHitCollection>(tag);
      EMTFTrackToken_   = cc.consumes<EMTFTrackCollection>(tag);
    }
  }
}
