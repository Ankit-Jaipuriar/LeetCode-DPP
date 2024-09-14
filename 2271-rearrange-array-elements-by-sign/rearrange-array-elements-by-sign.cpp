class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg;
        int index=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                neg.push_back(nums[i]);
            }else{
                nums[index++]=nums[i];
            }
        }
        nums.resize(index);
        int j=1;
        for(int i=0;i<neg.size();i++){
            if(j<nums.size()){
                nums.insert(nums.begin()+j,neg[i]);
            }else{
                nums.push_back(neg[i]);
            }
            j+=2;
        }
        return nums;
    }
};