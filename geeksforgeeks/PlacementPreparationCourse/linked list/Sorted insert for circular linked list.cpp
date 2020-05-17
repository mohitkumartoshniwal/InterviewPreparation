// Given a sorted circular linked list, the task is to insert a new node in this circular list so that it remains a sorted circular linked list.

// Input:
// First line of input contains number of testcases T. For each testcase first line of input contains length of the linked list, next line contains the linked list elements and the last line contains the element to be inserted into the linked list.

// Output:
// For each testcase, print the new linked list.

// User Task:
// The task is to complete the function sortedInsert() which should insert the new node into the given circular linked list.

// Constraints:
// 1 <= T <= 100
// 0 <= N <= 200
// Example:
// Input:
// 2
// 3
// 1 2 4
// 2
// 4
// 1 4 7 9
// 5

// Output:
// 1 2 2 4
// 1 4 5 7 9

// Explanation:
// Testcase 2: After inserting 5, the linked list would be 1, 4, 5, 7 and 9.

// { Driver Code Starts
#include <bits/stdc++.h>
/* structure for a Node */
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

Node *sortedInsert(struct Node *head, int x);

/* function to insert a new_Node in a list in sorted way.
   Note that this function expects a pointer to head Node
   as this can modify the head of the input linked list */

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
    struct Node *temp;

    if (start != NULL)
    {
        temp = start;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != start);
        printf("\n");
    }
}
/* Driver program to test above functions */
int main()
{
    int t, n, x;
    scanf("%d", &t);
    int arr;
    while (t--)
    {
        scanf("%d", &n);
        int list_size, i;

        /* start with empty linked list */
        struct Node *start = NULL;
        struct Node *temp, *r;

        /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
        if (n > 0)
        {
            scanf("%d", &arr);

            temp = new Node(arr);
            start = temp;
            r = start;
        }
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &arr);
            temp = new Node(arr);
            r->next = temp;
            r = r->next;
        }

        if (n > 0)
            temp->next = start;

        scanf("%d", &x);
        start = sortedInsert(start, x);
        printList(start);
        r = start;
        while (r != start->next)
        {

            temp = start;
            start = start->next;
            free(temp);
        }
        free(start);
    }
    return 0;
}
// } Driver Code Ends

/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;
  
  Node(int x){
      data = x;
      next = NULL;
  }
  
};
 */

// This function should return head of
// the modified list

//https://www.geeksforgeeks.org/sorted-insert-for-circular-linked-list/

Node *sortedInsert(Node *head, int x)
{
    Node *current = head;
    //Your code here
    if (!current)
    {
        Node *temp = new Node(x);
        temp->next = temp;
        head = temp;
    }
    else if (current->data >= x)
    {
        //find last pointer
        while (current->next != head)
        {
            current = current->next;
        }
        Node *temp = new Node(x);
        temp->next = head;
        current->next = temp;
        head = temp;
    }
    else
    {
        while (current->next != head && current->next->data < x)
        {
            current = current->next;
        }
        Node *temp = new Node(x);
        temp->next = current->next;
        current->next = temp;
    }
    return head;
}