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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> seen;

        ListNode* cur= head;
        ListNode* prev = nullptr;

        while(cur != nullptr){
            if (seen.count(cur->val)== 1){
                prev->next = cur->next;
                cur = cur->next;
               
            }
            else{
                prev = cur;
                seen.insert(cur->val);
                cur = cur->next;
               
            }
        }

        return head;
    }
};