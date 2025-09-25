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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newList = new ListNode();
        ListNode* currNode = newList;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                currNode->next = new ListNode(l1->val);
                currNode = currNode->next;
                l1 = l1->next;
            }
            else {
                currNode->next = new ListNode(l2->val);
                currNode = currNode->next;
                l2 = l2->next;
            }
        }

        while(l1!=nullptr){
            currNode->next = new ListNode(l1->val);
            currNode = currNode->next;
            l1 = l1->next;
        }

        while(l2 != nullptr){
            currNode->next = new ListNode(l2->val);
            currNode = currNode->next;
            l2 = l2->next;
        }
        
        return newList->next;
    }
};