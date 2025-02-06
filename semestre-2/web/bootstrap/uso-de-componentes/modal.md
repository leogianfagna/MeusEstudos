---
description: https://react-bootstrap.netlify.app/docs/components/modal/
---

# Modal

```jsx
import "./EventComponent.css";
import Button from "react-bootstrap/Button";
import Modal from "react-bootstrap/Modal";
import { useState } from 'react';

const EventComponent = ({ event, i, hour }) => {
  const [show, setShow] = useState(false);

  const handleClose = () => setShow(false);
  const handleShow = () => setShow(true);

  function getEventIcon(eventName) {
    const iconName = eventName.replace(/\s+/g, "").toLowerCase();
    return iconName + ".png";
  }

  return (
    <>
      <div className="event-button">
        <button onClick={handleShow}>Ver</button>
      </div>

      <Modal show={show} onHide={handleClose} dialogClassName="custom-modal">
        <Modal.Body>
          <img src="../src/assets/images/events/img.png"></img>
          <h1>Título</h1>
          <p>Descrição</p>
        </Modal.Body>
        <Modal.Footer>
          <Button variant="secondary" onClick={handleClose}>
            Close
          </Button>
        </Modal.Footer>
      </Modal>
      
    </>
  );
};

export default EventComponent;
```

```css
/* Bootstrap Modal */
/* Personalizando fundo do Modal */
.custom-modal .modal-content {
  background-color: #1a1a1a; /* Fundo escuro */
  color: #fff; /* Texto branco */
  border-radius: 10px; /* Borda arredondada */
  padding: 20px;
}

/* Cabeçalho do Modal */
.custom-modal .modal-header {
  background-color: #333; /* Fundo cinza escuro */
  color: #ffcc00; /* Título dourado */
  border-bottom: 2px solid #ffcc00; /* Linha dourada no header */
}

/* Rodapé do Modal */
.custom-modal .modal-footer {
  background-color: #222; /* Fundo escuro */
  border-top: 2px solid #ffcc00;
}

/* Personalizando botões dentro do modal */
.custom-modal .modal-body button {
  background-color: #ffcc00;
  border: none;
  padding: 10px 20px;
  border-radius: 5px;
  color: #000;
  font-weight: bold;
  cursor: pointer;
}

.custom-modal .modal-body button:hover {
  background-color: #e6b800; /* Um pouco mais escuro no hover */
}
```
