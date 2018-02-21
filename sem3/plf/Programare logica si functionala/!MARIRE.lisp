
;lungimea unei liste de pe orice nivel

(defun lungime(l)
	(cond
		( ( null l ) 0 )
		( ( atom ( car l ) ) ( + 1 ( lungime ( cdr l ) ) ) ) 
		( t ( + ( lungime ( car l ) ) ( lungime ( cdr l ) ) ) )
	)
)

;numarul de atomi numerici

(defun nr_atomi(l)
	(cond
		( ( null l ) 0 )
		( (and ( atom ( car l ) ) ( numberp ( car l ) ) ) ( + 1 ( nr_atomi ( cdr l ) ) ) )
		( ( atom ( car l ) ) ( nr_atomi ( cdr l ) ) )
		( t ( + ( nr_atomi( car l ) ) ( nr_atomi( cdr l ) ) ) )
	)
)

;inlocuiesc un element dintr-o lista cu alta lista

(defun inloc(l e ll)
	(cond
		( ( null l ) nil )
		( ( equal ( car l ) e ) ( append ll ( inloc ( cdr l ) e  ll ) ) )
		( ( atom ( car l ) ) ( cons ( car l ) ( inloc ( cdr l ) e ll ) ) )
		( t ( cons ( inloc ( car l ) e ll ) ( inloc ( cdr l ) e ll ) ) )
	)
)

;face maximul la orice nivel

(defun maxim(l)
	(cond
		( ( null l) -9999 )
		( ( numberp ( car l ) ) ( max ( car l ) ( maxim ( cdr l ) ) ) )
		( t ( max ( maxim ( car l ) ) ( maxim ( cdr l ) ) ) )
	)
)

(defun maxim2(l)
	(cond
		( ( null l ) -9999 )
		( ( > ( car l ) ( maxim2 ( cdr l ) ) ) ( car l ) )
		( t ( maxim2 ( cdr l ) ) )
	)
)

;cmmdc a doua numere
(defun cmmdc(a b)
	(cond
		( ( = a 0 ) b )
		( ( = b 0 ) a )
		( t ( cmmdc b (mod a b ) ) )
	)
)

(defun lcmmdc(l)
	( cond
		( ( null l ) 0 )
		( ( numberp l ) l )
		( t ( cmmdc ( car l ) ( lcmmdc ( cdr l ) ) ) )
	)
)
;cmmmmc a unui sir

(defun cmmmc(a b)
( / ( * a b ) ( cmmdc a b ) )
)

(defun lcmmmc(l)
	(cond
		( ( null l ) 1 )
		( ( numberp l ) l )
		( t ( cmmmc ( car l ) ( lcmmmc ( cdr l ) ) ) )
	)
)

;l1
;p2-d
;daca un element este membru al unei functii
(defun membru(e l)
	(cond
		( ( null l ) nil )
		( ( equal ( car l ) e ) t )
		( t ( membru e ( cdr l ) ) )
	)
)

(defun baga(l)
	(cond
		( ( null l ) nil )
		( ( member ( car l ) ( cdr l ) ) ( baga ( cdr l ) ) )
		( t ( append ( list ( car l ) ) ( baga ( cdr l ) ) ) )
	)
)


(defun apare( l e )
	(cond
		( ( null l ) 0 )
		( ( and ( numberp ( car l ) ) ( equal ( car l ) e ) ) ( + 1 ( apare ( cdr l ) e ) ) )
		( ( atom ( car l ) ) ( apare ( cdr l ) e ) )
		( t ( + ( apare ( car l ) e ) ( apare ( cdr l ) e ) ) )
	)
)

(defun make_pair(l l2)
	(cond
		( (null l ) nil )
		( ( cons ( list (car l ) ( apare l2 ( car l ) ) ) ( make_pair ( cdr l ) l2 ) ) )
		( t ( make_pair ( cdr l ) l2 ) )
	)
)

(defun fa(l l2)
	(cond
		( ( baga l ) ( make_pair l l ) )
		(t  )
	)
)
		
;p3-b

(defun verif(l)
	(cond
		( ( null l) nil )
		( ( member ( car l ) ( cdr l ) ) ( verif ( cdr l ) ) )
		( t ( append ( list ( car l ) ) ( verif ( cdr l ) ) ) )
	)
)

