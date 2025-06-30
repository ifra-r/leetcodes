// 21. Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(0), *temp = dummy;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val){
                dummy->next = new ListNode(list1->val);
                list1 = list1->next;    
            }
            else{
                dummy->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            dummy = dummy->next;
        }
        if (list1 != nullptr)
            dummy->next = list1;
        else
            dummy->next = list2;
        return temp->next;
    }
};

// while both arent null
//     cmp both vals -> smaller one added and moved to its next elemnet

// whichever one still not empty
//     whole of it appended at end -> no cmps needed
