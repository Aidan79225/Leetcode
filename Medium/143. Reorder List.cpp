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
    void reorderList(ListNode* head) {
        if(head == nullptr)return;
        vector<ListNode*> nodeRecord;
        ListNode* temp = head;
        while(temp){
            nodeRecord.push_back(temp);
            temp = temp -> next;
        }
        int size = nodeRecord.size();
        int half = size / 2;
        for(int i = 0 ; i < half;i++){
            nodeRecord[i] -> next = nodeRecord[size - 1 - i];
            nodeRecord[size - 1 - i] -> next = nodeRecord[i+1];
        }
        nodeRecord[half] -> next = nullptr;
    }
};
