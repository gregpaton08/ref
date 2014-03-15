#include <stdio.h>
#include <stdlib.h>

void swap(char *str, int a, int b) {
	char c = str[a];
	str[a] = str[b];
	str[b] = c;
}

void stringPermutations(char *str, int start, int len) {
	if (0 == str || 0 == len) {
		return;
	}

	if (start == len - 1) {
		printf("%s\n", str);
	}
	else {
		int j;
		for (j = start; j < len; ++j) {
			swap(str, start, j);
			stringPermutations(str, start + 1, len);
			swap(str, start, j);
		}
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

	stringPermutations(str, 0, len);

	return 0;
}
