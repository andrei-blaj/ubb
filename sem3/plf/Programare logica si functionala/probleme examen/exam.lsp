;5.	3. Write Lisp functions to determine the number of sublists of a given list,
; with an atom on their last position:

(defun nrsub(l)
(cond
	((null l) 0)
	((and(atom (car l)) (null(cdr l)))  1 )
	((atom (car l)) (nrsub (cdr l)))
	(t (+ (nrsub(cdr l)) (nrsub (car l))))
	)
	)
	
	
	(defun ultim(l)
	(cond
		((null l)0)
		((and (atom(car l)) (null (cdr l))) 1)
		(t (+ (ultim(cdr l))))
	)
	)
	
	(defun atsup(l)
	(cond
	((null l)0)
	((and(atom (car l))(null (cdr l))) 1)
		((atom (car l)) (atsup (cdr l)))
		(t (+ (ultim(car l))(atsup(cdr l)) ))
	)
	)
	
;. era o prob cu lista neliniara: formata din elem int si lista de int, si sa elimin listele de lung para
(defun lung(l)
(cond
	((null l)nil)
	((numberp (car l)) (append(list(car l)) (lung (cdr l))))
	((and (listp (car l)) (equal 0 (mod(length (car l)) 2)))(lung(cdr l)))
	((listp (car l)) (append (list(car l)) (lung( cdr l))))
	(t list(append (lung(car l)) (lung (cdr l))))
	)
	)
	
	
	;sa generez toata submultimile de N elem ale unei liste date
	
	
	(defun inse (e l)
	(cond
		((null l)nil)
		(t(cons(cons e(car l)) (inse e (cdr l))))
	))
	
	
(defun subm(l)
(cond
	((null l) ( list nil))
	(t (append (subm(cdr l)) (inse (car l) (subm(cdr l)))))
	)
	
)

(defun num( l n)
(cond
	((null l)nil)
		((equal (length (car l)) n) (append (list(car l))(num (cdr l) n)))
		(t (num (cdr l) n))
)
)
(defun start(l n)
(num (subm l) n)

)
	
	
	;sa se determine permutarile unei liste
;permult coada listei si inserez primul elem pe toate poz in fiecare din 
;permutarile obtinute
;insereaza un elem pe o poz
(defun ins(e n l)
  (cond 
    ((= n 1) (cons e l))
    (t (cons (car l) (ins e (- n 1) (cdr l))))
  )
)
;insereaza un elem pe poz 1,2,...,n
(defun insert (e n l)
  (cond
     ((= n 0) nil) ;insereare pe primele 0 pozitii, nimic
     (t (cons (ins e n l) (insert e (- n 1) l))) 
     ;inserez pe poz n, si pe primele n-1 pozitii
  )
)
;inser un elem pe toate poz posibile dintr-o lista
;concat rezultatele
(defun ins_all(e l)
  (insert e (+ 1 (length l)) l)
)
;insereaza elem e pe toate poz in elem (listele) din l
(defun add(e l)
   (cond
     ((null l) nil) ;nu fac nimic daca lista e vida
     (t (append (ins_all e (car l)) (add e (cdr l))))
    ;inserez pe toate poz in primul element
    ;recursiv, la fel, pt restul listei
    ;concatenez rezultatele
   )
)
(defun permutari(l)
  (cond 
     ;daca lista are un singur elem
    ((null (cdr l)) (list (list (car l))))
    ;altfel adaug primul elem in toate permut restului listei 
    (t (add (car l) (permutari (cdr l))))
  )
)

(defun insen(e n l)
(cond
	((= n 1) (cons e l))
	(t(append (list(car l)) (insen e (- n 1) (cdr l))))
)
)


(defun insn (e n l)
(cond
	((= n 0)	nil)
	(t(append (list(insen e n l)) (insn e (- n 1) l)))

))

(defun insl (e l)
	(insn e (+ (length l) 1) l)
)

(defun insp(e l)
(cond
	((null l) nil)
	(t(append (insl e (car l))	(insp e (cdr l))))
)
)

(defun permut(l)
(cond
	((null (cdr l)) (list (list(car l))))
	(t (insp (car l) (permutari (cdr l))))
	
)
)



;3. Write Lisp functions to determine the number of sublists of a given list, with an atom on their last position:
;(a)at superficial level
;e.g.:L=(A (B C) (D (E F)) ((G H) I)) has two sublists (B C) and ((G H) I);work recursively;
;(b)at any level
;e.g.:L=(A (B C) (D (E F)) ((G H) I)) has four sublists (B C),((G H) I),(E F),(G H);here use Map functions.



(defun verul(l)
(cond
		((null l) 0)
		((and(null (cdr l))(atom (car l))) 1)
		(t (verul (cdr l)))
)
)

(defun nrsubl(l)
(cond
	((null l) 0)
	((atom (car l)) (nrsubl (cdr l)))
	(t (+ (verul (car l)) (nrsubl (cdr l))))
)
)

(defun maps(l)
(cond
	((atom l) 0)
	((and(atom (car l)) (null(cdr l)))  1 )
	(t (apply '+  (mapcar  'maps l )))
))







