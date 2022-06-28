
#include <iostream>

using namespace std;

void merge(int arr[],int s,int e)
{
    int mid=s+(e-s)/2;
    int leftlength=mid-s+1;
    int rightlength=e-mid;
    
    //creat left and right parts
    
    int *left=new int[leftlength];
    int *right=new int[rightlength];
    
    //copy into left array
    
    int originalindex=s;
    for(int i=0;i<leftlength;i++)
    {
        left[i]=arr[originalindex++];
    }
    
    //copy into right array
    
    originalindex=mid+1;
    for(int i=0;i<rightlength;i++)
    {
        right[i]=arr[originalindex++];
    }
    
    //now we have to sorted array
    //now we merge them.
    
    int leftindex=0;
    int rightindex=0;
    originalindex=s;
    
    //compare element from left to right and copy in original array
    
     while(leftindex<leftlength && rightindex<rightlength)
     {
         if(left[leftindex] < right[rightindex])
         {
             arr[originalindex++]=left[leftindex++];
         }
         
         else
         {
             arr[originalindex] = right[rightindex ];
             originalindex++;
             rightindex++;
         }
     }
     
     //check if any other element is present in arrleft array
     //then copy it to another array
     while(leftindex<leftlength)
     {
         arr[originalindex++]=left[leftindex++];
         
     }
     
     //check if any other element is present in right array
     //then copy it to another array
     while(rightindex<rightlength)
     {
         arr[originalindex++]=right[rightindex++];
     }
     
}

void mergesort(int arr[],int s,int e)
{
    //base case
    if(s>=e)
    {
        return ;
    }
    
    int mid=s+(e-s)/2;
    
    //left part
    mergesort(arr,s,mid);
    
    //right part
    mergesort(arr,mid+1,e);
    
    //merge both 
    merge(arr,s,e);
}

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //int arr[]={12,11,13,5,6,7};
    //int size=6;
    
    mergesort(arr,0,n-1);
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}



