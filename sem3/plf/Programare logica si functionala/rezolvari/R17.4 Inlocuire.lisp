(defun inlocuire(l k niv)
  (cond
   ((null l) nil)
   ((AND(atom(car l))(= k niv))(SETF (car l) 0)(cons (car l)(inlocuire(cdr l) k niv)))
   ((listp (car l))(cons(inlocuire(car l) k (+ niv 1))(inlocuire(cdr l) k niv)))
   (t(cons(car l)(inlocuire(cdr l) k niv)))
  )
)

   
   