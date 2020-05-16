/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
*/

//Solution :

ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *a=head, *b=head->next, *c=head->next;
        
        while(a && b){
            if(b->next){
                a->next= b->next;
                a=a->next;
                if(a){
                    b->next=a->next;
                    b=b->next;
                }
            }
            else break;
        }
        a->next=c;
        return head;
    }
