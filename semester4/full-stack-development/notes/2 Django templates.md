
protecting ourselves against user errors: URL patterns

```python
# views.py

from django.shortcuts import render

def home(request):
	username = request.GET.get('username', 'Default')
	return render(request, 'home.html', {'username':username})
	
def about(request):
	return render(request, 'about.html')
	
# /profile/1 -> alice
# /profile/2 -> bob
def profile(request, id):
	users = {
		1:{'username':'alice', 'age':30},
		2:{'username':'bob', 'age':25},
		3:{'username':'charlie', 'age':35},
	}
	
	user = users.get(id)
	if user is None:
		return render(request, 'not_found.html', {'error':"User with id {id} not found."})
	else:
		return render(request, 'profile.html', {'user':users[id]})
```

```python
# urls.py

from django.urls import path
from . import views

urlpatterns = {
	path("", views.home, name="home"),
	path("about/", views.about, name="about")
	path("profile/", views.profile, name="profile")
}
```

## Base template - blocks

-  Main principle = **don't repeat yourself**
base.html - using blocks to abstract our code, we don't need to have multiple .html files with the same long code 

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>{% block title %}My Site{% endblock %}</title>
</head>
<body>
    <nav>
        <a href="/">Home</a>
        <a href="/about/">About</a>
    </nav>

    <main>
        {% block content %}
        {% endblock %}
    </main>

    <footer>
        <p>&copy; 2024 My Site</p>
    </footer>
</body>
</html>
```

an example of a child page -  we extend base.html so we don't have so write the same html over and over in each page

```html
{% extends 'base.html' %}

{% block title %}Home{% endblock %}

{% block content %}
<h1>Welcome to My Site</h1>
<p>This is the home page. We have lots of interesting content here.</p>
{% endblock %}
```

## dealing with static content

new directory in pages -> static -> css
you need to make base.html changes - `{% load static %}`

```html
{% load static %}
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>{% block title %}My Site{% endblock %}</title>
    <link rel="stylesheet" href="{%static 'css/style.css' %}">
</head>
<body>
    <nav>
        <a href="/">Home</a>
        <a href="/about/">About</a>
    </nav>

    <main>
        {% block content %}
        {% endblock %}
    </main>

    <footer>
        <p>&copy; 2024 My Site</p>
    </footer>
</body>
</html>
```