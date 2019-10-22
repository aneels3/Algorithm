/*
In this challenge you need to print the string that accompanies each integer in a list sorted by the integers. If two strings 
are associated with the same integer, they must be printed in their original order so your sorting algorithm should be stable. 
There is one other twist. The first half of the strings encountered in the inputs are to be replaced with the character "".

Insertion Sort and the simple version of Quicksort are stable, but the faster in-place version of Quicksort is not since it 
scrambles around elements while sorting.

In this challenge, you will use counting sort to sort a list while keeping the order of the strings preserved.

For example, if your inputs are  you could set up a helper array with three empty arrays as elements. The following shows the 
insertions:

i	string	converted	list
0				[[],[],[]]
1 	a 	-		[[-],[],[]]
2	b	-		[[-],[-],[]]
3	c			[[-,c],[-],[]]
4	d			[[-,c],[-,d],[]]
The result is then printed:  .

Function Description

Complete the countSort function in the editor below. It should construct and print out the sorted strings.

countSort has the following parameter(s):

arr: a 2D array where each arr[i] is comprised of two strings: x and s.
Note: The first element of each , , must be cast as an integer to perform the sort.

Input Format

The first line contains , the number of integer/string pairs in the array .
Each of the next  contains  and , the integers (as strings) with their associated strings.

Constraints


 is even


 consists of characters in the range 

Output Format

Print the strings in their correct order, space-separated on one line.

Sample Input

20
0 ab
6 cd
0 ef
6 gh
4 ij
0 ab
6 cd
0 ef
6 gh
0 ij
4 that
3 be
0 to
1 be
5 question
1 or
2 not
4 is
2 to
4 the
Sample Output

- - - - - to be or not to be - that is the question - - - -
Explanation

Below is the list in the correct order. In the array at the bottom, strings from the first half of the original array were 
replaced with dashes.

0 ab
0 ef
0 ab
0 ef
0 ij
0 to
1 be
1 or
2 not
2 to
3 be
4 ij
4 that
4 is
4 the
5 question
6 cd
6 gh
6 cd
6 gh
sorted = [['-', '-', '-', '-', '-', 'to'], ['be', 'or'], ['not', 'to'], ['be'], ['-', 'that', 'is', 'the'], ['question'], 
['-', '-', '-', '-'], [], [], [], []]
*/

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

//passed all test cases!! yay!!