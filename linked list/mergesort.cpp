Node* midNode(Node*head,Node*tail){
    Node* f=head;
    Node*s = head;
    while(f!=tail&&f->next!=tail){
        f=f->next->next;
        s=s->next;
    }
    return s;
}  

Node* merge(Node* x ,Node* y){
    Node* c;
    if(x->data<y->data){
        c=x;
        c->next = merge(x->next,y);
    }
    else{
        c=y;
        c->next = merge(x,y->next);
    }
    return c;
}

Node* mergeSort(Node* head,Node* tail){
    Node* mid = midNode(head,tail);
    Node* f1 = mergeSort(head,mid);
    Node* f2 = mergeSort(mid->next,tail);
    Node* ans = merge(f1,f2);
    return ans;
}