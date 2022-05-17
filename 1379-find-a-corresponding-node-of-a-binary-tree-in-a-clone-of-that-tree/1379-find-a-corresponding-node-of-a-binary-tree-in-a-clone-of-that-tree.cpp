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
  
    TreeNode* ret;  
  
    void getCloned(TreeNode* cloned, int val){

      if(cloned == nullptr) return;
      if(cloned->val == val){
        ret = cloned;
        return;
      }      
      getCloned(cloned->left, val);
      getCloned(cloned->right, val);
    }
  
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
      // TreeNode* ret;      
      //cout << target << "\n";
      //cout << target->val << "\n";
      //cout << target->left << "\n";
      //cout << target->right << "\n";
      
      getCloned(cloned, target->val);
      
      //cout << ret->val << "\n";
      //cout << &(ret->val) << "\n";
      
      return ret;
    }
};