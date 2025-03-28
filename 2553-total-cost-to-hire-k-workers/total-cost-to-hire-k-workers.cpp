class Solution {
public:
using p = pair<int,int>;
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<p,vector<p>,greater<p>> left;
        priority_queue<p,vector<p>,greater<p>> right;

        long long totalcost = 0;
        int i =0 ;
        int j = costs.size()-1;

        while(k--){
           while(left.size() < candidates && i<=j){
            left.push({costs[i],i});
            i++;
           }

            while(right.size() < candidates && i<=j){
            right.push({costs[j],j});
            j--;
           }

           //compare bw two heaps
           if(!left.empty() && !right.empty()){
                       if(left.top().first < right.top().first){
                totalcost += left.top().first;
                  left.pop();
           }
           else if(left.top().first > right.top().first){
                  totalcost +=right.top().first;
                right.pop();
           }
           else{
             if(left.top().second < right.top().second){
                  totalcost += left.top().first;
                  left.pop();
             }else{
                totalcost +=right.top().first;
                right.pop();
             }
           }
           }
           else{
            if(left.empty()){
               totalcost +=right.top().first;
                right.pop();
            }
            else{
                  totalcost += left.top().first;
                  left.pop();
            }
           }
           
        }

        return totalcost;

    }
};