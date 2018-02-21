;numarul de subliste care au ultimul atom numeric numar impar

(defun giveNum(L)
	(cond
		( (null L )nil)
		((numberp (car L) ) (append  (giveNum (cdr L)) (list(car L)) ))
		(t (giveNum (cdr L)))
	)
)

(defun verify(L)
	(= (mod (car (giveNum L)) 2 ) 1)
)

(defun countS(L)
	(cond
		( (atom L) 0 )
		( (verify L) (+ 1 (apply #'+ (mapcar #'countS L ) )))
		(t (apply #'+ (mapcar #'countS L)))
	)
)