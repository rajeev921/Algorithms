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
/*
    The complexity of this problem is O(knlogk), no algorithm can run it O(nlogk). We have T(n) = 2T(n/2) + kn, 
    and therefore, O(kn*logk).Or you can think about the complexity on each node and expand. For each node, the 
    complexity is O(logk), which is the complexity for adding to the PQ, and there are k*n that many of nodes, 
    which gives us O(knlogk).This is serious, if you get the complexity wrong, that's probably it for the interview.

    Hi, you are absolutely correct if n is the maximum number of nodes in k lists. But I believe people mean n is 
    the TOTAL number of nodes.
*/