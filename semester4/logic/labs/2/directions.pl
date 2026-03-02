% facts that represent the grid
directlyNorth(a, f).
directlyNorth(b, g).
directlyNorth(c, h).
directlyNorth(d, i).
directlyNorth(e, j).
directlyNorth(f, k).
directlyNorth(g, l).
directlyNorth(h, m).
directlyNorth(i, n).
directlyNorth(j, o).
directlyNorth(k, p).
directlyNorth(l, q).
directlyNorth(m, r).
directlyNorth(n, s).
directlyNorth(o, t).

directlyWest(a, b).
directlyWest(b, c).
directlyWest(c, d).
directlyWest(d, e).
directlyWest(f, g).
directlyWest(g, h).
directlyWest(h, i).
directlyWest(i, j).
directlyWest(k, l).
directlyWest(l, m).
directlyWest(m, n).
directlyWest(n, o).
directlyWest(p, q).
directlyWest(q, r).
directlyWest(r, s).
directlyWest(s, t).

% rules
% all rules contain base case(one step) and recursion (multiple steps)

north(X, Y) :- directlyNorth(X, Y).
north(X, Y) :-
    directlyNorth(X, Z),
    north(Z, Y).

west(X, Y) :- directlyWest(X, Y).
west(X, Y) :-
    directlyWest(X, Z),
    west(Z, Y).

northWest(X, Y) :- directlyNorth(Z, Y), directlyWest(X, Z).
northWest(X, Y) :-
    directlyNorth(Z, Y),
    directlyWest(W, Z),
    northWest(X, W).