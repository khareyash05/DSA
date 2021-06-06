int bsearch(int arr[],int low,int high,int key){
  while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid]==key) return mid;
    else if(arr[low]<arr[mid]){
      if(key>=arr[low]&&key<arr[mid])
        high=mid-1;
      else low = mid+1;  
    }
    else{
      if(key<=arr[high]&&key>arr[mid])
        low=mid+1;
      else high = mid-1;  
    }
  }
}