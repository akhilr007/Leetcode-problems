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
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = NULL, *nxt = NULL;

        while(cur != NULL){
            nxt = cur->next;
            cur->next = prev;

            prev = cur;
            cur = nxt;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int L, int R){

        if(head == NULL) return head;

        ListNode* prev = NULL, *cur = head;
        int count=1;

        while(count != L){
            prev = cur;
            cur = cur->next;
            count++;
        }

        ListNode* start = cur;

        while(count != R){
            cur = cur->next;
            count++;
        }

        ListNode* tail = cur->next;
        cur->next = NULL;

        ListNode* reverseHead = reverseList(start);

        if(prev != NULL) prev->next = reverseHead;

        cur = reverseHead;
        while(cur->next != NULL){
            cur = cur->next;
        }

        cur->next = tail;

        if(L == 1) return reverseHead;
        return head;
    }
};