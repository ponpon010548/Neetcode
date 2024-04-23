#include "Interval.h"
#include <vector>
#include <algorithm>
/*  s    e
 *  ------
 *     -----------------
 *    s                e
 * if all intervals are sorted:
 *  Any interval that its end > other's start, then they are overlapping
 *
 * Time: sorting O(nlogn) + scan all intervals O(n) -> O(nlogn)
 * space: sorting O(logn)
 */
bool intervalCmp(const Interval &I1, const Interval &I2){
    return I1.start < I2.start;
}
class Solution {
public:
    bool canAttendMeetings(std::vector<Interval>& intervals) {
        if(intervals.size() == 0){
            return true;
        }
        std::sort(intervals.begin(), intervals.end(), intervalCmp);
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i].end > intervals[i + 1].start){
                return false;
            }
        }
        return true;
    }
};
