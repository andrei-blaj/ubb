;;;;; Write a function to reverse a list with its all sublists, on all levels.
(defun reverse_all(L)
    (cond
        ((null L) nil)
        ((listp (car L)) (append (reverse_all (cdr L)) (list (reverse_all (car L)))))
        (T
            (append (reverse_all (cdr L)) (list (car L)))
        )
    )
)
