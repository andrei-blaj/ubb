(defun f(l1 l2)
(cdr l2)

)

(defun ins(e l)
( cond
	((null l) nil)
  (t (cons (cons e (car l)) (ins e (cdr l))))
)
)
(defun subm(l)
(cond
	((null l) ( list nil))
	(t (append (subm(cdr l)) (ins (car l) (subm(cdr l)))))
	)
	
)
(defun invers(l)
(cond
	((null l) nil)
	(t (append (invers (cdr l)) (list(car l))))
)
)

(defun col(l c)
(cond
((null l) c)
(t (col (cdr l) (cons (car l) c)))
)
)
(defun inve(l)
 (col l nil)
)

(defun numeric(l)
(cond
((null l) nil)
((numberp (car l)) (cons (car l) (numeric (cdr l))) )
((atom (car l)) (numeric(cdr l)))
(t (append (numeric (car l))(numeric(cdr l))))
)
)

(defun atomi(l)
(cond
((null l ) nil)
((atom  (car l)) (cons (car l) (atomi(cdr l))) )
(t (append (atomi (car l)) (atomi (cdr l))))
)
)

(defun invatom(l)
(cond
((null l ) nil)
((atom (car l)) ( cons (invatom (cdr l)) (car l)))
(t ( append (car l) (invatom(cdr l))))

)
)

(defun inversare(lista)
	(punctb lista nil)
)
(defun punctb(l v)
  (cond
	((null l)v)
	((atom (car l)) (punctb (cdr l) (cons (car l) v)))
	(t (append v (list (punctb (car l) nil)) (punctb (cdr l)nil)))
  )
)

(defun maxim(l)
  ( cond
     ( (null l) -3200)
     ( (numberp (car l)) (max (car l) (maxim(cdr l))))
     ( T  (maxim(cdr l))) 
  )
)

(defun rez (lr le)
(cond
((> (length lr)(length le)) (sumav le lr))
(t (sumav lr le))
))


(defun sumav (l1 l2)
(cond
	((and (null l1) (null l2)) nil)
	((and (numberp (car l1))(numberp (car l2 ))) (append (list (+ (car l1) (car l2))) (sumav (cdr l1) (cdr l2))) )
	(t (append (list (car l2))(sumav () (cdr l2))))

)

)

