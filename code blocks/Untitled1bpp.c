#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string A;
        cin >> A;
        int len = 2;
        for(int i = 1; i < A.size(); i++) len += (A[i] - A[i-1] + 26) % 26 + 1;
        cout << ((len<=(11*A.size()))?"YES":"NO") << endl;
    }
    return 0;
}
}
