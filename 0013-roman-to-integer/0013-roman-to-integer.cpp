//觀念核心:這題只會發生兩件事,插入得比自己小->增加 插入的比自己大->減少(且只有I,X,C可以,VLDM只能插小的),因為VLDM遵守只能插小的條件所以只要針對IXC插大做處理即可
//ex. I   可以:插比自己小,插比自己大
//ex. V   可以:插比自己小 不會發生:插比自己大(不用管他)
//ex.結論=>兩者皆可:插比自己小 I可以插大,V,所以會有一個判斷式
class Solution
{
public:
    int romanToInt(string s) 
    {
        int sum=0;
        int currentindex;
        int nextcurrentindex;
        //透過位置來比對所以使用vector而非unordered_map
        //vector透過位置來索引值,unordered_map則是透過key
        vector<pair<char,int>>list=
        //pair=>把兩個不同類型的資料綁在一起成為一組完整的資料
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        //我們要透過s[i]在list中的位置來完成數值總和
            //我們不知道s[i]在list裡面的位置,所以要先將s[i]與list每一組資料的key做比對
        for(int i=0;i<s.size();i++) //最外層迭代s[i],內層迴圈迭代list
        {
            //1.先找s[i]實際在list中的位置,是第幾個?
            for(int j=0;j<list.size();j++)
            {
                if(s[i]==list[j].first)//透過與逐個list[j]的key比對(使用first屬性取得list[j] 的key
                {
                   currentindex=j; //如果相同就記錄該位置到一個新的變數,這個變數會當作list的索引,不同繼續找
                   break;
                }
            }
            //2.剛剛找出s[i]list的位置後,先做判別s[i]是否是s最後一個,是的話直接加入總和到sum,
            //並且直接return sum;

            if(i==s.size()-1)
            {
                sum+=list[currentindex].second;
                return sum;
            }
            //3.尚未清楚s[i+1]在list中的位置先取得後才能作判別
            for(int k=0;k<list.size();k++)
            {
                if(s[i+1]==list[k].first)
                {
                    nextcurrentindex=k;
                    break;
                }

            }


            //4.判別s[i+1]在list中的位置是否在s[i]之上,是的話sum-list[currentindex],else 加入sum
            if(currentindex<nextcurrentindex)
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