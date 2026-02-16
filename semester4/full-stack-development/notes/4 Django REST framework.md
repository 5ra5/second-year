
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

# website notes

REST - REpresentational State Transfer
-  architectural style - set of constraints that that produce systems with desirable properties: scalability, simplicity, modifiability, and reliability

key insight: **the web already solved most of our problems**
-  HTTP, URLs, and the request-response model are a general-purpose architecture for distributed systems

## the six REST constraints

###  1.  **Client-Server**
separated to evolve independently
-  the **server** manages data and business logic
-  the **client** manages user interface and user experience

### 2. Stateless

Each request from client to server must contain **all the information needed to understand and process that request**.

- **Scalability**: Any server can handle any request. You can add more servers and load-balance freely - no need to route a user's requests to the same server.
- **Reliability**: If a server crashes, no client state is lost. Another server can immediately handle the next request.
- **Simplicity**: The server doesn't need complex session management. Each request is self-contained.

### 3. Cacheable

Responses must define themselves as cacheable or non-cacheable. If a response is cacheable, the client (or intermediaries like CDNs) can reuse that response for subsequent equivalent requests.

HTTP provides headers (`Cache-Control`, `ETag`, `Last-Modified`) to control caching behaviour.


### 4. Uniform interface

-  all resources are accessed through a **consistent, standardised interface**
-  4 parts

1.  resource identification
```
/books/42          # A specific book
/users/7           # A specific user
/orders/1001       # A specific order
```

2.  resource manipulation through representation
3.  self-descriptive messages
the `Content-Type` header tells you the format, the HTTP method tells you the action, the status code tells you the result
4.  hypermedia as the engine of application state (HATEOAS)

### 5. layered system

The architecture can be composed of multiple layers, each with its own responsibility. A client doesn't know (or care) whether it's talking directly to the server or through a proxy, load balancer, or cache.

### 6. code on demand (optional)

Servers can extend client functionality by sending executable code (like JavaScript). This is the only optional REST constraint and is rarely discussed in API contexts - it's more relevant to web browsers downloading and executing scripts.


## CRUD

resource = any concept that can be named and addressed - a user, a book, an order, a collection of items (each resource has a unique URL)

| Method | CRUD   | Purpose                     | Request Body                | Response Body              |
| ------ | ------ | --------------------------- | --------------------------- | -------------------------- |
| GET    | Read   | Retrieve a resource         | No                          | Yes (the resource)         |
| POST   | Create | Create a new resource       | Yes (the new resource)      | Yes (the created resource) |
| PUT    | Update | Replace a resource entirely | Yes (the complete resource) | Yes (the updated resource) |
| PATCH  | Update | Partially update a resource | Yes (only changed fields)   | Yes (the updated resource) |
| DELETE | Delete | Remove a resource           | No                          | Usually no                 |

# Summary

**API (Application Programming Interface)**
-  A way for **different programs** to communicate
-  Usually exchanges **JSON**, not HTML
-  Client (browser / app)
-  Server (Django)

In Django:
-  Normal views -> return HTML
-  API views -> return JSON

REST = architectural style, not a framework

**Core REST principles**:
-  stateless - server doesn't remember previous requests
-  resource-based URLs (`/products/`, `/products/1/`)
-  HTTP methods define actions
-  JSON responses
-  Client-server separation

**Why REST is useful:**
-  scalable
-  simple
-  works with web, mobile, frontend frameworks

**DRF** is a Django library that makes building APIs easier.

**What DRF gives you**:
-  serializers
-  APIViews & ViewSets
-  Automatic validation
-  JSON responses
-  Browsable API

**Serializers**
-  converts model instances into JSON and vice versa
-  validates incoming data
-  similar role to Django Forms, but for APIs

**Why serializers are important**:
-  prevent invalid data
-  reduce repetitive code
-  improve security

**ModelSerializer**
```python
class ProductSerializer(serializers.ModelSerializer):
	class Meta:
		model = Product
		fields = '__all__'
```

**APIView**
-  Manual
-  More code
-  Easy to get wrong
```python
class ProductCreate(APIView):
	def post(self, request):
	...
```

**ModelViewSet (BEST PRACTICE)**
-  Automatic CRUD
-  Uses serializers
```python
class ProductViewSet(ModelViewSet):
	queryset = Product.objects.all()
	serializer_class = ProductSerializer
```

**Routers**
used with ViewSets to generate URLs automatically
```python
router.register(r'products', ProductViewSet, basename='product')
```

DRF supports permissions and authentication classes

# API Views

**Approach 1: APIView (Most Control)**

complete control, lot of repetitive code
`get_object`, validation checks and response patterns repeat

