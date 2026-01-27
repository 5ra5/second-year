
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

`man execlp`

```shell
execl, execlp, execle, execv, execvp, execvpe - execute a file

The exec() family of functions replaces the current process image with a new process image.

The initial argument for these functions is the name of a file that is to be executed.

The _const char *arg_ and subsequent ellipses in the execl(), execlp(), and execle() functions can be thought of as _arg0_, _arg1_, ..., _argn_. Together they describe a list of one or more pointers to null-terminated strings that represent the argument list available to the executed program. The first argument, by convention, should point to the filename associated with the file being executed. The list of arguments _must_ be terminated by a NULL pointer, and, since these are variadic functions, this pointer must be cast _(char *) NULL_.

The execv(), execvp(), and execvpe() functions provide an array of pointers to null-terminated strings that represent the argument list available to the new program. The first argument, by convention, should point to the filename associated with the file being executed. The array of pointers _must_ be terminated by a NULL pointer.

The execle() and execvpe() functions allow the caller to specify the environment of the executed program via the argument _envp_. The _envp_ argument is an array of pointers to null-terminated strings and _must_ be terminated by a NULL pointer. The other functions take the environment for the new process image from the external variable _environ_ in the calling process.


Special semantics for execlp() and execvp()

The execlp(), execvp(), and execvpe() functions duplicate the actions of the shell in searching for an executable file if the specified filename does not contain a slash (/) character. The file is sought in the colon-separated list of directory pathnames specified in the **PATH** environment variable. If this variable isnt defined, the path list defaults to the current directory followed by the list of directories returned by _confstr(_CS_PATH)_. (This **[confstr](https://linux.die.net/man/3/confstr)**(3) call typically returns the value "/bin:/usr/bin".)

If the specified filename includes a slash character, then **PATH** is ignored, and the file at the specified pathname is executed.

In addition, certain errors are treated specially.

If permission is denied for a file (the attempted **[execve](https://linux.die.net/man/2/execve)**(2) failed with the error **EACCES**), these functions will continue searching the rest of the search path. If no other file is found, however, they will return with _errno_ set to **EACCES**.

If the header of a file isnt recognized (the attempted **[execve](https://linux.die.net/man/2/execve)**(2) failed with the error **ENOEXEC**), these functions will execute the shell (_/bin/sh_) with the path of the file as its first argument. (If this attempt fails, no further searching is done.)

The **exec**() functions only return if an error has occurred. The return value is -1, and _errno_ is set to indicate the error.
```

```c
cpid = wait(&status);
```

&status passed by reference to wait system call - this allows the parent to obtain the exit status of a child process
when the process terminates, all its resources are deallocated but it remains in the process table until the parent process calls wait
this is because the process table contains process's exit status
a process which is terminated but whose parent has not called wait is known as a zombie process

# activity 4

**two most important system calls here**
1.  **clone()** = this is the system call **fork()** uses to clone a process (creating a child process)
2.  **write()** = this is used in places to write text to stdout

```shell
strace ./newproc-posix

execve("./newproc-posix", ["./newproc-posix"], 0x7ffd0c0d9f80 /* 97 vars */) = 0
brk(NULL)                               = 0x580f90ba7000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7cf577e66000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=118779, ...}) = 0
mmap(NULL, 118779, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7cf577e49000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7cf577c00000
mmap(0x7cf577c28000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7cf577c28000
mmap(0x7cf577db0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7cf577db0000
mmap(0x7cf577dff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7cf577dff000
mmap(0x7cf577e05000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7cf577e05000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7cf577e46000
arch_prctl(ARCH_SET_FS, 0x7cf577e46740) = 0
set_tid_address(0x7cf577e46a10)         = 28818
set_robust_list(0x7cf577e46a20, 24)     = 0
rseq(0x7cf577e47060, 0x20, 0, 0x53053053) = 0
mprotect(0x7cf577dff000, 16384, PROT_READ) = 0
mprotect(0x580f52c3a000, 4096, PROT_READ) = 0
mprotect(0x7cf577e9e000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7cf577e49000, 118779)          = 0
clone(child_stack=NULL, flags=CLONE_CHILD_CLEARTID|CLONE_CHILD_SETTID|SIGCHLD, child_tidptr=0x7cf577e46a10) = 28819
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}) = 0
getrandom(I am the child 0
"\xeb\xa5\x79\x16\x7e\x8f\x04\xe8", 8, GRND_NONBLOCK) = 8
brk(NULL)                               = 0x580f90ba7000
brk(0x580f90bc8000)                     = 0x580f90bc8000
write(1, "I am the parent 28819\n", 22I am the parent 28819
) = 22
wait4(-1, '3 notes.md'   layout2           layout3     layout.c        newproc-posix.c
 layout        layout2.c   layout3.c   newproc-posix
[{WIFEXITED(s) && WEXITSTATUS(s) == 0}], 0, NULL) = 28819
--- SIGCHLD {si_signo=SIGCHLD, si_code=CLD_EXITED, si_pid=28819, si_uid=1000, si_status=0, si_utime=0, si_stime=0} ---
write(1, "Child Complete (pid=28819) with "..., 41Child Complete (pid=28819) with status=0
) = 41
exit_group(0)                           = ?
+++ exited with 0 +++
```


