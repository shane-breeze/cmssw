
from PhysicsTools.Heppy.analyzers.core.Analyzer import Analyzer
from PhysicsTools.HeppyCore.utils.deltar import deltaPhi
from math import atan2

##__________________________________________________________________||
class BiasedDPhiAnalyzer( Analyzer ):
    def process(self, event):
        self.readCollections( event.input )

        jets = getattr(event, self.cfg_ana.jets)

        if self.cfg_ana.jetSelectionFunc is not None:
            jets = [j for j in jets if self.cfg_ana.jetSelectionFunc(j)]

        biasedDPhi, biasedDPhiJet = self.makeBiasedDPhi(event, jets)

        setattr(event, self.cfg_ana.biasedDPhi, biasedDPhi)

        if self.cfg_ana.biasedDPhiJet is not None:
            setattr(event, self.cfg_ana.biasedDPhiJet, biasedDPhiJet)

        return True

    def makeBiasedDPhi(self, event, jets):

        if len(jets) < 2: return -1, [ ]

        mht_x = -sum([j.px() for j in jets])
        mht_y = -sum([j.py() for j in jets])

        biasedDPhis = [abs(deltaPhi(atan2(mht_y + j.py(), mht_x + j.px()), j.phi())) for j in jets]
        # the list of deltaPhis between the jet and MHT without the jet for each jet
        # e.g., [0.190480, 0.0787271, 0.156339, 0.284583]

        theBiasedDPhi = min(biasedDPhis)
        # the biasedDPhi is the minumum value of the list

        theJet = jets[biasedDPhis.index(theBiasedDPhi)]
        # the jet that gives the minimum value

        return theBiasedDPhi, [theJet]

##__________________________________________________________________||
