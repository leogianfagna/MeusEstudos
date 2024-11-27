# Implementação tabela de páginas

Se foi entregue endereços virtuais e queremos saber quais acessos são resolvidos diretamente pela MMU, pelo Sistema Operacional e quais resultam em Page Fault, precisamos seguir essa linha:

1. Dividir o endereço virtual pelo [tamanho da página](#user-content-fn-1)[^1] e assim preencher em qual página está.
2. A partir daqui, passando em cada endereço por vez.
3. Procurar o número da página na TLB[^2]. Caso a página esteja lá, quer dizer que a MMU vai resolver e este endereço virtual está resolvido.
4. Se não está na TLB, devemos seguir para a [tabela de páginas](#user-content-fn-3)[^3]. Ao encontrar a página na tabela, precisamos enviar essa página para a TLB, removendo de lá a página [menos recente utilizada](#user-content-fn-4)[^4].
   1. Na tabela de páginas, se o bit for `1` significa que a página é válida. Pode assinar apenas o sistema operacional como responsável.
   2. Mas se na tabela de páginas o bit for `0`, precisa assinalar também **Page Fault** e fazer algumas modificações na própria tabela de páginas.
      1. Alterar o bit de `0` para `1`.
      2. Alterar o valor do quadro para o [último + 1](#user-content-fn-5)[^5] pois agora ele foi para o próximo quadro disponível.

[^1]: O tamanho da página deve ser informado, como por exemplo `4KB`. Esse valor equivale à `4096`.

[^2]: Uma tabela que precisa ser entregue pelo exercício. Assim como a tabela de páginas.

[^3]: Também uma tabela que deve ser informada pelo exercício.

[^4]: Baseado em LRU.

[^5]: Ver na **tabela de páginas inteira** qual é o maior quadro. Se o maior de todos os quadros for 16, então alterar o valor para 17.
