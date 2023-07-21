//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
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

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
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

class Solution
{
    public:
    node* reverseLL(node* head){
        node *dummy = NULL;
        while(head != NULL){
            node *tmp = head->next;
            head->next = dummy;
            dummy = head;
            head = tmp;
        }
        return dummy;
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        
        if(!head || !head->next || k == 1)
            return head;
        
        node* temp = head;
        int i = 1;
        
        while(temp && i < k){
            ++i;
            temp = temp->next;
        }
        
        if(!temp)   
            return reverseLL(head);
        
        node* newHead = temp->next;
        temp->next = nullptr;
        node* smallHead = reverse(newHead, k);
        head = reverseLL(head);
        
        temp = head;
        while(temp->next){
            temp = temp->next;
        }
        
        temp->next = smallHead;
        return head;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends
