domains 
	el=integer
predicates
	suma(el,el) %i,o
	suma1(el,el) %i,o
clauses
	suma(0,0).
	suma(N,S):-N1=N-1,suma(N1,S1),S=S1+N.
	
	suma1(N,S):-N>0,N1=N-1,suma(N1,S1),S=S1+N,!.
	