(defun parimp (l)
	(cond
	((and (numberp l) (equal 0 (mod l 2))) ( + l))
	((and (numberp l) (equal 1 (mod l 2))) ( - l ))
	((atom l) 0)
	(t (apply '+ (mapcar 'parimp l)))
	)
)

(defun stn ( n l)
(cond
	((= n 1) (cdr l))
	(t(append (list(car l)) (stn (- n 1) (cdr l)) )))
)

;3. Scrieți un predicat care dintr-o listă de numere întregi returnează o
 ;listă cu submulțimile de k elemente aflate în progresie aritmetică.
 ;Explicați algoritmul. Exemplu pentru [1,3,2,5,9,8] și k=3 => [[1,2,3],[1,5,9],[2,5,8]]


(defun insn(e l)
(cond
	((null l)nil)
	(t(cons (cons e (car l)) (insn e (cdr l))))
))


(defun submulti (l)
(cond
((null l) (list nil))
(t(append (submulti (cdr l)) (insn (car l) (submulti (cdr l)))))
)
 )


(defun buna(l n)
(cond
	((null (cdr l))t)
	((null l) nil)
	((= (- (cadr l) (car l)) n) (buna (cdr l) (car l)))
	(t nil)
))

(defun startbun(l)
(buna (cdr l) (- (cadr l) (car l)))
)


(defun tr(l k)
	(final (submulti l) k)
)


(defun final(l k)
	(cond
	((null l)nil)
	((and (=(length (car l)) k) (startbun(car l))) (append (list(car l)) (final (cdr l) k)))
	(t (final (cdr l) k))
)
)

;30.Se cere sa se elimine prima aparitie a unui element e dintr-o lista neliniara
;ex: (elimin '1 '(2 3 (1 (4 5)) 1)) -> (2 3 ((4 5)) 1)
(defun elimin(l e)
(cond
	((null l) nil)
	((and(numberp (car l)) (=(car l) e)) (cdr l))
	((atom (car l)) (append (list (car l)) (elimin (cdr l) e)))
	(t(append (list (elimin(car l) e)) (elimin (cdr l) e)))
)
)
;Se da o lista liniara numerica si se cere sa se scrie de 2 ori elem-le din N in N.
;De exemplu, pentru lista (1 2 3 4 5) si N=2 rezulta lista (1 2 2 3 4 4 5)

(defun dublu(l n k)
(cond
	((null l)nil)
	((= 0 (mod k n)) ( append (list (car l) (car l)) (dublu (cdr l) n (+ k 1))))
	(t (append (list (car l)) (dublu (cdr l) n (+ k 1))))
)
)


;3. Se da o lista neliniara. Sa se scrie un program LISP pt determinarea numarului 
;de subliste de la orice nivel pt care nr-ul atomilor nenumerici de pe nivelurile pare(de la orice nivel)este impar
;- nivelul superficial al listei se considera 1.
 ;Prelucrarea se va face folosind o functie MAP. 
 ;De exemplu, lista (A (B 2) (1 C 4) (1(6 F)) (((G)4)6)) are 3 astfel de subliste: lista, (1(6 F)) si ((G)4)

 
 (defun nratomn(l)
	(cond
		((numberp l) 1)
		((atom l) 0)
		(t (apply '+ (mapcar 'nratomn l)))
	)
 )
 
 (defun adancime (l)
(cond
((null (cdr l)) 0)
(t(+ 1 (apply 'max (mapcar 'adancime (cdr l)))))

)
)

 
 (defun nrsbl(l n)
	(cond
	((atom l) 0)
	((and (= 1 (mod (nratomn l) 2)) (= 0 (mod n 2))) (+ 1 (apply '+ (mapcar (lambda(l) (nrsbl l (+ n 1)) ) l))))
	(t (apply '+ (mapcar (lambda(l) (nrsbl l (+ n 1))) l)))
	)
	)
 
 
(defun par(l)
(cond
((= 0 (mod (length l) 2)) t)
(t nil)
) 
)

(defun nr(l)
( cond
((atom l) 0)
((par l) (+ 1 (apply '+ (mapcar 'nr l))))
(t (apply '+ (mapcar 'nr l)))
))


;3. sa se scrie o fct care numara toate sublistele care se termina cu un numar dintr-o lista:
;a) de la nivelul superficial, ex pt (A (B 1) (1 C 4) (D 1 (6 F)) ((G 4) 6)) se va returna 3 deoarece: 
;(B 1), (1 C 4), ((G 4) 6)
;b) de la orice nivel, ex pt aceasi lista se va returna 3 pt ca (B 1), (1 C 4), ((G 4) 6), (G 4)

(defun ultim(l)
(cond
	((null l)nil)
	((and( null (cdr l))  (numberp (car l))) t)
	(t (ultim (cdr l)))
)
)

(defun term(l)
(cond
	((atom l)0)
	((ultim l) (+ 1 (apply '+ (mapcar 'term l))))
	(t (apply '+ (mapcar 'term l)))
)
)

;2. sa se elimine un element dintr-o lista de la orice nivel

