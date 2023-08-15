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
    ListNode* partition(ListNode* head, int x) {
       ListNode * temp = head;
        ListNode * smallhead = new ListNode();
        ListNode* smalldummy = smallhead;
        ListNode * bighead = new ListNode();
         ListNode* bigdummy = bighead;
        while(temp != NULL){
            if(temp -> val < x){
                smallhead -> next = temp;
                smallhead = smallhead-> next;
            }
            else{
                bighead -> next = temp;
                bighead = bighead -> next;
            }
            temp = temp -> next;
        }
        bighead -> next = NULL;
        smallhead -> next = bigdummy -> next;
        return smalldummy -> next;
        
        
        
    }
};