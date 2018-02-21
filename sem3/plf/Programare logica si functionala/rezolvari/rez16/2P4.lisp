;Stergem toate aparitile unui element E

(defun sterg(L E)
	(cond
		( (and (atom L)  (equal L E ) ) nil)
		( (atom L) (list L) )
		(t ( list (mapcan #'(lambda(L)(sterg L E)) L ) ))
	)
)