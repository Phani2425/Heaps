//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        priority_queue<int,vector<int>,greater<int>> q;
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(i < k-1){
                q.push(arr[i]);
                ans.push_back(-1);
            }
            else if(i == k-1){
                q.push(arr[k-1]);
                ans.push_back(q.top());
            }
            else{
                if(arr[i] > q.top()){
                    q.pop();
                    q.push(arr[i]);
                }
                ans.push_back(q.top());
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends