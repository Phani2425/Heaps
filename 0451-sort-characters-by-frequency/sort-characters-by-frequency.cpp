class Solution {
public:
    //this typedef thing also needed to be remembered
    //except this we can also use the using keyword like :- using p = pair<char,int> (modern)
    typedef pair<char,int> p;
    struct Comparator {
        bool operator()(p a, p b) {
            return a.second < b.second; 
        }
    };
    string frequencySort(string s) {
        //i had forgetten about how the comaprator passes in a priority_queue
        priority_queue<p,vector<p>,Comparator> pq;
        unordered_map<char,int> mp;
        for(char & c : s){
            mp[c]++;
        }
        //I HAD FORGETTEN THAT MAP STORES KEY VALUE IN PAIRS

        //i had forgeten that pq have simillar syntax as the stack :- push,pop,top etc
        for(auto & pr : mp){
            pq.push(pr);
        }

        int index = 0;
        while(!pq.empty()){
           p top = pq.top();
           while(top.second--){
            s[index++] = top.first;
           }
           pq.pop();
        }

        return s;

    }
};