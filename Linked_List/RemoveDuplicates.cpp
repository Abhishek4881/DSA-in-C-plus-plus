// Remove duplicates from a sorted doubly linked list
// Difficulty: EasyAccuracy: 50.36%Submissions: 18K+Points: 2
// Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

Node * removeDuplicates(struct Node *head)
    {
        // Your code here
        Node* temp=head;
        
        while(temp){
            
            
            if( (temp->next!=NULL) && (temp->data==temp->next->data)){
                
                if(temp==head){
                    head=head->next;
                }
                Node* front=temp->next;
                Node* prev=temp->prev;
                if(front) front->prev=prev;
                if(prev)  prev->next=front;
                temp->next=nullptr;
                temp->prev=nullptr;
                delete temp;
                temp=front;
                
            }
            
            else {
                temp=temp->next;
            }
            
            
        }
        
        return head;
    }