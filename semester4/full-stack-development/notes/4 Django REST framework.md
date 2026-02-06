
```
GET - retrieving data
POST - upload data (creating data)
PATCH - update specific fields (e.g. change my age)
PUT - update an entire resource (book)
DELETE - remove resource
```

REST is meant to be stateless in theory, but it is not in practice

```
GET /books -> return list of all books
POST /books -> creating a new book
GET /books/1 -> return book with id 1
PATCH /books/1 -> update some field for book with id 1
DELETE /books/1 -> delete book with the id 1
```

you need to use these for the service to be restful, otherwise it's not
note: important for a 3rd year project

```
GET /pokemon/151 -> Mew
```

## install Django REST framework and set it up
```
pip install djangorestframework drf-spectacular
```

go into settings.py and add 
```python
# settings.py

INSTALLED_APPS = [
	"rest_framework",
	"drf_spectacular",
]

REST_FRAMEWORK = [
	'DEFAULT_SCHEMA_CLASS' : 'drf_spectacular.openapi.AutoSchema'
]

SPECTACULAR_SETTINGS = [
'TITLE': 'Bookshop API',
	'DESCRIPTION': 'API for managing books and authors in our bookshop',
    'VERSION': '1.0.0',
    'SERVE_INCLUDE_SCHEMA': False,
]
```


how do the python object and java object talk to each other?
they use serialisation and deserialisation
```java
class Book():
	def __init__(self, title, author):
		self.title = title
		self.author = author

Python -> Json // serialization
Json -> Java // deserialisation

public class Book{
	private String title;
	private String author;
	
	public Book(String title, String author){
		this.title = title
		this.author = author
	}
}
```

the implementation:
```python
# serializers.py

from rest_framework import serializers
from .models import Author, Book

class AuthorSerializer(serializers.HyperlinkedModelSeriallzer):
	class Meta:
		model = Author
		fields = ['id', 'name', 'birth_date', 'genre', 'created_by']
		read_only_fields = ['id']
		
	def validate_name(self, value):
		if not values:
			raise serializers.ValidationError("Name cannot be empty.")
		return value
```

inside `views.py` we write just one class instead of a lot of functions
```python
# views.py

class AuthorViewSet(viewsets.ModelViewSet):
	queryset = Author.objects.all()
	serializer
```

this allows us to access `127.0.0.1:8000/api/authors/2` through the browser or the terminal `curl 127.0.0.1:8000/api/authors/2`

this allows us to filter through anything we have in our database
```python
# 
from rest_framework.routers import DefaultRouter

router = DefaultRouter()
router.register('authors', views.AuthorViewSet, basename='author')
```

this also automatically does verification for us

`Postman.app` = use this to test your API so you don' t have to write curl commands manually
-  industry standard testing tool