// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Solution using hashing :

int findMaxLength(vector<int>& nums) {
        int cnt = 0;
        unordered_map<int,int> m;
        unordered_map<int,int>::iterator it;
        m[0] = -1;
        int max_len = INT_MIN;
        for(int i=0;i<nums.size();i+=1) {
            cnt+= nums[i]?1:-1;
            it = m.find(cnt);
            if(it!=m.end()) {
                max_len = max(max_len, i - it->second);
            }else {
                m.insert(make_pair(cnt,i));
            }
       }
       if(max_len == INT_MIN) return 0;
       else return max_len;
    }
