/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode *> list;

        // create list;
        ListNode *tmp = head;
        while(tmp){
            list.push_back(tmp);
            tmp = tmp->next;
        }

        // reorderList;
        int size = list.size();
        tmp = head;
        for (int i = 0; i < size / 2; ++i) {
            ListNode *next = tmp->next;
            tmp->next = list[size - 1 - i];
            if(next != tmp->next) tmp->next->next = next;
            else tmp->next->next = NULL;
            tmp = next;
        }

        if(size % 2 == 1) tmp->next = NULL;

    }
};


class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next==NULL)
            return;
        //find the middle of the list, and split into two lists.
        ListNode *p=head,*q=head;
        while(p && q && q->next && q->next->next){
            p=p->next;
            q=q->next->next;
        }

        ListNode *mid = p->next;
        p->next=NULL;
        p=head;
        //reverse from the middle to the end
        ListNode *q1=mid, *q2,*q3;
        if(mid->next){
            q1=mid;
            q2=mid->next;
            while(q2){
                q3=q2->next;
                q2->next=q1;
                q1=q2;
                q2=q3;

            }
            mid->next=NULL;
        }
        q=q1;
        //merge these two list
        ListNode *s=p;
        p=p->next;
        while(p && q){
           s->next=q;
           s=s->next;
           q=q->next;

           s->next=p;
           s=s->next;
           p=p->next;
        }
        if(p){
            s->next=p;
        }
        if(q){
            s->next=q;
        }
    }
};