;;;;Write a function to return the sum of all numerical atoms in a list, at any level.

(defun sum (array)
	(cond
		((null array) 0)
		((numberp (car array)) (+ (car array) (sum (cdr array))))
		((listp (car array)) (+ (sum (car array)) (sum (cdr array))))
		(T (sum (cdr array)))
	)
)