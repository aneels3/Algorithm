#define _CRT_SECURE_NO_WARNINGS

#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <memory.h>
#include <time.h>

using namespace std;

typedef long long LL;


int n, m;

int main()
{
	scanf("%d", &n);
	set<int> s;
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	scanf("%d", &m);
	vector<int> v(s.begin(), s.end());
	for (int i = 0; i < m; ++i)
	{
		int x;
		scanf("%d", &x);
		int pos = upper_bound(v.begin(), v.end(), x) - v.begin();
		printf("%d\n", (int)v.size() - pos + 1);
	}
	return 0;
}
