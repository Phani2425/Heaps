//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    // max heap for left
    priority_queue<int> left;
    // min heap for right
    priority_queue<int,vector<int>,greater<int>> right;
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(left.empty()){
            left.push(x);
        }
        else{
            if(x>left.top()){
                right.push(x);
            }
            else{
                left.push(x);
            }
        }
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
        if(left.size() < right.size()){
            left.push(right.top());
            right.pop();
        }
        
        if(left.size()-right.size() > 1){
            right.push(left.top());
            left.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size() == right.size()){
            return (left.top()+right.top())/2;
        }
        
        else{
            return left.top();
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends