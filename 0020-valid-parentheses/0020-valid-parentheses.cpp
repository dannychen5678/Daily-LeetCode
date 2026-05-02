#include<vector> //動態陣列容器
#include<unordered_map>//使用hash table
class Solution
//當右括號進來時必須與最後的左括號配對,如果相同則return true,不同則return false
//當右括號進來時,如果沒有剩餘左括號則return false
{
public:
    bool isValid(string s) 
    {
        vector<char> temp;//用來暫時儲存左括號
        unordered_map<char,char>bucket
        {
            {'(',')'},
            {'[',']'},
            {'{','}'},
        };
        for(int i=0;i<s.length();i++)
        {
        
           if(s[i]=='('||s[i]=='['||s[i]=='{') //左括號處理
           {
             temp.push_back(s[i]);//丟入臨時陣列
           }
           else
           {
              if(temp.size()>0&&bucket[temp[temp.size()-1]]==s[i])
              //檢查temp為空發生的時間點是右括號要配對時,所以是在else裡面檢查
              {
                temp.pop_back(); //移除最後一個左括號
              }
              else
              {
                return false;
              }
           }
        }
        return temp.empty();
    }
};