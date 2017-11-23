% Pentru P3 => p2

% 3.
% a. Merge two sorted lists with removing the double values.
% b. For a heterogeneous list, formed from integer numbers and list of numbers, merge all sublists with removing
% the double values.
% [1, [2, 3], 4, 5, [1, 4, 6], 3, [1, 3, 7, 9, 10], 5, [1, 1, 11], 8] =>
% [1, 2, 3, 4, 6, 7, 9, 10, 11].

% when the list is empty
removeDup([], []).

% when there is one element in the list
removeDup([X], [X]).

% when the first element is not equal to the second
removeDup([H | T], X) :-
    removeDup(T, [H1 | Tr]),
    H1 =\= H,
    X = [H, H1 | Tr].

% when the first element is equal to the second
removeDup([H | T], X) :-
    removeDup(T, [H1 | Tr]),
    H1 =:= H,
    X = [H1 | Tr].

% when the list is empty
append([], E, [E]).

% when the first element is equal to the element that we have to insert
append([H | T], H, [H | T]) :-
    !.

% when the first element is not equal to the element that we have to insert
append([H | T], E, [E, H | T]) :-
    !.

% when the lists are empty 
merge([], [], []).

% when the first list is empty
merge([], X, Xr) :-
    removeDup(X, Xr).

% when the second list is empty
merge(X, [], Xr) :-
    removeDup(X, Xr).

% when the first element of the second list is greater or equal to the first element of the first list
merge([H1 | T1], [H2 | T2], X) :-
    H2 >= H1,
    merge(T1, [H2 | T2], Tr),
    append(Tr, H1, X).

% when the first element of the second list is less than the first element of the first list
merge([H1 | T1], [H2 | T2], X) :-
    H1 > H2,
    merge([H1 | T1], T2, Tr),
    append(Tr, H2, X).

% when the hetero_merge list is empty
merge_hetero([], []).

% when the first element is a number
merge_hetero([H | T], Tr) :-
    number(H),
    merge_hetero(T, Tr).

% when the first element is a list
merge_hetero([H | T], X) :-
    is_list(H),
    merge_hetero(T, Y),
    merge(H, Y, X).