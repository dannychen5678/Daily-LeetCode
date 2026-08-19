class Solution {
public:
    bool isPalindrome(int x) {
        // 1.負數必不為迴文
        // 2.如果末位為0且本身不為0(0為回文)
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int revertedNumber = 0;
        //不管奇數或偶數只需要處理到中間位數即可(x>r)
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            //*10是為了將現有數字左移一位空出個位數字

            /*
            (奇數處理)
            x=121 r=0 進入loop       
            x=12 r=1 繼續
            x=1 r=12  結束

            x=r/10

            */
            x /= 10;

            /*
            x=1221 r=0 進入loop
            x=122  r=1 繼續
            x=12   r=12 結束

            x=r
            */
        }

        //藉由最終x==r或者x==r/10d判斷是否回文

        // 偶數位數時：兩者應完全相同（例如 1221 -> x=12, revertedNumber=12）
        // 奇數位數時：去掉中間位數後應相同（例如 12321 -> x=12, revertedNumber=123）
        if( x == revertedNumber || x == revertedNumber / 10)
        return true;
        else return false;
    }
};