```shell
strace -e 'fork,write' ./newproc-posix 
I am the child 0
write(1, "I am the parent 30614\n", 22I am the parent 30614
) = 22
'3 notes.md'   layout2     layout3     layout.c        newproc-posix.c
 layout        layout2.c   layout3.c   newproc-posix
--- SIGCHLD {si_signo=SIGCHLD, si_code=CLD_EXITED, si_pid=30614, si_uid=1000, si_status=0, si_utime=0, si_stime=0} ---
write(1, "Child Complete (pid=30614) with "..., 41Child Complete (pid=30614) with status=0
) = 41
+++ exited with 0 +++
```

we need to tell strace to trace child processes as they are created by currently traced process using -f

```shell
execve("./newproc-posix", ["./newproc-posix"], 0x7ffc611f99d8 /* 97 vars */) = 0
brk(NULL)                               = 0x5788ef618000
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7c0f14fca000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=118779, ...}) = 0
mmap(NULL, 118779, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7c0f14fad000
close(3)                                = 0
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7c0f14c00000
mmap(0x7c0f14c28000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7c0f14c28000
mmap(0x7c0f14db0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x7c0f14db0000
mmap(0x7c0f14dff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x7c0f14dff000
mmap(0x7c0f14e05000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7c0f14e05000
close(3)                                = 0
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7c0f14faa000
arch_prctl(ARCH_SET_FS, 0x7c0f14faa740) = 0
set_tid_address(0x7c0f14faaa10)         = 31794
set_robust_list(0x7c0f14faaa20, 24)     = 0
rseq(0x7c0f14fab060, 0x20, 0, 0x53053053) = 0
mprotect(0x7c0f14dff000, 16384, PROT_READ) = 0
mprotect(0x5788c6db3000, 4096, PROT_READ) = 0
mprotect(0x7c0f15002000, 8192, PROT_READ) = 0
prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
munmap(0x7c0f14fad000, 118779)          = 0
clone(child_stack=NULL, flags=CLONE_CHILD_CLEARTID|CLONE_CHILD_SETTID|SIGCHLDstrace: Process 31795 attached
, child_tidptr=0x7c0f14faaa10) = 31795
[pid 31795] set_robust_list(0x7c0f14faaa20, 24 <unfinished ...>
[pid 31794] fstat(1,  <unfinished ...>
[pid 31795] <... set_robust_list resumed>) = 0
[pid 31794] <... fstat resumed>{st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}) = 0
[pid 31794] getrandom( <unfinished ...>
[pid 31795] fstat(1,  <unfinished ...>
[pid 31794] <... getrandom resumed>"\xea\x68\x72\x29\xe1\xfc\xdb\x2c", 8, GRND_NONBLOCK) = 8
[pid 31795] <... fstat resumed>{st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}) = 0
[pid 31794] brk(NULL <unfinished ...>
[pid 31795] getrandom( <unfinished ...>
[pid 31794] <... brk resumed>)          = 0x5788ef618000
[pid 31795] <... getrandom resumed>"\xc8\xf6\xd1\x54\x37\x70\x6f\x1e", 8, GRND_NONBLOCK) = 8
[pid 31794] brk(0x5788ef639000 <unfinished ...>
[pid 31795] brk(NULL <unfinished ...>
[pid 31794] <... brk resumed>)          = 0x5788ef639000
[pid 31795] <... brk resumed>)          = 0x5788ef618000
[pid 31794] write(1, "I am the parent 31795\n", 22 <unfinished ...>
I am the parent 31795
[pid 31795] brk(0x5788ef639000 <unfinished ...>
[pid 31794] <... write resumed>)        = 22
[pid 31795] <... brk resumed>)          = 0x5788ef639000
[pid 31794] wait4(-1,  <unfinished ...>
[pid 31795] write(1, "I am the child 0\n", 17I am the child 0
) = 17
[pid 31795] execve("/bin/ls", ["ls"], 0x7ffd6c920758 /* 97 vars */) = 0
[pid 31795] brk(NULL)                   = 0x624eca457000
[pid 31795] mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x77083d82b000
[pid 31795] access("/etc/ld.so.preload", R_OK) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=118779, ...}) = 0
[pid 31795] mmap(NULL, 118779, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d80e000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=174472, ...}) = 0
[pid 31795] mmap(NULL, 181960, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x77083d7e1000
[pid 31795] mmap(0x77083d7e7000, 118784, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x77083d7e7000
[pid 31795] mmap(0x77083d804000, 24576, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x23000) = 0x77083d804000
[pid 31795] mmap(0x77083d80a000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x29000) = 0x77083d80a000
[pid 31795] mmap(0x77083d80c000, 5832, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x77083d80c000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\220\243\2\0\0\0\0\0"..., 832) = 832
[pid 31795] pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
[pid 31795] fstat(3, {st_mode=S_IFREG|0755, st_size=2125328, ...}) = 0
[pid 31795] pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
[pid 31795] mmap(NULL, 2170256, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x77083d400000
[pid 31795] mmap(0x77083d428000, 1605632, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x77083d428000
[pid 31795] mmap(0x77083d5b0000, 323584, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0x77083d5b0000
[pid 31795] mmap(0x77083d5ff000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1fe000) = 0x77083d5ff000
[pid 31795] mmap(0x77083d605000, 52624, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x77083d605000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libpcre2-8.so.0", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=625344, ...}) = 0
[pid 31795] mmap(NULL, 627472, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x77083d747000
[pid 31795] mmap(0x77083d749000, 450560, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x2000) = 0x77083d749000
[pid 31795] mmap(0x77083d7b7000, 163840, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x70000) = 0x77083d7b7000
[pid 31795] mmap(0x77083d7df000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x97000) = 0x77083d7df000
[pid 31795] close(3)                    = 0
[pid 31795] mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x77083d744000
[pid 31795] arch_prctl(ARCH_SET_FS, 0x77083d744800) = 0
[pid 31795] set_tid_address(0x77083d744ad0) = 31795
[pid 31795] set_robust_list(0x77083d744ae0, 24) = 0
[pid 31795] rseq(0x77083d745120, 0x20, 0, 0x53053053) = 0
[pid 31795] mprotect(0x77083d5ff000, 16384, PROT_READ) = 0
[pid 31795] mprotect(0x77083d7df000, 4096, PROT_READ) = 0
[pid 31795] mprotect(0x77083d80a000, 4096, PROT_READ) = 0
[pid 31795] mprotect(0x624eb3810000, 8192, PROT_READ) = 0
[pid 31795] mprotect(0x77083d863000, 8192, PROT_READ) = 0
[pid 31795] prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
[pid 31795] munmap(0x77083d80e000, 118779) = 0
[pid 31795] statfs("/sys/fs/selinux", 0x7fffd2761490) = -1 ENOENT (No such file or directory)
[pid 31795] statfs("/selinux", 0x7fffd2761490) = -1 ENOENT (No such file or directory)
[pid 31795] getrandom("\xa8\x7e\xd3\xb5\x39\xe4\xaf\x11", 8, GRND_NONBLOCK) = 8
[pid 31795] brk(NULL)                   = 0x624eca457000
[pid 31795] brk(0x624eca478000)         = 0x624eca478000
[pid 31795] openat(AT_FDCWD, "/proc/filesystems", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0444, st_size=0, ...}) = 0
[pid 31795] read(3, "nodev\tsysfs\nnodev\ttmpfs\nnodev\tbd"..., 1024) = 421
[pid 31795] read(3, "", 1024)           = 0
[pid 31795] close(3)                    = 0
[pid 31795] access("/etc/selinux/config", F_OK) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/share/locale/locale.alias", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=2996, ...}) = 0
[pid 31795] read(3, "# Locale name alias data base.\n#"..., 4096) = 2996
[pid 31795] read(3, "", 4096)           = 0
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_IDENTIFICATION", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_IDENTIFICATION", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_IDENTIFICATION", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=345, ...}) = 0
[pid 31795] mmap(NULL, 345, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d82a000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/usr/lib/x86_64-linux-gnu/gconv/gconv-modules.cache", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=27028, ...}) = 0
[pid 31795] mmap(NULL, 27028, PROT_READ, MAP_SHARED, 3, 0) = 0x77083d823000
[pid 31795] close(3)                    = 0
[pid 31795] futex(0x77083d60472c, FUTEX_WAKE_PRIVATE, 2147483647) = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_MEASUREMENT", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_MEASUREMENT", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_MEASUREMENT", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=23, ...}) = 0
[pid 31795] mmap(NULL, 23, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d822000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_TELEPHONE", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_TELEPHONE", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_TELEPHONE", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=52, ...}) = 0
[pid 31795] mmap(NULL, 52, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d821000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_ADDRESS", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_ADDRESS", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_ADDRESS", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=154, ...}) = 0
[pid 31795] mmap(NULL, 154, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d820000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_NAME", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_NAME", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_NAME", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=62, ...}) = 0
[pid 31795] mmap(NULL, 62, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d81f000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_PAPER", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_PAPER", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_PAPER", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=34, ...}) = 0
[pid 31795] mmap(NULL, 34, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d81e000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_MESSAGES", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_MESSAGES", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_MESSAGES", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFDIR|0755, st_size=38, ...}) = 0
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_MESSAGES/SYS_LC_MESSAGES", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=57, ...}) = 0
[pid 31795] mmap(NULL, 57, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d81d000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_MONETARY", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_MONETARY", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_MONETARY", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=294, ...}) = 0
[pid 31795] mmap(NULL, 294, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d81c000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_COLLATE", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_COLLATE", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_COLLATE", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=2586930, ...}) = 0
[pid 31795] mmap(NULL, 2586930, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d188000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_TIME", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_TIME", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_TIME", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=3216, ...}) = 0
[pid 31795] mmap(NULL, 3216, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d81b000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_NUMERIC", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_NUMERIC", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_NUMERIC", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=54, ...}) = 0
[pid 31795] mmap(NULL, 54, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d81a000
[pid 31795] close(3)                    = 0
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.UTF-8/LC_CTYPE", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/usr/lib/locale/en_IE.UTF-8/LC_CTYPE", O_RDONLY|O_CLOEXEC) = -1 ENOENT (No such file or directory)
[pid 31795] openat(AT_FDCWD, "/snap/code/220/usr/lib/locale/en_IE.utf8/LC_CTYPE", O_RDONLY|O_CLOEXEC) = 3
[pid 31795] fstat(3, {st_mode=S_IFREG|0644, st_size=340640, ...}) = 0
[pid 31795] mmap(NULL, 340640, PROT_READ, MAP_PRIVATE, 3, 0) = 0x77083d6f0000
[pid 31795] close(3)                    = 0
[pid 31795] ioctl(1, TCGETS, {c_iflag=BRKINT|ICRNL|IXON|IXANY|IMAXBEL|IUTF8, c_oflag=NL0|CR0|TAB0|BS0|VT0|FF0|OPOST|ONLCR, c_cflag=B38400|CS8|CREAD|HUPCL, c_lflag=ISIG|ICANON|ECHO|ECHOE|ECHOK|IEXTEN|ECHOCTL|ECHOKE, ...}) = 0
[pid 31795] ioctl(1, TIOCGWINSZ, {ws_row=19, ws_col=84, ws_xpixel=0, ws_ypixel=0}) = 0
[pid 31795] openat(AT_FDCWD, ".", O_RDONLY|O_NONBLOCK|O_CLOEXEC|O_DIRECTORY) = 3
[pid 31795] fstat(3, {st_mode=S_IFDIR|0775, st_size=4096, ...}) = 0
[pid 31795] getdents64(3, 0x624eca467cf0 /* 11 entries */, 32768) = 352
[pid 31795] getdents64(3, 0x624eca467cf0 /* 0 entries */, 32768) = 0
[pid 31795] close(3)                    = 0
[pid 31795] fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0), ...}) = 0
[pid 31795] write(1, "'3 notes.md'   layout2\t   layout"..., 70'3 notes.md'   layout2          layout3     layout.c        newproc-posix.c
) = 70
[pid 31795] write(1, " layout        layout2.c   layou"..., 53 layout        layout2.c   layout3.c   newproc-posix
) = 53
[pid 31795] close(1)                    = 0
[pid 31795] close(2)                    = 0
[pid 31795] exit_group(0)               = ?
[pid 31795] +++ exited with 0 +++
<... wait4 resumed>[{WIFEXITED(s) && WEXITSTATUS(s) == 0}], 0, NULL) = 31795
--- SIGCHLD {si_signo=SIGCHLD, si_code=CLD_EXITED, si_pid=31795, si_uid=1000, si_status=0, si_utime=0, si_stime=0} ---
write(1, "Child Complete (pid=31795) with "..., 41Child Complete (pid=31795) with status=0
) = 41
exit_group(0)                           = ?
+++ exited with 0 +++
```

