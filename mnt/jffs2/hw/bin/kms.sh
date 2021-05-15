#!/bin/sh

#sleep 70 

#  kms  
iptables -I INPUT -s 192.168.1.1/24 -p tcp --dport 1688 -j ACCEPT
/mnt/jffs2/app/bin/vlmcsd -i /mnt/jffs2/hw/etc/vlmcsd.ini -l /tmp/kms.log -p /var/run/vlmcsd.pid -L 0.0.0.0:1688

exit 0;
