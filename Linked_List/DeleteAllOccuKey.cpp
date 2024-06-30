// Delete all occurrences of a given key in a doubly linked list
// Difficulty: MediumAccuracy: 50.04%Submissions: 16K+Points: 4
// You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL


 void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        
        Node* temp=*head_ref;
        
        while(temp){
            
            if(temp->data==x){
                
                if(temp==*head_ref){
                    (*head_ref)=(*head_ref)->next;
                }
                
                Node* front=temp->next;
                Node* prev=temp->prev;
                
                if(front) front->prev=prev;
                if(prev)  prev->next=front;
                temp->next=nullptr;
                
                free(temp);
                temp=front;
            }
            
            else{
                temp=temp->next;
            }
            
            
        }
    }