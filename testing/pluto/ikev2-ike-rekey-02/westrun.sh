ipsec auto --up west
../../guestbin/ping-once.sh --up -I 192.0.1.254 192.0.2.254
ipsec whack --trafficstatus
echo "sleep 50"
sleep 50
../../guestbin/ping-once.sh --up -I 192.0.1.254 192.0.2.254
ipsec whack --trafficstatus
ipsec showstates
echo "sleep 50"
sleep 50
../../guestbin/ping-once.sh --up -I 192.0.1.254 192.0.2.254
echo done
