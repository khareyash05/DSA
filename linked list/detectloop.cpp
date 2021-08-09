// Method 1 Using hashmap 
// TC - O(n) SC- O(n)
bool detectLoop(struct Node* h)
{
    unordered_set<Node*> s;
    while (h != NULL) {
        // If this node is already present
        // in hashmap it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (s.find(h) != s.end())
            return true;
 
        // If we are seeing the node for
        // the first time, insert it in hash
        s.insert(h);
 
        h = h->next;
    }
 
    return false;
}
// Method 2 without hashmap
bool detectLoop(struct Node* h)
{
    while (h != NULL) {
        // If this node is already traverse
        // it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (h->flag == 1)
            return true;
 
        // If we are seeing the node for
        // the first time, mark its flag as 1
        h->flag = 1;
 
        h = h->next;
    }
 
    return false;
}
// Method 3 - : Floyd’s Cycle-Finding Algorithm
// Traverse linked list using two pointers.
// Move one pointer(slow_p) by one and another pointer(fast_p) by two.
// If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
int detectLoop(Node* list)
{
    Node *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}