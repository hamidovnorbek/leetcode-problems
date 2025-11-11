class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int res = 0;
        for(auto it:nums){

            while(!s.empty() && s.back() > it){
                s.pop_back();
            }

            if(it == 0) continue;
            if(s.empty() || s.back() < it){
                res ++;
                s.push_back(it);
            }
        }

        for(auto it:s) cout <<  it << " ";

        return res;
    }
};
