## databases

**primary key** = a unique identifier of a certain row - something that distinguishes it from every other row
**foreign key** = references the primary key of another table

each column has a data type: its a single attribute/field/category of data
a row is a single record/entry of that category. it holds actual data we're working with
a table is a collection of related data consisting of columns and rows

## interacting with a database

many types of relational databases out there and they all use a different flavours of SQL

**querying the data against the database**

this would return the entire table - all of our data
```sql
SELECT * FROM Books,
```


return the title and the author
```sql
SELECT Title, Author FROM Books,
```


return all the books by Frank Herbert - 2 being the primary key (ID of an author)
```sql
SELECT * FROM Books WHERE Author = 2,
```

you shouldn't write databases manually! don't write code like this! this could be manipulated to find out all the users passwords by running `get_book()`
```python
import sqlite3
def get_book(id):
	conn = sqlite3.connect('example.db')
	cursor = conn.cursor()
	cursor.execute('''
		SELECT * FROM Books WHERE id = {id};
	''')
	rows = cursor.fetchall()
	
id = "-- SELECT password from user where 1=1;"

"SELECT * FROM Books WHERE id = {id} -- SELECT password from user where 1=1;"
```


it's better to use objects to mimic relational databases than using arrays
there is less work and complications, no manual work and we improve security of the data
**ORM = OBJECT RELATIONAL MAPPER**
```python
class Author:
	def __init__(self, name, birth_year):
		self.name = name
		self.birth_year = birth_year

class Book:
	def __init__(self, title, author:Author, year):
		self.title = title
		self.author = author
		self.year = year
		
Book.get(1)
# = SELECT * FROM books WHERE id=1
```

it's not good to directly deal with sensitive data, you should always have multiple barriers between you and the data.
Django understands this - it has object relational mapping built in
it's in app folder in `models.py`

focus on data types here:
```python
# models.py
from django.db import models

class Author(models.Model):
	id = models.AutoField(primary_key=True)
	name = models.CharField(max_length=100)
	birth_date = models.DateField()
	genre = models.CharField(max_length=100, default="Fiction")
	
	def __str__(self):
		return self.name

# Create your models here.
class Book(models.Model):
	id = models.AutoField(primary_key=True)
	title = models.CharField(max_length=200)
	genre = models.CharField(max_length=100)
	num_pages = models.IntegerField()
	# date_published = models.DateField(int year, int month, int day)
	date_published = models.DateField() # preferred way
	author = models.ForeignKey(Author, on_delete=models.CASCADE)
	
	def __str__(self):
		return self.title
```

```python

Author.objects.create(name="J.K. Rowling", birth_date="1965-07-31", genre="Fantasy")
```

how to use this `models.py`?
this code needs to be turned to SQL and ran against the database- migrations
1.  make a migration
2.  migrate

```bash
python manage.py makemigrations
```
you get the migrations directory - you shouldn't touch it! if you are reading the migrations directory, something went seriously wrong

```bash
python manage.py migrate
```

in `db.sqlite3` you get multiple tables after you migrate

**how to update the database after modifying the original code?**

let's say we add a genre column, you need to update the genres of other authors or set a default! 

```python
genre = models.CharField(max_length=100, default="Fiction") # setting a default
genre = models.CharField(max_length=100, null=True, blank=True) # allowing no data in the database
```

now make a new migration:
```shell
python manage.py makemigrations
python manage.py migrate
```

when you go to your database and refresh, you get a new genre table

**adding data in the database**
in `admin.py`
```python
from django.contrib import admin
from .models import Author, Book

admin.site.register(Author)
admin.site.register(Book)
```

you need to create a superuser to get into Django administration
this is how we will add the data into the database
you don't need to set a strong password in the development stage
```shell
python manage.py createsuperuser
```

```shell
username: admin
email address= a@a.com
password: 
```

after setting this info we can go to Django admin page and log in

**applying data to views and templates**

add these
```python
# urls.py

urlpatterns = [
	path("books/", views.books, name="all_books"),
	path("books/<int:id>", views.books, name="book_detail")],
	path("authors/<int:id>/", views.author_detail, name="author_detail"),
```

```python
# views.py
from django.shortcuts, import render, get_object_or_404
from .models import Book, Author

# getting the list of all book objects
def books(request):
	all_books = Book.objects.all() # returns an array of books
	return render(request, 'all_books.html', {'books'; all_books})
	
def book_detail(request, id):
	book = get_object_or_404(Book, id=id) # returns a single book object
	return render(request, 'book_detail.html', {'book' : book})
	
def author_detail(request, id):
	author = get_object_or_404(Author, id=id) # returns a single author object
	return render(request, 'author_detail.html', {'author' : author})
```

`all_books.html`
```html
{% extends "base.html" %}

{% block title %}Home{% endblock %}

{% block content %}
	<ul>
		{% for book in books %}
			<li><a href="{% url 'book_detail' book.id %}">{{book.title}}</a> by <a href="{% url 'author_detail' book.author.id %}">{{book.author.name}}</a></li>
		{% endfor %}
	</ul>
	
{% endblock %}
```

`book_detail.html`
```html
{% extends "base.html "%}

{% block title %}Home{% endlock %}

{% block content %}
	<p>
		Title {{book.title}}
		Author {{book.author.name}}
		Genre {{book.genre}}
		Number pages {{book.num_pages}}
		Published {{book.published_date}}%
	</p>
	
{% endblock %}
```

