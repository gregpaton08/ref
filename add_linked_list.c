// Greg Paton
// 5 Jan 2013
// add_linked_list.c
// example program to add two
// singly-linked lists that
// represent integer numbers

#include <stdio.h>
#include <stdlib.h>

// linked list node
// value holds single digit of list
// next points to the next noxe (0 if tail)
struct node {
    char value;
    struct node* next;
};

// sequentially prints the values of a linked list
void print_linked_list(struct node *head) {
    struct node *temp = head;
    if (temp == 0)
        return;
    do {
        printf("%d", temp->value);
        temp = temp->next;
    } while(temp != 0);
    printf("\n");
}

// returns 10^n
// returns 1 for negative values of n
int power_10(int n) {
    int ret = 1;
    int i;
   
    for (i = 0; i < n; ++i)
        ret *= 10;
    return ret;
}

// returns a list from input integer val
struct node *create_list_from_int(int val) {
    struct node *temp;
    struct node *ret;
    int len = 1;
    int i = 1;
    
    // find length of list to hold val
    while (val - power_10(i) > 0) {
        ++len;
        ++i;
    }
    
    // create list
    ret = (struct node *)malloc(sizeof(struct node));
    temp = ret;
    
    for (i = 1; i <= len; ++i) {
        temp->value = val / power_10(len - i);
        val -= temp->value * power_10(len - i);
        if (i != len) 
            temp->next = (struct node*)malloc(sizeof(struct node));
        else
            temp->next = 0;
        temp = temp->next;
    }
    
    return ret;
}

// returns the intger vale of input list head
int create_int_from_list(struct node *head) {
    int len = 1;
    int val = 0;
    int i;
    struct node *temp;
    
    // check if arguments are valid
    if (head == 0)
        return 0;
    
    // find length of list
    temp = head;
    while(temp->next != 0) {
        ++len;
        temp = temp->next;
    }
    
    // find value of list
    temp = head;
    for (i = len - 1; i >= 0; --i) {
        val += temp->value * power_10(i);
        temp = temp->next;
    }
    
    // return value
    return val;    
}

// returns the integer value of two linked lists
int add_linked_list(struct node *list1, struct node *list2) {
    
    int val1 = 0;
    int val2 = 0;

    // check if arguments are valid
    if (list1 == 0 || list2 == 0)
        return 0;
    
    // find values of lists
    val1 = create_int_from_list(list1);
    val2 = create_int_from_list(list2);
    
    // return sum
    return val1 + val2;
}

int main(int argc, char **argv) {
    int val;
    struct node *list1;
    struct node *list2;
    struct node *temp;

    // create linked lists
    if (argc != 3) {
        list1 = create_list_from_int(1234); 
        list2 = create_list_from_int(5678);
    }
    else {
        list1 = create_list_from_int(atoi(argv[1]));
        list2 = create_list_from_int(atoi(argv[2]));
    }
    print_linked_list(list1);
    print_linked_list(list2);

    val = add_linked_list(list1, list2);
    printf("%d\n", val);
    temp = create_list_from_int(val);
    print_linked_list(temp);

    return 0;
}
