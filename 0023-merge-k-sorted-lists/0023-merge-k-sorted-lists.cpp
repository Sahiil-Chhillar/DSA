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
// class Solution {
// public:
//     ListNode* mergeTwo(ListNode* l1, ListNode* l2) {
//         if (!l1) return l2;
//         if (!l2) return l1;

//         ListNode* head = nullptr;

//         if (l1->val < l2->val) {
//             head = l1;
//             l1 = l1->next;
//         }
//         else{
//             head = l2;
//             l2 = l2->next;
//         }

//         ListNode* curr = head;
//         while (l1 && l2) {
//             if (l1->val < l2->val) {
//                curr->next = l1;
//                 l1 = l1->next;
//             }
//             else {
//                 curr->next = l2;
//                 l2 = l2->next;
//             }
//             curr = curr->next;
//         }

//         curr->next = (l1 ? l1 : l2);
//         return head;
//     }
//     ListNode* mergeKLists(vector<ListNode*>& l) {
//         if(l.empty()) return nullptr;

//         ListNode* merged = l[0];
//         for(int i = 1; i < l.size();i++){
//             merged = mergeTwo(merged,l[i]);
//         }

//         return merged;
//     }
// };
class Solution {
public:
    typedef pair<int, ListNode*> p;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<p, vector<p>, greater<p>> pq;
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            temp->next = p.second;
            temp = temp->next;

            if (p.second->next) pq.push({p.second->next->val, p.second->next});
        }

        return newHead->next;
    }
};