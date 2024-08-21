# Estilização

Diversos recursos podem ser usados no HTML, como ícones externo.

## Adicionar ícones

Existem sites externos que disponibilizam ícones já criados para podermos usar e ainda customizá-los da forma que queremos. Um exemplo é o Google Icons: [https://fonts.google.com/icons](https://fonts.google.com/icons). Ao abrir a página, verá diversos ícones prontos para escolher, junto com <mark style="color:green;">opções</mark>: tamanho, preenchimento, cor, etc.

Para importar, mostrará duas opções: a opção estática e opção estilizada:

* Estática: não precisa importar um CSS e aquele ícone vai ficar daquele jeito para sempre
* Estilizada: pode importar um CSS junto que permite a customização dos ícones

Cada uma dessas opções vai dar uma opção de href diferente para ser importada. Podemos ver ela ao <mark style="color:purple;">lado direito</mark> logo após escolher um ícone:

<figure><img src="../../.gitbook/assets/image.png" alt=""><figcaption></figcaption></figure>

Assim, pegamos o que desejamos e importamos no `<head>` e depois usamos o ícone com o atributo `<span>`, igual mostra na aba lateral:

```html
<head>
  <!-- .... -->
  <link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:opsz,wght,FILL,GRAD@20..48,100..700,0..1,-50..200" />
  <link rel="stylesheet" href="test.css"> <!-- Aqui vai ter o estilo  do ícone -->
</head>

<body> 
  <span class="material-symbols-outlined">home</span>
```

```css
/* Podemos customizar livremente ao usar a opção estilizada */
.material-symbols-outlined {
  font-variation-settings:
  'FILL' 1,
  'wght' 600,
  'GRAD' 200,
  'opsz' 40
}
```

Um detalhe muito importante é que, para a customização do ícone via css funcionar, a importação dos estilos devem estar <mark style="color:red;">depois da importação das fontes do google</mark>, assim como está no exemplo. Isso porque, se estiver antes, quem carregar por último vai prevalecer e assim não poderemos editá-las.

### Aumentar tamanho do ícone

Para aumentar o seu tamanho, podemos usar o atributo `font-size` em pixels dentro do css criado para ele, desta forma:

```css
.material-symbols-outlined {
    font-size: 70px; /* Novo atributo */
    font-variation-settings:
    'FILL' 0,
    'wght' 400,
    'GRAD' 0,
    'opsz' 24
}
```
