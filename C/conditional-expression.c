/***********************************************
 * This loop prints n elements of an array,    *
 * 10 per line, which each column separated    *
 * by one blank, and with each line (includ    *
 * ing the last) terminated by a newline.      *
 ***********************************************/
for (int i = 0; i < n; i++)
    printf("%6d%c", a[i], (i%10 == 9 || i==n-1) ? '\n' : ' ');
