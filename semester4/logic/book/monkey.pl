% state(MonkeyHorizontal, MonkeyVertical, BoxPosition, HasBanana)
% move(State1, Move, State2).

move(state(middle, onbox, middle, hasnot),  % before move
    grasp,                                  % grasp banana
    state(middle, onbox, middle, has)).     % after move

move(state(P, onfloor, P, H),
    climb,                                  % climb box
    state(P, onbox, P, H)).

move(state(P1, onfloor, P1, H),
    push,                                    % push box from P1 to P2
    state(P2, onfloor, P2, H)).

move(state(P1, onfloor, Box, Has),
    walk(P1, P2),                            % walk from P1 to P2
    state(P2, onfloor, Box, Has)).

% canget(State): monkey can get banana in State
canget(state(_, _, _, has)).                 % can 1: monkey already has it

canget(State1) :-                            % can 2: do some work to get it
    move(State1, Move, State2),              % do something
    canget(State2).                          % get it now