% 2. Are given n points in a plan (represented using its coordinates). 
% Write a predicate to determine all subsets of collinear points.

determinant([XA, YA], [XB, YB], [XC, YC], Rez):-
    Rez is XA * (YB - YC) + XB * (YC - YA) + XC * (YA - YB).

col([]).

col([_]).

col([_, _]).

col([H1, H2, H3 | T]):-
    determinant(H1, H2, H3, Determinant),
    Determinant =:= 0,
    col([H2, H3 | T]).

generate_subset([], []).

generate_subset([_ | T], Rez):-
    generate_subset(T, Rez),
    col(Rez).

generate_subset([H | T], [H | Rez]):-
    generate_subset(T, Rez),
    col([H | Rez]).