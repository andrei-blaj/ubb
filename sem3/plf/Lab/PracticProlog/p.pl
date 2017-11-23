% Se da o lista formata din numere intregi.
% Se cere sa se adauge din M in M o valoare data (M > 1).
% Exemplu:
% 	[1 2 3 4 5 6 7] 3 11 -> [1 2 11 3 4 11 5 6 11 7]

ins(L,P,M,Rez):-
	inserare(L, P, M, 1, Rez).

inserare([],_,_,_,Rez):-
	Rez = [].

inserare([H | T], P, M, C, Rez):-
	C < P,
	inserare(T, P, M, C+1, R),
	Rez = [H | R].

inserare([H | T], P, M, C, Rez):-
	C =:= P,
	inserare([H | T], P, M, 1, R),
	Rez = [M | R].
