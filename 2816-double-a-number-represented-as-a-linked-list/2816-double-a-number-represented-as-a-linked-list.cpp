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
private:
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead = reverse(head);
        int carry = 0;
        ListNode* temp = newHead;
        ListNode* prev;
        while(temp != NULL){
            int sum = carry;
            sum += 2 * temp -> val;
            temp -> val = sum % 10;
            carry = sum / 10;
            prev = temp;
            temp = temp -> next;
        }
        while(carry){
            int sum = carry;
            prev -> next = new ListNode(sum % 10);
            carry = sum / 10;
            prev = prev -> next;
        }
        return reverse(newHead);
    }
};