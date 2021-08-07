// to reverse a linked list

prev,next=start

// 1. Iterative Method
int main(){
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head_ref = prev;
}
// 2. Recursive Method
int main(){
    reverse(start);
}
void reverse(Node *start){
    if(start->next==NULL){
        *head_ref=start;
        return;
    }
    Node *next=start->next;
    reverse(next);
    next->next=start;
    start->next=NULL;
    *head_ref=start;
}