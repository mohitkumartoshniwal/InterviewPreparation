// Given a linked list of size n, you have to delete the node at position pos of the linked list and return the new head. The position of initial node is 1.
// The tail of the circular linked list is connected to the head using next pointer.

// Input Format:
// First line of input contains number of testcases T. For each testcase, first line contains length of linked list n and next line contains n elements to be inserted into the linked list. The third line contains position pos.

// Output Format:
// For each testcase, in a new line, the updated linked list will be printed.

// User Task:
// The task is to complete the function deleteAtPosition() which takes head reference and pos as argument.. The function deletes the node at pos and returns reference to the new head node, which is then used to display the list. The printing is done automatically by the driver code.

// Constraints:
// 1 <= T <= 100
// 2 <= n <= 103
// 1 <= pos <= n

// Example:
// Input:
// 2
// 5
// 1 2 3 4 5
// 4
// 6
// 2 5 7 8 99 100
// 6

// Output:
// 1 2 3 5
// 2 5 7 8 99

// Explanation:
// Testcase 1: The linked list is 1 2 3 4 5. pos is 4. The element at position 4 is 1 2 3 4 5. So we delete 4.
// Testcase 2: The linked list is 2 5 7 8 99 100. The element at position 6 is 2 5 7 8 99 100. So we delete 100.

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}


Node *addNode(Node *head, int data)
{
    if(head==NULL)
    head=newNode(data);
    else
    head->next=addNode(head->next,data);
    
    return head;
}


void displayList(Node *head)
{
    Node *temp=head;
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<" ";
}


 // } Driver Code Ends


//User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};
*/

Node * deleteAtPosition(Node *head,int pos)
{
    Node * current=head;
    Node * temp;
    int n=0;
    //Your code here
    do{
     current=current->next;
     n++;
    }while(current!=head);
    
    current=head;
    
    if(pos==1){
        current=current->next;
        while(current->next!=head){
            current=current->next;
           
        }
        temp=head;
        current->next=head->next;
        head=head->next;
        delete temp;
        return head;
    }
    else if(pos==n){
         current=current->next;
          while(current->next->next!=head){
            current=current->next;
        }
        temp=current->next;
        current->next=head;
        delete temp;
        return head;
        
        
         
    }
    else{
        for(int i=1;i<pos-1;i++){
            current=current->next;
            
        }
        temp=current->next;
        current->next=temp->next;
        delete temp;
        return head;
        
        
    }
}


// { Driver Code Starts.




void makeCircular(Node * head)
{
    Node * temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=head;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        head=addNode(head,x);
	    }
	    
	    int pos;
	    cin>>pos;

	    makeCircular(head);
	    
	  
	    head=deleteAtPosition(head,pos);
	    
	    displayList(head);
 
	    cout<<endl;
	}
	return 0;
}  // } Driver Code Ends