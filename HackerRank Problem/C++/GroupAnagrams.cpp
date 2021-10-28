 vector<vector<string>> groupAnagrams(vector<string>& strs) {
      vector<vector<string>> vec;
        unordered_map<string, vector<string>> mp;
        for(auto str : strs)
        {
            string s=str;
            sort(str.begin(),str.end());
            mp[str].push_back(s);
        }
       for(auto itr : mp)
       {
            vec.push_back(itr.second);
        }
        return vec;
