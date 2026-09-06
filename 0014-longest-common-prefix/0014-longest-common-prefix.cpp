class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
     std::string prefix=strs[0];//第一個strs[0]設為前綴 
            
     int strslength=strs.size();//取得strs的大小用於跌代=>vector使用.size()

     bool different=false;//使用flag用於監控狀態=>三種情況

     if(strs.empty())return "";//檢測strs是否為空,為空的話直接回傳空字串

    for(int i=1;i<strslength;i++) //開始跌代strs元素
    {
       different=false;//每次都要初始化different

    for(int j=0;j<strs[i].length();j++)//跌代strs[i]裡的每個元素,字元。
    {
        if(j>prefix.length())//第一種情況prefix比strs提早結束
        {
            break;//換到下一個strs[i],前綴不變且狀態也維持不變(different),前綴維持當前prefix
        }

        if(prefix[j]!=strs[i][j])
        {
        //第二種情況prefix與strs[i]中途有不同,prefix設為j索引到最後相同位置的部分,並且更新狀態
        prefix=prefix.substr(0,j);//是用prefix,因為他才是完整字串

        different=true;//更新狀態

        }
    }
    //最後一種情況=>當j都順利跌代完後(strs[i]<prefix[j])
       if(strs[i].length()<prefix.length())
       {
        prefix=strs[i];
       }
    }
    return prefix; //回傳prefix
    }
};