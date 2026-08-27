class Solution 
{
public:
    int romanToInt(string s)
    {
        vector<pair<char,int>> list
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int currentindex;
        int sum=0;
        int nextindex;

        //1.找出s[i]在list中的位置,並記錄他的位置=>外層迴圈迭代s[i],內層迴圈迭代list[j]
        for(int i=0;i<s.length();i++)
        {
            for(int j=0;list.size();j++)
            {
                if(s[i]==list[j].first)
                {
                    currentindex=j;
                    break;
                }
            }
            //2.判斷s[i]是否是s的最後一個
            if(i==s.length()-1)
            {
                sum+=list[currentindex].second;
                return sum;
            }

            //3.取得s[i+1]在list中的位置
            for(int k=0;k<list.size();k++)
            {
                if(s[i+1]==list[k].first)
                {
                    nextindex=k;
                    break;
                }
            }
            
            //4.判斷s[i+1]在list中的位置是否>s[i]在list中的位置
            if(nextindex>currentindex)
            {
                sum-=list[currentindex].second;
            }
            else
            {
                sum+=list[currentindex].second;
            }
        }
        return sum;
    }
};