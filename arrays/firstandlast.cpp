int first(int arr[],int low,int high,int x){
  int res=-1;
  while(low<=high){
    int mid =(low+high)/2;
    if(arr[mid]>x)
      high=mid-1;
    else if(arr[mid]<x)  
      low = mid+1;
    else{
      res = mid;
      high = mid+1;
    }  
  }
}

int low(int arr[],int low,int high,int x){
  int res=-1;
  while(low<=high){
    int mid =(low+high)/2;
    if(arr[mid]>x)
      high=mid-1;
    else if(arr[mid]<x)  
      low = mid+1;
    else{
      res = mid;
      low = mid+1;
    }  
  }
}