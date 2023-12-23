/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
    ListNode* swapPairsHelper(ListNode* node1, node2) {
        Li
        
    }*/
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
/*
1->2->3->4
2->1->4->3
*/