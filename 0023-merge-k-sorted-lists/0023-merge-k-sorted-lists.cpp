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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

       if (lists.empty()) return nullptr;

        ListNode* res = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            ListNode* cur = lists[i];

            ListNode dummy(0, res);
            ListNode* start = &dummy;

            while (cur != nullptr && start->next != nullptr) {
                if (cur->val <= start->next->val) {
                    ListNode* temp = start->next;
                    ListNode* n = cur->next;

                    start->next = cur;
                    cur->next = temp;

                    cur = n;
                }

                start = start->next;
            }

            if (cur != nullptr) {
                start->next = cur;
            }

            res = dummy.next;
        }

        return res;
        
    }
};