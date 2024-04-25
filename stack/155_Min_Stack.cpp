#include <vector>
/* stack -> normal stack
 * findMin stack -> a stack to record min_val
 * ex: 2, 3, 1, pop, pop, 5
 *                      3
 *   2       2     ->   2        2      here, we don't push 3 into findMin,
 * stack  findMin      stack   findMin  because 3 is greater than 2.
 *
 *  1                        pop()->1
 *  3         1            3
 *  2         2      ->    2       2        if we want to pop(x), we have to check whether
 * stack    findMin      stack   findMin    x is findMin.top() or not
 *
 *    pop()->3             5
 *   2        2      ->    2        2
 * stack   findMin       stack   findMin
 *
 *  Time Complexity: push O(1), pop O(1), top O(1), getMin O(1)
 *  Space Complexity: O(2n) -> O(n)
 */
class MinStack{
private:
    std::vector<int> stack, findMin;
public:
    MinStack(){

    }
    void push(int val){
        stack.push_back(val);
        if(findMin.empty()){
            findMin.push_back(val);
        }
        else if(findMin.back() >= val){
            findMin.push_back(val);
        }
    }
    void pop(){
        int val = stack.back();
        stack.pop_back();
        if(val == findMin.back()){
            findMin.pop_back();
        }
    }
    int top(){
        return stack.back();
    }
    int getMin(){
        return findMin.back();
    }
};
