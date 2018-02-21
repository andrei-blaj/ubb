
suma([],0).
suma([H|T],S) :- suma(T,S2) , S is S2 + H.

%permutari
inseram(E,L,[E|L]).
inseram(E,[H|T],[H|R]) :- inseram(E,T,R).

permutare([],[]).
permutare([H|T],R) :- permutare(T,R2) , inseram(H,R2,R).

permut_all(L,R) :- findall( X , permutare(L,X) , R).

%combinari
combinn([H|_],1,[H]).
combinn([_|T],K,R) :- combinn(T,K,R).
combinn([H|T],K,[H|R]) :- K > 1 , K2 is K - 1 , combinn(T,K2,R).

%aranjament
aranjamente(L,K,R) :- combinn(L,K,R2) , permutare(R2,R).

%submultimi
subm([],[]).
subm([_|T],R) :- subm(T,R).
subm([H|T],[H|R]) :- subm(T,R).

subm_all(L,R) :- findall(X,subm(L,X) , R).

%fa in 2 feluri suma a primelor n numere
sum(N,S) :- S is ( N * ( N + 1 ) div 2 ).

sum2(0,0).
sum2(N,S) :- N2 is N - 1 , sum2(N2,S2) , S is N + S2 , !.

%dandu-se o lista formata din numere intregi sa se genereze lista aranjamentelor cu N elementele avand suma S data

suma_ll([],0).
suma_ll([H|T],S) :- suma_ll(T,S2) , S is S2 + H.

insert(E,L,[E|L]).
insert(E,[H|T],[H|R]) :- insert(E,T,R).

perm([],[]).
perm([H|T],R) :- perm(T,R2) , insert(H,R2,R).

combinam([H|_],1,[H]).
combinam([_|T],K,R) :- combinam(T,K,R).
combinam([H|T],K,[H|R]) :- K > 1 , K2 is K - 1 , combinam(T,K2,R).

aranjament(L,K,R) :- combinam(L,K,R2) , perm(R2,R).

aranj_total(L,K,R) :- findall(X,aranjament(L,K,X),R).

fac_suma([],[],_).
fac_suma([H|T],[H|R],S) :- not(number(H)) , suma_ll(H,P) , P =:=S , fac_suma(T,R,S),!.
fac_suma([_|T],R,S) :- fac_suma(T,R,S),!.

solve(L,K,S,R) :- aranj_total(L,K,R2) , fac_suma(R2,R,S),!.

%calculeaza x^n folosind 2 metode

produs(_,0,1) :-!.
produs(N,P,Pr) :- P2 is P - 1 , produs(N,P2,Pr2) , Pr is Pr2 * N.

ridic_log(_,0,1) :-!.
ridic_log(A,B,R):- B mod 2 =:= 1 , A2 is A * A , B2 is B div 2 , ridic_log(A2,B2,R2) , R is R2 * A.
ridic_log(A,B,R):- B mod 2 =:= 0 , A2 is A * A , B2 is B div 2 , ridic_log(A2,B2,R2) , R is R2. 

%genereaza permutari ale unei liste cu dif elementelor <= 3

%f de inserare 
ins(E,L,[E|L]).
ins(E,[H|T],[H|R]) :- ins(E,T,R).

%f de permutare
permm([],[]).
permm([H|T],R):- permm(T,R2) , ins(H,R2,R).

perm_all(L,R) :- findall(X, permm(L,X) , R).

%f de verificare
check([_]).
check([H1,H2|T]) :- abs(H1-H2) =< 3 , check([H2|T]) , !.
check([H1,H2|_]) :- abs(H1-H2) > 3 , fail , !.

%f de parcurgere si verificare

vezi_sol([],[]).
vezi_sol([H|T],[H|R]) :- not(number(H)) , check(H) , vezi_sol(T,R).
vezi_sol([_|T],R) :- vezi_sol(T,R).

%solve-ul propriu-zis

solve(L,R) :- perm_all(L,R2) , vezi_sol(R2,R),!.

%verifica daca un numar este prim

prim(N) :- este_prim(N,2).

este_prim(N,K) :- I is N div 2 , K > I , !.
este_prim(N,K) :- P is N mod K , P =\= 0 , K2 is K + 1 , este_prim(N,K2).

%elimina primele n numere prime din sir

elim_prim([],[],_).
elim_prim([H|T],R,N) :- prim(H) , N > 0 , N2 is N - 1 , elim_prim(T,R,N2),!.
elim_prim([H|T],[H|R],N) :- prim(H) , N =:= 0 , elim_prim(T,R,N),!.
elim_prim([H|T],[H|R],N) :- elim_prim(T,R,N),!.

%afisez submultimile cu suma S data

suma_sb([],0).
suma_sb([H|T],S) :- suma_sb(T,S2) , S is S2 + H.

submm([],[]).
submm([_|T],R) :- subm(T,R).
submm([H|T],[H|R]) :- subm(T,R).


