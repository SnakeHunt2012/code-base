/******************************************
 * Determing whether two arrays a and b   *
 * have and elementin common. (with goto) *
 ******************************************/
    for (i = 0; i < n; i++)
	for (j = 0; j < m; j++)
	    if (a[i] == b[j])
		goto found;
    /* didn't find any common element */
    ...
found:
    /* got one: a[i] == b[j] */
    ...

/*********************************************
 * Determing whether two arrays a and b      *
 * have and elementin common. (without goto) *
 *********************************************/
    found = 0;
    for (i = 0; i < n && !found; i++)
	for (j = 0; j < m && !found; j++)
	    if (a[i] == b[j])
		found = 1;
    if (found)
	/* got one: a[i] == b[j] */
	...
    else
	/* didn't find any common element */
	...