(setf l1 '(7 3 5 ))
(setf l2 '(1 2 3 9 ))



(defun intro(e l)
(cond 
	((null l) nil)
	(t (append (list(list e (car l))) (intro e (cdr l))))

)
)

(defun perechi(l)
(cond
	((null l) nil)
	(t (append (intro (car l) (cdr l)) (perechi (cdr l))))
)
)


(defun polon(l)
(SETF l2 NIL)
(cond 
  ((and (numberp (cadr l)) (numberp (caddr l))) 
     (append (cond 
           ((EQUAL (car l) '* ) (append l2 (list (* (cadr l) (caddr l)) )))
           ((EQUAL (car l) '+ ) (append l2 (list (+ (cadr l) (caddr l)) )))
           (T (append l2 (list (- (cadr l) (caddr l)) )))
              ) (cdr (cdr (cdr l)))))
  (T (append (append l2 (list (car l))) (polon (cdr l))))
)
)
(defun polo(l)
(cond
     ((numberp (car l)) (car l))
     (T ( polo (polon l)))
)
)
 
(defun produs (l)
(cond
((null l) 1)
((numberp (car l)) (* (car l) (produs(cdr l))) )
(t (produs (cdr l)))

)
)









(defun inversam(l)
(cond
	((null l ) nil)
	(t (append (inversam (cdr l)) (list(car l))))
))

(defun succ(l k)
(cond
	((and (null l) (equal k 1)) (list 1))
	((and (null l) (equal k 0)) nil)
	((and (equal (car l) 9) (equal k 1)) (append (list 0) (succ (cdr l) 1 )))
	(t (append (list (+ k (car l))) (succ (cdr l) 0)))
	)
	)
	
	
(defun succesor(l)
	 (inversam (succ(inversam l) 1))
)	

(defun dp(l)
(cond

		(( = (cadr l) 0) nil)
		(t (append (list(list (car l))) (dp (list (car l) (- (cadr l) 1) ))))
))



(defun  dup(l)
(cond
	((null l) nil)
	(t (append (dp (car l)) (dup(cdr l))) )
)
)



(defun apartine(l e)
(cond
	((null l) nil)
	((and (equal (car l) e) (atom (car l))) t)
	((atom (car l)) (apartine (cdr l) e))
	(t (or (apartine (car l) e) (apartine (cdr l) e)))
)
)

(defun atomic(l f)
(cond
	((null l) f)
	((and (atom (car l)) (apartine f (car l))) (atomic (cdr l) f ))
	((atom (car l)) (atomic (cdr l) (append (list(car l)) f)) )
	(t (and (atomic (car l) f) (atomic (cdr l) f) ))
)
)

(defun atomi(l)
(atomic l nil)
)




(defun apart(e l)
(cond
	((null l) nil)
	((equal (car l) e) t)
	(t (apart e (cdr l)))
)
)
(defun multime(l)
(cond
	((null l) t)
	((apart (car l) (cdr l)) nil)
	(t (multime (cdr l)))
)
)



(defun elimin(l n)
(cond
	((= n 1) (cdr l))
	(t (append (list (car l)) (elimin (cdr l) (- n 1))))
)
)



(defun maximi (l)
(cond
	((null l) -32000)
	((numberp (car l)) (max (car l) (maximi (cdr l))))
	((atom (car l)) (maximi (cdr l)))
	(t (or(maximi (car l)) (maximi (cdr l))))

))



(defun numara(l k)
(cond 
	((and (equal 0 (mod k 2)) (null l)) t)
	((null l) nil)
	(t (numara (cdr l) (+ k 1)))
)
)
(defun nump(l)
(numara l 0)
)

(defun numa(l)
	(cond
		((null l) t)
		((equal (cadr l) nil) nil)
		(t (numa (cdr (cdr l))))

)
)



(defun vmax(lr le)
(cond 
	((>(length lr) (length le)) (prodv le lr))
	(t (prodv le lr))
)
)

(defun prodv(l1 l2)
(cond
	((and(null l1)(null l2)) nil)
	((and (numberp (car l1)) (numberp (car l2))) (append (list(* (car l1) (car l2))) (prodv (cdr l1) (cdr l2))))
	(t(append (list(car l))(prodv () (cdr l2)) ))
)

)


(defun asociere (l1 l2)
(cond
	((null l1) nil)
	(t( cons (cons (car l1) (car l2)) (asociere (cdr l1) (cdr l2))))
)
)

(defun nrsub (l)
(cond
	((null l) 1)
	((atom (car l)) (+ 0 (nrsub( cdr l))))
	(t (+ (nrsub (car l)) (nrsub (cdr l) )))
))
(defun numar(l)
   (cond
	((null l) 1)
	((atom (car l)) (+ 0 (numar (cdr l))) )
	(t (+ (numar (car l)) (numar (cdr l))) )
   )
)


(defun dubn(l n)
(cond
	((= n 1) (append (list (car l) (car l)) (cdr l) ))
	(t (append (list (car l)) (dubn (cdr l) (- n 1))))
)
)


(defun nratom (l)
(cond
	((null l) 0)
	((atom (car l)) (+ 1 (nratom (cdr l))))
	(t (+ 0 (nratom (cdr l))))
)
)



(defun proda(l)
(cond
	((null l) 1)
	((numberp (car l)) (* (car l) ( proda (cdr l))))
	((atom (car l)) (proda (cdr l)))
	(t (* (proda (cdr l)) (proda (car l))))
)
)

(defun insereaza( e l)
(cond
	((null l) (list e))
	((> (car l) e )(cons e l))
	(t (cons (car l ) (insereaza e (cdr l))))
)
)

(defun sorteaza (l)
(cond
	((null l) nil)
	(t (insereaza (car l) (sorteaza (cdr l))))
	)
)



(defun apar(e l)
(cond
	((null l) nil)
	((= (car l) e) t)
    (t (apar e (cdr l) ))
)
)

(defun reuniune (l1 l2)
(cond
	((null l1) l2)
	((apar(car l1) l2) (reuniune (cdr l1) l2))
	(t (cons (car l1) (reuniune (cdr l1) l2)))
)
)



(defun suma (l)
(cond	((null l) 0)
		((numberp (car l)) (+ (car l) (suma (cdr l))))
		((atom (car l)) (suma (cdr l)))
		(t (+ (suma (car l)) (suma (cdr l))))

		)
	)

(defun sublist(l)
(cond
	((null l) nil)
	((listp (car l)) (append (list(car l)) (sublist (car l))(sublist (cdr l))))
	(t (sublist (cdr l)))
	)
)



(defun selectn(l n)
(cond
	((> n (length l)) nil)
	((= n 1) (car l))
	(t (selectn (cdr l) (- n 1)))
	)
)

(defun apa (e l)
(cond
	((null l) nil)
	((= (car l) e) t)
	(t (apa e (cdr l)))
)
)

(defun transf(l)
(cond
		((null l) nil)
		((apa (car l) (cdr l)) (transf (cdr l)))
			(t (cons (car l) (transf (cdr l))))

)
)



(defun subel(l e a)
(cond
	((null l) nil)
	((equal (car l) e)(append (list a) (cdr l)))
	(t (cons (car l) (subel (cdr l) e a)))
		

)
)



(defun inlocuire(l)
(cond
	((null l) nil)
	((listp (car l)) (append inlocuire (cdr l)))
	()
)

)


(defun interclasare(l1 l2)
(cond
	((and (null l1) (null l2)) nil)
	((equal (car l1) (car l2)) (cons (car l1) (interclasare (cdr l1) (cdr l2))))
	((= (car l1) (max (car l1) (car l2))) (cons (car l1) (interclasare (cdr l1) l2)))
	((= (car l2) (max (car l1) (car l2))) (cons (car l2) (interclasare l1 (cdr l2))))
	((and(null l1) (not (null l2)))(cons (car l2) (interclasare (cdr l2))))
	((and(null l2) (not (null l1)))(cons (car l1) (interclasare (cdr l1))))
	)
)



(defun liniara(l)
(cond
	((null l) t)
	((atom(car l)) (liniara (cdr l)))
	(t nil)
)
)


(defun adancime(l)
(cond
	((null l) 1)
	((atom (car l)) (adancime (cdr l)))
	(t (+ ( adancime (car l)) (adancime (cdr l))))
)
)



(defun inse(e l)
(cond
	((null l) (list e))
	((> (car l) e) (cons e l))
	((= (car l) e) l)
    (t (cons (car l) (inse e (cdr l))))
)
)

(defun sortez(l)
(cond
	((null l) nil)
	(t (inse (car l) (sortez(cdr l))))
)
)


(defun este(e l)
(cond
	((null l ) nil)
	((equal (car l) e) t)
	(t (este e (cdr l)))
	)
	)
(defun intersect(l1 l2)
(cond
	((null l1) nil)
	((este (car l1) l2) (cons (car l1) (intersect (cdr l1) l2)))
	(t (intersect (cdr l1) l2))
	)
)

(defun bigone(l1 l2)
(cond
	((> (length l1) (length l2)) (prov l2 l1)	)
	(t (prov l1 l2))
)
)

(defun prov(l1 l2)
(cond
	((and (null l1) (null l2)) nil)
	((null l1) (cons (car l2) (prov () (cdr l2))))
	(t (cons (* (car l1) (car l2)) (prov (cdr l1) (cdr l2))))
)
)




(defun invtot(l)
(cond
	((null l) nil)
	((atom (car l)) (append (invtot (cdr l)) (list(car l))))
	(t (append (invtot (cdr l)) (list(invtot (car l))) ))
)
)


(defun startconim(l)
(cond
	((and (atom (car l))(equal( mod (length l) 2) 1)) (append (list(car l)) (conim (cdr l))))
	((equal( mod (length l) 2) 1) (append (list(car(car l))) (conim (cdr l))))
	(t (conim l))
)
)
(defun conim (l)
( cond
	((null l)nil)
	((atom (car l)) (conim (cdr l)))
	((equal 1 (mod (length (car l)) 2)) (append (list(car (car l))) (conim (car l))(conim (cdr l))))
	(t (conim (cdr l)))

)
)




(defun sumaspf(l)
(cond
	((null l) 0)
	((numberp(car l)) (+ (car l) (sumaspf (cdr l))))
	(t (sumaspf (cdr l)))
)
)



(defun in(e l)
(cond
	((null l) nil)
	((equal (car l) e) t)
	(t (in e (cdr l)))
)
)

(defun difmult(l1 l2)
(cond
	((null l1) nil)
	((not (in (car l1) l2)) (append (list(car l1)) (difmult (cdr l1) l2)))
	(t (difmult (cdr l1) l2))
)
)

(defun startdif(l1 l2)
	(append (difmult l1 l2) (difmult l2 l1))
)


(defun suble (l e l1)
(cond
	((null l)nil)
	((equal (car l) e) (append (list l1 )(suble (cdr l) e l1)))
	((atom (car l)) (append (list (car l)) (suble (cdr l) e l1)))
	(t (append (suble (car l) e l1 ) (suble (cdr l) e l1 )))
)
)




(defun cmmdc (a b)
       (cond
            (( equal a b) a)
            (( equal 0 a) b)
            (( equal 0 b) a)
            ((> a b) (cmmdc (- a b) b))
            (t (cmmdc a (- b a)))  
       )
)



(defun formlist (l)
       (cond
            ((null l)nil)
            ((numberp (car l)) (cons (car l) (formlist (cdr l))))
            (t (formlist (cdr l)))
       )
)
(defun cmmdclist (e l)
       (cond
            ((null l) e)
            (t (cmmdclist (cmmdc e (car l)) (cdr l)))                     
       )
)
(defun cmm (l)
  (setq l (formlist l))
  (cmmdclist (car l) (cdr l))
)

(defun munte(l e c)
(cond
	((null l) t)
	((and (< e (car l)) (= c 0)) (munte (cdr l) (car l) 0) )

	((and (> e  (car l)) (= c 0)) (munte (cdr l) (car l) 1) )
	((and (> e  (car l)) (= c 1)) (munte (cdr l) (car l) 1) )
	(t nil)
	

)
)
(defun startmunte(l)
(munte (cdr l) (car l) 0)
)


(defun maximus(l)
(cond
	((null l) -32000)
	((numberp (car l)) (max (car l) (maximus (cdr l))))
	((atom (car l)) (maximus (cdr l)))
	(t (max(maximus (car l)) (maximus (cdr l))))
	)
)

(defun maxsterg(l e)
(cond
	((null l) nil)
	((and (numberp (car l))(equal (car l) e)) (maxsterg (cdr l) e))
	((atom (car l))(append (list(car l )) (maxsterg (cdr l) e) ))
	(t (cons (maxsterg (car l) e) (maxsterg (cdr l) e)))
)
)

(defun startmax(l)
(maxsterg l (maximus l))
)


(defun cmmdiv(a b)
(cond 
	((= a b) a)
	((= a 0) b)
	((= b 0) a)
	((> a b) (cmmdiv (- a b) b))
	(t(cmmdiv a (- b a))))
)


(defun cmul (l e m c)
(cond
	((null l) m)
	((numberp (car l)) (cmul (cdr l) (cmmdiv e(car l)) (/ (* (car l) c) (cmmdiv e (car l)) ) (car l)))
	((atom(car l)) (cmul (cdr l) e m c))
	(t (and (cmul (car l) e m c) (cmul (cdr l) e m c)))
)	
)
(defun cmultstart(l)
(cond
	((= (length l) 1) car l)
	(t (cmul l (car l) 0 (car l)) )
)
)



(defun prop(l)
(cond
	((null l) 1)
	((and (numberp (car l)) (equal (mod (car l) 2) 0)) (* (car l) (prop(cdr l))))
	((numberp (car l)) (* 1 prop (cdr l)))
	((atom (car l)) (* 1 prop (cdr l)))
	(t (* (prop (car l)) (prop (cdr l))))
)
 )
 


(defun latom(l)
(cond
	((null l) nil)
	((atom (car l)) (append (latom(cdr l)) (list (car l))))
	(t (append  (latom(cdr l)) (latom (car l))))
)
)




(defun cmdab(a b)
(cond
	((= a b) a )
	((= a 0) b )
	((= 0 b) a )
	((> a b) (cmdab (- a b) b))
	(t (cmdab a (- b a)))
)
)

(defun cmne(l e)
(cond
	((null l) e)
	( (numberp (car l)) (cmne(cdr l) (cmdab e (car l))))
	((atom (car l)) (cmne (cdr l) e))
	(t (and(cmne (cdr l) e)(cmne (car l) e)))
	
)
)

(defun startcmne(l)
(cmne l (car l))
)



(defun inse(l a k)
(cond
	((null l)nil)
	((equal (mod k 2) 0) (append (list (car l) a) (inse (cdr l) a (+ k 1))))
	(t (append (list (car l)) (inse (cdr l) a (+ k 1))))
	)
)



(defun nrap(l a)
(cond
	((null l) 0)
	((and (atom (car l)) (equal(car l) a))(+ 1 (nrap (cdr l) a)))
	(t(+ (nrap (car l) a) (nrap (cdr l) a)))
)
)

(defun startvale(l)
(vale (cdr l) 0 (car l))
)

(defun vale(l c e)
(cond
	((null l)t)
	((and (> e (car l)) (= c 0)) (vale (cdr l) c (car l)))
	((and (< e (car l)) (= c 0)) (vale (cdr l) 1 (car l)))
	((and (< e (car l)) (= c 1)) (vale (cdr l) 1 (car l)))
	(t nil)

)
)


(defun eln(l n k)
(cond
	((null l)nil)
	((equal 0 (mod k n)) (eln (cdr l) n (+ k 1)))
	(t(append (list (car l)) (eln (cdr l) n (+ k 1))))
)
)



(defun mini(l)
(cond
	((null l) 32000)
	((numberp (car l)) (min (car l) (mini (cdr l))))
	((atom (car l)) (mini (cdr l)))
	(t(min (mini (car l)) (mini (cdr l))))
)
)

(defun adaugn (l n a k)
(cond
	((null l)nil)
	((equal 0 (mod k n) ) (append (list a (car l) ) (adaugn (cdr l) n a (+ k 2))))
	(t (append (list (car l)) (adaugn (cdr l) n a (+ k 1))))
	
	)
)




(defun pozmin (l k)
(cond
	((null l ) nil)
	((and(numberp (car l))(equal(car l ) c)) (append (list k) (pozmin (cdr l) (+ k 1))  ))
	(t (pozmin (cdr l) (+ k 1)))
)
)


(defun inter(l1 l2)
(cond
	((and(null l1)(null l2)) nil)
	((equal (car l1) (car l2)) (append (list (car l1)) (inter (cdr l1) (cdr l2))))
	((and (numberp (car l1)) (numberp (car l2))(< (car l1) (car l2))) (append (list (car l1)) (inter (cdr l1) l2)))
	((and (numberp (car l1)) (numberp (car l2))(> (car l1) (car l2))) (append (list (car l2)) (inter l1 (cdr l2))))
	((and(null l1) (not (null l2))) (append (list (car l2)) (inter () (cdr l2))))
	((and(null l2) (not (null l1))) (append (list (car l1)) (inter (cdr l1) ())))
)
)


(defun imp(l)
(cond
	((null l)0)
	((numberp (car l)) (+ 1  (imp (cdr l))))
	((atom (car l)) (+ 0 (imp (cdr l))))
	(t(+ (imp (car l)) (imp (cdr l))))
))

(defun ni(l)
(cond
	((= 1 (mod (imp l) 2)) t)
	(t nil)
)

)
(defun nri(l)
(cond
	((atom l)0)
	((ni l) 1)
	(t(apply '+ (mapcar 'nri l)))
)
)



