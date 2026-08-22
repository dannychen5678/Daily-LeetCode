//1.排除掉負數以及末位為0的數
//2.建立反轉字串
//3.藉由x跟r的關係判斷是否是回文
class Solution
{
public:
    bool isPalindrome(int x)
{
if(x<0||(x%10==0&&x!=0))
{
    return false;
}

int r=0;

//迴圈直到r>x或r==x的時候(x<=r),r>x是位數為奇數時,r==x是位數為偶數時
while(x>r)
{
    r=x%10+r*10; //把x最後一位移到r最後一位
    x/=10;
}

//判斷回文,並且根據r偶數,奇數處理有所不同
//r/10是奇數位數的中間位數本來就是對的所以直接刪掉
if(x==r||x==r/10)
{
    return true;
}
else
{
    return false;
}
}
      
};