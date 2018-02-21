;;suma nivel impar
(defun suma_niv(l niv)
	(cond
		((AND (numberp l) (=(mod niv 2) 1)) l)
		((AND (numberp l) (=(mod niv 2) 0)) 0)
		(t (apply '+(mapcar #'(lambda(a) (suma_niv a (+ 1 niv))) l )))
	)
)

;;verific daca un numar e par
(defun verifica_par(n)
	(cond
		((= (mod n 2) 0) t)
	)
)

(defun determinare(l)
	(cond
		((atom l) 0)
		
		;;daca suma de pe nivelele impare este numar par, aplic un mapcar + 1
		((verifica_par (suma_niv l 0)) (+ 1 (apply '+(mapcar #'determinare l))) )
		
		(t  (apply '+(mapcar #'determinare l)) )
	)
)