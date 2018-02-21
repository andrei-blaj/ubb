domains
	el = integer
	list = el*
	dlist = list*
predicates
	subm(list,list) %i,o
	submultime(list,dlist)
clauses
	subm([],[]).
	subm([_|T],S):-subm(T,S).
	subm([H|T],[H|S]):-subm(T,S).
	submultime(L,LS):-findall(S,subm(L,S),LS).