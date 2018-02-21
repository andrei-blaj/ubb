domains
	el = integer
	l = el*
predicates
	prim(el) %i
	eprim(el,el) %i,i
	elimin(l,el,l) %i,i,o
clauses
	prim(2).
	prim(E):-E<2,fail,!.
	prim(E):-E1=E-1,eprim(E,E1).
	
	eprim(_,1).
	eprim(E,N):-E mod N <> 0,N1=N-1,eprim(E,N1),!.
	eprim(_,_):-fail,!.
	
	elimin([],_,[]).
	elimin(L,0,L):-!.
	elimin([H|T],N,S):-N1=N-1,prim(H),elimin(T,N1,S1),S=S1.
	elimin([H|T],N,S):-not(prim(H)),elimin(T,N,S1),S=[H|S1].