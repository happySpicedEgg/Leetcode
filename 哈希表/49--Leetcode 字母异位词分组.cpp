#include <iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> u_mapRes;
    for (auto& str : strs) {
        //对副本进行排序
        string key(str);
        sort(key.begin(), key.end());
        //存到hash表中
        u_mapRes[key].push_back(str);
    }
    for (auto& pair : u_mapRes) {
        res.push_back(pair.second);
    }
    return res;
}

int main()
{
	
}