(defun pt_alte(l)
	(cond
		( ( null l ) nil )
		( ( atom l ) ( verif ( append ( list ( car l ) ) ( pt_alte ( cdr l ) ) ) ) )
		( t ( verif ( append ( pt_alte ( car l ) ) ( pt_alte ( cdr l ) ) ) ) )
	)
)

;p5-b

(defun nr_sub(l)
	(cond
		( ( null l ) 0 )
		( ( atom (car l) ) ( nr_sub( cdr l ) ) )
		( + 1 (nr_sub (car l )) ( nr_sub ( cdr l ) ) ) 
	)
)

(defun subliste(l)
  (+ 1 (nr_sub l)) 
  ;adun 1--lista mare e lista
)

;p5-c scrie elementul de pe pozitia n a unei liste de 2 ori

(defun f(l n)
	(cond
		( ( null l) nil )
		( ( = n 0 ) ( cons ( car l ) l ) )
		( t ( cons ( car l ) ( f ( cdr l ) ( - n 1 )  ) ) )
	)
)

;p6-b sortare lista

(defun insert(e l)
	(cond
	
		( ( null l ) ( cons e nil ) )
		( ( < e ( car l ) ) ( cons e l ) )
		( t ( cons ( car l ) ( insert  e ( cdr l )  ) ) )
	)
)

(defun sortez(l)
	(cond
		( ( null l ) nil )
		( ( insert ( car l ) ( sortez ( cdr l ) ) ) )
	)
)

;p6-d inversez o lista

(defun swap(l)
	(cond
		( ( null l ) nil )
		( t ( append ( swap ( cdr l ) ) ( list ( car l ) ) ) )
	)
)

;p9-d interclaseare

(defun inter(l1 l2)
	(cond
		( ( null l1 ) l2 )
		( ( null l2 ) l1 )
		( ( <= ( car l1 ) ( car l2 ) ) ( cons ( car l1 ) ( inter ( cdr l1 ) l2 ) ) )
		( ( <= ( car l2 ) ( car l1 ) ) ( cons ( car l2 ) ( inter l1 ( c dr l2 ) ) ) )
		( t ( cons ( car l1 ) ( car l2 ) ( inter ( cdr l1 ) (cdr l2 ) ) ) )
	)
)	

;p12-a interschimb peste tot
(defun inloc(l e ll)
	(cond
		( ( null l ) nil )
		( ( equal ( car l ) e ) ( append ll ( inloc ( cdr l ) e  ll ) ) )
		( ( atom ( car l ) ) ( cons ( car l ) ( inloc ( cdr l ) e ll ) ) )
		( t ( cons ( inloc ( car l ) e ll ) ( inloc ( cdr l ) e ll ) ) )
	)
)

;p13-a  Sa se scrie o functie care sa testeze daca o lista liniara are aspect de munte

( defun munte(l)
	( cond
		( ( null l ) nil )
		( ( < ( car l ) ( cadr l ) ) ( urc l ) )
	)
)

(defun urc(l)
	(cond
		( ( null ( cdr l ) ) f )
		( ( < ( car l ) ( cadr l ) ) ( urc ( cdr l ) ) )
		( ( < ( cadr l ) ( car l ) ) ( cobor l ) )
	)
)

(defun cobor(l)
	(cond
		( ( null ( cdr l ) ) t )
		( ( < ( cadr l ) ( car l ) ) ( cobor ( cdr l ) ) )
	)
)
;p13-b elimina apar maximului
(defun maxim2(l)
	(cond
		( ( null l ) -99999 )
		( ( numberp ( car l ) ) ( max ( car l ) ( maxim2 ( cdr l ) ) ) )
		( t ( max ( maxim2 ( car l ) ) ( maxim2 ( cdr l ) ) ) )
	)
)

(defun elim(l l2)
	(cond
		( ( null l ) nil )
		( ( and ( numberp ( car l ) ) ( equal ( car l ) ( maxim l2 ) ) ) ( elim ( cdr l ) l2 ) )
		( ( atom ( car l )  ) ( cons ( car l ) ( elim ( cdr l ) l2 ) ) )
		( t ( cons ( elim ( car l ) l2 ) ( elim ( cdr l ) l2 ) ) ) 
	)
)

(defun solv(l)
	( elim l l )
)

;p14-c insereaza dupa al 2,4,6 ... 

