#include <iostream>
using namespace std;

int main(){
    int i, n, len, maxlen = 0, ans;
    int j = 1, k;

    for(n = 997; n > 1; n -= 2){
        j = 1;
        for(i = 0; i < n; i++)
            j = (j*10) % n;
        k = j;
        len = 0;
        do{
            j = (j*10) % n;
            len++;
        }while(j != k);
        if(len > maxlen){
            ans = n;
            maxlen = len;
        }
    }
    cout << maxlen << endl;
}
