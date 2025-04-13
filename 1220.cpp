class Solution { 
public:
    // 定義 `twoSum` 函數，用來找到數組中兩個數的索引，使它們的和等於目標值 `target`
    vector<int> twoSum(vector<int>& nums, int target) {
        // 獲取數組的長度 `n`
        int n = nums.size();

        // **外層迴圈**
        // 遍歷數組中的每個元素，作為第一個數
        for (int i = 0; i < n - 1; i++) {

            // **內層迴圈**
            // 從 `i + 1` 開始，遍歷數組中剩餘的元素，作為第二個數
            for (int j = i + 1; j < n; j++) {

                // 檢查兩個數字的和是否等於目標值
                if (nums[i] + nums[j] == target) {

                    // 如果找到符合條件的兩個數，返回它們的索引
                    return {i, j};
                }
            }
        }

        // 如果整個數組中沒有找到符合條件的數對，返回一個空的數組
        // （實際不會到這一步，因為題目保證至少有一個解）
        return {};
    }
};



class Solution { 
public:
    // 函數 `twoSum` 用來找到數組中兩個數的索引，使它們的和等於目標值 `target`
    vector<int> twoSum(vector<int>& nums, int target) {
        // 使用 `unordered_map` 來存儲數組中的數字及其對應的索引
        unordered_map<int, int> numMap;

        // 獲取數組的大小
        int n = nums.size();

        // **第一個迴圈：構建哈希表**
        // 這個哈希表將數組的數值作為鍵，索引作為值
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }

        // **第二個迴圈：尋找目標值的補數**
        for (int i = 0; i < n; i++) {
            // 計算補數：目標值減去當前數字
            int complement = target - nums[i];
            
            // 檢查補數是否存在於哈希表中，且不是當前數字本身
            if (numMap.count(complement) && numMap[complement] != i) {
                // 如果找到，返回當前索引和補數的索引
                return {i, numMap[complement]};
            }
        }

        // 如果沒有找到解，返回一個空的數組
        return {};
    }
};



class Solution { 
public:
    // 定義 `twoSum` 函數，目的是找到兩個數的索引，使它們的和等於目標值 `target`
    vector<int> twoSum(vector<int>& nums, int target) {
        // 定義一個 `unordered_map`（哈希表），用於存儲數字及其索引
        // 鍵為數字，值為該數字在數組中的索引
        unordered_map<int, int> numMap;

        // 獲取數組的長度 `n`
        int n = nums.size();

        // 遍歷數組
        for (int i = 0; i < n; i++) {
            // 計算補數：目標值減去當前數字
            int complement = target - nums[i];

            // 在哈希表中查找補數是否已經存在
            if (numMap.count(complement)) {
                // 如果補數存在，返回補數的索引和當前數字的索引
                return {numMap[complement], i};
            }

            // 如果補數不存在，將當前數字和索引存入哈希表
            numMap[nums[i]] = i;
        }

        // 如果沒有找到符合條件的兩個數，返回一個空的數組（理論上不會到這裡，因為題目保證至少有一個解）
        return {};
    }
};
