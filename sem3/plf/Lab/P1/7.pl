% 7.


% a. Write a predicate to compute the intersection of two sets.

cnt([], _, Rez) :-
    Rez is 0.

cnt([H | T], X, Rez) :-
    H =:= X,
    cnt(T, X, TempRez),
    Rez is TempRez + 1.

cnt([H | T], X, Rez) :-
    H =\= X,
    cnt(T, X, TempRez),
    Rez is TempRez.

inter([], _, Rez) :-
    Rez = [].

inter([H | T], L2, Rez) :-
    inter(T, L2, ARez),
    cnt(L2, H, Rez1),
    cnt(ARez, H, Rez2),
    add_to_list(ARez, H, Rez1, Rez2, Rez).

add_to_list(AuxR, X, R1, R2, R) :-
    R1 =\= 0,
    R2 =:= 0,
    R = [X | AuxR].

add_to_list(AuxR, _, R1, _, R) :-
    R1 =:= 0,
    R = AuxR.

add_to_list(AuxR, _, R1, R2, R) :-
    R1 =\= 0,
    R2 =\= 0,
    R = AuxR.



% b. Write a predicate to create a list (m, ..., n) of all integer numbers from the interval [m, n].

genList(M, N, []) :-
    M > N.

genList(M, N, Rez) :-
    NewM is M + 1,
    N >= M,
    genList(NewM, N, TempRez),
    Rez = [M | TempRez].
