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
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        if(lists.empty())
            return nullptr;
        
        auto cmp = [&](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        
        for(auto list : lists) {
            while(list != nullptr) {
                pq.push(list);
                list = list->next;
            }
        }
        
        ListNode* res = new ListNode(0);
        ListNode* temp;
        temp = res;
        while(!pq.empty()){
            res->next = pq.top();
            res = res->next;
            pq.pop();
        }
        
        res->next = nullptr;
        return temp->next;
    }
};