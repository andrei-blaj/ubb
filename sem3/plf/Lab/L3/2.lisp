; Write a function that returns the sum of numeric atoms in a list, at any level
; Need to solve it using map function

(defun sum(array)
  (cond
    ((null array) 0)
    ((numberp array) array)
    ((atom array) 0)
    (t (apply '+ (mapcar 'sum array)))
  )
)
