# Posicionamento

A propriedade `position` diz <mark style="color:blue;">qual posição aquele elemento vai ocupar da tela</mark>. Por padrão, os elementos seguem uma ordem no corpo do HTML (um abaixo do outro ou um ao lado do outro em caso, depende da propriedade flex). Esse padrão também não permite usar propriedades de direção, como left ou top.

Essa propriedade permite que elementos fiquem em diferentes posições e também que possamos ajustá-las. Por isso, ela será usada quando queremos que qualquer elemento ocupe uma posição diferente daquela da ordem padronizada do HTML.

## Relative

O elemento continua ocupando o mesmo espaço no layout mas permite movê-lo usando `top`, `left`, `right`, e `bottom`. O deslocamento é feito em relação à sua posição original.

* Serve também como **referência para elementos com `absolute` dentro dele**.

```css
iv {
  position: relative;
  top: 10px;   /* empurra 10px para baixo */
  left: 20px;  /* empurra 20px para a direita */
}
```

## Absolute

O elemento sai do fluxo normal da página e pode ser posicionado livremente, mas ele é posicionado em relação ao ancestral mais próximo que (PAREI AQUI)

* Ele é **posicionado em relação ao ancestral mais próximo com `position: relative` (ou `absolute`, `fixed`, ou `sticky`)**.
* Se nenhum ancestral tiver `position` definido, será posicionado **em relação ao `<html>` (ou `body`)**.

```css
cssCopiarEditardiv {
  position: absolute;
  top: 0;
  left: 0;
}
```

🔧 Exemplo comum:

```html
htmlCopiarEditar<div style="position: relative;">
  <div style="position: absolute; top: 0; left: 0;">Eu fico dentro desse container</div>
</div>
```

## Fixed

O elemento **fica fixo na tela**, mesmo quando a página é rolada.

* É **sempre posicionado em relação à viewport (janela do navegador)**.
* Útil para menus fixos, botões "voltar ao topo", etc.

```css
cssCopiarEditardiv {
  position: fixed;
  bottom: 10px;
  right: 10px;
}
```

## Sticky

Combina `relative` e `fixed`.

* Inicialmente se comporta como `relative`.
* Quando atinge um limite (por exemplo, ao rolar), ele **"gruda" na tela** e vira `fixed`.

```css
cssCopiarEditardiv {
  position: sticky;
  top: 0;
}
```

🔧 Útil para cabeçalhos que devem permanecer visíveis ao rolar.
