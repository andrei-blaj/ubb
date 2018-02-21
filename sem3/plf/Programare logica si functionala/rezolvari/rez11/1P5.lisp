

;numarul de liste care au primul atom numeric un numar impar


(defun verify(L)
	(cond
		((null L )nil)
		((and (numberp (car L)) (= (mod (car L) 2) 1)) t)
		(( numberp (car L)) nil )
		(t (verify (cdr L)) )
	)
)

(defun nr(L)
	(cond
		( (atom L) 0)
		( (null L) 0)
		( (verify L ) (+ 1 (apply #'+ (mapcar #'nr L) )))
		(t (apply #'+ (mapcar #'nr L)))
	)
)