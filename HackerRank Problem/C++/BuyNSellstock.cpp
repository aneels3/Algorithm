   int maxProfit(vector<int>& prices) {
        int profit=0;
        int mini=prices[0];
       
        for(int i=0;i<prices.size();i++)
        {
            profit=max(prices[i]-mini,profit);
            mini=min(mini,prices[i]);
            
        }
        return profit;
        
    }
