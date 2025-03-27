// class Solution {
// public:
//     int minimumIndex(vector<int>& nums) {
//        unordered_map<int,int>mp;
//        int maxFreq = 1;
//        int num;
//         for (int n : nums) {
//             mp[n]++;
//             if (mp[n] > maxFreq) {
//                 num = n;
//                 maxFreq = mp[n];
//             }
//         }

//        int count = 0;
//        for(int i=0;i<nums.size();i++){
//         if(nums[i]==num){
//             nums[i] = ++count;
//         }else{
//             nums[i] = count;
//         }
//        } 

//       int start = 0;
//       int end = nums.size()-1;
//       int ans = -1;

//       while(start <= end){
//         int mid = start + (end-start)/2;

//         if(nums[mid] > (mid+1)/2 && nums.back()-nums[mid] > (nums.size()-mid-1)/2  ){
//             //store answer and go to left
//             ans = mid;
//             end = mid-1;
//         }
//         else if(nums[mid] > (mid+1)/2 && nums.back()-nums[mid] <= (nums.size()-mid-1)/2){
//             // go left
//             end = mid-1;
//         }
//         else if(nums[mid] <= (mid+1)/2 && nums.back()-nums[mid] > (nums.size()-mid-1)/2){
//             //go right
//             start = mid+1;
//         }else{
//             break;
//         }

//       }

//       return ans;

//     }
// };

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
       unordered_map<int,int>mp;
       int maxFreq = 1;
       int num;
        for (int n : nums) {
            mp[n]++;
            if (mp[n] > maxFreq) {
                num = n;
                maxFreq = mp[n];
            }
        }

      int count = 0;
      for(int i =0 ;i<nums.size();i++){
       if(nums[i] == num){
        count++;
       }
       if(count > (i+1)/2 && maxFreq-count > (nums.size()-i-1)/2 ){
         return i;
       }
      }

      return -1;

    }
};