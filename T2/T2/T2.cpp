#include <iostream>
#include <vector>

/*
20支队伍打比赛，获得第几名会得到相应的分数，而总分数等于排名对应分数+杀敌数，n为比赛次数，输入n*20个数据，分别表示1-20的队伍三次比赛的排名和杀敌数
求1-20的 总分数，按队伍编号输出
*/
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> nums (n * 20 + 1,vector<int > (2,0));
	int f[] = { 0,12,9,7,5,4,3,3,2,2,2,1,1,1,1,1,0,0,0,0,0 };//每一名可以获得分数
	vector<int> ans(21,0);
	for (int i = 1; i < nums.size(); i++) {
		cin >> nums[i][0] >> nums[i][1];//第一个是排名，第二个是杀敌数
		int idx = nums[i][0];
		if (i % 20 == 0) {
			ans[20] += (f[idx] + nums[i][1]);//排名所对应分数加杀敌数
		}
		else {
			ans[i % 20] += (f[idx] + nums[i][1]);//排名所对应分数加杀敌数
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout <<i<<" " << ans[i]<<endl;
	}
}