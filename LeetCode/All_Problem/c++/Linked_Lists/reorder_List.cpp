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
    ListNode* reverse(ListNode* head){
        ListNode* prev(nullptr);
        ListNode* cur(nullptr);
        
        while(head != nullptr){
            prev = cur;
            cur = head;
            head = head->next;
            cur->next = prev;
        }
        return cur;
    }
    ListNode* midNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!= nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    inline ListNode* createNode(int val) {
		ListNode* t = new ListNode(val);
		return t;
	}
    ListNode* addNode(ListNode* l1, ListNode* l2){
        ListNode* cur = createNode(0);
        ListNode* temp = cur;
        int carry{};
        
        while(l1 != nullptr && l2 != nullptr) {
            temp->next = createNode(l1->val); 
            temp = temp->next;
            l1 = l1->next;
            temp->next = createNode(l2->val);
            temp = temp->next;
            l2 = l2->next;
        }
        
        while(l1 != nullptr) {
            temp->next = createNode(l1->val);
            l1 = l1->next;
            temp = temp->next;
        }
        
        while(l2 != nullptr) {
            temp->next = createNode(l2->val);
            l2 = l2->next;
            temp = temp->next;
        }
        temp = cur->next;
        while(temp != nullptr) {
            cout << temp->val << endl;
            temp = temp->next;
        }
        
        return cur->next;    
    }
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next == nullptr || head->next->next == nullptr){
            return;
        }
        ListNode* mid = midNode(head);
        ListNode* revNode = reverse(mid->next);
        mid->next = nullptr;
        head = addNode(head, revNode);
        return;
    }
};