/*  insert 1, remove 2, insert 2, getRandom, remove 1, insert 2, getRandom
 *  
 *  insert , remove O(1)  -> hash map
 *  getRandom in O(1)?
 *  -> we want to do this: arr[rand() % size]
 *  -> use hash map <val, index in arr>
 *  case insert:
 *      just push_back
 *  case remove:
 *      pop_back is O(1) -> find the val want to del
 *      -> <val, idx> swap (idx, end_idx_of_arr)
 *      -> pop_back
 *
 *  insert 1 ->   (1, 0)
 *  remove 2 ->   false
 *  insert 2 ->   map = [(1, 0), (2, 1)]  , arr = [1, 2]
 *  getRandom ->  return arr[i]
 *  remove 1 ->   (1, 0) => arr[0] would be deleted => swap(arr[0], arr[1]) => pop_back arr = [2]
 *                       => update hash_map:  map = [(2, 0)]
 */
#include <cstdlib>
#include <unordered_map>
#include <vector>

class RandomizedSet{
private:
    std::unordered_map<int, int> umap; // <val, idx>
    std::vector<int> valList;   //store val
public:
    RandomizedSet(){}

    bool insert(int val){
        if(umap.find(val) == umap.end()){
            valList.push_back(val);
            umap[val] = valList.size() - 1;
            return true;
        }
        return false;
    }
    bool remove(int val){
        auto it = umap.find(val);
        if(it == umap.end()){
            return false;
        }
        umap[valList.back()] = it->second; //update hash_map
        valList[it->second] = valList.back();  //update arr
        valList.pop_back();
        umap.erase(it);
        return true;
    }
    int getRandom(){
        return valList[std::rand() % valList.size()];
    }
};
