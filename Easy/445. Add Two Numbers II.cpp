/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//兩邊放入stack 做大數加法

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<ListNode*> stack1;
        vector<ListNode*> stack2;
        ListNode* temp = l1;
        while(temp != nullptr){
            stack1.push_back(temp);
            temp = temp -> next;
        }
        temp = l2;
        while(temp != nullptr){
            stack2.push_back(temp);
            temp = temp -> next;
        }
        int index1 = stack1.size();
        int index2 = stack2.size();
        ListNode* head = nullptr;
        int carry = 0;
        while(index1 > 0 && index2 > 0){
            --index1;
            --index2;
            int now = stack1[index1] -> val + stack2[index2] -> val + carry;
            carry = now / 10;
            now = now % 10;
            temp = new ListNode(now);
            temp -> next = head;
            head = temp;
        }
        while(index1 > 0){
            --index1;
            int now = stack1[index1] -> val + carry;
            carry = now / 10;
            now = now % 10;
            temp = new ListNode(now);
            temp -> next = head;
            head = temp;
        }
        while(index2 > 0){
            --index2;
            int now = stack2[index2] -> val + carry;
            carry = now / 10;
            now = now % 10;
            temp = new ListNode(now);
            temp -> next = head;
            head = temp;
        }
        if(carry >0){
            temp = new ListNode(carry);
            temp -> next = head;
            head = temp;
        }
        return head;
    }
};
