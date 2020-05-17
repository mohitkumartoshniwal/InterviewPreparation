// Given a linked list of N nodes. The task is to reverse this list.

// Input: Head of following linked list
// 1->2->3->4->NULL
// Output: Linked list should be changed to,
// 4->3->2->1->NULL

// Input: Head of following linked list
// 1->2->3->4->5->NULL
// Output: Linked list should be changed to,
// 5->4->3->2->1->NULL

// Input: NULL
// Output: NULL

// Input: 1->NULL
// Output: 1->NULL

// Input:
// First line of input contains number of testcases T. For each testcase, first line contains length of linked list and next line contains the elements of linked list.

// Output:
// Reverse the linked list and return head of the modified list.

// User Task:
// The task is to complete the function reverseList() which head reference as the only argument and should return new head after reversing the list.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 103

// Example:
// Input:
// 2
// 6
// 1 2 3 4 5 6
// 5
// 2 7 8 9 10
// Output:
// 6 5 4 3 2 1
// 10 9 8 7 2

// Explanation:
// Testcase 1: After reversing the list, elements are as 6->5->4->3->2->1.
// Testcase 2: After reversing the list, elements are as 10->9->8->7->2.

// { Driver Code Starts
//Initial Template for C++

// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
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

/* Function to get the middle of the linked list*/
struct Node *reverseList(struct Node *head);

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T, n, l, firstdata;
    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (int i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        head = reverseList(head);

        printList(head);

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Should reverse list and return new head.
//https://www.geeksforgeeks.org/reverse-a-linked-list/

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *restofthelist = reverseList(head->next);
    head->next->next = head;

    head->next = NULL;
    return restofthelist;

    // Your code here
}
