#include <iostream>
#include <vector>

/*
ÿ�ܳ������ģ����л���û�����������´��ڵ���35 ����Ը����ѩ�̡�
�����������������£���������һ�����ڼ�����������Ժȶ�����ѩ�̣��ж�����Ȳ���ѩ��
*/
using namespace std;



int main() {
	// �ر�����������棬ʹЧ������
	ios::sync_with_stdio(false);
	// ���cin��cout��Ĭ�ϰ󶨣�������IO�ĸ���ʹЧ������
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