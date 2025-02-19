# Plugins

Destinado para construção de plugins de Minecraft.

## Registrar classes onEnable

Quando uma classe [**não herda de uma classe específica do Bukkit**](#user-content-fn-1)[^1], ela **não interage diretamente com o ciclo de vida ou eventos do Minecraft**. Em vez disso, ela é usada como um **molde**, **estrutura de suporte** ou **auxílio** para organizar o código. Essas classes servem para funções **indiretas** ou de **apoio** no funcionamento do plugin.

Quando ela implementa uma funcionalidade de fato, ela <mark style="color:orange;">precisa ser registrada</mark> no método `onEnable`, que é o método acionado quando o plugin liga.

### Quando é um listener

```java
public void onEnable() {
    Bukkit.getPluginManager().registerEvents(new NomeDaClasse(), this);
}
```

### Quando é um comando

```java
public void onEnable() {
    this.getCommand("comando").setExecutor(new NomeDaClasse());
}
```

### O que muda na prática

Quase nada, apenas estrutura. O que vai mudar de fato é quando a classe secundária necessita usar alguma funcionalidade ou recurso da herança `JavaPlugin`. Quando isso acontece, precisamos passar uma instância dela no construtor da classe, assim podemos usá-la.

Em um <mark style="color:orange;">código final</mark>, vemos a diferença que, em vez de usar o `this` em certos métodos, vamos usar a instância passada que chamaremos de `plugin`.

{% hint style="success" %}
A classe secundária **não terá** um construtor caso passar o `this` não seja necessário.
{% endhint %}

#### Passando o `this` no construtor

```diff
- Bukkit.getPluginManager().registerEvents(new NomeDaClasse(), this);
+ Bukkit.getPluginManager().registerEvents(new NomeDaClasse(this), this);

- this.getCommand("comando").setExecutor(new NomeDaClasse());
+ this.getCommand("comando").setExecutor(new NomeDaClasse(this));
```

#### Recebendo o `this` no construtor da classe

```java
private final Plugin plugin;

public SpecialItems(Plugin plugin) {
    this.plugin = plugin;
}
```

#### Utilizando a variável `plugin`

```java
String mensagem = plugin.getConfig().getString("mensagens.cura");
NamespacedKey key = new NamespacedKey(plugin, "cajado_cura");
```

## Carregar mudanças do config.yml

Se esse arquivo teve mudanças em uma nova atualização, podemos criar um método que carregue essas novas mudanças, sem a necessidade de <mark style="color:orange;">recriar o config</mark>. Esse método deve ser chamado no `onEnable` do plugin.

```java
public void updateConfig() {
    File configFile = new File(getDataFolder(), "config.yml");
    if (!configFile.exists()) {
        saveResource("config.yml", false);
        return;
    }

    YamlConfiguration config = YamlConfiguration.loadConfiguration(configFile);
    YamlConfiguration defaultConfig = YamlConfiguration
            .loadConfiguration(new InputStreamReader(getResource("config.yml"), StandardCharsets.UTF_8));

    boolean checkLineChanges = false;

    for (String key : defaultConfig.getKeys(true)) {
        if (!config.contains(key)) {
            config.set(key, defaultConfig.get(key));
            checkLineChanges = true;
        }
    }

    if (checkLineChanges) {
        try {
            config.save(configFile);
            getLogger().info("Config.yml atualizado com novas opções.");
        } catch (IOException e) {
            getLogger().severe("Erro ao salvar o config.yml!");
            e.printStackTrace();
        }
    }
}
```

[^1]: Por exemplo `Listener`, `CommandExecutor` ou qualquer funcionalidade que a classe faça.
