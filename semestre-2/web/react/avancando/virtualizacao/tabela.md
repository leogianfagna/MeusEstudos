# Tabela

O objetivo é construir uma tabela virtualizada para **performance**, baseado em aplicações reais de produção, com:

* Cabeçalho fixo durante a [rolagem das linhas](#user-content-fn-1)[^1], que estarão virtualizadas.
* Colunas dinâmicas que se [adaptam com o tamanho da tela](#user-content-fn-2)[^2] e não desalinham com o cabeçalho.
* Scroll vertical sem mostrar a barra de rolagem, pois como a barra fica apenas nas linhas, isso iria desalinhar com o cabeçalho.

Para chegar a esse resultado, é necessário usar os componentes do `react-window` que foca na virtualização e exibição dos elementos e `auto-sizer`, que vai ajudar nos problemas dos componentes exigirem tamanhos em números fixos, resgatando as medidas ideais e passando para esses componentes.

## Dimensões de uma tabela virtualizada



***

#### 🎨 **CSS**

* Usamos `flexbox` para estruturar o layout da tabela (header + body).
* Técnica de ocultação de scrollbar:
  * `scrollbar-width: none` (Firefox)
  * `-ms-overflow-style: none` (IE/Edge)
  * `::-webkit-scrollbar { display: none; }` (Webkit browsers)

Assim conseguimos manter o comportamento de scroll sem exibir barras que causariam desalinhamento visual.

***



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

[^1]: As linhas rolam mas o cabeçalho não. A dificuldade está em não envolver o cabeçalho na virtualização.

[^2]: Emite uma grande dificuldade pois os componentes prontos não aceitam como estilos números físicos ou porcentagens, então vai obrigar a criar funções para resgatar o tamanho atual da tela e fazer conversões.