subm_all2(L,R) :- findall(X,submm(L,X) , R).

vezi_sol2([],[],_).
vezi_sol2([H|T],[H|R],S) :- suma_sb(H,P) , P =:= S , vezi_sol2(T,R,S).
vezi_sol2([_|T],R,S) :- vezi_sol2(T,R,S).

solvare(L,R,S) :- subm_all2(L,R2) , vezi_sol2(R2,R,S),!.


%combinari de suma data

com([H|_],1,H,[H]).
com([_|T],K,S,R) :- com(T,K,S,R).
com([H|T],K,S,[H|R]) :- H < S , S > 0 , S2 is S - H , K > 1  , K2 is K - 1 , com(T,K2,S2,R).

%subm de suma data
sumb([H|_],H,[H]).
sumb([_|T],S,R) :- sumb(T,S,R).
sumb([H|T],S,[H|R]) :- H < S , S > 0 , S2 is S - H , sumb(T,S2,R).


%afiseaza submultimile care au suma divizibila cu o valoare d

summ([],0):-!.
summ([H|T],S) :- summ(T,S2) , S is S2 + H.

submultimi([],[]).
submultimi([_|T],R) :- submultimi(T,R).
submultimi([H|T],[H|R]) :- submultimi(T,R).

submult_all(L,R) :- findall(X , submultimi(L,X) , R).

vezi_toate_sub([],[],_).
vezi_toate_sub([H|T],[H|R],D) :- not(number(H)) , summ(H,P) , P mod D =:= 0  , vezi_toate_sub(T,R,D).
vezi_toate_sub([_|T],R,D) :- vezi_toate_sub(T,R,D).

solve(L,R,D) :- submult_all(L,R2) , vezi_toate_sub(R2,R,D),!.

%aranjamentele cu suma divizibila cu 3

inserez(E,L,[E|L]).
inserez(E,[H|T],[H|R]) :- inserez(E,T,R).
 
next_perm([],[]).
next_perm([H|T],R) :- next_perm(T,R2) , inserez(H,R2,R).


next_comb([H|_],1,[H]).
next_comb([_|T],K,R) :- next_comb(T,K,R).
next_comb([H|T],K,[H|R]) :- K > 0 , K2 is K - 1 , next_comb(T,K2,R).


next_aranj(L,R,K) :- next_comb(L,K,R2) , next_perm(R2,R).
next_find_all(L,R,K) :- findall(X , next_aranj(L,X,K) , R ).

next_sum([],0).
next_sum([H|T],S) :- next_sum(T,S2) , S is S2 + H.

next_afla([],[],_).
next_afla([H|T],[H|R],D) :- not(number(H)) , next_sum(H,S) , S mod D =:= 0 , next_afla(T,R,D).
next_afla([_|T],R,D) :- next_afla(T,R,D).

solve_next(L,R,K) :- next_find_all(L,R2,K) , next_afla(R2,R,3),!.

%submultimile de k elemente care au suma divizibila cu k

%verific progresie aritmetica
verif([H1,H2|L]) :- D is abs(H2-H1) , check2([H1,H2|L],D).
check2([_],_).
check2([H1,H2|T],D) :- D2 is abs(H2-H1) , D =:= D2 , check2([H2|T],D) , !.
check2([H1,H2|_],D) :- D2 is abs(H2-H1) , D =\= D2 , fail , !.  


combinamente([H|_],1,[H]).
combinamente([_|T],K,R) :- combinamente(T,K,R).
combinamente([H|T],K,[H|R]) :- K > 1 , K2 is K - 1 , combinamente(T,K2,R).

comb_in_all(L,R,K) :- findall(X,combinamente(L,K,X),R).

ia_good_comb([],[]).
ia_good_comb([H|T],[H|R]) :- not(number(H)) , verif(H) , ia_good_comb(T,R).
ia_good_comb([_|T],R) :- ia_good_comb(T,R).

solve3(L,R,K) :- comb_in_all(L,R2,K) , ia_good_comb(R2,R) , !.

%aspect de vale

vale([H1,H2|T]) :- H1 > H2 , cobor([H1,H2|T]).

cobor([_]) :- fail.

cobor([H1,H2|T]) :- H2 < H1 , cobor([H2|T]).
cobor([H1,H2|T]) :- H1 < H2 , urc([H1,H2|T]).

urc([_]) :- true.
urc([H1,H2|T]) :- H1 < H2 , urc([H2|T]).

%munte

munte([H1,H2|T]) :- H1 < H2 , urc2([H1,H2|T]).

urc2([_]) :- fail.

urc2([H1,H2|T]) :- H1 < H2 , urc2([H2|T]).
urc2([H1,H2|T]) :- H1 > H2 , cobor2([H1,H2|T]).

cobor2([_]) :- true.
cobor2([H1,H2|T]) :- H1 > H2 , cobor2([H2|T]).

%elimina prima aparitie a minimului

minim([],99999).
minim([H|T],H) :- minim(T,M) , H < M , !.
minim([_|T],M) :- minim(T,M).

