/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    
    
    Node *reverse(Node *head) {
        // code here
        if(head->next==NULL || head==NULL) return head;
        Node* curr=head->next;
        Node* prev=head;
        Node* pp=NULL;
        while(curr!=NULL){
            Node* temp=curr->next;
            prev->next=pp;
            prev->prev=curr;
            pp=prev;
            prev=curr;
            curr=temp;
        }
        prev->next=pp;
        pp->prev=prev;
        return prev;
    }

};