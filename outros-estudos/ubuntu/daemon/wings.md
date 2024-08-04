# Wings

É o componente do daemon do painel de controle Pterodactyl, que é uma solução popular de gerenciamento de servidores de jogos. O Pterodactyl é amplamente utilizado para gerenciar servidores de jogos, como Minecraft, fornecendo uma interface de usuário amigável e um sistema de automação robusto para gerenciar os servidores de jogo em diversas instâncias. Aqui estão alguns detalhes principais sobre o Wings:

#### Funções Principais

1. **Gerenciamento de Contêineres**: O Wings utiliza o Docker para criar contêineres para cada servidor de jogos. Isso isola cada servidor, permitindo uma gestão segura e eficiente dos recursos e facilitando a instalação e manutenção de diferentes jogos ou versões de jogos em um único servidor físico.
2. **Automatização de Tarefas**: O daemon automatiza várias tarefas administrativas, como a instalação de atualizações de software, configuração de servidores, e backup e restauração de dados de jogo.
3. **Monitoramento de Recursos**: Ele monitora o uso de recursos (como CPU, memória e armazenamento) pelos servidores de jogos, permitindo ajustes para otimizar o desempenho e a estabilidade.
4. **Interação com o Painel Web**: O Wings se comunica com o painel web do Pterodactyl, que é a interface onde os administradores e usuários podem gerenciar seus servidores. Ele recebe comandos do painel e envia atualizações sobre o estado dos servidores.

#### Vantagens

* **Isolamento e Segurança**: Por usar Docker, cada servidor de jogo opera em seu próprio ambiente isolado, o que aumenta a segurança e reduz o risco de um servidor afetar outros.
* **Interface Amigável**: Facilita a gestão de servidores de jogos para usuários sem profundo conhecimento técnico em administração de sistemas.
* **Flexibilidade**: Suporta uma ampla variedade de jogos e pode ser configurado para atender a necessidades específicas, como diferentes configurações de hardware ou software.

#### Instalação e Configuração

O Wings é instalado em um servidor e configurado para comunicar-se com o painel web do Pterodactyl. A instalação geralmente envolve configurar o Docker, baixar o binário do Wings, configurar permissões adequadas e ajustar o sistema operacional para iniciar o daemon automaticamente.

Em resumo, o Wings é uma peça fundamental do ecossistema Pterodactyl, fornecendo as funcionalidades necessárias para a execução eficiente e segura de servidores de jogos em um ambiente controlado e gerenciável.
