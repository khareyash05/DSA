#include <iostream>
using namespace std;
int partition(int a[],int l ,int h){
  int pivot = a[l];
  int i=l;
  int j=h;
  while(i<j){
    while(a[i]<=pivot)
      i++;
    while(a[j]>=pivot)
      j--;
    if(i<j)
      swap(a,i,j);
  }
  swap(a,j,pivot);
  return j;    
}
void quickSort(int l,int h){
  if(l<h){
    int pivot = partition(a,l, h);
    quickSort(l, pivot-1);
    quickSort(pivot+1, h);
  }
}
int main() {
  std::cout << "Hello World!\n";
}