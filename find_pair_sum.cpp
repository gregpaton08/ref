// Greg Paton
// 1/24/2013
// function to find pairs in an
// array that add up to a given
// integer value

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

bool find_pair_sum(int *array, int n);

int main(int argc, char **argv)
{
    if (argc < 4)
        return -1;
    
    int size = argc - 1;
    int array[size + 1];
    int n = atoi(argv[argc - 1]);
    for (int i = 1; i < size; ++i) 
        array[i-1] = atoi(argv[i]);
    array[size] = INT_MAX;
    
    if (false == find_pair_sum(array, n))
        return -1;
    
    return 0;
}

bool find_pair_sum(int *array, int n)
{
    if (array == 0)
        return false;
    
    int size = 0;
    int temp;
    
    while (array[size] != INT_MAX)
        ++size;
    
    for (int i = 0; i < size; ++i) {
        temp = array[i];
        for (int j = i + 1; j < size; ++j) {
            if (temp + array[j] == n)
                printf("%d+%d=%d\n", temp, array[j], n);
        }
    }
    
    return true;
}