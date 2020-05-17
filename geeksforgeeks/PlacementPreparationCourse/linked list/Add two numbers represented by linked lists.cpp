// Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list which is a linked list representation of addition of two input numbers.

// Input:
// First line of input contains number of testcases T. For each testcase, first line of input contains length of first linked list and next line contains N elements of the linked list. Again, next line contains M, and following line contains M elements of the linked list.

// Output:
// Output the resultant linked list.

// User Task:
// The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of new list.

// Constraints:
// 1 <= T <= 100
// 1 <= N, M <= 100

// Example:
// Input:
// 2
// 2
// 4 5
// 3
// 3 4 5
// 2
// 6 3
// 1
// 7
// Output:
// 0 9 3
// 0 7

// Explaination:
// Testcase 1: For the given two linked list (4 5) and (3 4 5) ,after adding the two linked list resultant linked list will be (0 9 3).
// Testcase 2: For the given two linked list (6 3) and (7) , after adding the two linked list resultant linked list will be (0 7).

// Note:
// The linked list has been constructed in the reverse order of the number. That is, if the number given is 123 then the linked list representing it is: 3 -> 2 -> 1

// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *addTwoLists(struct Node *first, struct Node *second);

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node *Node)
{
    struct Node *temp;
    while (Node != NULL)
    {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void)
{
    int t, n, m, i, x;
    cin >> t;
    while (t--)
    {
        struct Node *res = NULL;
        struct Node *first = NULL;
        struct Node *second = NULL;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++)
        {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first)
            freeList(first);
        if (second)
            freeList(second);
    }
    return 0;
}
// } Driver Code Ends

/*
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
// write a function returns the resultant linked list
Node *addTwoLists(Node *first, Node *second)
{
    Node *res = NULL; // res is head node of the resultant list
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i) Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first ? first->data : 0) +
              (second ? second->data : 0);

        // update carry for next calulation
        carry = (sum >= 10) ? 1 : 0;

        // update sum if it is greater than 10
        sum = sum % 10;

        // Create a new node with sum as data
        temp = new Node(sum);

        // if this is the first node then
        // set it as head of the resultant list
        if (res == NULL)
            res = temp;

        // If this is not the first
        // node then connect it to the rest.
        else
            prev->next = temp;

        // Set prev for next insertion
        prev = temp;

        // Move first and second pointers to next nodes
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    if (carry > 0)
        temp->next = new Node(carry);

    // return head of the resultant list
    return res;
}