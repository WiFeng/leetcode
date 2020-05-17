func maxProfit(prices []int) int {
    var max int
    for i := 1; i < len(prices); i++ {
        if prices[i] > prices[i-1] {
            max += prices[i] - prices[i-1]
        }
    }
    return max
}
