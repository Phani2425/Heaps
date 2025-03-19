class Solution {
public:
    int minOperations(vector<int>& nums) {
        int flipCount = 0;
        int resultFlips = 0;
        vector<bool> isFlipped(nums.size(),false);

        for(int i=0;i<nums.size();i++){
            if(i>=3 && isFlipped[i-3]==true){
                flipCount--;
            }
            //applying the flipscounts
            if(flipCount%2 == nums[i]){
                //yani flip to hogaa ye
                //par usse pehle check karlo ki iske age aur 2 element hai ya nehi ...agar nehi hai then to bhai -1 return kardo kyu ki jitan bhi kosis karlo iske har bit ko tum set nehi kar paoge
                if(i+3 > nums.size()){
                    return -1;
                }
                isFlipped[i]=true;
                flipCount++;
                resultFlips++;
            }
        }

        return resultFlips;
    }
};