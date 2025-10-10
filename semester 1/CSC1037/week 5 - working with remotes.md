Create a bare repository (a repository with no associated working tree - no checked out files)
```
git init -bare
```

**ORIGIN** = the default name for the remote repository that a project was cloned from
**MASTER/MAIN** = the default main branch in a Git repository

- Manage and view remotes 
```
git remote # which remotes git knows about
-> origin

git remote -v # additional details, including URL
-> origin https://gitlab.computing.dcu.ie:ZhouB/csc1037
```


- see all branches (including remote branches)
```
git branch -a

-> remotes/origin/HEAD -> origin/main
-> remotes/origin/c
-> ...
```


**Propagating changes**

**FETCH** = downloads new commits and branches from remote repository but doesn't merge them into the working local branch
- fetch all new commits and branches from (usually) origin:
```
git fetch
```

- the same thing, but naming the remote from which we want to fetch:
```
git fetch origin
```

-  It is safer to fetch and merge  instead of pull to avoid merging conflicts
```
git checkout master
git fetch origin
git merge origin/master
```

**PULL** = fetches and merges changes from a remote branch into your current local branch. equivalent to ```git fetch + git merge``` 
```
git pull origin master
git pull
```

**PUSH** = uploads your committed changes from your local repository to a remote repository
```
git push origin master
git push
```

```
git touch AliceC
git add AliceC
git commit -m "add a new name AliceC"
git push
```


- pull changes from a remote branch
- ```
  git pull origin master
  ```

- merge changes from the local cache of a remote
```
git merge origin/master
```



**MAKEFILE** = a file defining build and test automation rules used by make tool.
**MAKE BUILD** = command that complies code according to rules in the makefile
**MAKE TEST** = command that runs automated tests defined in the makefile