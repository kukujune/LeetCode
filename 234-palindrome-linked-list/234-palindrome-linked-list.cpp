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
    bool isPalindrome(ListNode* head) {
      vector<int> vi;
      ListNode *now = head;
      
      while(now != NULL){
        
        int nowVal = now->val;
        vi.push_back(nowVal);
        //cout << now->val << " " << now->next << "\n";
        now = now->next;
        
      }
      
      int viSize = vi.size();
      bool ret = true;
      for(int i=0; i<viSize; i++){
        if(vi[i] != vi[viSize - i - 1]){
          ret = false;
          break;
        }   
      }
      
      return ret;
    }
};