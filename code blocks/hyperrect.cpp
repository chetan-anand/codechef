#include<iostream>
#include<cmath>

#define MOD 1000000007

using namespace std;


long long arr[100010];
long long ar[100010];

int main()
{
    int t,k;
    cin >> t;
    while(t--) {
        cin >> k;
        for(int i=0;i<k;i++) cin >> ar[i];
        int mini; // minimum index
        mini = 0;
        long long ans;
        ans = 0;
        for(int i=0;i<k;i++) if(ar[i] < ar[mini]) mini = i; //find the minimums index

        for(int i=ar[mini];i>=1;i--) {
            long long temp = 1;
            for(int j=0;j<k;j++) {
                temp = (temp*(ar[j]/i))%MOD;
            }
            arr[i] = temp;
            for(int j = 2*i;j<=ar[mini];j+=i) {
                arr[i] = (arr[i] - arr[j])%MOD;
                arr[i] = (arr[i] + MOD)%MOD;
            }
            ans = (ans + (arr[i]*i)%MOD )%MOD;
        }
        cout << ans << endl;
    }
}
