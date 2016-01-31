#define _CRT_SECURE_NO_WARNINGS
#define MAXN 300001
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

int plan[MAXN];
int next_p[MAXN];
int last[MAXN];
vector<int> res;


int main(){
	freopen("expedition.in", "r", stdin);
	freopen("expedition.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < MAXN; i++) {
		next_p[i] = -1;
		last[i] = -1;
		if (i == n - 1) {
			next_p[i] = MAXN;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> plan[i];
		if (last[plan[i]] != -1) {
			next_p[last[plan[i]]] = i;
		}
		last[plan[i]] = i;
	}
	int last_next = 0;
	int j = 0;
	while (next_p[j] != MAXN) {
		int maxi = last_next;
		for (int i = last_next; i <= next_p[j]; i++) {
			if (next_p[i] > next_p[maxi]) {
				maxi = i;
			}
		}
		if (next_p[maxi] == -1) {
			cout << 0 << endl;
			return 0;
		}
		res.push_back(j + 1);
		last_next = next_p[j];
		j = maxi;
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}