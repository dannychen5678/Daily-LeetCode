//雙指針邊界掃描
//使用一個變數j用於紀錄當前正確位置,如果字元比對正確j+1
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
       if(strs.empty()) return "";

       std::string prefix=strs[0];

       for(int i=1;i<strs.size();i++)
       {
        int j=0;
        while(j<prefix.length()&&j<strs[i].length()&&prefix[j]==strs[i][j])
        {
            j++;
        }
        prefix=prefix.substr(0,j);

        if(prefix.empty()) return "";
       }

       return prefix;
    }
};