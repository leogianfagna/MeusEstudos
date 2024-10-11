# Abordagem de estilos

## Seletores

Vamos supor que tenhamos um elemento body estilizado, mas uma outra página precisa de um body diferente, portanto, precisamos de estilos diferentes para cada caso. Para aplicar diferentes estilos de gradiente ao `body` em páginas diferentes, temos duas abordagens principais:

* Usar o mesmo arquivo CSS com seletores específicos (recomendado pela qualidade)
* Criar arquivos CSS separados para cada página

### Uso de seletores

Servem para especificar em que situação aquele elemento será aplicado àquela tag. Veja abaixo um exemplo onde cria o estilo body e assim um seletor `page-home` ou `page-about`, e eles são aplicados de acordo com a classe colocada na tag body.

<figure><img src="../../../.gitbook/assets/seletores em css.png" alt=""><figcaption></figcaption></figure>

Isso também serviria se nós declararmos um body sem seletor e abaixo outros bodys com diferentes seletores. Eles vão usar a base que há no body global e depois aplicar os seletores separadamente, dessa forma:

```css
body {
    margin: 0;
}

body.page-home {
    background-image: linear-gradient(to bottom right, #333c42, #1D1E24);
}

body.page-register {
    background-image: linear-gradient(
        to bottom,
        #ff0000,
        #00ff00,
        #0000ff
    );
}
```

### Arquivos diferentes

Aqui não tem segredo, basta apenas criar um arquivo css separado. Eles podem ser úteis em casos onde as páginas têm <mark style="color:orange;">estilos drasticamente diferentes</mark> e você deseja otimizar o carregamento de CSS, servindo apenas os estilos necessários para cada página. No entanto, isso pode gerar **mais manutenção** e isso vai contra a qualidade do projeto.
