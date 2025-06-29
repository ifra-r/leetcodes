// 206. Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = nullptr;
        while(head != nullptr) {
            ListNode *newNode = new ListNode(head->val);
            newNode->next = dummy;
            dummy = newNode; 
            head = head->next; // keep list moivng           
        }    
        return dummy;    
    }
};