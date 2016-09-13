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
    ListNode* A;
    ListNode* B;
    ListNode *getNode(ListNode *headA, ListNode *headB) {
        ListNode* ans;
        if(headA ==NULL && headB == NULL){
            return NULL;
        }else if(headA == NULL){
            headA = B;
            return getNode(headA,headB);
        }else if(headB == NULL){
            headB = A;
            return getNode(headA,headB);
        }
        if((headA -> val == headB -> val) && (headA -> next == headB -> next)){
            return headA;
        }
        
        
        return getNode(headA->next,headB ->next);
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        A = headA;
        B = headB;
        if(A==NULL || B == NULL)return NULL;
        else return getNode(headA,headB);
    }
};
