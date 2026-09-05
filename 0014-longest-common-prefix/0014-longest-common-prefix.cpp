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

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        std::string prefix=strs[0]; //第一元素當成prefix,並且她是字串
        bool different=false;//宣告flag紀錄當前狀態,原始狀態為false
        //different的意思應該是有沒有找到不同的字元
        for(int i=1;i<=strs.size()-1;i++)   //迭代每一個strs元素
        {
              different=false;//每一輪的different初始化為原始狀態
            for(int j=0;j<strs[i].length();j++)//迭代每一個strs[i]元素
            {
               if(j>prefix.length()-1)//處理超出prefix邊界情況
               {
                 
                 break;
               } 
                if(prefix[j]!=strs[i][j])//處理prefix與strs[i][j]不同的情況
                {
                    prefix=prefix.substr(0,j);//prefix裁切為j之前位置的字串
                    different=true; //變更flag狀態=>
                    break;
                } 
            }
             if(different==false&&strs[i].length()<prefix.length()) //處理str[i]與prefix完全相同,str[i]可能比prefix還短也有可能相同
                {
                   prefix=strs[i];//prefix設為strs[i
                }
        }
        return prefix;




    }
};