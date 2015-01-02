/************************************************
 * This fragment process only the non-negative  *
 * elements in the array a; negative values are *
 * skipped.                                     *
 ************************************************/
for (i = 0; i < n; i++) {
    if (a[i] <0)    /* skip negative elements */
	continue;
    ... /* do positive elements */
}
