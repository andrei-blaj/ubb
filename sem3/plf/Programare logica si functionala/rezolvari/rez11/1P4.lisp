;calea de la radacina catre un nod dat

(defun myOr(L)
	(cond
		( (null L) nil)
		( (car  L) t  )
		(t (myOr (cdr L)) )
	)
)

(defun exist(Tr N)
	(cond
		( (and (atom Tr) (equal Tr N)) t)
		( (atom Tr) nil)
		(t (myOr (mapcar #'(lambda(L)(exist L N)) Tr )))
	)
)
(defun takeElem(L)
	(cond
		((null L) nil)
		((car L) (car L) )
		(t (takeElem (cdr L)))
	)
)
(defun path(L N)
	(cond
		( (atom L) nil)
		((exist L N) (append (list(car L))  (takeElem(mapcar #'(lambda(L)(path L N)) L )) ) )
		(t nil)
	)
)