https://man7.org/linux/man-pages/man1/strace.1.html - man strace

# activity 6

`systemd --user` runs an independent instance of the systemd init system for each user, allowing management of services with user privileges rather than root

# activity 7

man ps
```
ps - report a snapshot of the current processes.

       **ps** displays information about a selection of the active processes.
       If you want a repetitive update of the selection and the displayed
       information, use **top** instead.

       This version of **ps** accepts several kinds of options.

       •   Unix options, which may be grouped and must be preceded by a
           dash.

       •   BSD options, which may be grouped and must not be used with a
           dash.

       •   GNU long options, which are preceded by two dashes.

       Options of different types may be freely mixed, but conflicts can
       appear.  There are some synonymous options, which are functionally
       identical, due to the many standards and **ps** implementations that
       this **ps** is compatible with.

       By default, **ps** selects all processes with the same effective user
       ID (euid=EUID) as the current user and associated with the same
       terminal as the invoker.  It displays the process ID (pid=PID),
       the terminal associated with the process (tname=TTY), the
       cumulated CPU time in [DD-]hh:mm:ss format (time=TIME), and the
       executable name (ucmd=CMD).  Output is unsorted by default.

       The use of BSD-style options will add process state (stat=STAT) to
       the default display and show the command args (args=COMMAND)
       instead of the executable name.  You can override this with the
       **PS_FORMAT** environment variable.  The use of BSD-style options will
       also change the process selection to include processes on other
       terminals (TTYs) that are owned by you; alternately, this may be
       described as setting the selection to be the set of all processes
       filtered to exclude processes owned by other users or not on a
       terminal.  These effects are not considered when options are
       described as being "identical" below, so **-M** will be considered
       identical to **Z** and so on.

       Except as described below, process selection options are additive.
       The default selection is discarded, and then the selected
       processes are added to the set of processes to be displayed.  A
       process will thus be shown if it meets any of the given selection
       criteria.
       
       To see every process on the system using standard syntax:
          **ps -e**
          **ps -ef**
          **ps -eF**
          **ps -ely**

       To see every process on the system using BSD syntax:
          **ps ax**
          **ps axu**

       To print a process tree:
          **ps -ejH**
          **ps axjf**

       To get info about threads:
          **ps -eLf**
          **ps axms**

       To get security info:
          **ps -eo euser,ruser,suser,fuser,f,comm,label**
          **ps axZ**
          **ps -eM**

       To see every process running as root (real & effective ID) in user
       format:
          **ps -U root -u root u**

       To see every process with a user-defined format:
          **ps -eo pid,tid,class,rtprio,ni,pri,psr,pcpu,stat,wchan:14,comm**
          **ps axo stat,euid,ruid,tty,tpgid,sess,pgrp,ppid,pid,pcpu,comm**
          **ps -Ao pid,tt,user,fname,tmout,f,wchan**

       Print only the process IDs of syslogd:
          **ps -C syslogd -o pid=**

       Print only the name of PID 42:
          **ps -q 42 -o comm=**
```

