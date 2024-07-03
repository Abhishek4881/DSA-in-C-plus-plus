// Given the head of a linked list, rotate the list to the right by k places.

class Solution {
public:

    ListNode* findNthNode(ListNode* temp,int k){
     k-=1;

     while(temp && k>0){
          temp=temp->next;
          k--;
     }

     return temp;
    }


    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL || k==0)  return head;

     ListNode* tail=head;
     int len=1;

     while(tail->next!=NULL){
          tail=tail->next;
          len++;
     }

     if(k%len==0)  return head;

     k=k%len;

     tail->next=head;
     ListNode* newTail=findNthNode(head,len-k);
     head=newTail->next;
     newTail->next=nullptr;

     return head;
        
    }
};