class Solution {
public:
    bool isPalindrome(int x) 
    {
     
     if(x<0)return false;
     if(x==0)return true;   //不斷/10的方法會排除掉0所以要額外設立條件
     int count=0;
     int temp;
     temp=x; //x賦值給temp

     while(temp!=0)//計算位數(不知道迴圈次數所以用while)
     {
        temp/=10;
        count++;
     }

     vector<int>nums(count);//知道幾位之後,代表我們知道大小了所以宣告一個動態陣列(大小由剛剛得出的count所決定)

     temp=x;//將temp內容從新初始化並且一樣從新賦值x
     
     for(int i=count-1;i>=0;i--)//將temp的數字由後往前賦給容器nums,使用for迴圈
     {
        nums[i]=temp%10;//取最後一位(%10的餘數除法)
        temp/=10;//捨棄最後一位
     }
     for(int j=0;j<count;j++)//使用nums本身的索引不同完成 ex.長度3但實際到索引2
     {
        if(nums[j]!=nums[count-1-j])//與nums自身作比對即可
        {
            return false;
        } 
     
     }
     return true;

    }
};