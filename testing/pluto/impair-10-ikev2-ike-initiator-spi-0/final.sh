grep 'dropping packet' /tmp/pluto.log
if [ -f /sbin/ausearch ]; then ausearch -r -m avc -ts recent ; fi
