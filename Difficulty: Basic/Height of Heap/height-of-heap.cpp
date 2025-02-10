//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int helperFun(int index,int arr[],int N){
        if(index*2+1>=N){
            return 0;
        }
        
        int left = helperFun(index*2+1,arr,N);
        int right = helperFun(index*2+2,arr,N);
        
        return  1+max(left,right);
    }

    int heapHeight(int N, int arr[]){
       return helperFun(0,arr,N);
    }
};

//{ Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.heapHeight(N, arr) << endl;
    
cout << "~" << "\n";
}
    return 0; 
} 

// } Driver Code Ends