#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // 1. 建立對應表（記得分號）
        unordered_map<char, char> bracket = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        
        vector<char> temp;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                temp.push_back(s[i]);
            } 
            else {
                if (temp.empty()) return false;
                
                // 比對最後一個進入的左括號所對應的右括號
                if (s[i] != bracket[temp[temp.size() - 1]]) {
                    return false;
                } 
                temp.pop_back(); 
            }
        }

        // 這裡是最精簡的寫法：如果空的就回傳 true，否則 false
        return temp.empty(); 
    } // <--- 這是結束 isValid 函式的括號
}; // <--- 這是結束 class Solution 的括號與分號