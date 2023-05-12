#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'equalStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY h1
 *  2. INTEGER_ARRAY h2
 *  3. INTEGER_ARRAY h3
 */
long long total_height(vector<int> v){
    long long sum = 0;
    for(auto x : v){
        sum += x;
    }
    return sum;
}
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    long long total1 = total_height(h1);
    long long total2 = total_height(h2);
    long long total3 = total_height(h3);
    queue<int> qe1;
    queue<int> qe2;
    queue<int> qe3;
    for(auto x : h1){
        qe1.push(x);
    }
    for(auto x : h2){
        qe2.push(x);
    }
    for(auto x : h3){
        qe3.push(x);
    }    
    while(total1 != total2 || total1 != total3 || total2 != total3){
        while(total1 > total2 || total1 > total3){
            total1 -= qe1.front();
            if(total1 < 1)  return 0;
            qe1.pop();
        }
        while(total2 > total1 || total2 > total3){
            total2 -= qe2.front();
            if(total2 < 1)  return 0;
            qe2.pop();
        }
        while(total3 > total1 || total3 > total2){
            total3 -= qe3.front();
            if(total3 < 1)  return 0;
            qe3.pop();
        }
    }
    return total1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n1 = stoi(first_multiple_input[0]);

    int n2 = stoi(first_multiple_input[1]);

    int n3 = stoi(first_multiple_input[2]);

    string h1_temp_temp;
    getline(cin, h1_temp_temp);

    vector<string> h1_temp = split(rtrim(h1_temp_temp));

    vector<int> h1(n1);

    for (int i = 0; i < n1; i++) {
        int h1_item = stoi(h1_temp[i]);

        h1[i] = h1_item;
    }

    string h2_temp_temp;
    getline(cin, h2_temp_temp);

    vector<string> h2_temp = split(rtrim(h2_temp_temp));

    vector<int> h2(n2);

    for (int i = 0; i < n2; i++) {
        int h2_item = stoi(h2_temp[i]);

        h2[i] = h2_item;
    }

    string h3_temp_temp;
    getline(cin, h3_temp_temp);

    vector<string> h3_temp = split(rtrim(h3_temp_temp));

    vector<int> h3(n3);

    for (int i = 0; i < n3; i++) {
        int h3_item = stoi(h3_temp[i]);

        h3[i] = h3_item;
    }

    int result = equalStacks(h1, h2, h3);

    fout << result << "\n";

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
