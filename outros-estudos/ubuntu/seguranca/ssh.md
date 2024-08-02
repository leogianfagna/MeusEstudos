# SSH

Secure Shell é um protocolo de rede criptográfico usado para operar serviços de rede de forma segura sobre uma rede não segura. O SSH é amplamente utilizado para acessar e gerenciar remotamente sistemas e servidores, oferecendo uma conexão segura e criptografada para transferir dados entre o cliente e o servidor.

## **Como SSH se encaixa na sua situação:**

1. **Acesso Remoto Seguro:**
   * O SSH permite que você se conecte ao seu servidor remotamente e execute comandos como se estivesse fisicamente presente na máquina.
   * Isso é crucial para a administração de servidores, pois permite gerenciar o servidor de qualquer lugar.
2. **Tentativas de Acesso Malicioso:**
   * Nos logs que você forneceu, há muitas tentativas falhas de login via SSH para o usuário root vindas de endereços IP desconhecidos (218.92.0.123 e 218.92.0.76).
   * Essas tentativas de login repetidas são típicas de ataques de força bruta, onde um atacante tenta adivinhar a senha do root para obter acesso não autorizado ao servidor.

## **Medidas de Segurança para SSH:**

1. **Desabilitar Login como Root:**
   * Para aumentar a segurança, é recomendável desativar o login direto como root e usar um usuário regular com privilégios de sudo.
2. **Autenticação por Chave SSH:**
   * Em vez de usar senhas, você pode configurar a autenticação por chave SSH, onde uma chave pública é armazenada no servidor e a chave privada é mantida segura no cliente.
   * Isso dificulta muito os ataques de força bruta, pois a chave privada é necessária para autenticar.
3. **Configurar Fail2Ban:**
   * O `fail2ban` é uma ferramenta que monitora os logs de autenticação e bane automaticamente endereços IP que fazem muitas tentativas falhas de login em um curto período de tempo.
4. **Mudar a Porta SSH Padrão:**
   * A porta padrão do SSH é a 22. Mudá-la para uma porta diferente pode ajudar a evitar ataques automatizados que visam a porta padrão.
5. **Firewall:**
   * Configurar regras de firewall para limitar o acesso SSH apenas a endereços IP confiáveis.
