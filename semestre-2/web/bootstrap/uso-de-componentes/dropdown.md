# Dropdown

Aqui será mostrado como usar o Dropdown ao passar o mouse em cima. Originalmente, o [dropdown do Boostrap](https://react-bootstrap.netlify.app/docs/components/dropdowns/) só funciona ao clicar em cima.

## Funcionar com hover

```jsx
const [menuOpen, toggleMenuOpen] = useState(false);

return (
  <NavDropdown
      title="PÁGINAS"
      id="navbarScrollingDropdown"
      onMouseEnter={() => {
        toggleMenuOpen(true);
      }}
      onMouseLeave={() => {
        toggleMenuOpen(false);
      }}
      show={menuOpen}>
      
      <NavDropdown.Item href="#novidades">Novidades</NavDropdown.Item>
      <NavDropdown.Item href="#eventos">Eventos</NavDropdown.Item>
    
  </NavDropdown>
)
```
