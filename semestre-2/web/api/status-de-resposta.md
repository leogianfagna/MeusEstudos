# Status de resposta

Existe uma lista de retornos possíveis referentes à status da resposta de uma API. Podemos ver uma lista documentada de cada status [aqui na documentação do Mozilla](https://developer.mozilla.org/pt-BR/docs/Web/HTTP/Status).

## Adicionando status nas respostas

Adicionar o método `status(num)` logo após a resposta. O número já deve ser preenchido com o tipo de status que vai retornar, veja um exemplo de inserção bem sucedida:

```diff
- res.json({message: "Resposta com sucesso!"});
+ res.status(201).json({message: "Resposta com sucesso!"});
```

Agora com os status, podemos colocá-los em diferentes validações, como por exemplo, se algum campo obrigatório do body não foi recebido:

```javascript
if (!name) {
    res.status(422).json({ message: "Campo 'nome' não foi informado." });
    return;
}
```

#### Checando status o Postman

Esses status podem ser conferidos no próprio Postman:

<figure><img src="../../../.gitbook/assets/http status no postman.png" alt=""><figcaption></figcaption></figure>
