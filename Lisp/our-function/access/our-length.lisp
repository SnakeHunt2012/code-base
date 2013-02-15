;; To see if a recursive function does what it's supposed to, all you have to ask is,
;; does it cover all the cases? We can assure ourselves that this function is correct
;; by verifying two things:
;; 
;; 1. That it works for lists of length 0.
;;
;; 2. Given that it works for lists of length n,
;;    that it also works for lists of length n+1.
;; 
;; If we can establish both points, then we know that the function is correct for
;; all possible lists.
;;
;; Our definition obviously satisfies the first point: if 1st is nil , the function
;; immediately returns 0. Now suppose that the function works for lists of length
;; n. We give it a list of length n-f-1. The definition says that the function will
;; return the len of the cdr of this list, plus 1. The cdr is a list of length n. We
;; know by our assumption that its l e n is n. Thus the l e n of the whole list is
;; n+1.
;;
;; This is all we need to know. The secret to understanding recursion is
;; a lot like the secret for dealing with parentheses. How do you see which
;; parenthesis matches which? You don't have to. How do you visualize all
;; those invocations? You don't have to.
;;
;; With more complicated recursive functions, there might be more cases,
;; but the procedure is the same.

(defun out-length (lst)
  (if (null lst)
      0
      (+ (len (cdr lst)) 1)))
