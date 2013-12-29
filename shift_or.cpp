// Copyright (c) 2013 Peking University.
// Author: Xiaosong Rong (rongxiaosong@gmail.com)

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void preprocess(unsigned int B[], string T, int n)
{
    unsigned int shift=1;
    for (int i=0; i<n; i++) {
        B[T[i]] &= ~shift; // right bit is set to "0"
        shift <<= 1;
    }
}

vector<int> or_match(string S, string T)
{
    int m=S.length(), n=T.length();
    unsigned int B[256], D=~0, mask;
    for (int i=0; i<256; i++)
        B[i] = ~0; // every bit is set to "1"
    preprocess(B, T, n);
    vector<int> res;

    mask  = ~(1 << (n - 1));
    for (int i=0; i<m; i++) {
        D = (D << 1) | B[S[i]];
        if (~(D | mask))
            res.push_back(i-n+1);
    }

    return res;
}

int main()
{
    string S, T;
    cin >> S >> T;
    vector<int> res=or_match(S,T);
    for (vector<int>::iterator it=res.begin(); it!=res.end(); ++it)
        cout << *it << endl;
    return 0;
}
