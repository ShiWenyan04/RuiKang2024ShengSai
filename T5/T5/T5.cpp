#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���幤���ṹ�壬�����������ԣ�
// t: ����ʱ�䣬d: ��ֹʱ�䣬p: ����
struct Job {
    int t, d, p;
};

// �ȽϺ�������������
// ����ֹʱ���������У�dС����ǰ�棩
bool compare(const Job& a, const Job& b) {
    return a.d < b.d;
}

int main() {
    // �Ż���������ٶ�
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;  // ������������
    cin >> T;

    while (T--) {
        int N;  // ��������
        cin >> N;
        vector<Job> jobs;  // �洢���й���
        int max_d = 0;     // ��¼���Ľ�ֹʱ��

        // ���빤������
        for (int i = 0; i < N; i++) {
            Job j;
            cin >> j.t >> j.d >> j.p;
            max_d = max(max_d, j.d);  // ��������ֹʱ��
            jobs.push_back(j);
        }

        // ����ֹʱ����������
        sort(jobs.begin(), jobs.end(), compare);

        // DP���飬dp[j]��ʾ��ʱ��jʱ�ܻ�õ���󱨳�
        // ��ʼ��Ϊ0����Ϊ��ʼʱ��û���κι������
        vector<int> dp(max_d + 1, 0);

        // ��̬�滮����ÿ������
        for (const Job& job : jobs) {
            // �ӽ�ֹʱ�䵹�����������ʱ��
            // ��������ȷ��ÿ������ֻ��ѡ��һ��
            for (int j = job.d; j >= job.t; j--) {
                // �ؼ�״̬ת�Ʒ��̣�
                // �Ƚ�"��ѡ��ǰ����"��"ѡ��ǰ����"�������
                dp[j] = max(dp[j], dp[j - job.t] + job.p);
            }
        }

        // �ҳ�dp�����е����ֵ������󱨳�
        int max_profit = *max_element(dp.begin(), dp.end());
        cout << max_profit << "\n";
    }

    return 0;
}