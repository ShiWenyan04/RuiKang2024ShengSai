#include <iostream>
#include <vector>

/*
20֧������������õڼ�����õ���Ӧ�ķ��������ܷ�������������Ӧ����+ɱ������nΪ��������������n*20�����ݣ��ֱ��ʾ1-20�Ķ������α�����������ɱ����
��1-20�� �ܷ����������������
*/
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int>> nums (n * 20 + 1,vector<int > (2,0));
	int f[] = { 0,12,9,7,5,4,3,3,2,2,2,1,1,1,1,1,0,0,0,0,0 };//ÿһ�����Ի�÷���
	vector<int> ans(21,0);
	for (int i = 1; i < nums.size(); i++) {
		cin >> nums[i][0] >> nums[i][1];//��һ�����������ڶ�����ɱ����
		int idx = nums[i][0];
		if (i % 20 == 0) {
			ans[20] += (f[idx] + nums[i][1]);//��������Ӧ������ɱ����
		}
		else {
			ans[i % 20] += (f[idx] + nums[i][1]);//��������Ӧ������ɱ����
		}
	}
	for (int i = 1; i <= 20; i++) {
		cout <<i<<" " << ans[i]<<endl;
	}
}