(defun inseram(l n e)
	(cond 
		( ( null l ) nil )
		( ( = ( mod n 2 ) 0 ) ( append ( list ( car l ) ) ( list e ) ( inseram ( cdr l ) (+ n 1 ) e ) ) )
		( t ( cons ( car l ) ( inseram ( cdr l ) (+ n 1 ) e ) ) )
	)
)

(defun inst(l e)
	( inseram l 1 e )
)

;p14-d nr de apar ale unui atom intr-o lista

(defun app(l e)
	(cond
		( ( null l ) 0 )
		( (and ( numberp ( car l ) ) ( equal ( car l ) e ) ) (+ 1 ( app ( cdr l ) e ) ) )
		( (atom ( car l ) ) ( app ( cdr l ) e ) )
		( t ( + ( app ( car l ) e ) ( app ( cdr l ) e ) ) )
	)
)


;p15-b elimina elementele din n in n

(defun sterg(l n p)
	(cond
		( ( null l ) nil )
		( ( = ( mod p n ) 0 ) ( sterg ( cdr l ) n (+ p 1 ) ) )
		( t ( cons ( car l ) ( sterg ( cdr l ) n (+ p 1 ) ) ) )
	)
)

(defun sterg_tot(l n)
	( sterg l n 1 )
)

;p16-a inserez elemente din n in n
(defun insert2(l n p e)
	(cond
		( ( null l ) nil )
		( ( = ( mod p n ) 0 ) ( append ( list ( car l ) ) ( list e ) ( insert2 ( cdr l ) n (+ p 1) e ) ) )
		( t ( cons ( car l ) ( insert2 ( cdr l ) n (+ p 1 ) e ) ) ) 
	)
)

(defun insert3(l n e)
	( insert2 l n 1 e )
)

;p16-d sterg aparitiile unui element

(defun elim_orice(l e)
	( cond
		( ( null l ) nil )
		( ( and ( numberp ( car l ) ) ( equal ( car l ) e ) ) ( elim_orice ( cdr l ) e ) )
		( ( atom ( car l) ) ( cons ( car l ) ( elim_orice ( cdr l ) e ) ) )
		(t ( cons (  elim_orice ( car l ) e ) ( elim_orice ( cdr l ) e ) ) )
	)
)

;p16-b Sa se construiasca o lista cu pozitiile pe care elementul numeric minim

(defun minim(l)
	( cond
		( ( null l ) 99999 )
		( ( numberp ( car l ) ) ( min ( car l ) ( minim ( cdr l ) ) ) )
		( t ( min ( minim ( car l ) ) ( minim ( cdr l ) ) ) )
	)
)

(defun afla_poz(l P l2 poz)
	(cond
		( ( null l ) P )
		( (and ( numberp ( car l ) ) ( = ( car l ) ( minim l2 ) ) ( append (list poz) P ( afla_poz ( cdr l ) P l2 (+ poz 1 ) ) ) ) )
		( t ( afla_poz ( cdr l ) P l2 (+ poz 1 ) ) )
	)
)

(defun afla_tot(l)
	( afla_poz l () l 1 )
)

;l222222



(defun bilet_16(l e)
	( cond
		( ( null l ) nil )
		( ( and ( numberp ( car l ) ) ( equal ( car l ) e ) ) ( bilet_16 ( cdr l ) e ) )
		( ( and ( atom ( car l ) ) ( equal ( car l ) e ) ) ( bilet_16 ( cdr l ) e ) )
		( ( atom (car l ) ) ( cons ( car l ) ( bilet_16 ( cdr l ) e ) ) )
		( t ( cons ( bilet_16 ( car l ) e ) ( bilet_16 ( cdr l ) e ) ) )
	)
)
;verifica daca suma de pe niv impare este para
(defun verif (l niv)
	(cond
		(( and  ( = ( mod (suma l) 2 ) 0 ) ( = ( mod niv 2) 1) ) t )
		(t nil)
	)
)

(defun suma(l)
	(cond
		( ( null l) 0 )
		( ( numberp ( car l ) ) ( + (car l ) ( suma ( cdr l ) ) ) )
		( ( atom ( car l ) ) ( suma ( cdr l ) ) )
		( t ( + ( suma ( car l ) ) ( suma ( cdr l ) ) ) )
	)
)

