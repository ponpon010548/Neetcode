#include <iostream>
#include <unordered_map>
#include <vector>
/* cnt freq -> O(n)
 *find top k -> O(n)
 *time: O(n)
 *space: O(n)
 *
 */

class Solution{
    public:
        std::vector<int> topKFrequent(std::vector<int> &nums, int k){
            std::unordered_map<int, int> umap;
            std::vector<std::vector<int>> bucket(nums.size() + 1);
            std::vector<int> res;
            for(int &n :nums){
                umap[n]++;
            }
            for(auto &p: umap){
                bucket[p.second].push_back(p.first);
                cout << p.second << endl;
            }
            for(int i = bucket.size() - 1; i >= 0; i--){
                int sz = bucket[i].size();
                if(k > 0 && sz){
                    k -= sz;
                    for(int &j: bucket[i]){
                        res.push_back(j);
                    }
                }
            }
            return res;
        }
};
