cd, clr, dir, environ, echo and pause.

fflush = It ensures that any unwritten data buffered in memory is written out to the file or terminal immediately.

Initially, I implemented output redirection for internal commands using freopen() without restoring the original stdout. This caused a bug where, after executing a command such as "dir > file.txt", the shell prompt and subsequent output were also redirected to the file instead of the terminal.

The issue occurred because internal commands run within the shell process, so modifying stdout directly affects the shell itself. As a result, stdout remained permanently redirected after the command finished.

To fix this, I introduced a store-and-restore approach using dup() and dup2(). The original stdout was saved before redirection, and after executing the command, fflush(stdout) ensured all output was written before restoring stdout to its original state. This ensured that redirection only applied to the command being executed and did not affect the shell's normal operation.