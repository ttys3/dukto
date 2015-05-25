# dukto
Dukto project from sf: http://sourceforge.net/p/dukto/

## firewall rules

dukto uses **TCP** or **UDP** port **4644** for receiving a message. so ,be aware to open 4644 to everybody on the LAN.
if you don't do so, you'll not be able to see any other buddies on the LAN.

for example, shorewall
```bash
cd /etc/shorewall
vim rules
```
add the following lines:

```ini
#dukto r6
ACCEPT          net             $FW             tcp             4644
ACCEPT          net             $FW             udp             4644
```
then, sudo sytemctl restart shorewall

iptables directly :

```bash
/sbin/iptables -I INPUT -p tcp --dport 4644 -j ACCEPT 
/sbin/iptables -I INPUT -p udp --dport 4644 -j ACCEPT 
```
windows or mac ox user plz just do the same job as above.

document created by [荒野无灯](http://ihacklog.com) @ 2015-05-25
thanks to [colomboe](http://sourceforge.net/u/colomboe/) for bringing us this wonderful software!

---EOF
