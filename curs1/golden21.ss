;golden21
(define a 2)(define b 3)
(define (fun x)
 (set! x (- x (/ 108 109)))
 (-(* 3 x) (* 4 (log(+ x 0))) 5)
)
(define (golden-section-search a b)
 (let(
      (xmin(cond((>= b a)(golden-start a b))(#t (golden-start b a ))))
     )
     (newline)
     xmin
 )
)
(define (golden-start a b)
 (set! total-iterations 0)
 (let(
      (xa (+ a (* mphi(- b a))))
      (xb (+ b (-(* mphi(- b a)))))
     )
     (try a b xa (fun xa) xb (fun xb))
 )
)
(define mphi (* (- 3(sqrt 5))(/ 2.0e0)))
(define (try a b xa ya xb yb)
 (cond((close-enough? a b)
      (* (+ a b)0.5e0))
      (#t (let() (display "+")
             (set! total-iterations (+ total-iterations 1))
             (cond((>= yb ya)(let() (set! b xb)
                         (set! xb xa)
                         (set! yb ya)
                         (set! xa (+ a (* mphi(- b a))))
                         (try a b xa (fun xa) xb yb))
                  )
                  (#t   (let() (set! a xa)
                         (set! xa xb)
                         (set! ya yb)
                         (set! xb (- b (* mphi(- b a))))
                         (try a b xa ya xb (fun xb)))
                   )
             );cond...
      );let...
 ));cond...
)
(define (close-enough? x y)
  (>= tolerance (abs (- x y))))
(define tolerance 0.001e0)
(define total-iterations 0)
(define xmin 0)
(set! xmin(golden-section-search a b))
  (display"Interval=\t[")
  (display a)
  (display" , ")
  (display b)
  (display"]\n")
  (display"Total number of iteranions=")
total-iterations
  (display"xmin=\t\t")
xmin
  (display"f(xmin)=\t")
(fun xmin)