maxim([],-99999).
maxim([H|T],H) :- maxim(T,M) , M < H , !.
maxim([_|T],M) :- maxim(T,M).

elim(L,R) :- minim(L,M) , solva(L,M,1,R).

solva([],_,_,[]).
solva([H|T],M,N,R) :- N =:= 1 , H =:= M , N2 is N - 1 , solva(T,M,N2,R) , !.
solva([H|T],M,N,[H|R]) :- solva(T,M,N,R).

%fac cmmdc
cmmdc(A,B,A) :- A =:= B,!.
cmmdc(A,B,D) :- A > B , A1 is A - B , cmmdc(A1,B,D).
cmmdc(A,B,D) :- B > A , B1 is B - A , cmmdc(A,B1,D).

lcmmdc([],1).
lcmmdc([E],E).
lcmmdc([H|T],D) :- lcmmdc(T,D2) , cmmdc(H,D2,D).

%las doar elementele simple
este_membru(E,[E|_]).
este_membru(E,[_|T]):- este_membru(E,T),!.

fa_list([],[]).
fa_list([H|T],R) :- este_membru(H,R) , fa_list(T,R).
fa_list([H|T],[H|R]) :- fa_list(T,R).

%dupa fiecare element par elementul 1

introdu([],[]).
introdu([H|T],[H|[1|R]]) :- H mod 2 =:= 0 , introdu(T,R) , !.
introdu([H|T],[H|R]) :- introdu(T,R) , !.

%fac cmmmc

cmdc(A,B,A) :- A =:= B , ! .
cmdc(A,B,D) :- A > B , A1 is A - B , cmdc(A1,B,D).
cmdc(A,B,D) :- B > A , B1 is B - A , cmdc(A,B1,D).


cmmmc(A,B,D) :- P is A * B , cmdc(A,B,X) , D is P div X.

lcmmc([],1).
lcmmc([H],H).
lcmmc([H|T],D) :- lcmmc(T,D2) , cmmmc(H,D2,D),!.

%insereaza dupa 1 , 2 , 4 , 8 , 16

inser_sm(L,R,X) :- faoda(L,R,X,1,1).

faoda([],[],_,_,_).
faoda([H|T],[H|[X|R]],X,N,M) :- N =:= M , M2 is 2 * M , N2 is N + 1 , faoda(T,R,X,N2,M2) , !.
faoda([H|T],[H|R],X,N,M) :- N2 is N + 1 , faoda(T,R,X,N2,M) , !.

%elimina primele 3 aparitii

elim(L,R,X) :- elimm(L,X,R,3).

elimm([],_,[],_).
elimm([H|T],X,R,N) :- H =:= X , N > 0 , N2 is N - 1 , elimm(T,X,R,N2),!.
elimm([H|T],X,[H|R],N) :- H =\= X , elimm(T,X,R,N),!.
elimm([H|T],X,[H|R],N) :- H =:= X , N =:= 0 , elimm(T,X,R,N),!.

%elimina elementele care se repeta

nraap(E,[],0).
nraap(E,[H|T],S) :- E =:= H , nraap(E,T,S1), S is S1 + 1 ,!.
nraap(E,[_|T],S) :- nraap(E,T,S) , !.

%elimina toate aparitiile maximului

mx([],-99999).
mx([H|T],H) :- mx(T,M) , M < H , !.
mx([_|T],M) :- mx(T,M) , !.

elim_mm(L,R) :- mx(L,M) , ee(L,M,R).

ee([],_,[]).
ee([H|T],M,R) :- H =:= M , ee(T,M,R).
ee([H|T],M,[H|R]) :- ee(T,M,R).

%sortam o lista

ins_f(E,[],[E]).
ins_f(E,[H|T],[E|[H|T]]) :- E =< H , !.
ins_f(E,[H|T],[H|R]) :- E > H , ins_f(E,T,R).

sortam([],[]).
sortam([H|T],R) :- sortam(T,R2) , ins_f(H,R2,R).

%inversa unei liste

baga_final(E,[],[E]).
baga_final(E,[H|T],[H|R]) :- baga_final(E,T,R).

swap([],[]).
swap([H|T],R) :- swap(T,R2) , baga_final(H,R2,R).


%elimina din toate sublistele elemente din n in n

elim1(L,R,N) :- baga_el(L,R,N,1).

baga_el([],[],_,_).
baga_el([H|T],[H|R],N,P) :- P mod N =\= 0 , P2 is P + 1, baga_el(T,R,N,P2) , !.
baga_el([_|T],R,N,P) :- P2 is P + 1 , baga_el(T,R,N,P2).

elim_din_subliste([],[],_).
elim_din_subliste([H|T],[R2|R],N) :- not(number(H)) , elim1(H,R2,N) , elim_din_subliste(T,R,N) , !.
elim_din_subliste([_|T],R,N) :- elim_din_subliste(T,R,N), !.


