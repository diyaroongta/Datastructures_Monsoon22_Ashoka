

NodeAddress bubbleSortLinkedList(NodeAddress head){
    NodeAddress c, lastDone;
    for (lastDone = NULL; lastDone != head; lastDone = c /*wherever the inner loop finishes*/ ){
        for (c = head; c->next != lastDone; c = c->next){
            if (c->val > c->next->val){
                //just swap the values
                int t = c->val;
                c->val = c->next->val;
                c->next->val = t;
            }
        } //end of c loop - the element has been bubbled upto position c
    }
    
    return head;
}
