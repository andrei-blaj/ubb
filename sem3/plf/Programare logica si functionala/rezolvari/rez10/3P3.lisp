Prin evaluarea formei se va optine o eroare deoarece f este o variabila,
si primul parametru nu este niciodata evaluat de lisp. O posibila optiune este
de a chema in felul urmator (funcall f '(1 2 3))