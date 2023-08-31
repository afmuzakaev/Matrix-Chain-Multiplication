#include <iostream>
#include <vector>
using namespace std;

int matrixChainMultiplication(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; ++len) {
        for (int i = 1; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int N;
    cout << "Enter the number of matrices: ";
    cin >> N;

    vector<int> arr(N);
    cout << "Enter the dimensions of matrices:\n";
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int result = matrixChainMultiplication(arr);
    cout << "Minimum number of multiplications: " << result << endl;

    return 0;
}
