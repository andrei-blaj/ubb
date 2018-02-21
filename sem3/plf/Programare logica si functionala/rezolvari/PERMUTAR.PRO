domains
	el=integer
	list = el*
	dlist = list*
predicates
	insert(el,list,list) %i,i,o
	perm(list,list) %i,o
	verifica(list) %i
	test(dlist)
	permutare(list,dlist) %i,o
clauses
	insert(E,L,[E|L]).
	insert(E,[H|T],[H|L]):-insert(E,T,L).

	verifica([_|[]]).
	verifica([H|[H1|T]]):-3>=H1-H,3>=H-H1,verifica([H1|T]).
	
	perm([],[]).
	perm([H|T],S):-perm(T,S1),insert(H,S1,S),verifica(S).

	permutare(L,LS):-findall(S,perm(L,S),LS).