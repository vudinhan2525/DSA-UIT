#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'closestNumbers' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
    void quicksort(vector<int> &a,int p,int r){
        if(p >= r)    return ;
        int x = a[r];
        int i = p - 1;
        for(int j = p;j < r; j++){
            if(a[j] <= x){
                i++;
                swap(a[j],a[i]);
            }
        }
        swap(a[i + 1],a[r]);
        quicksort(a,p,i);
        quicksort(a,i + 2, r);
    }
    vector<int> closestNumbers(vector<int> arr) {
        quicksort(arr,0,arr.size() - 1);
        int mi = 2e7;
        for(int i = 0;i < arr.size() - 1; i++){
            mi = min(abs(arr[i + 1] - arr[i]),mi);
        }
        vector<int> ans;
        for(int i = 0;i < arr.size() - 1; i ++){
            if(abs(arr[i + 1] - arr[i]) == mi){
                ans.push_back(arr[i]);
                ans.push_back(arr[i + 1]);
            }
        }
        return ans;
    }

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