man pstree
```shell
pstree - display a tree of processes

       **pstree** shows running processes as a tree.  The tree is rooted at
       either _pid_ or **init** if _pid_ is omitted.  If a user name is
       specified, all process trees rooted at processes owned by that
       user are shown.

       **pstree** visually merges identical branches by putting them in
       square brackets and prefixing them with the repetition count, e.g.

           init-+-getty
                |-getty
                |-getty
                `-getty

       becomes

           init---4*[getty]

       Child threads of a process are found under the parent process and
       are shown with the process name in curly braces, e.g.

           icecast2---13*[{icecast2}]

       If **pstree** is called as **pstree.x11** then it will prompt the user at
       the end of the line to press return and will not return until that
       has happened.  This is useful for when **pstree** is run in a
       xterminal.

       Certain kernel or mount parameters, such as the _hidepid_ option for
       procfs, will hide information for some processes. In these
       situations **pstree** will attempt to build the tree without this
       information, showing process names as question marks.

## [](https://man7.org/linux/man-pages/man1/pstree.1.html#OPTIONS)OPTIONS         [top](https://man7.org/linux/man-pages/man1/pstree.1.html#top_of_page)

       **-a**, **--arguments**
              Show command line arguments.  If the command line of a
              process is swapped out, that process is shown in
              parentheses.  **-a** implicitly disables compaction for
              processes but not threads.

       **-A**, **--ascii**
              Use ASCII characters to draw the tree.

       **-c**, **--compact-not**
              Disable compaction of identical subtrees.  By default,
              subtrees are compacted whenever possible.

       **-C**, **--color=**_TYPE_
              Color the process name by given attribute. Currently **pstree**
              only accepts the value **age** which colors by process age.
              Processes newer than 60 seconds are green, newer than an
              hour yellow and the remaining red.

       **-g**, **--show-pgids**
              Show PGIDs.  Process Group IDs are shown as decimal numbers
              in parentheses after each process name.  If both PIDs and
              PGIDs are displayed then PIDs are shown first.

       **-G**, **--vt100**
              Use VT100 line drawing characters.

       **-h**, **--hightlight-all**
              Highlight the current process and its ancestors.  This is a
              no-op if the terminal doesnt support highlighting or if
              neither the current process nor any of its ancestors are in
              the subtree being shown.

       **-H**, **--highlight-pid=**_PID_
              Like **-h**, but highlight the specified process instead.
              Unlike with **-h**, **pstree** fails when using **-H** if highlighting
              is not available.

       **-k**, **--kthreads**
              Show kernel threads.

       **-l**, **--long**
              Display long lines.  By default, lines are truncated to
              either the COLUMNS environment variable or the display
              width.  If neither of these methods work, the default of
              132 columns is used.

       **-n**, **--numeric-sort**
              Sort processes with the same parent by PID instead of by
              name.  (Numeric sort.)

       **-N**, **--ns-sort=**_TYPE_
              Show individual trees for each namespace of _TYPE_.  The
              available types are: _ipc_, _mnt_, _net_, _pid_, _time_, _user_, _uts_.
              Regular users dont have access to other users processes
              information, so the output will be limited.

       **-p**, **--show-pids**
              Show PIDs.  PIDs are shown as decimal numbers in
              parentheses after each process name.  **-p** implicitly
              disables compaction.

       **-P --show-paths**
              Show the full path to the running process on disk.

       **-s**, **--show-parents**
              Show parent processes of the specified process.

       **-S**, **--ns-changes**
              Show namespaces transitions.  Like **-N**, the output is
              limited when running as a regular user.

       **-t**, **--thread-names**
              Show full names for threads when available.

       **-T**, **--hide-threads**
              Hide threads and only show processes.

       **-u**, **--uid-changes**
              Show uid transitions.  Whenever the uid of a process
              differs from the uid of its parent, the new uid is shown in
              parentheses after the process name.

       **-U**, **--unicode**
              Use UTF-8 (Unicode) line drawing characters.  Under Linux
              1.1-54 and above, UTF-8 mode is entered on the console with
              **echo -e ' 33%8'** and left with **echo -e ' 33%@'**.

       **-V**, **--version**
              Display version information.

       **-Z**, **--security-context**
              Show the current security attributes of the process. For
              SELinux systems this will be the security context.
