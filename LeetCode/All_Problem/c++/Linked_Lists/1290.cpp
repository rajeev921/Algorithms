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
    int getDecimalValue(ListNode* head) {
        int res{};
        if(head==nullptr)
            return res;
        
        while(head!=nullptr) {
            res*=2;
            cout << res << "  ";
            if(head->val==1) 
                res++;
            head=head->next;
        }
        return res;
    }
};