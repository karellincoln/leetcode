/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/***********
*自己的做法*
************/
class Solution {
public:
    static ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *currNode = head->next;
        ListNode *lastNode = head;

        while (currNode) {
            ListNode *pos = head;
            if (currNode->val < pos->val) {
                head = currNode;
                lastNode->next = currNode->next;
                currNode->next = pos;
                currNode = lastNode->next;
                continue;
            }
            bool has_insertion = false;
            while (pos->next != currNode) {
                if (currNode->val < pos->next->val) {
                    lastNode->next = currNode->next;
                    currNode->next = pos->next;
                    pos->next = currNode;
                    currNode = lastNode->next;
                    has_insertion = true;
                    break;
                }
                else {
                    pos = pos->next;
                }
            }
            if(!has_insertion) {
                lastNode = currNode;
                currNode = lastNode->next;
            }
        }

        return head;
    }
};

// 别人的代码。
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);
        new_head -> next = head;
        ListNode* pre = new_head;
        ListNode* cur = head;
        while (cur) {
            if (cur -> next && cur -> next -> val < cur -> val) {
                while (pre -> next && pre -> next -> val < cur -> next -> val)
                    pre = pre -> next;
                /* Insert cur -> next after pre.*/
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                /* Move pre back to new_head. */
                pre = new_head;
            }
            else cur = cur -> next;
        }
        ListNode* res = new_head -> next;
        delete new_head;
        return res;
    }
};