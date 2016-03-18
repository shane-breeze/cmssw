#!/bin/bash

##__________________________________________________________________||
updir=$(dirname $(pwd))

if [ ! -f ${updir}/cmssw.tar.gz ]; then
    tmp_in_dir=`mktemp -d 2>/dev/null || mktemp -d -t 'tmp'`
    pushd $CMSSW_BASE
    tar --exclude=.git -czf ${tmp_in_dir}/cmssw.tar.gz *
    # tar --exclude=.git -czf ${tmp_in_dir}/cmssw.tar.gz $(GLOBIGNORE=.:..; echo  *)
    mv ${tmp_in_dir}/cmssw.tar.gz ${updir}
    rmdir ${tmp_in_dir}
    popd
fi
transfer_input_files=${updir}/cmssw.tar.gz

if [ -d ${HOME}/.cmgdataset ]; then
    if [ ! -f ${updir}/cmgdataset.tar.gz ]; then
	pushd $HOME
	tar -czf ${updir}/cmgdataset.tar.gz .cmgdataset
	popd
    fi
    transfer_input_files=${transfer_input_files},${updir}/cmgdataset.tar.gz
fi

tar -czf chunk.tar.gz *
transfer_input_files=${transfer_input_files},chunk.tar.gz

scriptName=${1:-./batchScript.sh}

##__________________________________________________________________||
cat > ./job_desc.cfg <<EOF
Universe = vanilla
Executable = ${scriptName}
use_x509userproxy = true
Log        = condor_job_\$(Process).log
Output     = condor_job_\$(Process).out
Error      = condor_job_\$(Process).error
should_transfer_files   = YES 
when_to_transfer_output = ON_EXIT
transfer_input_files=${transfer_input_files}
request_disk = 160000
request_memory = 900
queue 1
EOF

##__________________________________________________________________||
/condor/bin/condor_submit job_desc.cfg
