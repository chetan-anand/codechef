#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long int n, k, a[100000], b[100000];
        double ca[100000], cb[100000], ans = 0.000000, count = 0.000000;
        scanf("%lld", &n);
        k = 0;
        while (n--)
        {
            scanf("%lld", &a[k]);
            ca[k] = log(a[k])/a[k];
            k++;
        }
        n = 0;
        while (k--)
        {
            scanf("%lld", &b[n]);
            cb[n] = log(b[n])/b[n];
            n++;
        }
        sort(ca, ca + n);
        sort(cb, cb + n);
        if (ca[0] > cb[n-1])
        {
            ans = 1.000000 * n;
        }
        else if (ca[n-1] <= cb[0])
        {
            ans = 0.000000;
        }
        else
        {
            long long int j = 0, k = 0, count = 0;
            for (long long int i = 0; i < n; i++)
            {
                while (ca[i] > cb[j])
                {
                    count = count + 1.000000;
                    j++;
                    if (j == n)
                    break;
                }
                ans = ans + count;
                if (j == n)
                {
                    ans = ans + count * (n - i - 1);
                    break;
                }
            }
            ans = ans/n;
        }
    printf("%0.6lf\n", ans);
    }
return 0;
}
