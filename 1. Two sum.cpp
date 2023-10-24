/*
 Given an array of integers, return indices of the two numbers such that they add up to a 
 specific target. Note that you cannot use the same element in the array twice, but you can assume 
 that there will only be one solution for each test case.
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int size=nums.size();
        int diff;
        unordered_map<int, int>m;
        for(int i = 0; i < size; i++)
        {
            diff = target - nums[i];
            if(m.find(diff) != m.end() && m.find(diff)->second !=i)
            {
                ret.push_back(i);
                ret.push_back(m.find(diff)->second);
                return ret;
            }
            m[nums[i]]=i;
        }
        return ret;
    }
};