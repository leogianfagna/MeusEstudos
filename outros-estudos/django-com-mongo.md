# Django com Mongo

## Iniciando projeto

```bash
pip install django djangorestframework pymongo
django-admin startproject meu_projeto
cd meu_projeto
python manage.py startapp api
pip install djongo
```

Isso vai ser gerado uma estrutura:

* `/api`: Responsáveis por armazenar as **lógicas utilizadas**, como views, modelos e outros.
* `/backend`: Responsáveis por armazenar as **configurações**.

## Configurar aplicação

1. Definir a **conexão** com o banco de dados.
2. Declarar na configuração da aplicação quem precisa ser **carregado** (feito no INSTALLED\_APPS).

```python
# Configuração do MongoDB
MONGO_URI = "string de conexão aqui"
MONGO_DB_NAME = "users"

# Conexão com o MongoDB
mongo_client = pymongo.MongoClient(MONGO_URI)
db = mongo_client[MONGO_DB_NAME]

DATABASES = {
    'default': {
        'ENGINE': 'djongo',
        'NAME': 'users',
        'ENFORCE_SCHEMA': False,
        'CLIENT': {
            'host': os.getenv("MONGODB_CONNECTION", default="") # O link pode estar direto aqui
        }  
    }
}

INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    # Adições
    'rest_framework',
    'api',
]
```

## Criações lógicas CRUD

Essas lógicas são definidas em dois arquivos diferentes. Acaba se assimilando também com outras lógicas de backend, tipo Node, com controladores, rotas e modelos.

Atualmente, o tutorial abaixo <mark style="color:red;">não está utilizando serializers</mark> que é útil para uma aplicação API RESTful, será atualizada em um futuro.

* **Models**: Define a estrutura dos dados e interage diretamente com o banco de dados. Modelos definem a lógica de negócios relacionada aos dados, como <mark style="color:blue;">criação de objetos, validações de dados, consultas complexas</mark> e métodos personalizados que envolvem a manipulação dos dados.
* **Views**: Responsáveis por <mark style="color:blue;">lidar com as requisições HTTP e retornar respostas</mark>, frequentemente usando templates ou APIs. Como ela é responsável pela resposta ao usuário, podemos incluir mais lógica aqui para retornar mais dados ainda se quisermos. Elas <mark style="color:orange;">utilizam os modelos</mark> para manipular os dados e apresentar as informações ao usuário.

{% hint style="info" %}
Os métodos dos modelos e views necessitam ter a mesma lógica. Então, se um modelo implementa uma lógica de  checar se o usuário já existe, a view também precisa da mesma lógica.

Mas repare que a view pode conferir de outra maneira, usando o que foi resgatado de `result`.
{% endhint %}

### Modelos

Declarado no arquivo `models.py`. Cada método representa uma **operação no banco de dados**.

```python
from django.db import models
import pymongo
from django.conf import settings

client = pymongo.MongoClient("string de conexão")
db = client['users']
collection = db['users']

class User(models.Model):
    username = models.CharField(max_length=100)
    password = models.CharField(max_length=100)
    tickers = models.JSONField(default=list)

    @staticmethod
    def add_user(full_name, username, password):
        user_data = collection.find_one({"username": username})

        if user_data:
            return "Username already in use"
        else:
            user_data = {
                "full_name": full_name,
                "username": username,
                "password": password
            }
            collection.insert_one(user_data)
            return "User registred successfully"
```

### Views

Declarado no arquivo `views.py`. Cada método **representa a resposta ao usuário**, repare que essa <mark style="color:blue;">resposta é recebida ao chamar o método modelo do outro arquivo</mark> `User.add_user`.

```python
def add_user(request):
    full_name = request.GET.get('full_name')
    username = request.GET.get('username')
    password = request.GET.get('password')
    
    if username and password:
        result = User.add_user(full_name, username, password)
        
        # Checa se já existe um username com esse nome
        if result == "User registred successfully":
            return JsonResponse({"message": "User registered successfully"})
        else:
            return JsonResponse({"message": result}, status=400)
    else:
        return JsonResponse({"message": "Missing username and password"}, status=400)
```

## Rotas (URLs)

1. Necessário definir as rotas para **cada view criada**.
2. Necessário definir as rotas **do projeto Django**.

Cada view criada acima precisa ser acessada através de uma URL. Para isso, basta adicionar a URL correspondente à ela no arquivo `/api/urls.py`. Toda vez que tiver uma nova view, ela deve ser acrescentada aqui.

```python
from django.urls import path
from . import views

urlpatterns = [
    path('add_user/', views.add_user, name='add_user'),
]
```

Definir as rotas do projeto Django significa deixá-las acessíveis. Para isso, definimos a URL base para nossa API criada que vai incluir todas as rotas que fizemos acima. Esse caso deverá ser feito uma única vez e modificado apenas se tiver um novo projeto.

```python
from django.contrib import admin
from django.urls import path, include

urlpatterns = [
    path('admin/', admin.site.urls),
    path('api/', include('api.urls')), # Inclui as rotas da aplicação que chamamos
                                       # de API. Se o nome for diferente, mude
]
```

## Mover estruturas

O arquivo `manage.py` convencionalmente localiza-se na raíz do projeto, mas ela é criada dentro da pasta do projeto. Portanto, **mova** para a raíz.

Para o servidor continuar funcionando, é necessário importar o novo caminho. Adicione essas linhas no próprio arquivo `manage.py` (altere o nome "backend" se o nome do seu projeto for diferente).

```diff
def main():
    """Run administrative tasks."""
+    # Adiciona a pasta 'backend' ao caminho de busca de módulos
+    sys.path.append(os.path.join(os.path.dirname(__file__), 'backend'))
    os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'backend.settings')
```

## .env

As strings de conexções podem estar em um arquivo `.env` que deve estar presente na raíz do projeto. Para isso funcionar, instale a dependência:

```bash
pip install python-dotenv
```

Em cada lugar que for utilizar uma chave secreta, importe isso:

```python
import os
from dotenv import load_dotenv
load_dotenv()
```

A variável de resgate é essa:

```python
os.getenv("CHAVE_NO_ENV", default="")
```

## Migrações

As **migrações pendentes** representam mudanças no banco de dados que precisam ser aplicadas para garantir que ele esteja sincronizado com o código do seu projeto. Para aplicar essas migrações e garantir que seu banco de dados esteja atualizado, basta executar:

```bash
manage.py migrate
# Tive que usar abaixo como alternativa
python manage.py makemigrations api
```

Isso vai aplicar todas as migrações pendentes e garantir que a estrutura do banco de dados esteja de acordo com os modelos do seu projeto.

<details>

<summary>Anotações extras</summary>

## Interagir com o banco de dado

pip install mongoengine

"Você está correto em questionar a necessidade de configurar a conexão com o MongoDB diretamente no `settings.py`, já que o Django já possui a configuração de banco de dados definida no campo `DATABASES` para bancos relacionais, como o **SQLite**, **PostgreSQL**, **MySQL**, etc."

"orém, o **Django** não suporta nativamente o MongoDB. Para usar o MongoDB com o Django, é necessário usar bibliotecas externas como o **`mongoengine`** (ou **`djongo`** para uma integração mais transparente com o Django ORM). Essas bibliotecas não utilizam a configuração `DATABASES` no Django, porque o MongoDB não é um banco de dados relacional, e o Django não sabe como conectá-lo diretamente através dessa configuração."

</details>
