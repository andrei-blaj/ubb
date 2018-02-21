

(defun F(L)
	(funcall #'(lambda(FF)
		(cond
			((null L)nil)
			((listp (car L)) (append FF (F (cdr L))(car FF )))
			(t (list(car L)))
		)
	) (F (car L)))
)