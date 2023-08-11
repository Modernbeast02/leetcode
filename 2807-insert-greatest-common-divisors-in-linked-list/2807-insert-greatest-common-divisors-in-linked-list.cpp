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
    int gcd(int a, int b){
        if(b > 0){
            return gcd(b, a % b);
        }
        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp != NULL && temp -> next != NULL){
            int val1 = temp -> val;
            int val2 = temp -> next -> val;
            int gcdd = gcd(val1, val2);
            ListNode* newHead = new ListNode(gcdd);
            newHead -> next = temp -> next;
            temp -> next = newHead;
            temp = newHead -> next;
        }
        return head;
    }
};