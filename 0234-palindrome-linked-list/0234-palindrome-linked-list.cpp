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
    bool isPalindrome(ListNode* head) {

        // way i will do it is get the middle element then reverse the left side and check f the vals match 
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow; // this is were the half were comparing will start 

        auto reverse = [](auto&& self , ListNode* head){
            if (head == nullptr || head->next == nullptr) return head;
            ListNode* newHead = self(self , head->next);

            head->next->next = head;
            head->next = nullptr;

            return newHead;
        };

        ListNode* compare = reverse(reverse , mid);

        while(compare != nullptr){
            if (compare->val != head->val){
                return false;
            }
            compare = compare->next;
            head = head->next;
        }

        return true;
        
    }
};