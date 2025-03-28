class Solution {
public:
typedef pair<int,vector<int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p,vector<p>> pq;
        vector<vector<int>> ans;

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum = nums1[i] + nums2[j];
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if(sum < pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    // optimisation due to sorted behaviour of array
                    //if sum of current pair is greater than the sum of pair present in the top of the queue setebele inner loop break karija as apar nums2[j] ra value ahuri badhi badhi jiba
                    break;
                }
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};

// ye heap ra standard question like finding kth smallest , kth largest, k no of smallest or largest etc
//in this type of problem jadi tora mane achi then ame max_heap use karuthile for finding smaller elements and min_heap use karuthile for finding larger element and this method was optimising the space complexity very well as ion this method the size of the priority queue will never exceed than k

//ok so ame ethore ei method use karidaba..but is this enough??   jadi normal ei method use karibara thila then kn pain array sorted achi???

//kichi ta achi jouthuipain se array ku sorted kariki deichanti..........is there any optmisation with the sorted array???

//yes ofcourse ..tu nije bhabe ame max_heap ethipain nau ki ame jadi gote element ku process karuche then at that point jadi se element [or the sum in this case] is less that the top elemnt of the queue then we will pop the top element and push the new one into the queue

//and is the current element is grater than the top of queue the we dont do anything as there our intention was to find the k minimum elements

//so here as we have to take nested loop so at somepoint if sum of 2 elements at index i and j is greater then the sum of pair present at the top of max_heap then we will dont do anything as we are trying to find the minimum sum pairs....... so if this happen then tu nije bhabe kn tu j ku gaaku badheiba darkar???

//bcs array ta sorted au ebethu jadi sum,  top ra sum thu adhika hauchi then j ku agaku badheile ta sum ra vallue ahuri adhika haba na??  so ame kn kariba na ei case re inner loop break karidaba au next i ku move karijiba

//ei small optimisation will make our code to get accepted