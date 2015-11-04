class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> arr;
        int count = 0, runtime = 0;
        for(int elem:nums)  arr.insert(elem);
        while(arr.size() > 0 && runtime < nums.size()){
            int tmp = *arr.begin();
            int right = tmp + 1;
            int left = tmp - 1;
            arr.erase(tmp);
            int mycount = 1;
            runtime ++;
            while(arr.find(right) != arr.end()){
                arr.erase(right++);
                mycount ++;
                runtime ++;
            }
            while(arr.find(left) != arr.end()){
                arr.erase(left--);
                mycount ++;
                runtime ++;
            }
            if(mycount > count) count = mycount;
        }
        return count;
    }
};
