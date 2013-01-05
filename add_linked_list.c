// Greg Paton
// 5 Jan 2013
// add_linked_list.c
// example program to add two
// singly-linked lists that
// represent integer numbers

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

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

int power_10(int n) {
    int ret = 1;
    int i;
   
    for (i = 0; i < n; ++i)
        ret *= 10;
    return ret;
}

struct node *create_list_from_int(int val) {
    struct node *temp;
    int len = 1;
    int i = 1;
    
    // find length of list to hold val
    while (val - power_10(i) > 0) {
        ++len;
        ++i;
    }
    
    for (i = 1; i <= len; ++i) {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->value = val / power_10(len - i);
        //val -= temp->value;
        temp->next = 0;
    }
    
    return temp;    
}

int add_linked_list(struct node *list1, struct node *list2) {
    int len1 = 1;
    int len2 = 1;
    int val1 = 0;
    int val2 = 0;
    int i;
    struct node *temp;

    // check if arguments are valid
    if (list1 == 0 || list2 == 0)
        return 0;

    // find lengths of lists
    temp = list1;
    while(temp->next != 0) {
        ++len1;
        temp = temp->next;
    }
    temp = list2;
    while(temp->next != 0) {
        ++len2;
        temp = temp->next;
    }

    // find value of first list
    temp = list1;
    for (i = len1 - 1; i >= 0; --i) {
        val1 += temp->value * power_10(i);
        temp = temp->next;
    }
    // find value of second list
    temp = list2;
    for (i = len2 - 1; i >= 0; --i) {
        val2 += temp->value * power_10(i);
        temp = temp->next;
    }
    
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
