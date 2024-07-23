#include <iostream>
using namespace std;
int n, m;
int arr[111][111];
int cnt;
int main() {
    cin>>n>>m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>arr[i][j];
        }
    }
    //행 카운트
    for (int i=1; i<=n; i++) {
        bool flag2 = true;
        for (int j=1; j<=n-m+1; j++) {
            bool flag = true;
            for (int k=1; k<m; k++) {
                if (j+k>n) break;
                if (arr[i][j] == arr[i][j+k]) {
                    continue;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                flag2 = true;
                break;
            }
            else {
                flag2 = false;
                continue;
            }
        }
        if (flag2) {
            cnt++;
        }
    }
    for (int j=1; j<=n; j++) {
        bool flag2 = true;
        for (int i=1; i<=n-m+1; i++) {
            bool flag = true;
            for (int k=1; k<m; k++) {
                if (i+k>n) break;
                if (arr[i][j] == arr[i+k][j]) {
                    continue;
                }
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                flag2 = true;
                break;
            }
            else {
                flag2 = false;
                continue;
            }
        }
        if (flag2) {
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}