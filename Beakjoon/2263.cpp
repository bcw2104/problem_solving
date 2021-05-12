#include<iostream>
using namespace std;

int inorder[100001];
int postorder[100001];

void preorder(int is,int ie, int ps, int pe) {
	if (is > ie || ps > pe)
		return;

	int root = postorder[pe];
	cout << root << " ";

	for (int i = is; i <= ie; i++) {
		if (root == inorder[i]) {
				
			preorder(is, i - 1,ps,ps+(i-is)-1);
			preorder(i+1, ie, ps + (i - is),pe-1);

			break;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}

	preorder(0, n - 1,0,n-1);

	cout << "\n";
	return 0;
}
