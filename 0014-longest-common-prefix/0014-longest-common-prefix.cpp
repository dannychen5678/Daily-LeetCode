//寫一個函式去找出字串陣列中的最長的共同前綴字串,如果沒有共同前綴,回傳空字串 

//1.先記錄第一個索引到的字串
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
       
        //先透過陣列大小找出需要迭代的外層陣列次數

        //int strslength=sizeof(strs)/sizeof(strs[0]);=>strs是vector不是傳統c++陣列,所以用.size取得長度
        int strslength=strs.size();
        std::string prefix=strs[0] ;//把strs[0]當成prefix
        for(int i=1;i<strslength;i++)
        {
             bool different=false;
            //2.內層迴圈做字串單獨索引
            for(int j=0;j<strs[i].length();j++)
            {
               //prefix比strs[i]還短的情況,prefix會超出邊界
               /*
               if(prefix.length()<strs[i].length())
               {
                break;//直接換下一個strs[i]
               }
               */
               if(j>prefix.length()-1)
               {
                different=true;
                break;
               }
               if(prefix[j]!=strs[i][j])
               {
                prefix=prefix.substr(0,j);//擷取包含0但不包含j的值
                different=true;
                break;
               }
            } 
            //如果prefix比strs[i]還長(上面迴圈值run完),並且strs[i]==prefix,prefix應該改成strs[i]
            if(different==false)
            {
                prefix=strs[i];
            }
        }
        return prefix;
    }
};