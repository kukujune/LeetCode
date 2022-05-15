/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int findDepth(TreeNode* root){
      if(!root) return 0;
      return 1 + max(findDepth(root->left), findDepth(root->right));
    }
   int getLastNode(TreeNode* root, int dep){
     if(!root) return 0;
     //cout << root->val << " " << dep << "\n";
     if(dep == 1){
       return root->val;
     }
     return getLastNode(root->left, dep-1) + getLastNode(root->right, dep-1);
   }
  
    int deepestLeavesSum(TreeNode* root) {
      // depth를 구한다.
      int depth = findDepth(root);
      //cout << depth << "\n";
      int ret = getLastNode(root, depth);
      
      // 마지막 depth의 sum을 구한다.
      
      return ret;
    }
};