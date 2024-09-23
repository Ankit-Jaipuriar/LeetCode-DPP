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
        for(int k=0;k<neg.size();k++){
            if(k<nums.size()){
                nums.insert(nums.begin()+j,neg[k]);
            }else{
                nums.push_back(neg[k]);
            }
            j+=2;
        }
        return nums;
    }
};