// Sort a linked list of 0s, 1s and 2s
// Difficulty: EasyAccuracy: 60.75%Submissions: 176K+Points: 2
// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.


class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        unordered_map<int,int>mp;
        
        Node* temp=head;
        
        while(temp){
            
            mp[temp->data]++;
            temp=temp->next;
        }
        
        temp=head;
        
        for(int i=0 ;i<=2; i++){
            
            while( (temp!=NULL) && (mp[i]--) ){
                temp->data=i;
                temp=temp->next;
            }
        }
        
        return head;
        
    }
};