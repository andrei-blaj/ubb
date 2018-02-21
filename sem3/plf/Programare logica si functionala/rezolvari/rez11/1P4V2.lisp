;;;; Se da un arbore de tipul (2). Sa se afiseze calea de la 
;;;; radacina pana la un nod x dat.
;;;; repr: (A (B) (C (D) (E))))
 
;;; l - arborele sub forma de lista 
;;; x - nodul cautat 
(defun get-path(l x) 
	(cond
		;; nu mai avem unde cauta 
		((null l) nil)
		((equal (car l) x) (list x)) ;; am gasit elementul cautat,caz in care se returneaza lista form. din elem. x
	 	((not(equal (get-path (cadr l) x) nil))		;; atomul a fost gasit pe ramura stanga
			 (cons (car l) (get-path (cadr l) x)))
		((not(equal (get-path (caddr l) x) nil))	;; atomul a fost gasit pe ramura dreapta
		         (cons (car l) (get-path (caddr l) x)))
	)
)