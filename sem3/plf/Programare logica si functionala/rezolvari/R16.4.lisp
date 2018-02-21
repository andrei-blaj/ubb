(defun sterge(l e)
	(cond
		((null l) nil)
		((AND (atom(car l)) (equal (car l) e)) (sterge (cdr l) e))
		( (listp(car l)) (cons (sterge (car l) e) (sterge (cdr l) e) ))
		(t (cons (car l) (sterge (cdr l) e) ))
	)
)
