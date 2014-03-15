#include <stdio.h>
#include <stdlib.h>

int euclid(int m, int n)
{
	if (n > m) {
		int temp = m;
		m = n;
		n = temp;
	}

	int rem;
	while (0 != (rem = m %n)) {
		m = n;
		n = rem;
	}

	return n;
}

int main(int argc, char **argv)
{
	if (3 != argc) {
		printf("Usage: %s <positive int> <positive int>\n", argv[0]);
		return -1;
	}

	int m = atoi(argv[1]);
	int n = atoi(argv[2]);

	int ret = euclid(m, n);

	printf("%d\n", ret);

    return 0;
}
