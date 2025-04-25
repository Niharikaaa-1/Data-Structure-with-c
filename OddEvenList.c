/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;
    else{
        struct ListNode *pre=head;
        struct ListNode *current=head->next;
        struct ListNode *head1=current;
        while(current!=NULL && current->next !=NULL){
            pre->next=current->next;
            pre=pre->next;
            current->next=pre->next;
            current=current->next;
        }
        pre->next=head1;
        return head;
    }
}
