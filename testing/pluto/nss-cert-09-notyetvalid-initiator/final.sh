# will only show up on east - note "expired" is wrong and should be "not yet valid"
grep "ERROR" /tmp/pluto.log
if [ -f /sbin/ausearch ]; then ausearch -r -m avc -ts recent ; fi
