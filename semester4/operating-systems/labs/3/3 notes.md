
# activity 1

```shell
gcc layout.c -o layout

size layout

   text    data     bss     dec     hex filename
   1426     604      12    2042     7fa layout
```

text = instructions (code)
data = initialised data (e.g. int y = 15;)
bss = unitialised data (e.g. int x;)
dec = text + data + bss

**size** = reports ELF section sizes for the whole executable, including runtime and linked overhead, not just variables from your source file

# activity 2

```shell
gcc layout2.c -o layout2

size layout2

   text    data     bss     dec     hex filename
   1426     604      28    2058     80a layout2
```

-  instructions same
-  initialised data same
-  uninitialised data larger ( because we created more uninitialised variables a, b, c, d)
-  dec larger

```shell
gcc layout3.c -o layout3

size layout3

   text    data     bss     dec     hex filename
   1455     604      28    2087     827 layout3
```

-  instructions code is now larger after we included additional 'text' (code)
```c
values[0] = values[1] * values[2];
```

after adding 2 more initialised values the data goes up
```shell
   text    data     bss     dec     hex filename
   1455     612      28    2095     82f layout3
```

# activity 3

-  if there is no error with `fork()` then the pid > 0
-  the fork call has caused this process to now become two processes (parent and child)