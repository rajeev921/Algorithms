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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2== nullptr) {
            return nullptr;
        }
        else if(l2== nullptr) {
            return l1;
        }
        else if(l1== nullptr){
            return l2;
        }
        
        ListNode* t = new ListNode(0);
        ListNode* temp = t;
        
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                t->next = l1;
                l1=l1->next;
            }
            else{
                t->next = l2;
                l2=l2->next;
            }
            t = t->next;
        }
        while(l1 != nullptr){
            t->next = l1;
            t = t->next;
            l1=l1->next;
        }
        
        while(l2 != nullptr){
            t->next = l2;
            t = t->next;
            l2=l2->next;
        }
        
        return temp->next;
    }
};

// Solution -2 Recursion 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
		if(l2 == nullptr) return l1;
		if(l1->val < l2->val){
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		} else{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
    }     
};