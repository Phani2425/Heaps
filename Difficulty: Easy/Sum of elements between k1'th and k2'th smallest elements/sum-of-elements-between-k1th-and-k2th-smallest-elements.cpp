//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2)
    {
        
        priority_queue<long long>q1;
        priority_queue<long long>q2;
        
        for(long long i=0;i<K1;i++){
            q1.push(A[i]);
        }
         for(long long i=0;i<K2;i++){
            q2.push(A[i]);
        }
        
        for(long long i=K1;i<N;i++){
            if(A[i] < q1.top()){
                q1.pop();
                q1.push(A[i]);
            }
        }
        
        for(long long i=K2;i<N;i++){
            if(A[i] < q2.top()){
                q2.pop();
                q2.push(A[i]);
            }
        }
        
        long long sum = 0;
        q2.pop();
        while(q2.size() > q1.size()){
            sum+=q2.top();
            q2.pop();
        }
        
        return sum;
        
    }
};
 
//  APPRAOCH:-
 
//  I WAS QUITE SIMPLE THOGH I WAS ONLY MAKING IT MORE COMPLEX THINKING HOW CAN I SOLEV THIS IN A SINGLE MAX HEAP
//  I DONT KNOW IT CAN BE SOLVED USING SINGLE MAX HEAP OR NOT BUT I WILL SOLEV IT USING 2 MAX HEAPS FOR NOW
 


//{ Driver Code Starts.
int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin>>n;
        long long a[n+5];
        for(int i =0;i<n;i++)
            cin >> a[i];
        
        long long k1, k2;
        cin >> k1 >> k2;
        Solution ob;
        cout << ob.sumBetweenTwoKth(a, n, k1, k2) << endl;
        
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends