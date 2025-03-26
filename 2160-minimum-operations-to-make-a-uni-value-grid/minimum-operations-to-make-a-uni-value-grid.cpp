class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        if(grid.size() == 1 && grid[0].size()==1){
            return 0;
        }
        vector<int> v;
        int Rem = grid[0][0]%x;
        for(auto &g :grid){
            for(int i=0;i<g.size();i++){
                if(g[i]%x != Rem){
                    return -1;
                }
                v.push_back(g[i]);
            }
        }
        sort(begin(v),end(v));
        int mid = (v.size()-1)/2;
        int ans=0;
        // first i was thinking that to make the grid uni value every element of the grid must be divisible by x , that is why i was checking that if v[i]%x != 0 then return -1.....
        // but it is not mandatory means if elements are 3,5,7,9 and x is 2 then they can be convert to uni value but  they wont be divisible by 2....so we need to check that the reminders are same for all element not necesserily to be 0
        for(int i=0;i<v.size();i++){
            ans += max(v[mid],v[i])-min(v[mid],v[i]);
        }

        return ans/x;
        
    }
};

//ANOTHER SOLUTION

// this have a simillar approach but little bit optimised in terms of operation and also in prev approach we are calculating the steps to reach the middle value for each element but her in this approach we can calculate them by using prefix sum
