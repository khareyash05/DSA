void removeLoop(struct Node* loop_node, struct Node* head)
{
    struct Node* ptr1;
    struct Node* ptr2;
 
    /* Set a pointer to the beginning
      of the Linked List and
      move it one by one to find the
      first node which is
      part of the Linked List */
    ptr1 = head;
    while (1) {
        /* Now start a pointer from
        loop_node and check if
       it ever reaches ptr2 */
        ptr2 = loop_node;
        while (ptr2->next != loop_node
               && ptr2->next != ptr1)
            ptr2 = ptr2->next;
 
        /* If ptr2 reahced ptr1
        then there is a loop. So
        break the loop */
        if (ptr2->next == ptr1)
            break;
 
        /* If ptr2 did't reach ptr1
         then try the next node
         * after ptr1 */
        ptr1 = ptr1->next;
    }
 
    /* After the end of loop ptr2
     is the last node of the
     loop. So make next of ptr2 as NULL */
    ptr2->next = NULL;
}