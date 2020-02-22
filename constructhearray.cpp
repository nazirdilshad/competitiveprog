#include <bits/stdc++.h>

using namespace std;
long mod = 1e9+7;
vector<string> split_string(string);

// Complete the countArray function below.

long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    long a[n],b[n];
    a[0]= x==1?1:0;   //if x is also equal to 1 then this condition 
    b[0]= x==1?0:1;
   
    for(int i=1;i<n;i++){                                     // when you will create a tree you will observe a pattern
        a[i]= b[i-1]%mod;
        b[i]= (a[i-1]*(k-1) + b[i-1]*(k-2) )%mod;    
    }
    return a[n-1];

}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkx_temp;
    getline(cin, nkx_temp);

    vector<string> nkx = split_string(nkx_temp);

    int n = stoi(nkx[0]);

    int k = stoi(nkx[1]);

    int x = stoi(nkx[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}