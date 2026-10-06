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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n = new ListNode();
        ListNode* cur = n;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr|| carry){
            // we check if the current value in the listnode is nullptr if not take val else put zero 
            int val1 = 0;
            if (l1 != nullptr){
                val1 = l1->val;
            }
            int val2 = 0;
            if (l2 != nullptr){
                val2 = l2-> val;
            }

            int sum = val1 + val2 + carry;
            int rem = sum / 10;
            int num = sum % 10;

            cur->next = new ListNode(num);
            carry = rem;

            if (l1 != nullptr){
                l1 = l1->next;
            }
            if (l2 != nullptr){
                l2 = l2->next;
            }
            cur = cur->next;

        }

        return n->next;

    }
};