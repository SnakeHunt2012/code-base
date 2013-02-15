(defun our-subst (new old tree)
  (if (eql tree old)
      new
      (if (atom tree)
	  tree
	  (cons (our-subst new old (car tree))
		(our-subst new old (cdr tree))))))