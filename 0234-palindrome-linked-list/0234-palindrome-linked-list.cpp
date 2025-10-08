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
        if(!head->next) return true;

        auto slow = head;
        auto fast = head;

        while(fast && fast->next){
            slow = slow-> next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        auto curr = head;
        while(curr != slow){
            auto next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        if(fast) slow = slow->next; // can skip middle if odd length

        while(prev && slow){
            if(prev->val != slow->val) return false;
            prev = prev->next;
            slow= slow->next;
        }

        if(prev || slow) return false;

        return true;
    }

};