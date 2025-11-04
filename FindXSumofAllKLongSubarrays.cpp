#include <bits/stdc++.h>

using namespace  std;

class Solution {
  public:
      vector<int> findXSum(vector<int>& nums, int k, int x) {
          vector<int>res;
          int n = nums.size();
          for(int i = 0; i < n-k+1; i ++){

              map<int, int, greater<int>> mp;
              int sum = 0;

              for(int j = 0; j < k; j ++){
                  mp[nums[i+j]] +=1;
              }

              multimap<int, int, greater<int>> mp1;
              for(auto it:mp){
                  mp1.insert({it.second, it.first});
              }



              int cnt = 0;
              for(auto t:mp1){
                  if(cnt == x){
                      break;
                  }

                  sum += t.first * t.second;
                  cnt ++;
              }

              res.push_back(sum);

              // cout << res[0] << "\n";
          }
          return res;
      }
  };
