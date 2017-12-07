;;;;;Write a function to return the difference of two sets.

(defun list_exists (array elem)
	(cond
		((null array) 0)
		((equal (car array) elem) 1)
		(T (list_exists (cdr array) elem))
	)
)

(defun abs_set_diff (first_set second_set)
	(append (set_diff first_set second_set) (set_diff second_set first_set))
)

(defun set_diff (first_set second_set)
	(cond
		((null first_set) nil)
		((equal (list_exists second_set (car first_set)) 0 ) (cons (car first_set) (set_diff (cdr first_set) second_set)))
		(T (set_diff (cdr first_set) second_set))
	) 
)