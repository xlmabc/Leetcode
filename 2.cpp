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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode *head, *res;
        res = head;
        int carry = 0;
        while(l1 && l2) {
            l1->val += l2->val + carry;
            carry = l1->val/10;
            l1->val %= 10;
            res->next = l1;
            res = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            l1->val += carry;
            carry = l1->val/10;
            l1->val %= 10;
            res->next = l1;
            res = l1;
            l1 = l1->next;
        }
        while(l2){
            l1 = l2;
            //cout<<l1->val;
            l1 ->val += carry;
            carry = l1->val/10;
            l1->val %= 10;
            res->next = l2;
            res = l2;
            l2 = l2->next;
        }
        if(carry){
            ListNode *tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
            tmp->val =1;
            tmp->next = NULL;
            res->next = tmp;
        }
        return head->next;
    }
};