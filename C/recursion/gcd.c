#include <stdio.h>

int gcd(int m, int n)
{
    if (n == 0) return m;
    return gcd(n, m % n);
}

main(int argc, char *argv[])
{
    int M = atoi(argv[1]), N = atoi(argv[2]);
    printf("gcd(%d, %d) = %d", M, N, gcd(M, N));
    return 0;
}
