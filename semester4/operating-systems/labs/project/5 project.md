### I/O Redirection - Stage 2

The shell must support i/o-redirection on either or both stdin and/or stdout. i.e. the command line:

**programname arg1 arg2 < inputfile > outputfile**

will execute the program programname with arguments arg1 and arg2, the stdin FILE stream replaced by inputfile and the stdout FILE stream replaced by outputfile.

stdout redirection should also be possible for the internal commands: dir, environ, echo, and help.

With output redirection, if the redirection character is > then the outputfile is created if it does not exist and truncated if it does. If the redirection token is >> then outputfile is created if it does not exist and appended to if it does.

### Background Execution - Stage 2

The shell must support background execution of programs. This does not need to be implemented for internal commands but it should be implemented for "Other Commands". An ampersand , or & character, at the end of the command line indicates that the shell should return to the command line prompt immediately after launching that program whilst it continues to run in the background.

### Miscellaneous

The command line prompt must contain the pathname of the current directory. Note: you can assume that all command line arguments including the redirection symbols, <, > and >> and the background execution symbol, & will be delimited from other command line arguments by white space - one or more spaces and/or tabs (see the command line above). We should just have to type make to build your shell. There should be evidence in your code that you have attempted to handle errors. For example, if using fopen, freopen, etc you should check the return status and indicate if an error has occurred, and take appropriate action.

This stage represents getting more advanced functionality working. 

**Extend the code base you developed in Stage 1** to include the following functionality:

> External Commands: Forking and execing for external command execution, with the environment variable parent set accordingly.

> Background Execution: Support for background process execution using the & symbol.

> I/O Redirection: Implementation of input (<) and output (>, >>) redirection for both internal and external commands.


External command functionality (10 marks)  
I/O redirection (15 marks)  
Background execution (15 marks)  
A extended readme file (5 marks) - see “user manual” section for requirements for Stage 2.

```
/*Name: Petra Sartori

Student ID: 23324986

I acknowledge DCU Academic Integrity Policy while working on this project.

My work is my work only and is a result of research, practice and design which I did on my own.

This project does not contain any plagiarised content.*/
```