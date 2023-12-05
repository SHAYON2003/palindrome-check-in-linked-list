#include <iostream>
using namespace std;

class Node{
   public: 
    int data;
    Node* next;

     Node(int data){
       this->data = data;
       this->next = NULL;
     } 
};

 Node* reverse(Node* &head){
     Node*prev = NULL;
     Node* curr = head;
    Node* temp = curr->next;
     
      while(curr != NULL){
        temp = curr -> next;
          curr->next = prev;
          prev = curr;
          curr = temp;
      }
    return prev;
 }
 bool checkforpalindrome(Node* &head){
      if(head == NULL){
        cout<<"Linked list is empty"<<endl;
            return true;
      }
    if(head->next == NULL){
        cout<<" linked is palindrome"<<endl;
        return true;
    }
    // step 1 finding the middle node
  Node* fast = head ->next;
  Node* slow = head;
   while(fast != NULL){ 
     fast = fast->next;
        if(fast != NULL){
           fast = fast->next;
          slow = slow -> next;
        }
   }
  // slow pointer pointing on the middle node
  // step 2: REVERSE linked list after middle node;
     Node* reversellkahead = reverse(slow->next);
   
    //step 3: slow ka aage reverse linkedlist ka head laga do
      slow->next = reversellkahead;
 
   //step 4: compare kro 

  Node* temp1 = head;
  Node* temp2 = reversellkahead;

  if(temp2 != NULL){
      if(temp1 -> data != temp2 -> data){
         return false;
      }
    
    else{
       // if daata is equal aage badho
       temp1 = temp1 -> next;
       temp2 = temp2 -> next;
       
    }
  }
 
     return true;
 }


int main(){
   Node* head = new Node(10);
   Node* second = new Node(20);
   Node* third = new Node(30);
   Node* fourth = new Node(20);
   Node* fifth = new Node(101);
  
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = NULL;
   bool isPalindrome = checkforpalindrome(head);
  
   if(isPalindrome){
     cout<<"linked list is palindrome"<<endl;
   }
  else{
     cout<<"linked list is not a palindrome"<<endl;
  }
}