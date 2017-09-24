from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'nano'
config.General.workArea = 'crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'nano_cfg.py'

config.Data.inputDataset = '/MET/Run2017C-PromptReco-v3/MINIAOD'
config.Data.inputDBS = 'global'
config.Data.splitting = 'EventAwareLumiBased'
config.Data.unitsPerJob = 100000
config.Data.totalUnits = -1
config.Data.outLFNDirBase = '/store/user/%s/NanoTest/' % (getUsernameFromSiteDB())
config.Data.publication = True
config.Data.outputDatasetTag = 'NanoTest'

config.Site.storageSite = 'T2_London_UK_IC'
