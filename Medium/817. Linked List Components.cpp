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
    int numComponents(ListNode* head, vector<int>& G) {
        int ans = 0;
        unordered_set<int> mSet;
        for(auto&it : G){
            mSet.insert(it);
        }
        ListNode* t = head;
        bool used = false;;
        while(t){
            if(mSet.find(t -> val) != mSet.end()){
                if(!used){
                    ans++;
                    used = true;   
                }
            }else{
                used = false;
            }
            t = t-> next;
        }
        return ans;
    }
};
