 int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1)
        {
            return s.size();
        }
        
      
        int len=0;
        int j=0;
        int i=0;
        
      unordered_map<char, int> mp;
       while(i<s.size())
       {
            if(mp.find(s[i]) != mp.end())
            {
                 j=max(mp[s[i]]+1,j);
                 
            }
           len=max(len,i-j+1);
           mp[s[i]]=i;
           
         i++;
        }
      
    
        return len;
