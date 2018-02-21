(defun adauga(l n i)
	(cond
		((null l) nil )
		((= (mod i n) 0) (cons (car l) (cons (car l) (adauga (cdr l) n (+ i 1)))))
		(t (cons (car l) (adauga (cdr l) n (+ i 1))))
	)
)
