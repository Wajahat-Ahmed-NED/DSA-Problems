// Source: LeetCode
class Solution(object) : 
def maxProfit(self, prices) : 
  profit = 0 left = 0
  right = 1
  while (right < len(prices)) :
    if prices[left] < prices[right] :
    currentProfit = prices[right] - prices[left]
      profit = max(currentProfit, profit) 
    else : left = right
                                                                                                                                                                      right += 1

                                                                                                                                                                  return profit