/*
	题目大义：求0-n中数个数，其中二进制没有连续1。 
	很好的DP题目，最开始估计到使用DP来解决此题目，但是用了几个小时都没有做出来。
	在做此题目时体会到了一种一些编程比赛中会出现的状态；
		感觉有思路，感觉方向可能是对的，感觉马上就要做出来了，但是一直处于一种紧张的状态，没有什么进展，持续了半个小时后，还是没有
	所获，这时就感觉到了一种失败无助的滋味，会影响到后面的题目正确心态。
		纠正方法：一般一个题目不要花费超过20分钟，最多25分钟，如果还是没有想出来，一般要么超出实力，要么头皮发热没有正确认识题目，
	思路方法都是错的，但是有一种能做出的假象。但是不管怎样，停止，立即停止。先做其他题目，等到后面缓和以后，再重新认识题目，换一种角度和方法解决。

	本题的错误：方法DP没有问题，但是对问题本身的认识不够，1-n中连续11，没有认识清楚这些数字的构成分析，一直扎身于错误中，没有反面思考错误，换方向，认识问题。

	这道题目算是一种多次分割问题的题目，将原问题分割为多个小问题，每个问题又需其他方法来解决，但是问题类型一致。 
*/
class Solution {
	public:
		int findIntegers(int num) {
			int f[32];
			f[0] = 1;
			f[1] = 2;
			for (int i = 2; i < 32; ++i)
				f[i] = f[i-1]+f[i-2];
			int ans = 0, k = 30, pre_bit = 0;
			while (k >= 0) {
				if (num&(1<<k)) {
					ans += f[k];
					if (pre_bit) return ans;
					pre_bit = 1;
				} else
					pre_bit = 0;
				--k;
			}
			return ans+1;
		}
};
