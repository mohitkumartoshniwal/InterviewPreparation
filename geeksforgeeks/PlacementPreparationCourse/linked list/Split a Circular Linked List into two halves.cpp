// Given a Cirular Linked List split it into two halves circular lists. If there are odd number of nodes in the given circular linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant lists should also be circular lists and not linear lists.

// Input:
// You have to complete the method which takes 3 argument: The address of the head of the linked list , addresses of the head of the first and second halved resultant lists.. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

// Output:
// Set the *head1_ref and *head2_ref to first resultant list and second resultant list respectively.

// Constraints:
// 1<=T<=100
// 2<=N<=100

// Example:
// Input:
// 2
// 3
// 1 5 7
// 4
// 2 6 1 5

// Output:
// 1 5
// 7
// 2 6
// 1 5

// Explanation:
// Testcase 2: Distributing the given circular linked list into two halves makes two linked list as 2, 6 and 1, 5.

// { Driver Code Starts
/* Program to split a circular linked list into two halves */
#include <stdio.h>
#include <stdlib.h>

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

void splitList(struct Node *head, struct Node **head1_ref, struct Node **head2_ref);
struct Node *newNode(int key)
{
    struct Node *temp = new Node(key);

    return temp;
}
/* Function to split a list (starting with head) into two lists.
   head1_ref and head2_ref are references to head Nodes of 
    the two resultant linked lists */

void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

/* Driver program to test above functions */
int main()
{

    int t, n, i, x;
    scanf("%d", &t);
    while (t--)
    {
        struct Node *temp, *head = NULL;
        struct Node *head1 = NULL;
        struct Node *head2 = NULL;
        scanf("%d", &n);
        scanf("%d", &x);
        head = new Node(x);
        temp = head;
        for (i = 0; i < n - 1; i++)
        {
            scanf("%d", &x);

            temp->next = new Node(x);

            temp = temp->next;
        }

        temp->next = head;

        splitList(head, &head1, &head2);

        // printf("\nFirst Circular Linked List");
        printList(head1);

        // printf("\nSecond Circular Linked List");
        printList(head2);
    }
    return 0;
}
// } Driver Code Ends

/* The structure of linked list is the following
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

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // // your code goes here
    // int size=0;
    // Node * curr=head;
    // do{
    //     size++;
    //     curr=curr->next;
    // }while(curr!=head);

    // int count=0;
    // curr=head;
    // *head1_ref=curr;
    // while(count <= (size/2)){
    //     curr=curr->next;
    //     count++;
    // }
    // *head2_ref=curr->next;
    // curr->next=head1_ref;
    // while(count < size){
    //     curr=curr->next;
    //     count++;
    // }
    // curr->next=head2_ref;

    if (!head)
        return;

    Node *slow_ptr = head;
    Node *fast_ptr = head;

    /* If there are odd nodes in the circular list then  
       fast_ptr->next becomes head and for even nodes  
       fast_ptr->next->next becomes head */
    while (fast_ptr->next != head && fast_ptr->next->next != head)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    /* If there are even elements in list 
       then move fast_ptr */
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    *head1_ref = head;
    *head2_ref = slow_ptr->next;
    fast_ptr->next = slow_ptr->next;

    slow_ptr->next = head;
}