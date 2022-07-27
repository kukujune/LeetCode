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
    TreeNode* findRightEnd(TreeNode* a){
      if(a->right == NULL) return a;
      else return findRightEnd(a->right);
    }
  
    void flatten(TreeNode* root) {
      
      if(root == NULL) return;
      TreeNode* nextLeft;
      TreeNode* nextRight;
      TreeNode* nextRightEnd;
      
      while(root){
        
        //cout << root->val << "\n";
        if(root->left == NULL){
          root = root->right;
          continue;
        }
        
        if(root->left != NULL){
          nextRightEnd = findRightEnd(root->left);
          nextRight = root->right;
          
          nextLeft = root->left;
          root->left = NULL;
          root->right = nextLeft;
          root = nextLeft;
          
          nextRightEnd->right = nextRight;
        }
        
      }
      
    }
};