#include <stdio.h>
#include <stdlib.h>

int euclid(int m, int n)
{
	int rem = m % n;
	if (0 == rem) {
		return n;
	}
	else {
		return euclid(n, rem);
	}	
}

int main(int argc, char **argv)
{
	if (3 != argc) {
		printf("Usage: %s <positive int> <positive int>\n", argv[0]);
		return -1;
	}

	int m = atoi(argv[1]);
	int n = atoi(argv[2]);

	int res = euclid(m, n);

	printf("%d\n", res);

    return 0;
}