(defun eli(l e)
(cond
	((null l)nil)
	((equal (car l) e) (eli (cdr l) e))
	((atom (car l)) ( append (list (car l)) (eli (cdr l) e)))
	(t (append (list(eli (car l) e)) (eli (cdr l) e)))
	)
)

;3. sa se scrie o fct care afiseaza toate sublistele al carui maxim este numar par:
;a) de la nivelul superficial, ex pt (A (B 1) (1 C 4) (D 1 (6 F)) ((G 4) 6)) se va returna
;, (1 C 4),(D 1 (6 F)), ((G 4) 6)
;b) de la orice nivel, ex pt aceasi lista se va returna  (1 C 4),(1 C 4) ,((G 4) 6), (G 4),(D 1 (6 F)), (6 F)


(defun maxim (l)
(cond
	((null l) -32000)
	((numberp (car l)) (max (car l) (maxim (cdr l))))
	(t(maxim (cdr l)))
)
)

(defun mpar(l)
(cond
	((null l) nil)
	((and (listp (car l))(= 0 (mod (maxim (car l)) 2) )) (append (list(car l)) (mpar (cdr l))))
	(t (mpar (cdr l)) )
	)
)
(defun maxin(l)
(cond
	((null l) -32000)
	((numberp (car l)) (max (car l) (maxin (cdr l))))
	((atom (car l))(maxin (cdr l)))
	(t(max(maxin(car l)) (maxin (cdr l))))
)
)
(defun oricen(l)
(cond
	((atom l) nil)
	((= 0 (mod (maxin l) 2))(append (list l) (apply 'append (mapcar 'oricen l))))
	(t (apply 'append (mapcar 'oricen l)))
)
)



(defun apare (l e)
(cond
	((null l)nil)
	((equal (car l) e)t)
	(t(or (apare(cadr l) e) (apare (caddr l) e)) )
)
)
(defun adancime (l)
(cond
  ((null (cdr l)) 0)
  (t(+ 1 (apply 'max(mapcar 'adancime (cdr l)))))
)
)



(defun lista (l k)
(cond
	((and (= k 0) (atom l))(list l))
	((= k 0) nil)
	((atom l) nil)
	(t (mapcan (lambda (l) (lista l (- k 1))) l))
)
)


;2. Un arbore n-ar se reprezintă în LISP în următorul fel: (nod subarb1 subarb2 ... subarb n).
 ;Se cere numărul de noduri de pe nivelul k. Nivelul rădăcinii se consideră 0.
 ;Exemplu: pentru (a (b (g)) (c (d (e)) (f))) și k=2 => 3 (g, d și f). k= 4 => 0

 (defun nrsub(l k)
 (cond
	((and (= k 0) (atom l)) 1)
	((atom l) 0)
	((= k 0) 0)
	(t (apply '+ (mapcar (lambda(l) (nrsub l (- k 1))) l)))
)
)


;(nrsub '(a (b (g)) (c (d (e)) (f)))4 ) 
;3. Se dă o listă neliniară. Se cere un program LISP pentru determinare 
;numărului de subliste de pe orice nivel pentru care primul atom numeric la orice nivel este număr par

(defun primul(l)
	(cond
		((and (numberp (car l))( = 0 (mod (car l) 2)) ) t)
		(t nil)
	)
)

(defun nrsubli(l)
	(cond
		((atom l) 0)
		((primul l) (+ 1 (apply '+ (mapcar 'nrsubli l))))
		(t (apply '+ (mapcar 'nrsubli l)))
		
	)
)

;
;3. Se da o lista neliniara. Sa se scrie un program LISP pt determinarea nr-lui de subliste de la 
 ;  orice nivel pt care nr-ul atomilor numerici de la orice nivel este impar
';- nivelul superficial al listei se considera 1. Prelucrarea se va face folosind o fctie MAP.
  ;De exemplu, lista (A( B 2)(1 C 4)(D 1 (9 F)((G 7)6))) are 3 astfel de liste (D 1 (9F)), (9 F),
(;G 7)

(defun imp(l)
(cond
	((null l)0)
	((numberp (car l)) (1 + (imp (cdr l))))
	((atom (car l)) (0 + (imp (cdr l))))
	(t(+ (imp (car l)) (imp (cdr l))))
))

(defun ni(l)
(cond
	((= 1 (mod (imp l) 2)) t)
	(t nil)
)

)
(defun nri(l)
(cond
	((atom l)0)
	((ni l)(+ 1 (apply '+ (mapcar 'nri l))))
	(t(apply '+ (mapcar 'nri l)))
)
)

;e.g.:L=(A (B C) (D (E F)) ((G H) I)) has two sublists (B C) and ((G H) I);work recursively;
;.	(b)at any level	e.g.:L=(A (B C) (D (E F)) ((G H) I)) has four sublists (B C),((G H) I),(E F),(G H);here use Map functions.


(defun numa(l)
(cond
	((null l )nil)
	((and(null (cdr l)) (atom (car l)))t)
	(t(numa (cdr l)))
)
)
(defun nrsa(l)
(cond
	((atom (car l)) 0)
	(t(+ (numa(car l)) (nrsa (cdr l))))
)
)


















