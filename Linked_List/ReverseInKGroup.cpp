// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

class Solution {
public:

    ListNode* reverseLL(ListNode* temp){
   
    ListNode* current =temp;
    ListNode* prev=NULL;
    

    while(current){

        ListNode* front=current->next;
    
        current->next=prev;
        prev=current;
        current=front;

    }

    return prev;

}

ListNode* getKthNode(ListNode* temp, int k){

    k=k-1;

    while(temp  && k>0){

        temp=temp->next;
        k--;
    }

    return temp;
}


    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* temp=head;
    ListNode* prevSLL=NULL;

    while(temp){

        ListNode* KthNode=getKthNode(temp,k);

        if(KthNode==NULL){
          
          if(prevSLL) prevSLL->next=temp;
          break;

        }

        ListNode* nextNode=KthNode->next;
        KthNode->next=NULL;
        reverseLL(temp);

        //First sub group of LL hoga toh head update karna hoga
        if(temp==head){
           head=KthNode;
        }

        else{
            prevSLL->next=KthNode; 
        }

        prevSLL=temp;
        temp=nextNode;
    }

    return head;
    }
};