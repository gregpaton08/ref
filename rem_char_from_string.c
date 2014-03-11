#include <stdio.h>


void removeChar(char *str, int len, char c) {
	int i = 0;
	int j = 0;
	for ( ; i < len; ++i) {
		while (c == str[i]) {
			++i;
		}
		str[j++] = str[i];
	}
	str[j] = 0;
}


int main(int argc, char **argv) {

	if (3 != argc) {
		printf("Usage: %s <string> <char>\n", argv[0]);
		return -1;
	}

	char *str = argv[1];
	char c  = argv[2][0];
	
	// Get length of input string
	int len = 0;
	while (0 != str[len]) {
		++len;
	}

	printf("%s %s %c\n", argv[0], str, c); 

	removeChar(str, len, c);

	printf("%s\n", str);
}
