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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;
        ListNode* odd_ptr = head;
        ListNode* even_ptr = head->next;
        ListNode* mvng_ptr = head->next->next;
        int cntr{1};
        
        while(mvng_ptr != nullptr){
            ListNode* temp = mvng_ptr->next;
            if(cntr%2 != 0) {  // For odd
                mvng_ptr->next = odd_ptr->next;
                odd_ptr->next = mvng_ptr;
                odd_ptr = odd_ptr->next;
                even_ptr->next = temp; 
                
            } else {
                even_ptr = even_ptr->next;
            }
            mvng_ptr = temp;
            ++cntr;
        }
        
        return head;
    }
};