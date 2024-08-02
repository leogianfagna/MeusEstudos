# Bloquear IPs

Use o `iptables` para bloquear os IPs suspeitos (por exemplo, 218.92.0.123 e 218.92.0.76).

```sh
sudo iptables -A INPUT -s 218.92.0.123 -j DROP
sudo iptables -A INPUT -s 218.92.0.76 -j DROP
```

