;double the element from n to n
(defun doub(L K C)
	(cond
		( (null L) nil)
		( (= C 1) ( append (list(car L)) (list(car L)) ( doub (cdr L) K K ) ) )
		(t (cons (car L) (doub (cdr L) K (- C 1) ) ) )
	)
)
(defun double (L K) 
	(doub L K K)
)



;;V2

(defun dublare(l n poz)
	(cond
		((null l) nil)
		( (=(mod poz n) 0) (cons (car l)(cons (car l) (dublare (cdr l) n (+ poz 1)))) )
		(t (cons (car l)(dublare (cdr l) n (+ poz 1))))
	)
)