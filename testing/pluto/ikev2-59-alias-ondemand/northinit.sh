/testing/guestbin/swan-prep
rm -fr /var/run/pluto/pluto.pid
PLUTO_CRYPTO_HELPER_DELAY=1 /usr/local/libexec/ipsec/pluto --config /etc/ipsec.conf
../../guestbin/wait-until-pluto-started
echo "initdone"
