#include <vector>
/*
           2
    3              4
5        1       6    0

headId = 2
manager = [4, 3, -1, 2, 2, 3, 4]
informTime = [1, 1, 1, 1, 1, 1, 1]

0: 
1: 
2: 3 -> 4 
3: 1 -> 5
4: 0 -> 6
5:
6:

*/

class Solution {
private:
    void dfs(std::vector<std::vector<int>> &adjList, std::vector<int>& informTime, int v, int &t_max, int t){
        if(adjList[v].size() == 0){
            t_max = max(t_max, t);
            return;
        }
        t += informTime[v];
        for(int &u: adjList[v]){
            dfs(adjList, informTime, u, t_max, t);
        }
    }
public:
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime) {
        std::vector<std::vector<int>> adjList(n); //<mag, employee>
        int t_max = 0;
        for(int i = 0; i < n; i++){
            if(manager[i] != -1){
                adjList[manager[i]].push_back(i);
            }
        }
        dfs(adjList, informTime, headID, t_max, 0);
        return t_max;
    }
};