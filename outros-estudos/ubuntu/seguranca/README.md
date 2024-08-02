# Segurança

As logs do sistema podem identificar problemas na segurança da máquina, como tentativas de login ou outras linhas de registros do tipo WARN ou ERROR. As logs podem acessadas usando:

```bash
sudo tail -n 100 /var/log/syslog
```

```bash
sudo tail -n 100 /var/log/auth.log
```

A primeira irá mostrar as mensagens do sistema enquanto a segunda de autenticações. Vejamos os seguintes possíveis problemas em situações reais:

#### Autenticação

<figure><img src="../../../.gitbook/assets/logs de autenticação ubuntu.png" alt=""><figcaption></figcaption></figure>

Através dessas logs, parece que o servidor está sofrendo uma série de tentativas de login não autorizadas via SSH, o que pode ser uma forma de ataque de força bruta. Isso pode contribuir para o desempenho lento e os problemas de conexão. Para resolver esse problema, podemos tomar várias medidas de segurança:

* Bloquear IPS suspeitos
