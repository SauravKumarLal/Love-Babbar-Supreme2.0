// 206. Reverse Linked List

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
    
    ListNode* reverseListUsingRecurssion(ListNode* prev, ListNode* curr){
        //base case
        if(curr == NULL){
            return prev;
        }
        //1 case hum solve karenge
        ListNode* nextNode = curr->next;
        curr->next = prev; 
        prev = curr;
        curr = nextNode;

        //baaki RECURSSION samhalega
        ListNode* recurssionKaAns = reverseListUsingRecurssion(prev ,curr);
        return recurssionKaAns;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        return reverseListUsingRecurssion(prev, curr);
        // while(curr != NULL){
        //     ListNode* nextNode = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = nextNode;
        // }
        // // return prev;
        // head = prev;
        // return head;
    }
};