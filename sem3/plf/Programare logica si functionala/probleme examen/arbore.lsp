(defun pre(l)
(cond
((null l) nil)
(t (append (list(car l))(pre(cadr l))(pre(caddr l))))
)
) 

(defun pre(l)
(cond
((null l) nil)
(t (append (list(car l))(pre(cadr l))(pre(caddr l))))
)
) 