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

// Another Simpler Solution 
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* res = new ListNode(0);
        ListNode* odd = res;
        
        ListNode* res2 = new ListNode(0);
        ListNode* even = res2;
        
        int count{1};
        while(head != nullptr){
            if(count%2 != 0) {
                odd->next = head;
                cout <<"odd   " << odd->next->val << endl;
                odd = odd->next;
            } else {
                even->next = head;
                cout <<"even   "<< even->next->val << endl;
                even = even->next;
            }
            head = head->next;
            ++count;
        }
        even->next = nullptr;
        while(res2->next){
            odd->next = res2->next;
            odd = odd->next;
            res2 = res2->next;
        }
        
        even = odd = nullptr;
        
        return res->next;
    }
};
