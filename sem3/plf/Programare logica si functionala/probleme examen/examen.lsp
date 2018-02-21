


(defun produs(l x c)
(cond
		
		((and(null l ) (= c 0)) nil)
		((and (null l) (> c 10)) (list (mod c 10) (- c (mod c 10)) ))
		((and(null l ) (< c 10)) (list c))
		((<(+(* x (car l))c) 10)(append (list(+( * x (car l)) c)) (produs (cdr l) x 0) ))
		(t(append (list(mod (+( * x (car l)) c) 10)) (produs (cdr l) x (/(- (+( * x (car l)) c) (mod (+( * x (car l)) c) 10)) 10) )))
)
)

(defun invers(l)
(cond
	((null l)nil)
	(t(append (invers (cdr l)) (list(car l))))
	))
	
(defun start(l x)
(cond
	((= x 1) l)
	(t(invers(produs (invers l) x 0)))
)
)