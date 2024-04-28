#include <vector>

/*
 *
 * (73, 0)  ->   74  pop() 1 - 0 = 1 for 73 -> push 74 -> (74, 1) -> 75 pop() 2 - 1 = 0 for 74 -> push 75
 *
 * (75, 2) -> push 71 ->  (71, 3)   ->  push 69   ->  (69, 4)   ->   72 pop()  69: 5 - 4 = 1, pop() 71: 5 - 3 = 2 
 *                        (75, 2)                     (71, 3)
 *                                                    (75, 2)
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> stack;
        vector<int> res(size, 0);
        for(int i = 0; i < size; i++){
            while(!stack.empty() && temperatures[i] > temperatures[stack.back()]){
                res[stack.back()] = i - stack.back();
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return res;
    }
};