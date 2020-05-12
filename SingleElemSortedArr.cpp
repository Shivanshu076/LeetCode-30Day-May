/*
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.
Your solution should run in O(log n) time and O(1) space.
*/

//Solution using Binary search :

int singleNonDuplicate(vector<int>& nums) {
    int l=0, h=nums.size()-1;
    if(!h) return nums[h];
    while(l<=h){
        int m=(l+h)/2;
        if(!(m%2)){
            if(nums[m]==nums[m+1]){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        else{
            if(nums[m]==nums[m+1]){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
    }
    return nums[l];
}
