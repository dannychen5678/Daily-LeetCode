//1.判斷是否是I,X,C其中一個,不是的話加入該符號數字到總和,並且索引到下一個位置
//2.如果是其中一個的話(I,X.C)判斷他們下一個位置的符號是否是相減為4開頭或9開頭的符
//ex.判斷I->V或者I->X?
//3.是的話減掉該符號代表數字,不是的話加入當前索引到符號的數字到總和即可,然後繼續索引下一個符號直到所有符號檢查完畢
class Solution
{
public:
    int romanToInt(string s) 
    {
        int sum=0;
        
        unordered_map<char,int>list=
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        //為每個符號標明其數字(用一張表紀錄全部),宣告list且裡面存放I,V,X,L,C,D,M即各自代表數字
        for(int i=0;i<s.length();i++) 
        //這裡原本寫s.length-1->x 應該是s.length()
        //以及陣列從0開始所以索引不會到length=> i<length或是i<=length-1
        {
            if(s[i]=='I'||s[i]=='X'||s[i]=='C')
            {
             if(i==s.length()-1) 
             //s[i+1]==null=>s[i+1]本身必須先是合法範圍才能跟null做比較,如果本身不合法的話,就是非法存取會直接報錯

             //i==s.length()-1代表我們檢查i是否剛好是s的最後一個元素
             {
                sum+=list[s[i]];
                return sum;
             }

             if(s[i]=='I')
             {
                if(s[i+1]=='V'||s[i+1]=='X')
                {
                    sum-=list[s[i]];
                }
                else
                {
                    sum+=list[s[i]];
                }
             }   
            else if(s[i]=='X')
             {
                if(s[i+1]=='L'||s[i+1]=='C')
                {
                    sum-=list[s[i]];
                }
                else
                {
                    sum+=list[s[i]];
                }
             }  
              else if(s[i]=='C')
             {
                if(s[i+1]=='D'||s[i+1]=='M')
                {
                    sum-=list[s[i]];
                }
                else
                {
                    sum+=list[s[i]];
                }
             }  
            }
            else //如果是V,L,D,M
            {
                sum+=list[s[i]];
            }
        }
        return sum;
    }
};