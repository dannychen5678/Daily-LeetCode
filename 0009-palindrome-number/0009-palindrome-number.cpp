class Solution
{
public:
    bool isPalindrome(int x) 
    {
       
        //1.排除掉負數,以及末位為0(0本身為回文)的數字
        if(x<0||(x%10==0&&x!=0))
        {
            return false;
        }
        //2.建立反轉字串=>r*10向右增加一位,個位數字空出來 ,以及x%10取得x最後一位
        int r=0;
        while(x>r)
        {
            r=r*10+x%10;
            x/=10;
        }
        //奇數位的結果會是x<r
        //偶數位的結果會是x==r

        //3.與原始數字做比對,奇跟偶處理方式不同

        //第一層做奇數位還是偶數位判斷,第二層做真實數字的比對
        //奇數位
        if(x<r) 
        {
           if(x==r/10) //r/10與x做比對
           {
            return true;
           }
           else
           {
            return false;
           }
        }
        //偶數位
        else
        {
            if(x==r)
            {
                return true;
            }
            else
            {
                return false;
            }
        }


    }
};