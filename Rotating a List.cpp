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
    ListNode* rotateRight(ListNode* head, int k) {
        
        ListNode* tail = head;
        
        int len = 0;
        
        
        if(k==0){
            return head;
        }
        
        if(head==NULL || len ==1){
            return head;
        }
        
        while(tail->next!=NULL){
            len++;
            tail = tail->next;
        }
        len++;
        cout<<len;
        
        
        if(k>=len){
            while(k>=len){
                k = k - len;
            }
        }
        
        ListNode* temp2 = head;
        for(int i=0;i<len-k-1;i++){
            
            temp2 = temp2->next;
        }
        
        tail->next = head;
        head = temp2->next;
        temp2->next = NULL;
           
        return head;
    }
};