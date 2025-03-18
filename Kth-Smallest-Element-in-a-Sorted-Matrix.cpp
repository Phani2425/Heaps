class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue< pair<int, pair<int,int>>,vector< pair<int, pair<int,int>>>,greater< pair<int, pair<int,int>>>> pq;
        pair<int, pair<int,int>> p;

        //insert first column to the matrix
        for(int i = 0;i < matrix[0].size();i++){
            pq.push({matrix[i][0], {i,0}});
        }

        for(int i = 1; i < k; i++) {
        auto val = pq.top();
        pq.pop();

        int row = val.second.first;
        int col = val.second.second;

        // Insert the next element from the same row if it exists
        if(col + 1 < matrix[row].size()) {
            pq.push({matrix[row][col + 1], {row, col + 1}});
        }
    }

        return pq.top().first;
    }
};

//ye mast problme hai bhai
//matlab approachh easy ho sakta hai but the intution behind finding the most optimised solution for this is really awesome

//and hmm initally the step in which what i do is insret complete 1st column and then keep on going to add and remove things in the priority queue but it is not mandatory that we have to insert a column only as we can insert a row too....

//approach will change a little bit as when we are inserting the column first then for each time we will get a smallest element i.e 1st,2nd,3rd etc we need to insert the element present next to that in the same row but when we insert first row initially then each time we get a nth smallest element we will insert the nummber present below that in the same colummn to the priority queue

