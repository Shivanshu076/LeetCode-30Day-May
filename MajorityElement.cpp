/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

// Solution using hashing :

int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])==mp.end()) mp[nums[i]]=1;
            else mp[nums[i]]++;
            if(mp[nums[i]] > nums.size()/2) return nums[i];
        }
        return -1;
    }
    
// Solution using Boyer-Moore Voting Algorithm :

int majorityElement(vector<int>& nums) {
        int a, c=0;
        for(int i=0;i<nums.size();i++){
            if(!c) a=nums[i];
            if(nums[i]==a) c++;
            else c--;
        }
        return a;
    }
