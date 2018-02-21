candidat(N,N,_).
candidat(E,N,M):-N>M,N1 is N-1, candidat(E,N1,M).

apare(_,[]):-false.
apare(E,[H|_]):-E=:=H,!.
apare(E,[_|T]):-apare(E,T).

perm(N,C):-N1 is 2*N-1,candidat(E,N1,N),perm_aux(N,C,[E],1).

perm_aux(N,C,C,N):-!.
perm_aux(N,C,[H|T],Lg):-Lg<N,N1 is 2*N-1,candidat(E,N1,N),\+apare(E,[H|T]),abs(H-E)=<2,
	Lg1 is Lg+1,perm_aux(N,C,[E|[H|T]],Lg1).
