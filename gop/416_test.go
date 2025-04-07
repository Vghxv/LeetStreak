package gop

import "testing"

func Test416(t *testing.T) {
	testCases := []struct {
		nums []int
		k    bool
	}{
		{
			nums: []int{1, 5, 11, 5},
			k:    true,
		},
		{
			nums: []int{1, 2, 3, 5},
			k:    false,
		},
	}
	for i, tc := range testCases {
		if canPartition(tc.nums) != tc.k {
			t.Errorf("Test case %d failed: got %v, want %v", i+1, canPartition(tc.nums), tc.k)
		}
	}

}
