import FWCore.ParameterSet.Config as cms
process = cms.Process('NANO')

process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load('Configuration.StandardSequences.Services_cff')
from Configuration.AlCa.autoCond import autoCond

process.options = cms.untracked.PSet(wantSummary = cms.untracked.bool(True))
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10000))

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring())
process.source.fileNames = [
	'/store/data/Run2017C/MET/MINIAOD/PromptReco-v3/000/301/998/00000/881E5BD6-B48E-E711-A0A9-02163E011D56.root',
]

process.load("PhysicsTools.NanoAOD.nano_cff")
from PhysicsTools.NanoAOD.nano_cff import nanoAOD_customizeData
process = nanoAOD_customizeData(process)
process.GlobalTag.globaltag = autoCond['run2_data']

process.out = cms.OutputModule("NanoAODOutputModule",
    fileName = cms.untracked.string('nano.root'),
    outputCommands = process.NanoAODEDMEventContent.outputCommands,
    compressionLevel = cms.untracked.int32(9),
    #compressionAlgorithm = cms.untracked.string("LZMA"),
)

process.end = cms.EndPath(process.out)
