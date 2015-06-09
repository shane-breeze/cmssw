#ifndef __l1t_gmt_internal_muon_h__
#define __l1t_gmt_internal_muon_h__

#include "DataFormats/L1TMuon/interface/L1TRegionalMuonCandidate.h"
#include <utility>

namespace l1t {
class L1TGMTInternalMuon : public L1TRegionalMuonCandidate {
  public:
    explicit L1TGMTInternalMuon(const L1TRegionalMuonCandidate& regional);
    L1TGMTInternalMuon(const L1TGMTInternalMuon&);

    virtual ~L1TGMTInternalMuon() {};

    void setHwCancelBit(int bit) { m_hwCancelBit = bit; };
    void setHwRank(int bits) { m_hwRank = bits; };
    void setHwWins(int wins) { m_hwWins = wins; };
    void increaseWins() { m_hwWins++; };
    void setHwIsoSum(int isosum) { m_hwIsoSum = isosum; };
    void setHwAbsIso(int iso) { m_hwAbsIso = iso; };
    void setHwRelIso(int iso) { m_hwRelIso = iso; };
    void setExtrapolation(int deta, int dphi) { m_hwDeltaEta = deta; m_hwDeltaPhi = dphi; };
    void setHwCaloEta(int idx) { hwCaloIndex_.second = idx; };
    void setHwCaloPhi(int idx) { hwCaloIndex_.first = idx; };

    const int hwCancelBit() const { return m_hwCancelBit; };
    const int hwRank() const { return m_hwRank; };
    const int hwWins() const { return m_hwWins; };
    const int hwIsoSum() const { return m_hwIsoSum; };
    const int hwDEta() const { return m_hwDeltaEta; };
    const int hwDPhi() const { return m_hwDeltaPhi; };
    const int hwAbsIso() const { return m_hwAbsIso; };
    const int hwRelIso() const { return m_hwRelIso; };
    const int hwCaloEta() const { return hwCaloIndex_.second; };
    const int hwCaloPhi() const { return hwCaloIndex_.first; };

    const L1TRegionalMuonCandidate& origin() const { return *m_regional; };
    
    inline const int hwPt() const { return m_regional->hwPt(); };
    inline const int hwPhi() const { return m_regional->hwPhi(); };
    inline const int hwEta() const { return m_regional->hwEta(); };
    inline const int hwSign() const { return m_regional->hwSign(); };
    inline const int hwSignValid() const { return m_regional->hwSignValid(); };
    inline const int hwQual() const { return m_regional->hwQual(); };
    inline const int hwTrackAddress() const { return m_regional->hwTrackAddress(); };
    inline const int processor() const { return m_regional->processor(); };
    inline const tftype trackFinderType() const { return m_regional->trackFinderType(); };
    inline const int link() const { return m_regional->link(); }

  private:
    L1TGMTInternalMuon();
    
    const L1TRegionalMuonCandidate* m_regional;
    int m_hwRank;
    int m_hwCancelBit;
    int m_hwWins;
    int m_hwIsoSum;
    int m_hwDeltaEta;
    int m_hwDeltaPhi;
    int m_hwAbsIso;
    int m_hwRelIso;
    std::pair<int, int> hwCaloIndex_;
};

} // namespace l1t

#endif /* define __l1t_gmt_internal_muon_h__ */