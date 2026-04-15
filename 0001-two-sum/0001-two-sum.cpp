class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 1. 建立哈希表
        unordered_map<int, int> hash; //第一個int是key,第二個int是value
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i; //hash表的key是nums的值,而他的value是i
        }

        // 2. 尋找補數
        for (int j = 0; j < nums.size(); j++) {
            int complement = target - nums[j]; //先找出當前number的補數

            // 透過find方法查找complement是否是hash表裡的一個項目或是key
            //加入!=hash.end()是為了確保find沒有找到東西時不會崩潰=>==hash.end()代表沒有找到東西傳FALSE,!=hash.end()代表有找到東西,complement是真實存在的傳true,且find是回傳一個記憶體位址,而if只能接收true或flase所以還需要!=hash.end()讓他成為條件式
            if (hash.find(complement) != hash.end() && hash[complement] != j) {
                return {j, hash[complement]};
            }
        }

        return {}; // 找不到時回傳空陣列，這行要放在迴圈外面
    } // 這裡要關閉 twoSum 函數
}; // 這裡才是關閉 Solution 類別