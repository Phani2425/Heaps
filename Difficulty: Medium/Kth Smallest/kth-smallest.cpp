//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function

    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> q;
        
        for(int i=0;i<k;i++){
            q.push(arr[i]);
        }
        
        for(int i=k;i<arr.size();i++){
            if(arr[i]<q.top()){
                q.pop();
                q.push(arr[i]);
            }
        }
        
        return q.top();
    }
    
    
    // APPROACHES:-
    
    // iska intution me to maja hi agaya bhai
    // mene third and most intuitive soultion khud hi guess kardia
    // ro dun kya???🫠
    
    // ok lets see how many ways we can solev this:-
    
    // way:1
    // sort the array and you will find the ans at k-1 index
    // TC:-O(nlogn)
    // SC:-O(1)
    
    // way:2
    // create min heap from array
    // then for k-1 times remove elemnt from the heap
    // and at last the top element will be the ans
    // TC:O(n+klogn) => n for creating the heap either by passing v.begin() and v.end() to the priority_queue method or by using step-down approcah or bottom-up approach or floyeds algorithm
    // SC:O(n)
    
    // way:3
    // think it like this jadi gote class re n pila acahnti au tate tanka height ra array deichi au tate bahara karibara achi ki kth smallest height bala pila kie then tu simply kn karibu
    // just think what you will do in real???
    
    // tu obviously first k ta pila nku dakiki to pakahre thia karibu then jane jane kariki au alaga pila nku asibaku kahibu
    // then semanananku ei 4 ta group bhitaru sabuthu bada pila saha comapre karibu jadi ta thu se nua pila ra height kam then sie se bada pila ku replace kariki group re rahiba
    // emiti hele at a certain point of time ama pakahre k no of students rahibe joumane examined pila nka bhitaru sabuthu sana height
    
    // au last re jetebele sabu pila sarijibe then se group ra sabuthu bada height pila hi kth smallest haba
    
    // TC:O(n)
    // SC:O(k)
    
    // THERE IS A RULE ACTUALLY FOR THIS TYPE OF QUESTIONS SUCH AS:
    // FIND KTH SMALLES OR FIND KTH LARGEST
    
    // SO THE RULE IS FOR KTH SMALLEST USE MAX_HEAP AND FOR KTH LARGEST USE MIN_HEAP
    
    
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        k = crr[0];
        int n = arr.size();
        Solution ob;
        cout << ob.kthSmallest(arr, k) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends