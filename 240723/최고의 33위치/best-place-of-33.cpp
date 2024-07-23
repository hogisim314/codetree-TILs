#include <iostream>
using namespace std;
int n;
int arr[22][22];
int MAX;
int main() {
    cin>>n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin>>arr[i][j];
        }
    }

    for (int i=1; i<=n-2; i++) {
        for (int j=1; j<=n-2; j++) {
            int cnt = 0;
            if (arr[i][j]==1) {
                cnt++;
            }
            if (arr[i+1][j]==1) {
                cnt++;
            }
            if (arr[i+2][j]==1) {
                cnt++;
            }
            if (arr[i][j+1]==1) {
                cnt++;
            }
            if (arr[i+1][j+1]==1) {
                cnt++;
            }
            if (arr[i+2][j+1]==1) {
                cnt++;
            }
            if (arr[i][j+2]==1) {
                cnt++;
            }
            if (arr[i+1][j+2]==1) {
                cnt++;
            }
            if (arr[i+2][j+2]==1) {
                cnt++;
            }
            MAX = max(cnt, MAX);
        }
    }
    cout<<MAX;

    return 0;
}