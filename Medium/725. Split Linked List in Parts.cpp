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
    //a = b * q + r
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> ans;
        int len = getLen(root);
        int r = len % k;
        int q = len / k;
        ListNode* cur = root;
        ListNode* temp = new ListNode(0);
        temp -> next = root;
        ListNode* head;
        for(int i = 0 ; i < k ; i++){
            cur = temp;
            for(int j = 0 ; j < q ; j++){
                if(cur == nullptr)
                    break;
                cur = cur -> next;
            }
            if(r > 0){
                r--;
                if(cur != nullptr)
                    cur = cur -> next;
            }
            ans.push_back(temp -> next);
            if(cur != nullptr){
                temp -> next = cur -> next;
                cur -> next = nullptr;
            }else{
                temp -> next = nullptr;
            }
        }
        return ans;
    }
    int getLen(ListNode* root){
        ListNode* temp = root;
        int len = 0;
        while(temp){
            temp = temp -> next;
            len++;
        }
        return len;
    }
};
