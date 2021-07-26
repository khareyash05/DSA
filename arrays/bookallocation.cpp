bool checkFeasible(int a[],int k,int mid){
  int student=1,sum=0;
  for(int i=0;i<n;i++){
    if(sum+a[i]>mid){
      student++;
      sum=a[i];
    }
    else sum+=a[i];
  }
  return student<=k;
}

int minPages(int arr[],int k,int n){
  int mini = 0,maxi=0;
  for(int i=0;i<n;i++)
    mini=max(arr[i],mini);
  for(int i=0;i<n;i++)  
    maxi+=arr[i];
  int res=0;
  while(mini<=maxi)  {
    int mid = (mini+maxi)/2;
    if(checkFeasible(arr,k,mid)){
      res=mid;
      mini=mid+1;
    }
    else maxi=mid+1;
  }
  return res;
}

