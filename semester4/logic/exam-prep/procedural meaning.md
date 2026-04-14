A Prolog program has both a **declarative meaning** and a **procedural meaning**. The procedural meaning describes **how the Prolog run-time system executes a query** to determine whether a set of goals succeeds .

Given a goal list:

```prolog
G1, G2, ..., Gn
```

Prolog evaluates it using the following process:

1. If the goal list is empty, return success
2. Search the program from **top to bottom** for a clause whose head matches the first goal
3. If no such clause exists, return failure
4. If a matching clause is found:
    - match (unify) the goal with the head of the clause
    - replace the goal with the body of the clause
    - apply the variable substitutions
5. Repeat the process on the new goal list

---

### Example

parent(john, mary).  
parent(mary, ann).  
  
ancestor(X,Y) :- parent(X,Y).  
ancestor(X,Y) :- parent(X,Z), ancestor(Z,Y).

Query:

```prolog
?- ancestor(john, ann).
```

Execution proceeds as follows:

- Try first clause: `parent(john, ann)` → fails
- Try second clause: `parent(john, Z), ancestor(Z, ann)`
- Match gives `Z = mary`
- New goal: `ancestor(mary, ann)`
- This matches `parent(mary, ann)` → succeeds

Since all goals succeed, the query succeeds.

---

### Backtracking

If a goal fails, Prolog **backtracks** to the most recent choice point and tries alternative clauses or variable bindings. This continues until a solution is found or all possibilities are exhausted.

---

### Key features

- Top-to-bottom clause selection
- Left-to-right goal evaluation
- Depth-first search strategy
- Backtracking to explore alternatives

---

### Conclusion

The procedural interpretation explains how Prolog executes queries by systematically matching goals, applying rules, and using backtracking to find solutions. Understanding this is essential for writing efficient Prolog programs.