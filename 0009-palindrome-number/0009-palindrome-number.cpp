 #include <string>
using namespace std;
class Solution 
{
   
public:
    bool isPalindrome(int x) 
    {
        string numbers =to_string(x);
        //先將整數轉成字串,透過引入string library ,然後再使用to_string方法

        //將字串當做陣列去操作

        int n=numbers.length()

        for(int i=0;i<numbers.length()/2;i++)
        {
            if(numbers[i]!=numbers[n-1-i])
            {
                return false;
            }
            
    //逐一比對,如果字元與相對位置的值不同,則return false,1是電腦是從0開始算1,-i是向前移動幾個位置
        }
        return true;
    }
};