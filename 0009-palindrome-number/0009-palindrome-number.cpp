class Solution 
{
public:
    bool isPalindrome(int x)
    {
        if(x<0) return false; //處理負數 
        if(x==0) return true;//0本身也是回文
        int count=0;
        int temp=x;    //宣告temp暫存x,為了不破壞原本x    
        while(temp!=0)
        {
         temp/=10;//計算位數
         count++;
        }
        vector<int>nums(count);//宣告動態陣列用於比對
        temp=x;//重新初始化temp
        for(int i=count-1;i>=0;i--)//將temp內容複製到nums
        {
            nums[i]=temp%10;
            temp/=10;
        }
        for(int i=0;i<count/2;i++) //進行比對(使用自身nums陣列即可)
        {
          if(nums[i]!=nums[count-1-i])//nums最後一個count-1
          {
            return false;
          }
        }
        return true;

    }
};
//確定array長度
//取得總長度一半的元素到新array
//逐項比對