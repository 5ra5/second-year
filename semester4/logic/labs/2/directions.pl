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

% rules - direct ways have both a base case and a recursive case
north(X, Y) :- directlyNorth(X, Y).
north(X, Y) :-
    directlyNorth(Z, Y),
    north(X, Z).

south(X, Y) :- directlyNorth(Y, X).
south(X, Y) :-
    directlyNorth(Y, Z),
    south(X, Z).

west(X, Y) :- directlyWest(X, Y).
west(X, Y) :-
    directlyWest(Z, Y),
    west(X, Z).

east(X, Y) :- directlyWest(Y, X).
east(X, Y) :-
    directlyWest(Z, Y),
    east(X, Z).

% rules - diagonal ways use recursive cases of direct rules
northWest(X, Y) :- north(Z, Y), west(X, Z).

southWest(X, Y) :- south(Z, Y), west(X, Z).

southEast(X, Y) :- south(Z, Y), east(X, Z).

northEast(X, Y) :- north(Z, Y), east(X, Z).