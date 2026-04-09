%% CLP(FD) - Constraint Logic Programming over Finite Domains
%% used to solve combinatorial problems - scheduling task
:- use_module(library(clpfd)).

%% FACTS: teams division into groups - 5 teams in 6 groups
group(g1, [t1, t2, t3, t4, t5]).
group(g2, [t6, t7, t8, t9, t10]).
group(g3, [t11, t12, t13, t14, t15]).
group(g4, [t16, t17, t18, t19, t20]).
group(g5, [t21, t22, t23, t24, t25]).
group(g6, [t26, t27, t28, t29, t30]).

%% A and B are two different teams from the same group
%% game(A, B)

%% choose the first team A
%% choose some team B
%% make the pair (A, B)
%% recurse on the tail
games([], []). %% base case - no teams no games
games([Team|TeamTail], Games) :-
    pair(Team, TeamTail, Games1),
    games(TeamTail, Games2),
    append(Games1, Games2, Games).

%% get team list for each group, compute group names, collect into one big list
all_games(Games) :-
    findall(Gs,
        (group(_, Teams), games(Teams, Gs)),
        NestedGames),
    append(NestedGames, Games).

%% helper predicate that pairs one team with other teams
%% create one game against the first opponent with variable Day and recurse
pair(_, [], []). % base case - no opponents no games
pair(Team, [Opponent|Rest], [game(Team, Opponent, Day)|Games]) :-
    pair(Team, Rest, Games).

%% extract the day variables from a list of games into one list
days([], []).
days([game(_,_, Day)|RestGames], [Day|RestDays]) :-
    days(RestGames, RestDays).

%% build games, collect day variables, contstrain them to a range
%% Games - full list of required matches
%% Days - list of day variables
%% every day variable must be between 1 and 40
schedule(Games) :-
    all_games(Games),
    days(Games, Days),
    Days ins 1..40.