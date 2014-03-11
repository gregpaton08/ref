#include <stdio.h>


// If string is a palindrome return 1
// If string is not a palindrome return 0
// else return -1 on error
int palindromeCheck(char *str, int len) {
	if (0 == str) {
		return -1;
	}
	
	int i;
	for (i = 0; i < len / 2; ++i) {
		if (str[i] != str[len - 1 - i]) {
			return 0;
		}	
	}

	return 1;
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
	
	int ret = palindromeCheck(str, len);
	if (0 == ret) {
		printf("%s is not a palindrome.\n", str);
	}
	else if (1 == ret) {
		printf("%s is a palindrome.\n", str);
	}
	else {
		printf("Error reading string.\n");
	}

	return 0;
}