(defun numara(l n)
	(cond
		
		( ( atom l ) 0 )
		( ( verif l n ) ( + 1 ( apply #'+ ( mapcar #'(lambda (l) ( numara l (+ n 1 ) ) ) l ) ) ) )
		( t ( apply #'+ ( mapcar #' (lambda (l) ( numara l (+ n 1 ) ) ) l ) ) )
	)
)


(defun final(l)
	( numara l 0 )
)

;Sa se scrie un program LISP pentru determinarea numarului de subliste de la orice nivel, pentru care atomul numeric minim de pe nivelurile impare este par

(defun verif (l niv)
	(cond
		(( and  ( = ( mod (minim l) 2 ) 0 ) ( = ( mod niv 2) 1) ) t )
		(t nil)
	)
)

(defun minim(l)
	( cond
		( ( null l ) 99999 )
		( ( numberp ( car l ) ) ( min ( car l ) ( minim ( cdr l ) ) ) )
		( (atom (car l)) ( minim ( cdr l ) ) ) 
		( t ( min ( minim ( car l ) ) ( minim ( cdr l ) ) ) )
	)
)

(defun funct (l niv)
	(cond
		((null l) 0)
		((atom l) 0)
		((verif l niv) 1)
		(t (apply #'+ (mapcar #'(lambda (l)
							(funct l (+ 1 niv))
							)l
					)))
	)
)

(defun f (l)
	(funct l 0)
)

;;; sa se numere sublistele de pe orice nivel care au primul atom numeric impar

(defun verif(l)
	( cond
		( ( = ( vezi_list l ) 1 ) t )
		( t nil )
	)
)

(defun vezi_list(l)
	(cond
		( ( null l ) 0 )
		( ( and ( numberp ( car l ) ) ( = ( mod ( car l ) 2 ) 1 ) ) 1 )
		( t ( vezi_list ( cdr l ) ) )
	)
)

(defun f(l)
	( cond
		( ( null l ) 0 )
		( ( atom l ) 0 )
		( ( verif l ) ( + 1 ( apply #'+ ( mapcar #'f l  ) ) ))
		( t ( apply #'+ ( mapcar #'f l ) ) )
	)
)

;;sa se numere sublistele care au cel mai mare atom numeric par

(defun verif(l)
	(cond
		( ( = ( mod ( maxim l ) 2 ) 0 ) t )
		( t nil )
	)
)

(defun maxim(l)
	( cond
		( ( null l ) -99999 )
		( ( numberp ( car l ) ) ( max ( car l ) ( maxim ( cdr l ) ) ) )
		( ( atom ( car l ) ) ( maxim (cdr l ) ) )
		( t ( max ( maxim ( car l ) ) ( maxim ( cdr l ) ) ) )
	)
)

(defun f(l)
	( cond 
		( ( null l ) 0 )
		( ( atom l ) 0 )
		( ( verif l ) ( + 1 ( apply #'+ ( mapcar #'f l ) ) ) )
		( t ( apply #'+ ( mapcar #'f l ) ) )
	)
)
;; sa se numere sublistele pt care atomul maxim de pe nivelurile impare este par


(defun verif(l niv)
	( cond
		( ( and ( = ( mod ( maxim l ) 2 ) 0 ) ( = ( mod niv 2 ) 1 ) ) t )
		( t nil )
	)
)

(defun maxim(l)
	( cond
		( ( null l ) -99999 )
		( ( numberp ( car l ) ) ( max ( car l ) ( maxim ( cdr l ) ) ) )
		( ( atom ( car l ) ) ( maxim (cdr l ) ) )
		( t ( max ( maxim ( car l ) ) ( maxim ( cdr l ) ) ) )
	)
)

(defun solv(l n)
	(cond
		( ( null l ) 0 )
		( ( atom l ) 0 )
		( ( verif l n) ( + 1 ( apply #'+ ( mapcar #' ( lambda(l) ( solv l (+ n 1 )) ) l ) ) ) )
		( t ( apply #'+ ( mapcar #' ( lambda(l) ( solv l (+ n 1) ) ) l ) ) )
	)
)

(defun f(l)
	( solv l 1 )
)

;p22222 arbori

;parcurge in inordine ( srd )

(defun inordine(l)
	(cond
		( ( null l ) nil )
		( t ( append ( inordine ( cadr l ) ) ( list ( car l ) ) ( inordine ( caddr l ) ) ) ) 

	)
)
;adancimea unui arbore
(defun adancime(l)
	( cond
		( ( null ( cdr l ) ) 0 )
		( t ( + 1 ( max ( adancime ( cadr l ) ) ( adancime ( caddr l ) ) ) ) )
	)
)

;nivelul pe care apare un nod x in arbore

(defun nivel(l x)
	(cond
		( ( null l ) -999 )
		( (equal ( car l ) x ) 0 )
		( t( + 1 ( max ( nivel ( cadr l ) x ) ( nivel ( caddr l ) x ) ) ) )
	)
)

;schimba elementele care apar pe nivelu k
(defun schimb(l l2 k)
	( cond
		( ( null l ) nil )
		( (and ( atom (car l) ) ( equal ( nivel l2 (car l) ) k ) ) ( cons 0 ( schimb ( cdr l ) l2 k ) ) )
		( ( atom ( car l ) ) ( cons ( car l ) ( schimb ( cdr l ) l2 k ) ) )
		( t ( cons ( schimb ( car l ) l2 k ) ( schimb ( cdr l ) l2 k ) ) )
	)
)

(defun sol(l k)
	( schimb l l k )
)


;lista nodurilor de pe un nivel
(defun list_nod(l k)
	(cond
		( ( = k 1 ) ( list ( car l ) ) )
		( t ( append ( list_nod ( cadr l ) (- k 1 ) ) ( list_nod (caddr l) (- k 1 ) ) ) )
	)
)
;afiseaza calea de la radacina pana la un nod dat
;vezi daca exista
(defun exista(l e)
	( cond
		( ( null l ) nil )
		( (equal ( car l ) e ) t )
		( (listp (car l) ) ( or ( exista ( car l ) e ) ( exista ( cdr l ) e ) ) )
		( t ( exista ( cdr l ) e ) )
	)
)
;fac drumul
(defun drum(l e)
	(cond
		( ( equal ( car l ) e ) ( list e ) )
		( ( exista ( cadr l ) e ) ( cons ( car l ) ( drum ( cadr l ) e ) ) )
		( ( exista ( caddr l ) e ) ( cons ( car l ) ( drum ( caddr l ) e ) ) )
		( t nil )
	)
)

;mapuri
(defun nr_atomi(l)
	(cond
		( ( null l ) 0 )
		( ( atom l ) 1 )
		( t ( apply #'+ ( mapcar #'nr_atomi l ) ) )
	)
)
;suma intr-o lista la orice level
(defun suma(l)
	(cond
		 ( ( null l ) 0 )
		 ( ( atom l ) l )
		 ( t ( apply #'+ ( mapcar #'suma l ) ) )
	)
)

;Definiti o functie care inlocuieste un nod cu altul intr-un arbore n-ar 
(defun inloc(l e1 e2)
	( cond
		( ( null l ) nil )
		( (equal l e1 ) e2 )
		( ( atom l ) l  )
		( t ( apply #'list ( mapcar #' ( lambda(l) ( inloc l e1 e2 ) ) l ) ) )
	)
)


;Sa se construiasca o functie care intoarce maximul atomilor numerici

(defun maxim(l)
	( cond
		( ( null l ) -999 )
		( (numberp l) l )
		( t ( apply #'max ( mapcar #'maxim l ) ) )
	)
)

;Sa se construiasca o functie care intoarce adancimea unei liste. 

(defun adancime(l)
	( cond
		 ( ( null (cdr l ) 0 ) )
		 ( t ( + 1 ( apply #'max ( mapcar #'adancime (cdr l ) ) ) ) )
	)
)

;sa se verifice daca un element exista pe orice nivel al unei liste

(defun exist(l e)
	(cond
		( ( null l ) nil )
		( ( equal ( car l ) e ) t )
		( ( listp ( car l ) ) ( or ( exist ( car l ) e ) ( exist ( cdr l ) e ) ) )
		( t ( exist ( cdr l ) e ) )
	)
)

;Definiti o functie care determina numarul nodurilor de pe nivelul k

(defun numar(l k)
	(cond
		 ( ( null l ) 0 )
		 ( ( = k 1 ) 1 )
		 ( t ( apply #'+ ( mapcar #' ( lambda (l) ( numar l (- k 1 ) ) ) ( cdr l ) ) ) ) 
	)
)

;Sa se scrie o functie care sterge toate aparitiile unui atom

(defun sterg(l n)
	(cond
		 ( ( null l ) nil )
		 ( (equal l n ) )
		 ( ( atom l ) ( list l ) )
		 ( t ( apply #'list ( mapcar #' ( lambda(l) ( sterg l n ) ) l ) ) )
	)
)



