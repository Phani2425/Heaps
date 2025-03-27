class Solution {
public:
    using p = pair<int,int>; 
    struct Compare {
      bool operator()(p& a, p& b){
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int & i : nums){
            mp[i]++;
        }
        priority_queue<p,vector<p>,Compare> pq;
        for(p pr : mp){
            if(pq.size()<k){
                pq.push(pr);
            }
            else{
                if(pr.second > pq.top().second){
                   pq.pop();
                   pq.push(pr);
                }
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};

// think if we needed to find the k most frequent elements then we should have used max heap for finding k elements with highest frequency but why did we use min heap???

//ans:-  to maintain the size of heap to k and this leads to lower time and space complexity

//PATTERN:- JETEBELE BI K SMALLEST OR K LARGEST BAHARA KARIBARA THIBA OR KTH SMALLEST OR KTH LARGEST BAHARA KARIBARA THIBA THE ALAWAYS USE MAX HEAP IF IT IS SMALLEST AND USE MIN_HEAP IF IT IS LARGEST

//BY THIS WE CANS SAVE SOME SPACE AND COMPUTATIONAL TIME 