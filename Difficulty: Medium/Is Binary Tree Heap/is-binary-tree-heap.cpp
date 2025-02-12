//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
    
    pair<int,pair<int,bool>> helperFun (Node* tree, int & maxIndex,int index){
        if(!tree){
            return {0,{0,true}};
        }
        
        maxIndex = max(index,maxIndex);
        
        auto left = helperFun(tree->left,maxIndex,index*2);
        auto right = helperFun(tree->right,maxIndex,index*2+1);
        
        if(tree->data >= left.second.first && tree->data >= right.second.first){
            return {1+left.first+right.first,{tree->data,(left.second.second && right.second.second)}};
        }
        return {1+left.first+right.first,{tree->data,false}};
        
        
    }
    
  public:
    bool isHeap(struct Node* tree) {
        int maxIndex = 1;
        auto p = helperFun(tree,maxIndex,1);
        if(p.first < maxIndex || p.second.second == false){
            return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends