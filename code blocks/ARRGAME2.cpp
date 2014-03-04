#include <stdio.h>
#include <math.h>
#include <algorithm>

int main()
{
    int t;
    long long int n, k,i,j, a[100000], b[100000],cnta;
    double cnt,ans,x[100000], y[100000];
    scanf("%d", &t);
    while (t--)
    {

        ans = 0.000000, cnt = 0.000000;
        scanf("%lld", &n);
        for(i=0;i<n;i++)
        {
            scanf("%lld", &a[i]);
            x[i] = log(a[i])/a[i];
        }
        for(i=0;i<n;i++)
        {
            scanf("%lld", &b[i]);
            y[i] = log(b[i])/b[i];
        }
        std::sort(x, x + n);
        std::sort(y, y + n);
        if (x[0] > y[n-1]){ans = 1.000000 * n;}
        else if (x[n-1] <= y[0]){ans = 0.000000;}
        else
        {
            j = 0;
            k = 0;
            cnta = 0;
            for (long long int i = 0; i < n; i++)
            {
                while (x[i] > y[j])
                {
                    cnta = cnta+ 1.000000;
                    j++;
                    if (j == n)
                    break;
                }
                ans = ans + cnta;
                if (j == n){ans = ans + cnta*(n-i-1);break;}
            }
            ans = ans/n;
        }
    printf("%0.6lf\n", ans);
    }
    return 0;
}