```python
# pages/views.py
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import status
from .models import Book
from .serializers import BookSerializer

class BookListAPIView(APIView):
	
	def get(self, request):
		books = Book.objects.all()
		serializer = BookSerializer(books, many=True)
		return Response(serializer.data)
		
	def post(self, request):
		serializer = BookSerialzer(data=request.data)
		if serializer.is_valid():
			serializer.save()
			return Response(serializer.data, status=status.HTTP_201_CREATED)
		return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)
		
```

```python
class BookDetailAPIView(APIView):
    """Retrieve, update, or delete a specific book."""

    def get_object(self, pk):
        try:
            return Book.objects.get(pk=pk)
        except Book.DoesNotExist:
            return None

    def get(self, request, pk):
        """GET /api/books/{id}/ - Retrieve a book."""
        book = self.get_object(pk)
        if book is None:
            return Response(status=status.HTTP_404_NOT_FOUND)
        serializer = BookSerializer(book)
        return Response(serializer.data)

    def put(self, request, pk):
        """PUT /api/books/{id}/ - Replace a book."""
        book = self.get_object(pk)
        if book is None:
            return Response(status=status.HTTP_404_NOT_FOUND)
        serializer = BookSerializer(book, data=request.data)
        if serializer.is_valid():
            serializer.save()
            return Response(serializer.data)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)

    def delete(self, request, pk):
        """DELETE /api/books/{id}/ - Delete a book."""
        book = self.get_object(pk)
        if book is None:
            return Response(status=status.HTTP_404_NOT_FOUND)
        book.delete()
        return Response(status=status.HTTP_204_NO_CONTENT)
```

# Generic Views (Less Boilerplate)

two classes, four lines of code, and we get the same functionality as before
-  fetching objects from the queryset
-  404 responses when objects don't exist
-  serialization/deserialization
-  proper status codes
```python
# pages/views.py
from rest_framework import generics
from .models import Book
from .serializers import BookSerializer

class BookListCreateView(generics.ListCreateAPIView):
	queryset = Book.objects.all()
	serializer_class = BookSerializer
	
class BookDetailView(generics.RetrieveUpdateDestroyAPIView):
	queryset = Book.objects.all()
	serializer_class = BookSerializer
```

Available generic views:

|View|Methods|Purpose|
|---|---|---|
|`ListAPIView`|GET|List objects|
|`CreateAPIView`|POST|Create an object|
|`RetrieveAPIView`|GET|Get a single object|
|`UpdateAPIView`|PUT, PATCH|Update an object|
|`DestroyAPIView`|DELETE|Delete an object|
|`ListCreateAPIView`|GET, POST|List + Create|
|`RetrieveUpdateDestroyAPIView`|GET, PUT, PATCH, DELETE|Full single-object CRUD|
# ViewSets (Recommended)

```python
# pages/views.py
from rest_framework import viewsets
from .models import Author, Book
from .serializers import AuthorSerializer, BookSerializer

class AuthorViewSet(viewsets.ModelViewSet):
	queryset = Author.objects.all()
	serializer_class = AuthorSerializer
	
class BookViewSet(viewsets.ModelViewSet):
	queryset = Book.objects.all()
	serializer_class = BookSerializer
```

# Creating serializers

```python
# pages/serializers.py
from rest_framework import serializers
from .models import Author, Book

class AuthorSerializer(serializers.ModelSerializer):
	class Meta:
		model = Author
		fields = ['id', 'name', 'birth_year', 'country']
		read_only_fields = ['id']
		
class BookSerializer(serializers.ModelSerializer):
	author_name = serializers.CharField(source='author.name', read_only=True)
	
	class Meta:
		model = Book
		fields = ['id', 'title', 'year_published', 'author', 'author_name']
		read_only_fields = ['id']
```

`serializers.ModelSerializer` = a serializer that automatically generates fields based on a Django model (like Django's `ModelForm' but for APIs)

`class Meta` - configuration for the serializer:
-  `model` = which Django model to serialize
-  `fields` = which fields to include (use `__all__` for everything, but explicit is better)
-  `read_only_fields` = fields that can't be set via the API (auto-generated-fields)

`author_name` = a computed field that pulls the author's name from the related object
`source='author.name` = tells DRF to traverse the ForeignKey relationship

# URL Configuration with Routers
```python
# pages/urls.py
from django.urls import path, include
from rest_framework.routers import DefaultRouter
from .views import AuthorViewSet, BookViewSet

router = DefaultRouter()
router.register = (r'authors', AuthorViewSet, basename='author')
router.register = (r'books', BookViewSet, basename='book')

urlpatterns = [
	path('api/', include(router.urls)),
]
```