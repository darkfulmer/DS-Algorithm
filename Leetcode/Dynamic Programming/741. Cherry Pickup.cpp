/*
�ο����ӣ�http://blog.csdn.net/luke2834/article/details/79365645
 
��������û�з�������ô��Ȼ������һ����ͨ��άdp��ֱ�����
��ô���ȣ������뵽�Ŀ϶���һ��̰�ĵ�˼·����������һ�����ŵ�·����·����1��0��������dpһ��
���˼·�Ǵ���ģ����Լ���֤�ķ������ȼ������̰����ȷ�����÷�֤������֤������֤�������У���ͻᷢ��һЩ�޷�cover�����������һ�����Ȩ·������Ϊ6�������δ�����·���໥û���ص�������Ϊ5�������·���ֱ���������δ�·���ص���2����������λ�ö���0����ô̰�ķ������������9����ѡ�����δ�·��������10
��ô���Ǿ���Ҫ�������dp״̬�����ص�������⿼�ǽ�ȥ
��������֪�������������ߣ��ȼ��ڷֱ������������ߡ�����ͱ�ɷֱ���������������棬���е�һ���߹���1����0��
Ȼ�����ǽ�һ���������⣬������2����ͬʱ�����ߣ����ٶ�һ����ϣ�������������������������ͬʱ�ߵ�һ�������ϣ�������ֻ����һ�Ρ����Լ�����һ��Ϊʲô������⣬�͸ղŵ�����ȼۣ����ٶȶ���1�����t��ʱ�̣����һ�����ߵ�(x1, y1)���ڶ������ߵ�(x2, y2)����ôһ����x1 + y1 = t��x2 + y2 = t������x1 != x2����ô��һ���г��У���һ������Զ�����ߵ�(x2, y2)��ͬ���ڶ�����Զ�����ߵ�(x1, y1)����ˣ����ص�����ֻ��������ͬʱ�ߵ�һ�����ӵ�ʱ����������������ж�����ÿ��ʱ���Ƿ�ᵽ��ͬһ�����ӾͿ���ȥ���ˡ�
�����˼��ת����dp��״̬������Ա�ʾΪdp(t, x1, x2)��Ҳ���ǵ�tʱ�̵�һ�����ߵ�(x1, t - x1)���ڶ������ߵ�(x2, t - x2)ʱ���˵�������档
״̬ת��Ҳ�ǳ��򵥣�dp(t, x1, x2) = grid(x1, t - x1) + (x1 == x2 ? 0 : grid(x2, t - x2)) + max(dp(t-1, x1, x2), dp(t - 1, x1, x2 - 1), dp(t - 1, x1 - 1, x2), dp(t - 1, x1 - 1, x2 - 1))
������t��һά���ǿ���ͨ����������ѹ����ע�������Ļ���Ҫ�����������dp
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define NMAX 50
#define INF 0x3f3f3f

class Solution {
		int dp[(NMAX<<1)][NMAX][NMAX];
		vector<vector<int>>grid;
		int n;
		int solve(int t, int x1, int x2) {
			int y1=t-x1, y2=t-x2;
			if(x1==0&&x2==0&&y1==0&&y2==0) {
				return dp[t][x1][x2]=grid[x1][t-x1];
			} else if(x1<0||x2<0||y1<0||y2<0) {
				return -999999;
			}
			if(dp[t][x1][x2]!=-INF) {
				return dp[t][x1][x2];
			}
			if(grid[x1][y1]==-1||grid[x2][y2]==-1) {
				return dp[t][x1][x2]=-999999;
			}
			dp[t][x1][x2]=grid[x1][y1]+(x1==x2?0:grid[x2][y2])+
			              max(max(solve(t-1, x1, x2), solve(t-1, x1, x2-1)),
			                  max(solve(t-1, x1-1, x2), solve(t-1, x1-1, x2-1))
			                 );
			return dp[t][x1][x2];
		}
	public:
		int cherryPickup(vector<vector<int>>& grid) {
			this->grid=grid;
			n=grid.size();
			fill((int*)dp, (int*)dp+sizeof(dp)/sizeof(int), -INF);
			return max(0, solve((n<<1)-2, n-1, n-1));
		}
};

int main() {
	vector<vector<int>>grid= {{1, 1, -1}, {1, -1, 1}, {-1, 1, 1}};
	Solution s;
	cout<<s.cherryPickup(grid);
	return 0;
}