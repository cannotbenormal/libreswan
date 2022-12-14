/testing/guestbin/swan-prep --x509
crlutil -I -i /testing/x509/crls/needupdate.crl -d sql:/etc/ipsec.d
certutil -d sql:/etc/ipsec.d -D -n west
# ipsec start
ipsec pluto --config /etc/ipsec.conf --leak-detective --impair event-check-crls
../../guestbin/wait-until-pluto-started
ipsec auto --add nss-cert-crl
ipsec auto --status |grep nss-cert-crl
ipsec auto --listcrls
echo "initdone"
