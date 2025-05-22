#include <iostream>
#include <vector>

/*
每周除了周四，均有活动，该活动：若当天气温大于等于35 则可以给免费雪碧。
给定连续的天气气温，并给定第一天星期几，计算出可以喝多少天雪碧，有多少天喝不到雪碧
*/
using namespace std;



int main() {
	// 关闭输入输出缓存，使效率提升
	ios::sync_with_stdio(false);
	// 解除cin和cout的默认绑定，来降低IO的负担使效率提升
	cin.tie(NULL); cout.tie(NULL);
	int n,day;
	cin >> n >> day;
	vector<int> nums(n + day);
	int cnt = 0;
	int uncnt = 0;
	for (int i = day; i < nums.size(); i++) {
		cin >> nums[i];
		if (nums[i] >= 35 && i%7!=4) {
			cnt++;
		}else if (nums[i] >= 35 && i%7 == 4) {
			uncnt++;
		}
	}
	cout << cnt << " " << uncnt << endl;

}