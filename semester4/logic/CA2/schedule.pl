%% I declare that this material, which I now submit for assessment, is entirely my own work and has not been taken from the work of others save and to
%% the extent that such work has been cited and acknowledged within the text of my work.

%% CLP(FD) - Constraint Logic Programming over Finite Domains
%% used to solve combinatorial problems - scheduling task
:- use_module(library(clpfd)).
:- use_module(library(random)).

%% FACTS: teams division into groups - 5 teams in 6 groups
group(g1, [t1, t2, t3, t4, t5]).
group(g2, [t6, t7, t8, t9, t10]).
group(g3, [t11, t12, t13, t14, t15]).
group(g4, [t16, t17, t18, t19, t20]).
group(g5, [t21, t22, t23, t24, t25]).
group(g6, [t26, t27, t28, t29, t30]).

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
pair(Team, [Opponent|Rest], [game(Team, Opponent, _Day, _Home)|Games]) :-
    pair(Team, Rest, Games).

%% extract the day variables from a list of games into one list
days([], []).
days([game(_,_, Day, _)|RestGames], [Day|RestDays]) :-
    days(RestGames, RestDays).

%% build games, collect day variables, contstrain them to a range
%% Games - full list of required matches
%% Days - list of day variables
%% every day variable must be between 1 and 40
%% every home variable must be 0 or 1
schedule(Games) :-
    all_games(Games),
    days(Games, Days),
    homes(Games, Homes),
    Days ins 1..40,
    Homes ins 0..1,
    three_daily(Days),
    rest_days(Games),
    home_away(Games),
    random_permutation(Days, RandomDays),
    random_permutation(Homes, RandomHomes),
    labeling([], RandomDays),
    labeling([], RandomHomes).

% constraint implementation 1: there are no more than three matches on any day
% in the list of day variables, each day number occurs at most 3 times
three_daily(Days) :-
    build_pairs(1, 40, Pairs),
    global_cardinality(Days, Pairs),
    three_max(Pairs).

% build a list of placeholders which will keep the day-count pair for each day
build_pairs(Day, Max, []) :-
    Day > Max.
build_pairs(Day, Max, [Day-Count|Tail]) :-
    Day =< Max,
    NextDay is Day + 1,
    build_pairs(NextDay, Max, Tail).

%% every count in each pair is maximum 3
%% ignore the day, take the count of each day and apply constraint
three_max([]).
three_max([_-Count|Tail]) :-
    Count #=< 3,
    three_max(Tail).

%% collect the days of all games that involve a given team into a new list
team_days(_, [], []).

team_days(Team, [game(A, B, Day, _)|GamesTail], [Day|DaysTail]) :-
    memberchk(Team, [A, B]),
    !,
    team_days(Team, GamesTail, DaysTail).

team_days(Team, [_|GamesTail], DaysTail) :-
    team_days(Team, GamesTail, DaysTail).

%% constraint implementation 2: there are at least 4 rest days inbetween every teams match
%% take a particular day and check if there is 5 days between fixtures
check_length(_, []).
check_length(Day, [OtherDay|Tail]) :-
    abs(Day - OtherDay) #>= 5,
    check_length(Day, Tail).

%% apply check_length to a whole list of days
rest([]).
rest([_]).
rest([Day|Tail]) :-
    check_length(Day, Tail),
    rest(Tail).

%% go through all teams, their match days, and apply rest
%% get the full team list
all_teams(Teams) :-
    findall(Team, (group(_, GroupTeams), member(Team, GroupTeams)), Teams).

%% apply rest recursively for all teams
all_teams_rest([], _).
all_teams_rest([Team|TeamTail], Games) :-
    team_days(Team, Games, Days),
    rest(Days),
    all_teams_rest(TeamTail, Games).

%% call helper functions to implement the 4 day constraint
rest_days(Games) :-
    all_teams(Teams),
    all_teams_rest(Teams, Games).

%% constraint implementation 3: each team has the same number of home and away fixtures in the whole schedule
%% Home = 0 means the first team in game(A, B, Day, Home) is home
%% Home = 1 means the second team is home
%% traverse games and extract each teams home/away flags
home_flags(_, [], []).
%% case 1: target team is team A - Home is 0
home_flags(Team, [game(A, _, _, Home)|GamesTail], [Flag|FlagsTail]) :-
    Team == A,
    !,
    Flag #= 1 - Home,
    home_flags(Team, GamesTail, FlagsTail).

%% case 2: target team is team B - Home is 1
home_flags(Team, [game(_, B, _, Home)|GamesTail], [Flag|FlagsTail]) :-
    Team == B,
    !,
    Flag #= Home,
    home_flags(Team, GamesTail, FlagsTail).

%% case 3: target team not in this game - keep traversing
home_flags(Team, [_|GamesTail], FlagsTail) :-
    home_flags(Team, GamesTail, FlagsTail).

%% using clpfd to ensure there are 2 home matches per team
all_teams_home([], _).
all_teams_home([Team|TeamTail], Games) :-
    home_flags(Team, Games, Flags),
    sum(Flags, #=, 2),
    all_teams_home(TeamTail, Games).

home_away(Games) :-
    all_teams(Teams),
    all_teams_home(Teams, Games).

%% collect all home/away variables for the entire schedule
homes([], []).
homes([game(_, _, _, Home)|GamesTail], [Home|HomesTail]) :-
    homes(GamesTail, HomesTail).