:- use_module(library(lists)).

%% FACTS: teams in groups (example)

group(g1, [a,b,c,d,e]).
group(g2, [f,g,h,i,j]).
group(g3, [k,l,m,n,o]).
group(g4, [p,q,r,s,t]).
group(g5, [u,v,w,x,y]).
group(g6, [z,aa,bb,cc,dd]).

%% MAIN PREDICATE

schedule(S) :-
    all_matches(Matches),
    assign_days(Matches, S),
    valid_schedule(S).

%% GENERATE ALL MATCHES (round robin in group)

all_matches(Matches) :-
    findall(match(A,B,_),
        ( group(_, Teams),
          select(A, Teams, Rest),
          member(B, Rest),
          A @< B  % avoid duplicates
        ),
    Matches).

%% ASSIGN DAYS (non-deterministic)

assign_days([], []).
assign_days([match(A,B,_)|Rest], [match(A,B,D)|SRest]) :-
    between(1, 100, D),  % upper bound for search
    assign_days(Rest, SRest).

%% VALIDATION

valid_schedule(S) :-
    max_three_matches_per_day(S),
    balanced_home_away(S),
    rest_days_ok(S).

%% CONSTRAINT 1: max 3 matches per day

max_three_matches_per_day(S) :-
    findall(D, member(match(_,_,D), S), Days),
    sort(Days, UniqueDays),
    forall(member(D, UniqueDays),
        ( findall(1, member(match(_,_,D), S), L),
          length(L, N),
          N =< 3
        )).

%% CONSTRAINT 2: equal home and away per team

balanced_home_away(S) :-
    teams(AllTeams),
    forall(member(T, AllTeams),
        ( count_home(T, S, H),
          count_away(T, S, A),
          H =:= A
        )).

count_home(T, S, N) :-
    findall(1, member(match(T,_,_), S), L),
    length(L, N).

count_away(T, S, N) :-
    findall(1, member(match(_,T,_), S), L),
    length(L, N).

teams(All) :-
    findall(T,
        (group(_, Ts), member(T, Ts)),
    AllDup),
    sort(AllDup, All).

%% CONSTRAINT 3: at least 4 rest days

rest_days_ok(S) :-
    teams(Teams),
    forall(member(T, Teams),
        team_rest_ok(T, S)).

team_rest_ok(T, S) :-
    findall(D,
        (member(match(A,B,D), S),
         (A = T ; B = T)),
    Days),
    sort(Days, Sorted),
    rest_gaps_ok(Sorted).

rest_gaps_ok([]).
rest_gaps_ok([_]).
rest_gaps_ok([D1,D2|Rest]) :-
    Gap is D2 - D1,
    Gap >= 5,   % at least 4 rest days BETWEEN matches
    rest_gaps_ok([D2|Rest]).