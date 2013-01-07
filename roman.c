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

int main(int argc, char **argv) {
    int val;
    while (val >= 1000) {
        printf("M");
        val -= 1000;
    }
    while (val >= 500) {
        printf("D");
        val -= 500;
    }
    while (val >= 100) {
        printf("C");
        val -= 100;
    }
    while (val >= 50) {
        printf("L");
        val -= 50;
    }
    while (val >= 10) {
        printf("X");
        val -=10;
    }
    while (val >= 5) {
        printf("V");
        val -= 5;
    }
}