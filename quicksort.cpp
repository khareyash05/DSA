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
  swap(a,j,pivot);// swap pivot and j when i>j
  return j;    
}
void quickSort(int l,int h){
  if(l<h){
    int pivot = partition(a,l, h);
    quickSort(l, pivot-1); // not including pivot because pivot will be sorted before hand and thus not to be included
    quickSort(pivot+1, h);
  }
}
int main() {
  std::cout << "Hello World!\n";
}