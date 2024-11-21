# Pacotes

Classes que estão no mesmo pacote, a palavra `protected` [passa a valer](#user-content-fn-1)[^1] todos que estão na mesma pasta/pacote. A recomendação é, se criar um método `protected`, deixá-lo sozinho na pasta ou certificar que as outras classes possam usá-lo sem problemas.

`import` é necessário quando classes estão em pastas diferentes e o `package` só passa a ser válido a partir de sub-pastas.

```java
package grupopi4.kartconnect;

import grupopi4.kartconnect.model.Classificacao;
```

[^1]: Quer dizer, todos poderão usar.
