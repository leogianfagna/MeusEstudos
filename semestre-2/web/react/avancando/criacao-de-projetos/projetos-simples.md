# Projetos simples

#### Importações de variáveis

Importou um objeto de um outro arquivo, no caso as palavras usando:

```jsx
import { words } from './src/data/word'
```

#### Criação de variáveis usáveis

Acima da função principal App(), ele cria as variáveis que serão usadas. No caso, ele criou um objeto `{id,status}` que simboliza as fazes do jogo. Essa variável pode ser modificada pois foi atrelada a um useState.

Todas as variáveis foram criadas no App e atreladas a estados para serem alteradas. Essas variáveis são passadas para os componentes com props (uma por uma) para serem consumidas.

#### Variáveis escopadas

Diferentemente como feito acima, dentro de cada componente existe também a criação de variáveis que são usadas temporariamente para algo. Por exemplo, no componente Game tem uma variável letra que é só usada para definir as letras digitadas.

```jsx
const [letter, setLetter] = setState("");

return (
  <form onSubmit={handleSubmit}> // handleSubmit também é criado apenas no componente
    <input value={letter} onChange={(e) => setLetter(e.input.value)}></input>
  </form>
)
```

#### Alteração de variáveis com base no estado anterior

Se o valor da variável atual conta, por exemplo, queremos diminuir 1, precisamos fazer a lógica do [previous state](../hooks.md#estado-anterior), que muda o estado com arrow function:

<pre class="language-jsx"><code class="lang-jsx">const handleSubmit = () => {
<strong>    setGuesses((guesses) => guesses - 1);
</strong>}
</code></pre>

#### Componentes baseado em condições

Os componentes são mostrados baseado na fase do jogo. Então se a fase (simbolizado pela variável `stages.name` for "start", ele mostra o componente relacionado à ele.

```jsx
const [gameStage, setGameStage] = useState(stages[0].name);

return (
    <div className="app">
        {gameStage === 'start' && <StartComponent />}
        {gameStage === 'game' && <GameComponent />}
        {gameStage === 'end' && <EndComponent />}
    </div>
);
```

#### Funções

Criamos funções acima do return. Cada função tem suas responsabilidades e também pode ser responsável por alterar o estado das condições vista acima. A função é passada para o componente para ser usada livremente lá dentro.

```jsx
// App.jsx
const startGame = () => {
    setGameStage(stages[1].name);
};

return (
    <div className="app">
        // Passa a função aqui
        {gameStage === 'start' && <StartComponent startGame={startGame} />}
        {gameStage === 'game' && <GameComponent />}
        {gameStage === 'end' && <EndComponent />}
    </div>
);
```

```jsx
// StartComponent.jsx
const StartComponent = ({ startGame }) => {
    return (
        // Isso já vai mudar o estado no App.jsx e mudar o visual do componente
        <button onClick={startGame}>Iniciar Jogo</button>
    );
};
```

#### Mais complexidade nas funções

Como visto acima, startGame pode ser mais complexo e pode usar funções dentro dela, por exemplo:

```jsx
const getRandomWord = () => {
    // ... Lógica
    return {word, category};
}

const startGame = () => {
    const {word, category} = getRandomWord();
    let wordLetters = word.split("");
    
    setWords(word);
    setCategory(category);
    setLetters(wordLetters );
    
    setGameStage(stages[1].name);
};
```

#### Monitoramento de dados

Usando o hook `useEffect` dentro do `function App()` que monitora o valor de um dado escolhido toda vez que ele é alterado.

```jsx
useEffect(() => {
    // Se true, função que seta todos os estados para condições iniciais
    if (guesses <= 0) {
        clearAllStates();
    }
}, [guesses] )
```

#### Técnicas usadas

```jsx
// Mapear para cada letra, mas condicional se essa letra pertence ou não
// à lista de letras acertadas

<div className="palavras">
  // Itera sobre todas as letras
  {letters.map((letter, i) => 
    
    // Condição que retorna true ou false
    guessedLetters.include(letter) ? (
    
      // True
      <span key={i} className="letraAcertada">{letter}</span>
    ) : (
    
      // False
      <span key={i} className="espacoVazio"></span>
    )  
  )}
</div>
```