```

man kill
```shell
kill - terminate a process

   The command **kill** sends the specified _signal_ to the specified
       processes or process groups.

       If no signal is specified, the **TERM** signal is sent. The default
       action for this signal is to terminate the process. This signal
       should be used in preference to the **KILL** signal (number 9), since
       a process may install a handler for the TERM signal in order to
       perform clean-up steps before terminating in an orderly fashion.
       If a process does not terminate after a **TERM** signal has been sent,
       then the **KILL** signal may be used; be aware that the latter signal
       cannot be caught, and so does not give the target process the
       opportunity to perform any clean-up before terminating.

       Most modern shells have a builtin **kill** command, with a usage
       rather similar to that of the command described here. The **--all**,
       **--pid**, and **--queue** options, and the possibility to specify
       processes by command name, are local extensions.

       If _signal_ is 0, then no actual signal is sent, but error checking
       is still performed
       
       
       **-s**, **--signal** _signal_
           The signal to send. It may be given as a name or a number.

       **-l**, **--list** [_number_|0x_sigmask_]
           Print a list of signal names, convert the given signal number
           to a name, or convert the given signal mask to names. The
           signals can be found in _/usr/include/linux/signal.h_.
           
           If neither **NUMBER** nor 0x**SIGMASK** is given, list all signal
           names. In that case, print one signal per line when the output
           is not a terminal.

       **-L**, **--table**
           Similar to **-l**, but it will print signal names and their
           corresponding numbers. Print one signal per line when the
           output is not a terminal.

       **-a**, **--all**
           Do not restrict the command-name-to-PID conversion to
           processes with the same UID as the present process.

       **-p**, **--pid**
           Only print the process ID (PID) of the named processes, do not
           send any signals.

       **-r**, **--require-handler**
           Do not send the signal if it is not caught in userspace by the
           signalled process.

       **--verbose**
           Print PID(s) that will be signaled with **kill** along with the
           signal.

       **-q**, **--queue** _value_
           Send the signal using [sigqueue(3)](https://man7.org/linux/man-pages/man3/sigqueue.3.html) rather than [kill(2)](https://man7.org/linux/man-pages/man2/kill.2.html). The
           _value_ argument is an integer that is sent along with the
           signal. If the receiving process has installed a handler for
           this signal using the **SA_SIGINFO** flag to [sigaction(2)](https://man7.org/linux/man-pages/man2/sigaction.2.html), then it
           can obtain this data via the _si_sigval_ field of the _siginfo_t_
           structure.

       **--timeout** _milliseconds signal_
           Send a signal defined in the usual way to a process, followed
           by an additional signal after a specified delay. The **--timeout**
           option causes **kill** to wait for a period defined in
           _milliseconds_ before sending a follow-up _signal_ to the process.
           This feature is implemented using the Linux kernel PID file
           descriptor feature in order to guarantee that the follow-up
           signal is sent to the same process or not sent if the process
           no longer exists.

           Note that the operating system may re-use PIDs and
           implementing an equivalent feature in a shell using **kill** and
           **sleep** would be subject to races whereby the follow-up signal
           might be sent to a different process that used a recycled PID.

           The **--timeout** option can be specified multiple times: the
           signals are sent sequentially with the specified timeouts. The
           **--timeout** option can be combined with the **--queue** option.

           As an example, the following command sends the signals **QUIT**,
           **TERM** and **KILL** in sequence and waits for 1000 milliseconds
           between sending the signals:

               kill --verbose --timeout 1000 TERM --timeout 1000 KILL \
                       --signal QUIT 12345

       **-d**, **--show-process-state** _pid_
           Decode signal related fields in /proc/_pid_/status.

               $ kill -d $$
               Blocked: INT
               Ignored: TERM TSTP TTIN TTOU
               Caught: HUP INT PIPE ALRM CHLD WINCH

       **-h**, **--help**
           Display help text and exit.

       **-V**, **--version**
           Display version and exit
```

# activity 8

when we statically compile, it links in the glibc functions called into the executable i.e. this means it does not require glibc to be present as a shared library on the target machine
when we dynamically compile, we are assuming glibc will be available on the target machine, and can be loaded at runtime

**we can see from the relative file sizes (static is larger), differences in the output of the ldd command (no output for the static because it doesn't require glibc), and importantly, in the dynamic symbol table from both executables, that the dynamically compiled version will require glibc to be available at runtime as a shared library, while the statically compiled has this code directly compiled into the executable**

# activity 10

-  building my own CLI - languages to consider: shell, C, C++, python for tools etc.
-  `fork()` would use `clone()` to make new processes
-  `wait()` and `exit()` would manage the termination of child and parent processes
-  `write()` would print output to the command line and files