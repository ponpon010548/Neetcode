#include <string>

class Solution {
public:
    string encode(vector<string>& strs) {
        string encodeString;
        for(string &s: strs){
            encodeString += (s + "/");
        }
        return encodeString;
    }

    vector<string> decode(string s) {
        string decodeStrings = "";
        vector<string> res;
        for(char &c: s){
            if(c != '/'){
                decodeStrings += c;
            }
            else{
                res.push_back(decodeStrings);
                decodeStrings = "";
            }
        }
        return res;
    }
};
