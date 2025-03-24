// SOLUTION 1:- CALCULATING THE BUSY DAYS AND RETURNING BY SUBSTARCTINNG THAT FROM TOTAL DAYS

// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         int prevEnd = 0;
//         int busyDay = 0;
//         //sorting the mettings array
//         sort(meetings.begin(), meetings.end());
//         for(int i=0;i<meetings.size();i++){
//             int start = meetings[i][0];
//             int end = meetings[i][1];
//             if(end <= prevEnd){
//                 continue;
//             }
//             if(start <= prevEnd){
//                 start = prevEnd+1;
//             }
//             busyDay+=(end-start)+1;

//             prevEnd = max(prevEnd,end);
//         }

//         return (days-busyDay);
//     }
// };

// SOLUTION 2:- ONLY CALCULATING THE FREE DAYS

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int prevEnd = 0;
        int result = 0;
        //sorting the mettings array
        sort(meetings.begin(), meetings.end());
        for(auto &meet: meetings){
            // jadi gote meeting ra start date prevEnd date thu adhika achionly then hni ta bhitare gap rahiba
          if(meet[0]>prevEnd){
            result+=meet[0]-prevEnd-1;
          }
          //ab max end date nikal lo age kaam ayega
          prevEnd = max(prevEnd,meet[1]);
        }

        //last me ek edge case dekhlo ki pura end meeting ka date kya total days se chota hai agar hmm to hame free days add karne honge result me
        if(prevEnd < days){
            result+=(days-prevEnd);
        }

        return result;
    }
};