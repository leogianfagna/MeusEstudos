# Android Studio

## Criando um projeto no Android Studio

Em aula, foi criado um projeto usando a plataforma Android Studio com a base "<mark style="color:blue;">**Basic Views Activity**</mark>”. Na criação do projeto, usou-se de exemplo “com.nintendo.superarmario” para o nome do pacote. Chamou uma empresa fictícia de Nintendo.

#### Como usar o controle de versões Git no Android Studio

1. Mudar perspectiva de Android para projeto
2. Navegar para VCS na barra em cima
3. Habilitar primeira opção Enable version control integration
4. Selecionar a opção GitHub

Logo após isso dá para ver que os códigos estão em vermelho. Isso quer dizer que eles não estão versionados. Isso pode ser traduzido para o commit. O commit é diferente do push, no qual o <mark style="color:orange;">**commit é algo local**</mark> e o push envia para o repositório remoto.

1. Botão direito no nome do projeto
2. Vai em git e em add
3. Depois git novamente e em commit
4. Assim, criar um repositório no GitHub para copiarmos o endereço do repositório
5. Voltando no Studio, no branch “origin”, adicionar o URL do repositório

O <mark style="color:orange;">**ramo principal**</mark> é no origin. Quando está trabalhando em algo, cria-se um ramo e você trabalha nesse ramo, depois disso junta ao principal. Fazer isso para cada tipo de trabalho.

### Escolha de versão no Android

O sistema da Android é aberto e por isso muita gente consegue mexer e criar sua versão. Por conta disso, na hora de programar tem que lidar com versões diferentes de builds, e isso é muito ruim (péssima qualidade).

Falando em códigos, existem muitas variações grotescas de telas, abres diversas condições baseado na versão do celular da pessoa. Algo que não acontece no iOS, já que o sistema é fechado e não é permitido isso, deixando um código muito mais bonito e leve.

### Conceitos para projetos

* VCs: Version Control System. Você pode pegar um projeto já pronto de um controle de versão, como ficando no GitHub.
* SDK: conjunto de pacotes do Android, usados para desenvolver o projeto. Vários componentes já estão incluídos, como botões.



### Pacotes

Todos os recursos estão em pacotes de classes/código. Ao falar que criou um pacote significa que você pode reusar em um projeto. Ele tem a ideia de componente. Esses pacotes são dirigidos a uma empresa, usando a nomenclatura:

<figure><img src="../../.gitbook/assets/image (12).png" alt=""><figcaption></figcaption></figure>

Usando um exemplo metafórico seria a separação de ferramentas por propósito, por exemplo, uma caixa apenas com ferramentas para furar, com várias delas ali dentro.
