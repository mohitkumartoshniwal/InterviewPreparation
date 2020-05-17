// Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.

// Input:
// First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains linked list data.

// Output:
// Output the linked list after swapping pairwise nodes.

// User Task:
// The task is to complete the function pairWiseSwap() which takes head node as the only argument and returns the modified head.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 103

// Example:
// Input:
// 1
// 8
// 1 2 2 4 5 6 7 8

// Output:
// 2 1 4 2 6 5 8 7

// Explanation:
// Testcase 1: After swapping each pair considering (1,2), (2, 4), (5, 6).. so on as pairs, we get 2, 1, 4, 2, 6, 5, 8, 7 as new linked list.

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *pairWiseSwap(Node *head);

void insert(Node **head)
{
    int n, i, value;
    Node *temp;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);

        if (i == 0)
        {
            *head = new Node(value);
            temp = *head;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

void printList(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t, k, n, value;

    /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
    scanf("%d", &t);

    Node *head = NULL;

    while (t--)
    {
        head = NULL;
        insert(&head);
        head = pairWiseSwap(head);
        printList(head);
    }
    return (0);
}
// } Driver Code Ends

/*
  Pairwise swap a linked list
  The input list will have at least one element
  node is defined as

struct node
{
    int data;
    struct node* next;

    node(int x){
        data = x;
        next = NULL;
    }

}*head;
*/

Node *pairWiseSwap(struct Node *head)
{
    // Base Case: The list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return head;

    // Store head of list after two nodes
    node *remaing = head->next->next;

    // Change head
    node *newhead = head->next;

    // Change next of second node
    head->next->next = head;

    // Recur for remaining list and change next of head
    head->next = pairWiseSwap(remaing);

    // Return new head of modified list
    return newhead;
}