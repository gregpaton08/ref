// Greg Paton
// 6 January 2013
// convert integer to
// Roman numeral

// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// arrays to hold roman numerals and sizes
const char *huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
const char *tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
const char *ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
const int   size[] = { 0,   1,    2,     3,    2,   1,    2,     3,      4,    2};

// converts intger to roman numeral
void int_to_roman(int val, char *res) {
    
    while (val >= 1000) {
        sprintf(res, "M");
        *res++;
        val -= 1000;
    }
    
    strcpy(res, huns[val/100]);
    res += size[val/100];
    val = val % 100;
    strcpy(res, tens[val/10]);
    res += size[val/10];
    val = val % 10;
    strcpy(res, ones[val]);
    res += size[val];
    *res = 0;
}

int main(int argc, char **argv) {
    int val;
    char res[128];
    
    if (argc == 2)
        val = atoi(argv[1]);
    else {
        printf("usage: %s number_to_convert\n", argv[0]);
        return 0;
    }
    
    int_to_roman(val, res);
    
    printf("%s\n", res);
}