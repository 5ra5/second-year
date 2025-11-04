# 02-docker-run-detached

Makefile
```shell
name = $(notdir $(PWD))

start up run:
	docker compose up --detach

get:
	wget -O - -q http://localhost:8000/

connect:
	docker exec -it $(name)-web-1 bash

down stop:
	docker compose down

.PHONY: start up run get down stop

```

docker-compose.yml
```shell
services:
  web:
    image: "httpd:latest"
    ports:
      - "8000:80"
```

# 03a-redis
Makefile
```shell

name = $(notdir $(PWD))

start up run:
	docker compose up --detach

get increment count:
	redis-cli incr count

down stop:
	docker compose down

.PHONY: start up run increment count down stop
```

docker-compose.yml
```shell
services:
  web:
    image: "redis:latest"
    ports:
      - "6379:6379"
```

# 05-custom-image-2-dockerfile
Dockerfile
```shell
FROM httpd:latest
COPY nobody.txt /usr/local/apache2/htdocs/
```

Makefile
```shell

name = $(notdir $(PWD))

start up run:
	docker compose up --detach

get:
	wget -O - -q http://localhost:8000/
	wget -O - -q http://localhost:8000/nobody.txt

down stop:
	docker compose down

.PHONY: start up run get down stop

```

docker-compose.yml
```shell
services:
  web:
    build: .
    ports:
      - "8000:80"
```


# 06-nodejs-express-demo-1

Dockerfile
```shell
FROM node:latest
RUN mkdir /app
WORKDIR /app
RUN npm install express
CMD ["node", "app.js"]
EXPOSE 80

# We put this *last*, because this is the element of this configuration
# most likely to change.  And when that happens, rebuilding the image
# requires fewer new layes.
COPY app.js .

```

Makefile
```shell

name = $(notdir $(PWD))

start up run:
	docker compose up --detach

get:
	wget -O - -q http://localhost:8000/

down stop:
	docker compose down

.PHONY: start up run get down stop

```

docker-compose.yml
```shell
services:
  web:
    build: .
    ports:
      - "8000:80"
```
