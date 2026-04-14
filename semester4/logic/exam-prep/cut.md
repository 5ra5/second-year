A **cut** in Prolog is a special operator written as `!` which is used to **control backtracking**. The cut always succeeds, but it has the effect of **preventing Prolog from reconsidering alternative choices made before the cut**.

When Prolog evaluates a rule of the form:

```prolog
p :- A1, A2, ..., Am, !, B1, ..., Bn.
```

execution proceeds normally until the cut is reached. Once the cut is passed:

- all alternative solutions for the goals `A1, ..., Am` are **discarded**
- no alternative clauses for `p` will be considered
- the current solution is effectively **frozen**

Thus, the cut **prunes the search tree** and restricts backtracking.

### Example

```prolog
p(X) :- q(X), !, r(X).  
p(X) :- s(X).
```
If `q(X)` succeeds for some value of `X`, the cut is reached and Prolog commits to this clause. Even if `r(X)` later fails, Prolog will **not backtrack to try `s(X)`**, because the cut prevents this.

### Why cuts are used

Cuts are used to:

- improve efficiency by eliminating unnecessary parts of the search tree
- reduce memory usage by limiting stored backtracking points
- make predicates deterministic (i.e. return only one solution)

### Types of cuts

- **Green cuts**: do not change the logical meaning, only improve efficiency
- **Red cuts**: change the meaning of the program and can remove valid solutions

### Conclusion

Cuts are a powerful control mechanism in Prolog for managing backtracking and improving efficiency, but must be used carefully as they can alter the logical meaning of a program.

---