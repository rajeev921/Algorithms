/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return head;
        
        Node* head_tmp = head;
        Node* temp = new Node(head->val, NULL, NULL);
        Node* ref = new Node(0, NULL, NULL);
        
        ref->next = temp;
        
        lookup[head->val] = temp;
        head = head->next;
        while(head)
        {
            Node* cur = new Node(head->val, NULL, NULL);
            lookup[cur->val] = cur;
            temp->next = cur;
            
            head = head->next;
            temp = temp->next;
        }
        
        head = head_tmp;
        temp = ref->next;
        while(head)
        {
            if(head->random)
            {
                int val = head->random->val;
                if(lookup.find(val) != lookup.end())
                {
                    temp->random = lookup[val];    
                }     
            }
            temp = temp->next;
            head= head->next;
        }
        
        return ref->next;
    }
private:
    unordered_map<int, Node*> lookup;
    
};