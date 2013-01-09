// Greg Paton
// 8 Jan 2013
// Function to recursively
// reverse a string


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(char *str, int len) {
    char c;
    char *ret = (char *)malloc(sizeof(char) * len);
    if (len == 0)
        return str;
    else {
        c = str[0];
        ++str;
        sprintf(ret, "%s%c", reverse(str, len-1), c);
        return ret;
    }
        
}

int main (int argc, char **argv) {
    int len = 0;
    char *ret;
    
    if (argc == 2) {
        len = strlen(argv[1]);
        ret = reverse(argv[1], len);
    }
    else
        ret = reverse("HELLO", 5);
    
    
    printf("%s\n", ret);
    
    return 0;
}