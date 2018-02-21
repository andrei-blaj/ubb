
; R3. 4.Atomii de pe nivelul k au fost inlocuiti cu 0
(defun inlocuire(k l e)
	(cond 
		((and (= k 0) (atom l)) (list e))
		;((= k 0) (list l))
		((atom l) (list e))

		(t (list(mapcan #'(lambda (v)
							(inlocuire (- k 1) v)
							)
							l
			)
		)
		)
	)
)

; Lista atomilor de adancime k
(defun lista (l k)
	(cond
		((and (= k 0) (atom l)) (list l))
		((= k 0) nil)
		((atom l) nil)
		(t (mapcan #'(lambda (v)
						(lista v (- k 1))
					  )
						l
			)
		)
	)
)
; R5. 4
(defun inlocuirenod(k l e)
	(cond 
		((and (= k 0) (atom l)) (list e))
		;((= k 0) (list l))
		((atom l) (list l))

		(t (list(mapcan #'(lambda (v)
							(inlocuirenod (- k 1) v e)
							)
							l
			)
		)
		)
	)
)

; Numarul de noduri de pe nivelul k
(defun nr_nod(l k)
	(cond
		((null l) 0)
		((and (atom l) (= k 0)) 1)
		((atom l) 0)
		(t (apply #'+ (mapcar #'(lambda (x) (nr_nod x (- k 1))) l)))
	)
)

;R16. 4
(defun sterge_toate(l e)
	(cond
		((null l) nil)
		((and (atom l) (eq l e)) nil)
		((atom l) (list l))
		(t (list (mapcan #'(lambda (x) 
								(sterge_toate x e)
							) 
							l
					)
			)
		)
)
) 


;R11. 4.
(defun inlocuirenod_impar(k l e)
	(cond 
		((and ( = (mod k 2) 0) (atom l)) (list e))
		;((= k 0) (list l))
		((atom l) (list l))

		(t (list(mapcan #'(lambda (v)
							(inlocuirenod_impar (- k 1) v e)
							)
							l
			)
		)
		)
	)
)

; R11* 4. Calea de la radacina la un nod dat.
(defun mem(e l)
  (cond
	((null l) nil)
	((and (atom (car l)) (eql e (car l))) t)
	((and (atom (car l)) (not (eql e (car l)))) (mem e (cdr l)) )
	(t  (mem e (car l)))
  )
)

(defun path2(l e)
    (cond
        ((null l) nil)
        ((equal (car l) e) (list (car l))) ;if the element is the root of subtree return it
        ((mem e (cadr l) ) (cons (car l) (path2 (cadr l) e))) ;if it is in the first subtree, get the root and check in first subtree until you get to it
        ((mem e (caddr l) ) (cons (car l) (path2 (caddr l) e ))) ; get the root and parse the second subtree
        (T nil))) ;here i can't find the rule to check in the rest of the subtrees

 ;R12. 4. Sa se dubleze elementele din N in N.
 (defun dublu(l n k)
(cond
	((null l)nil)
	((= 0 (mod k n)) ( append (list (car l) (car l)) (dublu (cdr l) n (+ k 1))))
	(t  (cons (car l) (dublu (cdr l) n (+ k 1))))
)
)

 ;R17. Inlocuire valori numerice cu o valoare data, la toate nivelurile.

(defun sterge_toate2(l e)
	(cond
		((null l) nil)
		((numberp l) (list e))
		((atom l) (list l))
		(t (list (mapcan #'(lambda (x) 
								(sterge_toate2 x e)
							) 
							l
					)
			)
		)
)
) 

(defun substituire(l e)
	(cond 
		((null l) nil)
		((numberp (car l)) (cons e (substituire (cdr l) e ) ))
		((atom (car l)) (cons (car l) (substituire (cdr l) e)))
		(t (cons (substituire (car l) e) (substituire (cdr l) e)))
	)
)

; Numarul de subliste pt care primul atom numeric este par
(defun primul(l)
	(cond
		((and (numberp (car l))( = 0 (mod (car l) 2)) ) t)
		(t nil)
	)
)

(defun nrsubli(l)
	(cond
		((atom l) 0)
		((primul l) (+ 1 (apply #'+ (mapcar 'nrsubli l))))
		(t (apply #'+ (mapcar 'nrsubli (cdr l))))
		
	)
)


;nr-lui de subliste de la 
 ;  orice nivel pt care nr-ul atomilor numerici de la orice nivel este impar
(defun imp(l)
(cond
	((null l)0)
	((numberp (car l)) (+ 1 (imp (cdr l))))
	((atom (car l)) (+ 0 (imp (cdr l))))
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

; nr sub care se termina cu un numar par
(defun ultim(l)
(cond
	((null l)nil)
	((and( null (cdr l))  (numberp (car l)) (= 0 (mod (car l) 2)))  t)
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

;R3. 1
(defun F(L)
	(cond
		((atom L) -1)
		((> (F(car L)) 0) (+ (car L) (F(car L)) (F(cdr L))))
		(t (F(cdr L)))
	)
)

;R12. Primul atom este nenumeric

(defun primul2(l)
	(cond
		((and (atom (car l))(not (numberp (car l)))) t)
		(t nil)
	)
)

(defun nrsubli2(l)
	(cond
		((atom l) 0)
		((primul2 l) (+ 1 (apply #'+ (mapcar 'nrsubli2 l))))
		(t (apply #'+ (mapcar 'nrsubli2 (cdr l))))
		
	)
)


; R5.  5.Numarul de subliste pt care atomul numeric maxim este par
(defun numar(l)
	(cond
		((= 0 ( mod (maxim l) 2)) t) 
		(t nil)
	)
)
(defun maxim(l)
	(cond
        ((null l) 0)
	    ((numberp (car l)) (max (car l) (maxim(cdr l))))
	    ((and (atom(car l)) (not(numberp (car l)))) (maxim(cdr l)))
	    (t (max (maxim (car l)) (maxim (cdr l))))
	)
)


(defun nr(l)
	(cond
		((atom l) 0)
		((numar l) (+ 1 (apply #'+ (mapcar #'nr l))))
		(t (apply #'+ (mapcar #'nr l)))
	)
)