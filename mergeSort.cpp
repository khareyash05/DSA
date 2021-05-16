void merge(int arr[],int l,int mid ,int r){ // same as merging 2 arrays sorted
  int n1= mid-l+1;
  int n2 = r-mid;
  int a[n1],b[n2];
  for(int i=0;i<n1;i++)
    a[i]=arr[i+l];
  for(int i=0;i<n2;i++)
    b[i]=arr[mid+1+i];
  int i=0,j=0,k=l;    
  while(i<n1 && j<n2){
    if(a[i]>b[j]){
      arr[k]=a[i];
      i++;
    }
    else{
      arr[k]=b[j];
      j++;
    }
  }
  while(i<n1){ // now checking if any array is left to be done 
    arr[k]=a[i];
    i++;k++;
  }
  while(j<n2){
    arr[k]=b[j];
    j++;k++;
  }
}

void mergeSort(int arr[],int l ,int r){
  if(l<r){
    int mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
  }
}

// Basic logic of mergesort is splitting array into halves and doing halves till single element in a half and merging them after that