; 5. Return the level of a node in a tree of type (1). The level of the root element is 0.

; (node no-subtrees list-subtree-1 list-subtree-2 ...) (1)
; (A 2 B 0 C 2 D 0 E 0) (1)

(defun explore (x node level children l)
        (cond
            ((eq x node) (format t "found ~d on level ~d~%" x level))
        )
        (cond
            ((null l) nil)
            ((= children 0) l)
            (t (explore x node level (- children 1) (explore x (car l) (+ level 1) (cadr l) (cddr l))))
        )
)

(defun solve (x l)
    (explore x (car l) 0 (cadr l) (cddr l))
)

(format t "B in (A 2 B 0 C 2 D 0 E 0):~%")
(solve 'G (list 'A 2 'B 2 'D 0 'E 2 'F 1 'H 1 'I 0 'G 0 'C 2 'J 0 'K 1 'L 0))

(format t "E in (A 2 B 0 C 2 D 0 E 0):~%")
(solve 'E (list 'A 2 'B 0 'C 2 'D 0 'E 0))

(format t "F in (A 2 B 0 C 2 D 1 F 0 E 0):~%")
(solve 'F (list 'A 2 'B 0 'C 2 'D 1 'F 0 'E 0))
