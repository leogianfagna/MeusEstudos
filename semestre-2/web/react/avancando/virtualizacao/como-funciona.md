# Como funciona

O `react-window` controla o número de elementos montados no DOM, então virtualiza os demais elementos para não sobrecarregar quando existem muitos outros elementos.

Mas sobre renderização, essa biblioteca só evita que itens invisíveis fiquem montados, mas não impede que os itens visíveis re-renderizem toda vez que o React acha que precisa, por exemplo, quando um estado muda ou quando ele aparece na lista depois de estar virtualizado.

Então pode ser útil cada elemento da lista utilizar um memo.

```jsx
const WindowedRow = memo(({ index, style, data }) => {
  const { register } = useFormContext()

  return <input {...register(`${index}.quantity`)} />
})

<List
  height={height}
  itemCount={items.length}
  itemSize={() => 100}
  width={width}
  itemData={items}
>
  {WindowedRow}
</List>
```
