#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义工作结构体，包含三个属性：
// t: 工作时间，d: 截止时间，p: 报酬
struct Job {
    int t, d, p;
};

// 比较函数，用于排序
// 按截止时间升序排列（d小的排前面）
bool compare(const Job& a, const Job& b) {
    return a.d < b.d;
}

int main() {
    // 优化输入输出速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T;  // 测试数据组数
    cin >> T;

    while (T--) {
        int N;  // 工作数量
        cin >> N;
        vector<Job> jobs;  // 存储所有工作
        int max_d = 0;     // 记录最大的截止时间

        // 输入工作数据
        for (int i = 0; i < N; i++) {
            Job j;
            cin >> j.t >> j.d >> j.p;
            max_d = max(max_d, j.d);  // 更新最大截止时间
            jobs.push_back(j);
        }

        // 按截止时间升序排序
        sort(jobs.begin(), jobs.end(), compare);

        // DP数组，dp[j]表示在时间j时能获得的最大报酬
        // 初始化为0，因为初始时刻没有任何工作完成
        vector<int> dp(max_d + 1, 0);

        // 动态规划处理每个工作
        for (const Job& job : jobs) {
            // 从截止时间倒序遍历到工作时间
            // 这样可以确保每个工作只被选择一次
            for (int j = job.d; j >= job.t; j--) {
                // 关键状态转移方程：
                // 比较"不选当前工作"和"选当前工作"两种情况
                dp[j] = max(dp[j], dp[j - job.t] + job.p);
            }
        }

        // 找出dp数组中的最大值，即最大报酬
        int max_profit = *max_element(dp.begin(), dp.end());
        cout << max_profit << "\n";
    }

    return 0;
}