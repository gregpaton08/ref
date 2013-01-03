#include <stdio.h>
#include <string.h>

void pascal(int n);

int main(int argc, char **argv)
{
    int n;
    if (argc > 1)
        n = atoi(argv[1]);
    else {
        printf("usage: %s [row]\n", argv[0]);
        return;
    }

    pascal(n);
}

void pascal(int n)
{
    if (n == 0) 
        return;
    
    int pbuf[n];
    int cbuf[n];
    int i, j;
    for (i = 0; i < n; ++i) {
        cbuf[i] = 1;
        pbuf[i] = 1;
    }

    for (i = 2; i < n; ++i) {
        for (j = 1; j < i; ++j) 
            cbuf[j] = pbuf[j-1] + pbuf[j];
        memcpy(pbuf, cbuf, n * sizeof(int));
    }

    for (i = 0; i < n; ++i) 
        printf("%d ", cbuf[i]);
    printf("\n");
}
