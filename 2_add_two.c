/*
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *next;
    int val;
} node;

void slist_insert_head(node **s, int v)
{
    node *n = (node*)malloc(sizeof(*n));
    n->val = v;

    n->next = *s;
    *s = n;
}

void slist_print(node *head)
{
    node *n;
    for (n=head; n; n=n->next) {
        printf("%d", n->val);
        if (n->next)
            printf(" -> ");
    }
    printf("\n");
}

node * slist_add(node *s1, node *s2)
{
    node *n1 = s1, *n2 = s2;
    node *prev = NULL; 
    int carry = 0;
    while (1) {
        int sum;
        node *n;
        if (n1 && n2) {
            sum = n1->val + n2->val + carry;
            n = n1;
            prev = n1;
            n1 = n1->next;
            n2 = n2->next;
        } else if (n1) {
            sum = n1->val + carry;
            n = n1;
            prev = n1;
            n1 = n1->next;
        } else if (n2) {
            n = (node*)malloc(sizeof(*n));
            n->next = NULL;
            sum = n2->val + carry;
            prev->next = n;
            n2 = n2->next;
            prev = n;
        } else {
            sum = carry;
            if (carry) {
                n = (node*)malloc(sizeof(*n));
                n->next = NULL;
                n->val = sum;
                prev->next = n;
            }
            break;
        }
        
        if (sum >= 10) {
            n->val = sum-10;
            carry = 1;
        } else {
            n->val = sum;
            carry = 0;
        }
    }
    return s1;
}

int main()
{
    node *s1 = NULL, *s2 = NULL;

    slist_insert_head(&s1, 3);
    slist_insert_head(&s1, 4);
    slist_insert_head(&s1, 2);

    slist_insert_head(&s2, 4);
    slist_insert_head(&s2, 6);
    slist_insert_head(&s2, 5);

    node *s3 = slist_add(s1, s2);
    slist_print(s3);

    return 0;
}
