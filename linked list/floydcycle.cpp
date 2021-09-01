int floyd(Node* list){
  Node* slow_p =list;
  Node* fast_p=list;
  while(slow_p&&fast_p&&fast_p->next){
    slow_p=slow_p->next;
    fast_p=fast_p->next->next;
    if(slow_p==fast_p) return 1;
  }
  return 0;

}
// two pointer one is slow and other fast when slow=fast loop present