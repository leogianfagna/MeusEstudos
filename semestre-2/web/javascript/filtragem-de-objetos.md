# Filtragem de objetos

## Acessar elementos

Suponha que temos um objeto com vários campos, o acesso de um elemento desse objeto pode ser dado usando dot notation ou chaves.

O acesso a elementos é o procedimento básico de um objeto. Quando temos uma grande quantidade de objetos, precisamos filtrá-los antes de acessar, mostrado nas seções a seguir.

```javascript
const objeto = {
    plugin: "Core",
    version: 1.5,
    lastUpdate: "03/05/2025"
}
```

### Notação de pontos

É a forma simples de encontrar um campo de um objeto, onde escrevemos de <mark style="color:blue;">forma rígida</mark> o nome do campo que queremos, como:

```javascript
const campoObjeto = objeto.version; // 1.5
```

### Chaves

É usado quando queremos fazer o mesmo acesso acima, mas em vez de usar de forma rígida, usar o <mark style="color:blue;">nome de uma variável para encontrar o campo</mark>.

```javascript
const filtro = "version";
const campoObjeto = objeto[filtro]; // 1.55
```

### Campos dentro de campos

Basta apenas repetir os pontos, como se fosse um caminho para chegar até onde quiser. <mark style="color:green;">Pode alternar entre pontos e chaves</mark>.

```javascript
const empresa = {
  nome: "TechCorp",
  endereco: {
    cidade: "São Paulo",
    rua: {
      nome: "Rua Azul",
      numero: 100,
    },
  },
};

const campo = "endereco";
const tipo = "rua";
const result = "nome";

// Pode alternar, qualquer maneira está correto
nomeDaRua = empresa[campo][tipo][result];
nomeDaRua = empresa.endereco.rua.nome;

nomeDaRua = empresa.endereco[tipo].nome;
nomeDaRua = empresa[campo][tipo].nome;
```

## Encontrar elementos

Agora, <mark style="color:blue;">temos um valor e queremos encontrar os campos</mark> em que ele aparece. Isso pode ser útil quando temos vários dados salvos em um campo e queremos encontrar todos esses dados através apenas de um único deles, por exemplo: **Quais são os alunos da sala em que o Aluno 11 está?**

```javascript
const salas = {
  100: ["Aluno 01", "Aluno 02"],
  101: ["Aluno 06", "Aluno 11"],
  102: ["Aluno 13", "Aluno 15"]
};
```

Como agora estamos buscando por campos, usamos a propriedade `entries` da classe objeto para percorrer, depois podemos verificar com `includes` se o aluno procurado está lá.

Este algoritmo não passa de uma <mark style="color:green;">repetição que itera os campos e busca o resultado dentro de cada um deles</mark>. Isso quer dizer que, se tivemos mais objetos dentro de objetos, é uma repetição dentro de outra repetição, como se fosse uma matriz e assim sucessivamente.&#x20;

```javascript
function encontrarSalaPorAluno(nomeAluno) {
  for (const [sala, alunos] of Object.entries(salas)) {
    if (alunos.includes(nomeAluno)) {
      return sala;
    }
  }
  return null;
}

const salaDoAluno = encontrarSalaPorAluno("Aluno 11");
const alunosDestaSala = salas[salaDoAluno];
```

<details>

<summary>Exemplo sem conhecer os campos</summary>

Veja que acima mencionamos os nomes dos campos. Se nós não soubermos, precisamos fazer como busca recursiva (pois não sabemos quantos objetos há dentro de outros objetos). Esse exemplo resulta em:

```javascript
function buscarAluno(obj, alvo, caminho = []) {
  let resultados = [];

  if (Array.isArray(obj)) {
    if (obj.includes(alvo)) {
      resultados.push(caminho.join("."));
    }
  } else if (typeof obj === "object" && obj !== null) {
    for (const chave in obj) {
      const novosResultados = buscarAluno(
        obj[chave], alvo, [...caminho, chave]
      );
      resultados.push(...novosResultados);
    }
  }

  return resultados;
}
```

</details>

## Buscar campos em profundidade

Em um <mark style="color:green;">longo objeto</mark> (normalmente estão em JSON), quando há campos dentro de campos e não sabemos onde está o que queremos, podemos usar uma recursão para percorrer e encontrar o valor do campo encontrado:

```javascript
function buscarRecursivo(obj, chaveDesejada) {
  if (typeof obj !== 'object' || obj === null) return null;

  if (obj.hasOwnProperty(chaveDesejada)) {
    return obj[chaveDesejada];
  }

  for (const chave in obj) {
    const resultado = buscarRecursivo(obj[chave], chaveDesejada);
    if (resultado !== null) return resultado;
  }

  return null;
}

const resultadoCampo = buscarRecursivo(objeto, "valorComprimento");
```

## Filtrar objetos

Consiste em retornar os objetos desejados a partir de um filtro. O método mais comum é usando find quando temos um array de objetos, que já foi explicado em [array functions](metodos-arrays.md).

```javascript
const objetoEncontrado = array.find((obj) => obj.name === "Core");
```

Isso vai retornar o **objeto inteiro**, cujo o campo nome dentro dele seja equivalente à Core.&#x20;
