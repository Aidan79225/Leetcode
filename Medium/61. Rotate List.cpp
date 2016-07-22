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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp =  head;
        if(temp == NULL) return head;
        int lenth = 1;
        while(temp->next != NULL){
            temp = temp->next;
            lenth++;
        }
        temp->next = head;
        temp = head;
        
        int kk = lenth-k%lenth;
        cout<<lenth-k%lenth<<endl;
        while(kk>0){
            temp = temp->next;
            kk--;
        }
        
        ListNode* ans = temp;
        
        while(lenth>1){
            temp = temp->next;
            lenth--;
        }
        temp->next=NULL;
        
        return ans;
    }
};
