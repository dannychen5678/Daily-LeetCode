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

//迴圈裡面要先處理prefix先跑完的情況=>ex.prefix:flow strs[i]:flower
//接著處裡正常情況prefix比strs[i]還長,或是相等長度
//而正常情況又分為:strs[i]與prefix都比對無誤,以及中途確實有不同
/*
ex.

中途有不同=>
prefix:flower
strs[i]:flowx

都相等=>
prefix:flower
strs:flow

處理順序是中途有不同以然後才是都相等

中途有不同就是索引到不相同的字元的前一個位置然後當作prefix
都相同就是prefix不變
*/