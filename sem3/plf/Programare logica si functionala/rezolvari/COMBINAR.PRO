domains
	el = integer
	list=el*
	dlist = list*
predicates
	combinari(list,el,dlist) %i,i,o
	cmb(list,el,list) %i,i,o
clauses
	combinari(L,K,LS):-findall(S,cmb(L,K,S),LS).
	
	cmb([H|_],1,[H]).
	cmb([H|T],K,S):-K>1,K1=K-1,cmb(T,K1,S1),S=[H|S1].
	cmb([_|T],K,S):-cmb(T,K,S).