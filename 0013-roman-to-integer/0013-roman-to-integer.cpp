//觀念核心:這題只會發生兩件事,插入得比自己小->增加 插入的比自己大->減少(且只有I,X,C可以,VLDM只能插小的),所以其實只有一個插入的會比自己大並減少的特殊條件
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