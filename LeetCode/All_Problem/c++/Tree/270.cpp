/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int ret = root->val;
        
        while(root != nullptr) {
            cout << target <<"  "<< root->val <<"  " << ret <<"  " << fabs(target - root->val) <<" " << fabs(target - ret)<< endl;
            if(fabs(target - root->val) < fabs(target - ret)){
                ret = root->val;
            }
            root = root->val > target ? root->left : root->right;
        }
        cout << ret;
        return ret;
    }
};															  
/* 
															  4 
															 /   \
Input: root = [4,2,5,1,3]									2    5
target = 3.714286										  /	 \  /  \
3.71429  4  4  0.285714 0.285714                         1   3  n   n 
3.71429  2  4  1.71429 0.285714
3.71429  3  4  0.714286 0.285714
4

target = 1.714286
1.71429  4  4  2.28571 2.28571
1.71429  2  4  0.285714 2.28571
1.71429  1  2  0.714286 0.285714
2

*/