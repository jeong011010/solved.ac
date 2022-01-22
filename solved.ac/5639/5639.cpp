#include <iostream>
#include <vector>
using namespace std;

int tree[10000];
void postOrder(int start, int end) {
	if (start >= end) {
		return;
	}
	if (start == end - 1) {
		cout << tree[start] << '\n';
		return;
	}
	int i = start + 1;
	while (i<end) {
		if (tree[start]<tree[i]) {
			break;
		}
		i++;
	}
	
	postOrder(start+1, i);
	postOrder(i, end);
	cout << tree[start] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int num;
	int i = 0;
	while (cin >> num) {
		tree[i++] = num;
	}

	postOrder(0,i);



	return 0;
}