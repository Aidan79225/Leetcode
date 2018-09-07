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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* root = new ListNode(0);
        root -> next = head;
        ListNode* pre = root;
        ListNode* temp = head;
        while(temp != nullptr){
            ListNode* end = temp;
            int count = k;
            while(end != nullptr && --count)end = end -> next;
            ListNode* next = nullptr;
            if(end != nullptr){
                next = end -> next;
                end -> next = nullptr;
                pre -> next = reverse(temp);
                pre = temp;
                temp = next;
            }else{
                pre -> next = temp;
                break;
            }
            
        }
        return root -> next;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* next = nullptr;
        ListNode* pre = nullptr;
        while(temp != nullptr){
            next = temp -> next;
            temp -> next = pre;
            pre = temp;
            temp = next;
        }
        return pre;
    }
};
