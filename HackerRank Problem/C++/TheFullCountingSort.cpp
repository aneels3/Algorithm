#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the countSort function below.
//void countSort(vector<vector<string>> arr) {
void countSort(vector<vector<string>> arr) {
    int n = arr.size();
    // create a "helper" array of vectors of pairs for counting sort with structure:
    // -----------------------
    // associated_int   vector of pairs
    //      0           <i, str_ith>, ... 
    //      1           ...
    //      ...
    //      99          ...
    // -----------------------
    // since the integer associated with string in range [0,100) so inititialize size 
    // of "helper" array to 100
    vector<vector<pair<int,string>>> countingList(100);
    for (int i = 0; i < n; i++) {
        pair<int, string> p(i, arr[i][1]);
        countingList[stoi(arr[i][0])].push_back(p);
    }

    for (int i=0; i<countingList.size(); i++) {
        if (countingList[i].size()) {
            for (auto const &e: countingList[i]) {
                if (e.first < n/2) {
                    cout << "- ";
                } else {
                    cout << e.second << " ";
                }
            }
        }
    }
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<string>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(2);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string arr_row_item = arr_row_temp[j];

            arr[i][j] = arr_row_item;
        }
    }

    countSort(arr);

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
