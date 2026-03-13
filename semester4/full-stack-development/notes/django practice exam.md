things to know for the exam:
-  environment
-  urls, url patterns
-  views - reading data in/out (GET v POST)
-  models - data types correct, validation max, min, default values
-  templates - context `{'book : all_books} - {{all_books}}`
-  forms & serializers

**Question 1**
When using `python manage.py makemigrations`, what does Django create?
a. SQL statements that are immediately executed
b. a new virtual environment
c. Python files describing database schema changes
d. Backup copies of your models

**Question 2**
Which of the following is the correct way to define a URL pattern in Django?
a. `path('articles/', views.article_list)`
b. `link('articles/', views.article_list)`
c. `url(r'^articles/$', views.article_list)`
d. `route('/articles/', views.article_list)`

**Question 3**
Which file should you add to .gitignore for a Django project, explain why this file should be ignored.
-  The file db.sqlite should not be included in a git repo as it is a local development database, each developer should have their own copy of db.sqlite automatically created and managed by Django.

**Question 4**
A student runs these commands
```
python -m venv myenv
pip install django
python manage.py runserver
```

What will likely happen?
a. The virtual environment auto activates
b. Django installs into the virtual environment
c. Django installs globally
d. `manage.py` activates the virtual environment

**Question 5**
Why should you use a virtual environment for your Django project?
a. It makes your code run faster
b. It's required for Django to function
c. It automatically backs up your code
d. It isolates project dependencies from your system-wide Python packages

**Question 6**
What does the `null=True` argument do in a Django model field?
a. Encrypts the field value
b. Deletes the field from the database
c. Allows the database column to store NULL values
d. Makes the field invisible in forms

**Question 7**
The code below represents a model called Product developed by a junior developer. Comment on the quality of the code and any changes that are required.
```python
from django.db import models

class Product(models.Model):
    name = models.CharField(max_length=200)
    price = models.CharField(max_length=10)
    stock_quantity = models.CharField(max_length=5)
    is_available = models.CharField(max_length=5)
```

- price should be a DecimalField
- stock_quantity should be an IntegerField
- is_available appears to be True/False so it should be a BooleanField
- Product names could be more than 200 characters in length so a TextField would be better suited.

**Question 8**
A client wants a feature on their website that allows users to search for available products based on their category and minimum price available at the url "/search". Using this a junior developer created this function in views.py.

```python
  def product_search(request):
    category = request.GET['category']
    min_price = request.GET['price_min']
    
    products = Product.objects.filter(
        category=category,
        price__gte=min_price
    )
    return render(request, 'products.html', {'products': products})
```

Comment on the suitability of the code to satisfy these requirements and what changes (if any) you would make.

-  The code is retrieving variables from request.GET without checking that they exist. It assumes a user will always hit the search url with GET parameters. 

-  A user can visit that URL without providing these parameters, the code never checks if they are null (or if they exist at all) so the code will break on a KeyError. 

-  Additionally, it is not guaranteed that the filter operation will return anything (it may be an empty list) , this may be covered in the template