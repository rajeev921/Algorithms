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
    ListNode* reverse(ListNode* head) {
        ListNode *cur{head}, *prev{0}, *next{0};
        
        while(cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==nullptr) {
            return true;
        }
        
        ListNode *slow{head}, *fast{head};
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast= fast->next->next;
        }
        fast = head;
        slow = reverse(slow);
        
        while(slow != nullptr) {
            if(slow->val != fast->val) {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
    }
};