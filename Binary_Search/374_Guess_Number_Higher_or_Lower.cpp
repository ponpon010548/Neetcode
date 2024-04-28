class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid, res;
        while(left <= right){
            mid = left + ((right - left) >> 1);
            res = guess(mid);
            if(res == 0){
                return mid;
            }
            if(res == -1){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};