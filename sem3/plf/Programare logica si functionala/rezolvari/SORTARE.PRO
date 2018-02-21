domains
	el = integer
	list = el*
predicates
	insert(el,list,list)
	ord(list,list)
clauses
	insert(E,[],[E]).			
	insert(E,[H|T],S):-E>H,insert(E,T,S1),S=[H|S1],!.
	insert(E,L,S):-S=[E|L].
	
	ord([],[]).
	ord([H|T],S):-ord(T,S1),insert(H,S1,S),!.