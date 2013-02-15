(defun our-copy-list (lst)
  (if (atom lst)
      lst
      (cons (car lst)
	    (our-copy-list (cdr lst)))))