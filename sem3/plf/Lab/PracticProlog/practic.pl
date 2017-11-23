% Se da o lista de numere, dupa fiecare numar care nu e prim 
% sa se insereze divizorii lui

get_divs(Nr, Div, Res):-
	Div >= Nr,
	Res = [].

get_divs(Nr, Div, Res):-
	Div < Nr,
	NextDiv is Div + 1,
	get_divs(Nr, NextDiv, ARes),
	Rest is mod(Nr, Div),
	push_div(Rest, Div, ARes, Res).

push_div(Rest, Div, ARes, Res):-
	Rest =:= 0,
	Res = [Div | ARes].

push_div(Rest, _, ARes, Res):-
	Rest =\= 0,
	Res = ARes.

solve([], Res):-
	Res = [].

solve([H | T], Res):-
	solve(T, AuxRes),
	get_divs(H, 2, Divs),
	append([H | Divs], AuxRes, Res).