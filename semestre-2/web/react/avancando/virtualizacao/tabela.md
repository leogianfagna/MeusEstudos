# Tabela

### ✅ 1️⃣ O que temos aqui

Estamos construindo uma **tabela virtualizada** em React, com:

* Um **cabeçalho fixo** (header)
* Um **corpo de tabela virtualizado**, que permite navegar entre milhares de linhas sem travar
* **4 colunas** dinâmicas que se adaptam ao tamanho da tela
* **Scroll vertical ativo**, mas com a **barra de rolagem visualmente oculta**, mantendo o alinhamento perfeito entre header e grid
* **Layout 100% responsivo**, se a tela for redimensionada, a tabela e as colunas se adaptam automaticamente

O resultado é uma tabela **rápida, leve, sem desalinhamento**, que se comporta bem em qualquer resolução — ideal para aplicações modernas.

***

### ⚙️ 2️⃣ Tecnologias usadas

#### 📦 **react-window**

* Biblioteca para **virtualização de listas e grids** em React.
* Extremamente leve (\~2 kB), muito mais simples que alternativas maiores como react-virtualized.
* Oferece componentes como:
  * `FixedSizeList`
  * `FixedSizeGrid` (que usamos aqui)

Permite renderizar **apenas as células visíveis na tela**, reduzindo drasticamente o custo de renderização no React.

***

#### 📦 **react-virtualized-auto-sizer**

* Pequeno utilitário que mede automaticamente o tamanho disponível do container (altura e largura).
* Passa esses valores para o `Grid`, permitindo que ele se ajuste **responsivamente**.

***

#### 🎨 **CSS**

* Usamos `flexbox` para estruturar o layout da tabela (header + body).
* Técnica de ocultação de scrollbar:
  * `scrollbar-width: none` (Firefox)
  * `-ms-overflow-style: none` (IE/Edge)
  * `::-webkit-scrollbar { display: none; }` (Webkit browsers)

Assim conseguimos manter o comportamento de scroll sem exibir barras que causariam desalinhamento visual.

***

### 🚀 3️⃣ Técnicas e práticas comuns em produção

👉 **1️⃣ Virtualização com Grid**

Em aplicações profissionais (ERPs, dashboards, fintechs, sistemas SaaS), quando há tabelas com:

* Muitas linhas
* Muitas colunas
* Dados dinâmicos (paginação, filtragem)

... a **virtualização** é fundamental para garantir performance.\
`react-window` é uma escolha muito comum por ser leve e eficiente.

***

👉 **2️⃣ Layout responsivo com AutoSizer**

* É prática padrão envolver o Grid em um AutoSizer para que ele se ajuste a:
  * Containers redimensionáveis
  * Sidebars abertas/fechadas
  * Layouts fluidos

Isso evita ter que "fixar" larguras e torna a UI mais profissional.

***

👉 **3️⃣ Cabeçalho fixo + grid separado**

* Em produção, o header geralmente é separado do Grid (como fizemos aqui), porque:
  * Permite estilização independente
  * Permite sticky header (com `position: sticky`)
  * Evita problemas com scrollbars

***

👉 **4️⃣ Ocultação da scrollbar vertical**

* Muito usado em **tabelas com header separado**, porque se a scrollbar aparece no Grid e não no header, gera desalinhamento.
* Ocultar visualmente a scrollbar resolve o problema estético sem prejudicar a UX.

***

👉 **5️⃣ Arredondamento do columnWidth**

* Sempre arredondamos `columnWidth` com `Math.floor` para evitar erros de fração de pixel que causam scroll horizontal indesejado.
* Esse é um detalhe fino que distingue grids bem implementados de grids que "tremem" ou desalinham.



<details>

<summary>Componente React</summary>

```jsx
import { FixedSizeGrid as Grid } from "react-window";
import AutoSizer from "react-virtualized-auto-sizer";
import "./styles.css";

const rowCount = 1000;
const columnCount = 4;
const rowHeight = 35;

const getItem = (rowIndex, columnIndex) =>
  `Item ${rowIndex + 1} - Col ${columnIndex + 1}`;

const Test = () => {
  return (
    <div
      style={{
        height: "400px",
        display: "flex",
        flexDirection: "column",
        overflow: "hidden",
        boxSizing: "border-box",
      }}
    >
      <AutoSizer>
        {({ height, width }) => {
          const columnWidth = Math.floor(width / columnCount);
          const gridWidth = columnWidth * columnCount;
          const headerHeight = 40;
          const gridHeight = height - headerHeight;

          return (
            <>
              {/* Header */}
              <div
                className="grid-header"
                style={{
                  display: "flex",
                  width: gridWidth,
                  height: headerHeight,
                  boxSizing: "border-box",
                }}
              >
                {Array.from({ length: columnCount }).map((_, columnIndex) => (
                  <div
                    key={columnIndex}
                    style={{ width: columnWidth }}
                    className="grid-header-cell"
                  >
                    Coluna {columnIndex + 1}
                  </div>
                ))}
              </div>

              {/* Grid */}
              <Grid
                className="grid-wrapper"
                columnCount={columnCount}
                columnWidth={columnWidth}
                height={gridHeight}
                rowCount={rowCount}
                rowHeight={rowHeight}
                width={gridWidth}
              >
                {({ columnIndex, rowIndex, style }) => (
                  <div className="grid-cell" style={style}>
                    {getItem(rowIndex, columnIndex)}
                  </div>
                )}
              </Grid>
            </>
          );
        }}
      </AutoSizer>
    </div>
  );
};

export default Test;
```

</details>

<details>

<summary>Estilização</summary>

```css
.grid-header-cell {
  padding: 8px;
  background-color: #f7f7f7;
  font-weight: bold;
  border: 1px solid #ccc;
  box-sizing: border-box;
  text-align: center;
}

.grid-cell {
  padding: 8px;
  border: 1px solid #eee;
  box-sizing: border-box;
  text-align: center;
}

.grid-wrapper {
  scrollbar-width: none; /* Firefox */
  -ms-overflow-style: none; /* IE and Edge */
}

.grid-wrapper::-webkit-scrollbar {
  display: none; /* Chrome, Safari, Opera */
}
```

</details>
