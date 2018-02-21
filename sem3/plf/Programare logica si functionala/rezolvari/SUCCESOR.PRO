domains
	el=integer
	list=el*
predicates
	add(list,el,list) %i,o,o
	succ(list,list) %i,o
clauses
	succ(L,S):-add(L,R,S1),R>0,S=[1|S1],!.
	succ(L,S):-add(L,_,S).
	
	add([],1,[]).
	add([H|T],R,S):-add(T,R1,S1),H1=H+R1,R=H1 div 10,H2=H1 mod 10,S=[H2|S1].
	
