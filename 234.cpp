// 234. Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        vector<int> vec;
        while (head) {
            vec.emplace_back(head->val);
            head = head->next;
        }
        int len = vec.size();
        for (int i=0; i<len/2; i++) {
            if (vec[i] != vec[len-i-1])
                return false;
        }
        return true;
    }
};