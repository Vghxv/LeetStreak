package gop

func canPartition(nums []int) bool {
	sum := 0

	for _, v := range nums {
		sum += v
	}
	if sum%2 != 0 {
		return false
	}
	half := sum / 2
	dp := make([]bool, half+1)
	dp[0] = true
	for _, v := range nums {
		for j := half; j >= v; j-- {
			dp[j] = dp[j] || dp[half-v]
		}
	}
	return dp[half]
}
