

(defun nratom(l)
(cond
	((atom l) 1)
	(t(apply '+ (mapcar 'nratom l)))
)
)


(defun sumatom(l)
(cond
	((numberp l) l)
	((atom l) 0)
	(t (apply '+ (mapcar 'sumatom l)))
)
)

(defun elmn(l)
(cond
	((numberp l) nil)
	((atom l) (list l))
	(t (list(apply 'append (mapcar 'elmn l))))
)
)

(defun adancime (l)
(cond
((null (cdr l)) 0)
(t(+ 1 (apply 'max (mapcar 'adancime (cdr l)))))

)
)


(defun inloc(l b g)
(cond
	((equal b l) (list g))
	((atom l) (list l))
	(t (list(apply 'append(mapcar (lambda (l) (inloc l b g))
							l))))
)
)


(defun prodn(l)
(cond
	((numberp l) l)
	((atom l) 1)
	(t (apply '* (mapcar 'prodn l)))
)
)


(defun maxim(l)
(cond
		((numberp l) l)
		((atom l) -32000)
		(t(apply 'max (mapcar 'maxim l)))
)
)


(defun adancimea(l)
(cond
	((atom l) 0)
	(t(+ 1(apply 'max (mapcar 'adancimea l))))

))





(defun apare(l a)
(cond
	((equal l a) (list t))
	(t (apply 'append (mapcar (lambda(l) (apare l a)) l) ))
)
)







;Definiti o functie care inverseaza o lista impreuna cu toate sublistele
;sale de pe orice nivel.


(defun invers(l)
(cond
	((atom l) (list l))
     (t (list(apply 'append( mapcar 'invers (reverse l)))))
)
)

;Definiti o functie care determina numarul nodurilor de pe nivelul k
;dintr-un arbore n-ar reprezentat sub forma (radacina lista_noduri_subarb1
;... lista_noduri_subarbn) Ex: arborelele este (a (b (c)) (d) (e (f))) si
;k=1 => 3 noduri

(defun nrnod(l k)
(cond
 ((= k 1) 1)
 (t (apply '+ (mapcar (lambda(l) (nrnod l (- k 1))) l)))
)
)

;Sa se scrie o functie care sterge toate aparitiile unui atom de la
;toate nivelurile unei liste.

(defun stergere (l a)
(cond
	((equal l a) nil)
	((atom l) (list l))
	(t (list(apply 'append (mapcar (lambda (l) (stergere l a)) l))))
)
)

;Sa se scrie o functie care calculeaza suma numerelor pare minus suma
;numerelor impare la toate nivelurile unei liste.

(defun parimp (l)
	(cond
	((and (numberp l) (equal 0 (mod l 2))) ( + l))
	((and (numberp l) (equal 1 (mod l 2))) ( - l))
	((atom l) 0)
	(t (apply '+ (mapcar 'parimp l)))
	)
)

(defun inser(l e)
(cond
	((null l) nil)
	(t ( cons (cons e ( car l)) (inser (cdr l) e) ))
))

(defun submult(l)
(cond
	((null l) (list nil))
	(t(append (submult(cdr l))(inser (submult (cdr l)) (car l)) ))
)
)
(defun subm(l)
(cond
	((null l) ( list nil))
	(t (append (subm(cdr l)) (ins (car l) (subm(cdr l)))))
	)

)

(defun ins(e l)
( cond
	((null l) nil)
  (t (cons (cons e (car l)) (ins e (cdr l))))
)
)













;Definiti o functie care substituie un element prin altul la toate
;nivelurile unei liste date.

(defun substi (l a b)
(cond
	((equal l a) (list b))
	((atom l) (list l))
	(t (list(apply 'append (mapcar (lambda (l) (substi l a b)) l))))

)
)

;Definiti o functie care substituie un element E prin elementele
;unei liste L1 la toate nivelurile unei liste date L.


(defun substl (l e l1)
(cond
	((equal l e) l1)
	((atom l) l)
	(t (mapcar (lambda(l) (substl l e l1)) l))
)
)





;14. Definiti o functie care obtine dintr-o lista data lista tuturor atomilor
;care apar, pe orice nivel, dar in aceeasi ordine. De exemplu
;(((A B) C) (D E)) --> (A B C D E)

(defun atomt(l)
(cond
	((atom l) (list l))
	(t (apply 'append (mapcar 'atomt l)))
)
)

;Definiti o functie care testeaza apartenenta unui nod intr-un arbore n-ar
;reprezentat sub forma (radacina lista_noduri_subarb1... lista_noduri__subarbn)
;Ex: arborelele este (a (b (c)) (d) (e (f))) si nodul este 'b => adevarat



;16. Definiti o functie care da adancimea unui arbore n-ar reprezentat sub forma
;(radacina lista_noduri_subarb1...lista_noduri_subarbn)
;Ex: adancimea arborelui este (a (b (c)) (d) (e (f))) este 3

(defun adanc (l)
(cond
	((null (cdr l))0)
	(t (max(apply '+ 1 (mapcar 'adanc (cdr l)))))
)
)

(defun inversare(lista)
	(punctb lista nil)
)
(defun punctb(l v)
  (cond
	((null l)v)
	((atom (car l)) (punctb (cdr l) (append (list(car l)) v)))
	(t (append v (list (punctb (car l) nil)) (punctb (cdr l)nil)))
  )
)

(defun invmap(l)
(cond
	((atom l) (list l))
	(t(list(apply 'append (mapcar 'invers (reverse l)))))
))


(defun inspoz(e k l)
(cond
	((= k 1) (cons e l))
	(t (cons(car l) (inspoz e (- k 1) (cdr l))))
)
)

(defun inserare(e k l)
(cond
	((= k 0) nil)
	(t(cons (inspoz e k l) (inserare e (- k 1) l)))
)
)
(defun instoatepoz(e l)
(inserare e (+ (length l) 1) l)

)
;insereaza elem e pe toate poz in elem (listele) din l
(defun add(e l)
   (cond
     ((null l) nil) ;nu fac nimic daca lista e vida
     (t (append (instoatepoz e (car l)) (add e (cdr l))))
    ;inserez pe toate poz in primul element
    ;recursiv, la fel, pt restul listei
    ;concatenez rezultatele
   )
)
(defun permutari(l)
  (cond
     ;daca lista are un singur elem
    ((null (cdr l)) (list (list (car l))))
    ;altfel adaug primul elem in toate permut restului listei
    (t (add (car l) (permutari (cdr l))))
  )
)
