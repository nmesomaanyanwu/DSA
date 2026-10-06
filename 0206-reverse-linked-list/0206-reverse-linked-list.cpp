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
    ListNode* reverseList(ListNode* head) {
        /*
            ok so i can save the next pointer in a temp , use a prev pointer 
        */
        ListNode* cur = head;
        ListNode* prev = nullptr;

       while(cur != nullptr){
            ListNode* n = cur->next; //3
            cur->next = prev; //5 -4
            prev = cur;
            cur = n;
            
       }
       return prev;
    }
};