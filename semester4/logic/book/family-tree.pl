parent(pam, bob).   % Pam is a parent of Bob.
parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(pat, jim).

female(pam).    % Pam is a female.
female(liz).
female(ann).
female(pat).

male(bob).
male(tom).  % Tom is a male.
male(jim).

% Y is an offspring of X if X is a parent of Y
offspring(Y, X) :- parent(X, Y).

% X is the mother of Y if X is female and X is a parent of Y
mother(X, Y) :- female(X), parent(X, Y).

% X is a grandparent of Y is X is a parent of Z and Z is a parent of Y
grandparent(X, Y) :- parent(X, Z), parent(Z, Y).

% X is a sister of Y if X is female and X and Y have the same parent and X and Y are different 
sister(X, Y) :- female(X), parent(Z, X), parent(Z, Y).

happy(X) :- parent(X, _).
hastwochildren(X) :- parent(X, Y), sister(_, Y).

grandchild(X, Y) :- parent(Y, Z), parent(Z, X).

aunt(X, Y) :- sister(X, Z), parent(Z, Y).

predecessor(X, Z) :- parent(X, Z).                    % Rule pr1: X is a predecessor of Z
predecessor(X, Z) :- parent(X, Y), predecessor(Y, Z). % Rule pr2: X is a predecessor of Z
