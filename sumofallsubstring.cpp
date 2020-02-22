#include <bits/stdc++.h>
long mod = 1e9+7;

using namespace std;

// Complete the substrings function below.
int substrings(string n) {
    
    int w = n.size();
    int* a = new int[w];
    a[0]=n[0]-'0';
    long sum=a[0];
    for(int i=1;i<w;i++){
        a[i]= ((a[i-1]%mod)*10 + (n[i]-'0')*(i+1))%mod;  //we multiply the string recived i+1 times because it will be added eventualy that many times.
        sum += a[i];
    }
    delete [] a;
    return sum%mod;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    int result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
