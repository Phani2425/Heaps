class Solution {
public:
    typedef vector<int> v;
    struct Compare {
        bool operator()(v& a, v& b) {
                if (a[1] == b[1]) {
                    return a[2] > b[2]; 
                } else {
                    return a[1] > b[1];
                }
            }
    };

    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        //storing the indexes in their respective vectors as after that we will sort it and sorting will led to mixing of the indexes
        for(int i =0;i<tasks.size();i++){
            tasks[i].push_back(i);
        }
        //sorting
        sort(rbegin(tasks),rend(tasks));
        vector<int> ans;
        long long currTime = tasks.back()[0];
        int size = tasks.size();
        while(ans.size() < size){
            while(!tasks.empty() && tasks.back()[0] <= currTime){
                pq.push(tasks.back());
                tasks.pop_back();
            }
            if(!pq.empty()){
                ans.push_back(pq.top()[2]);
                currTime+=pq.top()[1];
                pq.pop();
            }else{
                currTime = tasks.back()[0];
            }
        }

        return ans;
    }
};