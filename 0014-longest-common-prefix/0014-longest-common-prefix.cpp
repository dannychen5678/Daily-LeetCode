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

//三種情況
/*
ex.

超出邊界情況=>
prefix比strs[i]早結束=>prefix維持原先不動,還是strs[0]。,因為這樣代表prefix的字元都與strs[i]相同而題目球的是最常共同前綴子串,所以維持原先即可

中途有不同=>
prefix:flower
strs[i]:flowx

都相等=>
prefix:flower
strs:flow

處理順序是中途有不同以然後才是都相等

中途有不同就是索引到不相同的字元的前一個位置然後當作prefix
都相同的就是prefix要改成strs[i]=>更新新的prefix成strs[i]

處理順序優先級=>
1.超出邊界情形
2.中途不同
3.都相等
*/

/*
步驟
1.取得字串vector大小透過.size()=>
判斷是甚麼資料型態=>array? vector?

array=>透過sizeof(strs)/sizeof(strs[i])

vector=>透過.size()方法

2.vector第一個當成prefix
=>std::string prefix=strs[0];

3.透過flag來監控事件當下的狀態,初始狀態是false

3.迭代vector(容器)中的元素,直到strs.length()-1結束

4.迭代每一個元素(字串)中的每一個字元

**5.處理超出邊界情形(i>prefix本身)=>prefix不變

**6.處理不同字元情形=>j位置之前的字串設為新的prefix

**7.比對都相同(strs[i]與prefix)=>strs[i]當作新的prefix

8.都結束後最後跳出迴圈return新的prefix

*/


