#include<iostream>
#include<vector>
using namespace std;

int N, ans=0;
bool PrimeArray[4000001];
vector <int>Prime;

void Eratos(int n)
{
	if (n <= 1) return;

	for (int i = 2; i <= n; i++)
		PrimeArray[i] = true;
	for (long long i = 2; i <= n; i++)
	{
		if (PrimeArray[i]) {
			Prime.push_back(i);
			for (long long j = 2 * i; j <= n; j += i)
				PrimeArray[j] = false;
		}
	}
}

void f() {
	int a = 0, b = 0;
	int sum = 2;
	while(1) {
		if (sum == N) {
			ans++;
		}
		if (a == Prime.size() - 1) return;
		if (sum<=N) {
			b++;
			sum += Prime[b];
		}
		else {
			sum -= Prime[a];
			a++;
		}
		
	}
}

void solve() {
	cin >> N;
	if (N == 1) {
		cout << 0;
		return;
	}
	Eratos(N);
	f();
	cout << ans;
}

int main() {
	solve();
	return 0;
}