;R16P5
(defun sum(l)
	(cond
		((null l) 0)
		((numberp (car l)) (+ (car l) (sum (cdr l))))
		(t(sum (cdr l)))
	)
)
(defun par(l)
	(cond
		((= (mod l 2) 0) 1)
		(t 0)
	)
)

(defun nrsub (l k)
	(cond 
		((atom l) 0)
		;((and (equal (par (sum l)) 1) (equal (par k) 0)) (+ 1 (apply '+ (mapcar #'(lambda(x)(nrsub x k)) l))))
		((and (equal (par (sum l)) 1) (equal (par k) 0))(cons l (mapcar #'(lambda(x)(nrsub x k)) l)))
		;(t (apply '+ (mapcar #'(lambda(x)(nrsub x (+ 1 k))) l)))
		(t(mapcar #'(lambda(x)(nrsub x (+ 1 k))) l))
	)
)