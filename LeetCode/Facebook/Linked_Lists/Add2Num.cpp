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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
        	return nullptr;

        else if(l1 == nullptr)
        	return l2;

		else if(l2 == nullptr)
        	return l1;        	
        
        ListNode* cur = createNode(0);
        ListNode* temp = cur;
        int carry{};
      
        while(l1 != nullptr || l2 != nullptr) {
  			int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            int res = carry + x + y;
        	carry = res/10;
        	temp->next = createNode(res % 10);
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            temp = temp->next;
        }
        cout << "Before if " << endl;
        if(carry != 0) {
            temp->next = createNode(carry);
        }
    
        return cur->next;
    }
};
