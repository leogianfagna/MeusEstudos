# Forks

## Padrão para fazer PRs

A abordagem padrão e recomendada ao trabalhar com forks no GitHub é sempre criar um PR a partir de um **branch separado**, e nunca direto do `master/main` do fork. Primeiro passo é [atualizar o fork](#user-content-fn-1)[^1].

```bash
git checkout -b nova-feature
```

Depois faça o push dos commits nesta branch, abra um PR que envia essas features para o <mark style="color:orange;">repositório original</mark>. Quando aprovado, **sincronize o repositório, delete a branch e refaça o processo**.

## Sincronização do fork com o repositório principal

Abordagens para deixar o fork sincronizado, principalmente <mark style="color:blue;">após enviar uma PR</mark> e ela ser aceita.

### Abordagem padrão (sem resetar)

```bash
git fetch upstream
git checkout master
git merge upstream/master
git push origin master
```

### Resolver histórico bagunçado

Se o histórico ficou bagunçado por algum motivo, podemos sincronizar ele com comandos:

```bash
git remote add upstream 'link do repositório'
git fetch upstream
git checkout master
git reset --hard upstream/master
git push origin master --force
```

[^1]: Veja os passos de sincronização no próximo tópico.
