// Given the head of a singly linked list, return the middle node of the linked list.

// If there are two middle nodes, return the second middle node.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int LengthLL(ListNode* head){

        int count=0;

        ListNode* temp=head;

        while(temp)
{
         count++;
         temp=temp->next;
}

       return count;
    }
    ListNode* middleNode(ListNode* head) {


        int length=LengthLL(head);

        int c=1;

        ListNode* mid=head;

        while(mid!=nullptr && c!=(length/2)+1 ){
            
            mid=mid->next;
            c++;

        }

        return mid;


        
    }
};
