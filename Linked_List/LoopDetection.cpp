// Loop/Cycle Detection

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// bool hasCycle(ListNode *head) {

//         ListNode* slow=head;
//         ListNode* fast=head;

//         while(fast!=NULL && fast->next!=NULL){

//             slow=slow->next;
//             fast=fast->next->next;

//             if(slow==fast) return true;
//         } 

//         return false;
        
//     }


// LENGTH OF LOOP.....

// 1.)BRUTE FORCE USING MAP 

// int countNodesinLoop(struct Node *head)
// {
//     // Code here
//       Node* temp = head;  
    
    
//     unordered_map<Node*, int> nodeMap;  
//     int timer=1;

   
//     while (temp != nullptr) {
       
//         if (nodeMap.find(temp) != nodeMap.end()) {
//             int val=nodeMap[temp];
//             return (timer-val);
//         }
       
//         nodeMap[temp] = timer;
//         timer++;
        
       
//         temp = temp->next;  
//     }

    
//     return 0;
// }

//2.) OPTIMAL APPROACH USING FLOYDS CYCLE /TORTOISE & HARE

// int countNodesinLoop(struct Node *head)
// {
//     // Code here
    
//     Node* slow=head;
//     Node* fast=head;
    
    
//     while(fast!=NULL && fast->next!=NULL){
        
//         slow=slow->next;
//         fast=fast->next->next;
        
        
//         if(slow==fast){
            
//             fast=fast->next;
//             int Length=1;
            
//             while(slow!=fast){
//                 Length++;
                
//                 fast=fast->next;
//             }
            
//             return Length;
//         }
//     }
    
//     return 0;
    
// }