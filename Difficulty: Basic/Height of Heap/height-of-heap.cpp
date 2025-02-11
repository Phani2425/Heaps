//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function Template for C++

// WAY - 1

//complete brute force approach and quite simmilar approach to finding the height of the normal tree
// there i was going to left and right child using the links and here i am just doing thet using indexes as i know 
// that as this is arary representation of heap hence there is no chance that a NULL can come 
// in between array as heap is a complete binary tree

// TC:- O(n)
// SC:- O(logn)

// class Solution{
// public:

//     int helperFun(int index,int N){
//         if(index*2+1>=N){
//             return 0;
//         }
        
//         int left = helperFun(index*2+1,N);
//         int right = helperFun(index*2+2,N);
        
//         return  1+max(left,right);
//     }

//     int heapHeight(int N, int arr[]){
//       return helperFun(0,N);
//     }
// };

// way - 2

//mu bhabili ki are bhai jadi eta heap i.e a complete binary tree then ara feature hauchi ki
// all level will be completely filled except the last level i which the nodes will be as left  as possible 

// and this means in the last level even if it have a single node still it will be in the left most position
// so from root if we go only left and each time we go we will add 1 to a variable then for sure we will get the height of the tree



class Solution{
public:

    int heapHeight(int N, int arr[]){
        
        // handling a edge case
        if(N==1){
            return 1;
        }
        
        int count = 0;
        int index = 0;
        
        while(index*2 + 1 < N){
            index = index*2+1;
            count++;
        }
        
        return count;
      
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