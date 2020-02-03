#!/bin/bash

LOGIN=11508363
SYSTEMDIR=/etc
SYSTEMARCHIVE=/root/SystemSave-`hostname`.tar.gz


if [ $# -eq 1 ] ; then
    let UPTIME=`date +%s`-`date +%s -d $1`
else 
    UPTIME=`cat /proc/uptime | cut -d' ' -f1|cut -d'.' -f1`
fi

echo "uptime : $UPTIME"

let UPTIME/=60
let UPTIME+=1

# cp $HOME/.bash_history /tmp/history-`hostname`.txt

echo "uptime : $UPTIME (min)"

tar czvf $SYSTEMARCHIVE `find $SYSTEMDIR  -type f -mmin "-$UPTIME"` /tmp/history-`hostname`.txt

echo "scp $SYSTEMARCHIVE $LOGIN@172.23.0.254:"

scp $SYSTEMARCHIVE $LOGIN@172.23.0.254:

