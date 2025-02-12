//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

Node* buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
void postorderTraversal(Node* root)
{
    if (!root)
        return;

    // recur on left subtree
    postorderTraversal(root->left);

    // then recur on right subtree
    postorderTraversal(root->right);

    // print the root's data
    cout << root->data << " ";
}



// } Driver Code Ends
//User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution{
    void inorder(Node* root,vector<int>&ans){
        
        if(!root)return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
    }
    void fillHeap(Node* root,vector<int>&ans,int & index){
        
        if(!root) return;
        
        fillHeap(root->left,ans,index);
        fillHeap(root->right,ans,index);
        
        root->data = ans[index];
        index++;
        
    }
    
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> ans;
        inorder(root,ans);
        int index = 0;
        fillHeap(root,ans,index);
        return;
    }    
};

// Are bhai tu just notice kar ki jetebele ei given rules re heap create karibu setebele se heap ra postorder sabubele
// increment order re hi rahiba...

//and emiti every possible case re haba and to know this you dont have to try from different examples you just have to understab=nd what are the rules
// and visualize how it will form a heap whose postorder will always be in increasing order

// au jadi tu ekatha janigalu then ta easy heigala bcs ame janiche BST ra inorder amaku same order re nodes daba

//so jadi inorder ru ame heap re postorder ra complete vallue paijiba au  amaku tree re inplace changes karibara achi then it is so so simple that we will just fill
// the values we got in the tree while traversing it in postorder


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string inp, ch;
        getline(cin, inp);
        struct Node* root = buildTree(inp);
        Solution ob;
        ob.convertToMaxHeapUtil(root);
        postorderTraversal(root);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends