;;;; Write a function to return the list of the first elements of all list elements of a given list with an odd number of elements at superficial level

(defun solve_c(array)
	(cond
		((equal (mod (length array) 2) 1) (cons (car array) (solve array)))
		(T (solve array))
	)	
)

(defun solve (array)
	(cond
		((null array) nil)
		((and (listp (car array)) (equal (mod (length (car array)) 2) 1)) (append (cons (car (car array)) (solve (car array)) ) (solve (cdr array)) ) )
		((and (listp (car array)) (equal (mod (length (car array)) 2) 0)) (append (solve (car array)) (solve (cdr array))) )
		(T (solve (cdr array)))
	)
)