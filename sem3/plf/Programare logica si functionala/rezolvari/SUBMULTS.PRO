domains
	el=integer
	list=el*
	dlist=list*
predicates
	submall(list,el,dlist) %i,i,o
	subm(list,list,el) %i,o,i
	submultime(list,list) %i,o 
	verifica(list,el) %i,i
	suma(list,el) %i,o
clauses
	suma([],0).
	suma([H|T],S):-suma(T,S1),S=H+S1.
	
	verifica(L,S):-suma(L,S1),S=S1.
	
	submultime([],[]).
	submultime([H|T],S):-submultime(T,S1),S=[H|S1].
	submultime([_|T],S):-submultime(T,S).
	
	subm(L,S,N):-submultime(L,Sol),verifica(Sol,N),S=Sol.
	
	submall(L,N,LS):-findall(S,subm(L,S,N),LS).