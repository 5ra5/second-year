focus on understanding the three-component pattern: **template**, **view**, **URL**
## Create a new Django project

```bash
django-admin startproject myproject .
```

## manage.py common commands

-  you don't need to edit manage.py - it's like a control panel for your project
-  instead you can run these commands through manage.py

start the development web server
```bash
python manage.py runserver
```

apply database changes
```bash
python manage.py migrate
```

create an admin user
```bash
python manage.py createsuperuser
```

create a new application within the project
```bash
python manage.py startapp
```


## key settings in settings.py

When True, Django shows detailed error pages. Set to False in production to hide sensitive information.
```python
DEBUG = True
```

 A list of domain names this site can serve. Empty during development, but must be set in production.
```python
ALLOWED_HOSTS = []
```

A list of all Django applications that are active in this project. You add your own apps later.
```python
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
]
```

Configuration for your database connection. Django uses SQLite
```python
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.sqlite3',
        'NAME': BASE_DIR / 'db.sqlite3',
    }
}
```

## Projects vs Apps

**PROJECT** = entire web application - it contains configuration, settings, and one or more apps.
**APP** = self-contained module that does one specific thing. Apps are building blocks of a Django project.

## Creating an app

```bash
python manage.py startapp pages
```

## How URL Routing Works

When a request comes in, Django processes URLs like this:
```
Request: http://127.0.0.1:8000/about/

1. Django checks myproject/urls.py
2. '' matches the start of 'about/', so it includes pages.urls
3. Django checks pages/urls.py with the remaining 'about/'
4. 'about/' matches, so it calls views.about
5. The view returns a response
```

