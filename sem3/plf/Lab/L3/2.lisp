; Write a function that returns the sum of numeric atoms in a list, at any level

// Need to solve it using map function

(defun sum (array)
	(cond
		((null array) 0)
		((numberp (car array)) (+ (car array) (sum (cdr array))))
		((listp (car array)) (+ (sum (car array)) (sum (cdr array))))
		(T (sum (cdr array)))
	)
)
