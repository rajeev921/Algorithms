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
    inline ListNode* createNode(int val) {
		ListNode* t = new ListNode(val);
		return t;
	}
    
    void addNodeToList(ListNode* l1, ListNode* temp) {
        while(l1 != nullptr) {
            temp->next = createNode(l1->val);            	
            l1 = l1->next;
            temp = temp->next;
        }

    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
        	return nullptr;

        else if(l1 == nullptr)
        	return l2;

		else if(l2 == nullptr)
        	return l1;        	
        
        ListNode* cur = createNode(0);
        ListNode* temp = cur;
        int carry{};
      
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val){
                temp->next = createNode(l1->val);    
                if(l1 != nullptr) l1 = l1->next;
            }
            else {
                temp->next = createNode(l2->val);
                if(l2 != nullptr) l2 = l2->next;
            }        	
            temp = temp->next;
        }
        
        addNodeToList(l1, temp);
        addNodeToList(l2, temp);
        
        return cur->next;
    }
};
