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
        int count = 1;
        ListNode* temp = head;
        ListNode* ans = head;
        while (temp->next != nullptr) {
            count++;
            temp = temp->next;
        }
        if (count % 2 == 0) {
            for (int i = 1; i < count / 2; i++) {
                ans = ans->next;
            }
            return ans->next;
        } else {
            for (int i = 0; i < count / 2; i++) {
                ans = ans->next;
            }
            return ans;
        }
    }
};