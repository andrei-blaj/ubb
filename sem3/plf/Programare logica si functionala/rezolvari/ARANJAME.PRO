domains
	el=integer
	list=el*
	dlist=list*
predicates
	insert(el,list,list) %i,i,o
	cmb(list,el,list) %i,i,o
	perm(list,list) %i,o
	aranj(list,el,list,el) %i,i,o,i
	ver(list,el) %i,i
	suma(list,el) %i,o
	aranjamente(list,el,el,dlist) %i,i,i,o
clauses
	insert(E,L,[E|L]).
	insert(E,[H|T],S):-insert(E,T,S1),S=[H|S1].
	
	cmb([H|_],1,[H]).
	cmb([H|T],K,S):-K1=K-1,cmb(T,K1,S1),S=[H|S1].
	cmb([_|T],K,S):-cmb(T,K,S).
	
	perm([],[]).
	perm([H|T],S):-perm(T,S1),insert(H,S1,S).
	
	aranj(L,K,S,SUMA):-cmb(L,K,S1),perm(S1,S),ver(S,SUMA).
	
	ver(L,S):-suma(L,S1),S1=S.
	
	suma([],0).
	suma([H|T],S):-suma(T,S1),S=S1+H.
	
	aranjamente(L,K,Suma,LS):-findall(S,aranj(L,K,S,Suma),LS).