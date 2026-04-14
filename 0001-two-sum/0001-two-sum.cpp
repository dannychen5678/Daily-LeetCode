class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. 建立哈希表
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }

        // 2. 尋找補數
        for (int j = 0; j < nums.size(); j++) {
            int complement = target - nums[j]; // 這裡原本寫成 i，應改為 j

            // 檢查 complement 存在，且不是原本自己這個元素
            if (hash.find(complement) != hash.end() && hash[complement] != j) {
                return {j, hash[complement]};
            }
        }

        return {}; // 找不到時回傳空陣列，這行要放在迴圈外面
    } // 這裡要關閉 twoSum 函數
}; // 這裡才是關閉 Solution 類別