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
    ListNode* middleNode(ListNode* head) {

        int n = 0;
        ListNode* dummy = head;

        while(dummy != nullptr){
            n++;
            dummy = dummy->next;
        }

        int count = 0;
      
        count = (n / 2);

        while (count > 0){
            head = head->next;
            count--;
        }

        return head;

       
        
    }
};