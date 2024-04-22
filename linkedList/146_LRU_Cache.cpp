#include <list>
#include <unordered_map>

class LRUCache{
private:
    int cap;
    std::list<std::pair<int,int>> cache; //key, value
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> umap;  //key -> node addr
public:
    LRUCache(int capacity): cap(capacity){}
    int get(int key){
        auto it = umap.find(key);
        if(it == nullptr){
            return -1;
        }
        //move to front
        cache.push_front({key,it->second->second});
        cache.erase(it->second);
        //update addr
        umap[key] = cache.begin();
        return cache.begin()->second;
    }
    void put(int key, int value){
        auto it = umap.find(key);
        if(it == nullptr){
            if(cap > 0){
                cap--;
            }
            else{
                //del LRU
                umap.erase(cache.back().first);
                cache.pop_back();
            }
        }
        else{
            cache.erase(it->second); 
        }
        cache.push_front({key,value});
        umap[key] = cache.begin();
    }
};
