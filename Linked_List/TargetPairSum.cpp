// Find pairs with given sum in doubly linked list
// Difficulty: EasyAccuracy: 66.01%Submissions: 36K+Points: 2
// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

 

  Node* findTail(Node* head){
        
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        return tail;
    }
    
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int,int>>ans;
        
        Node* left=head;
        Node* right=findTail(head);
        
        while(left->data < right->data){
            
            if(left->data + right->data==target){
                
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            
            else if(left->data + right->data >target){
                right=right->prev;
            }
            
            else{
                left=left->next;
            }
        }
        return ans;
    }