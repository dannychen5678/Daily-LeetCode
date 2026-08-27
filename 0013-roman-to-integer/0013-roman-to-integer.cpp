//透過值的大小來解

class Solution
{
public:
    int romanToInt(string s)
    {
      //使用hash表
      unordered_map<char,int> list
      {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000},
      };
      int sum=0;
      //1.判斷s[i]是否是s中最後一個
      for(int i=0;i<s.length();i++)
      {
        if(i==s.length()-1)
        {
            sum+=list[s[i]];
            break;
        }
        
        //2.判斷s[i+1]的值是否>s[i]

        else if(list[s[i+1]]>list[s[i]])
        {
            sum-=list[s[i]];
        }
        else
        {
            sum+=list[s[i]];
        }
        
      }
      return sum;
    }
};