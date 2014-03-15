#include <stdio.h>

void stringPermutations(char *str, int len) {
	if (0 == str || 0 == len) {
		return;
	}

	int i;
	int j;
	for (i = 0; i < len; ++i) {
		printf("%c", str[i]);
		for (j = 0; j < len; ++j) {
			if (i == j)
				continue;
			printf("%c", str[j]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv) {
	
	if (2 != argc) {
		printf("Usage: %s <string>\n", argv[0]);
		return -1;
	}

	char *str = argv[1];
	
	int len = 0;
	while (0 != str[len]) {
		++len;
	}

	stringPermutations(str, len);

	return 0;
}
