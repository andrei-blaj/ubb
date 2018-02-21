(defun insen(e n l)
(cond
	((= n 1) (cons e l))
	(t(append (list(car l)) (insen e (- n 1) (cdr l))))
)
)


(defun insn (e n l)
(cond
	((= n 0)	nil)
	(t(append (list(insen e n l)) (insn e (- n 1) l)))

))

(defun insl (e l)
	(insn e (+ (length l) 1) l)
)

(defun insp(e l)
(cond
	((null l) nil)
	(t(append (insl e (car l))	(insp e (cdr l))))
)
)

(defun permut(l)
(cond
	((null (cdr l)) (list (list(car l))))
	(t (insp (car l) (permut (cdr l))))
	
)
)

(defun insert(e n l)
(cond
	((= n 1 ) (cons e l))
	(t( append (list (car l)) (insert e (- n 1) (cdr l))))
))

(defun insertall(e n l)
(cond
	((= n 0) nil)
	(t(append (list(insert e n l)) (insertall e (- n 1) l)))
)
)


(defun insn (e l)
	(insertall e (+ 1(length l)) l)
)

(defun add(e l)
(cond
	((null l)nil)
	(t(append(insn e (car l)) (add e (cdr l))))
	)
)
(defun permut(l)
	((null cdr l) (list(car l)))
	(t (add(car l) (permut (cdrl))))
	
)

























