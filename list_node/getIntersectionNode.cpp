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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA){
            lenA++;
            curA = curA->next;
        }
        while(curB){
            lenB++;
            curB = curB->next;
        }
        if(lenB > lenA){
            swap(headA, headB);
            swap(lenA, lenB);
        }
        curA = headA;
        curB = headB;
        int size = lenA - lenB;
        for(int i = 0; i < size; i++){
            curA = curA->next;
        }
        while(curA && curB){
            if(curA == curB){
                return curA;
            }else{
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr;
    }
};