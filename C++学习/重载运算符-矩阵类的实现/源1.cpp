/*#include<iostream> 
using namespace std;
class myMatrix{
	int n;
	int a[20][20];
public:
	myMatrix(){
		n = 0;
	}
	myMatrix(int nn, int p[][20])
	{
		n = nn;
		int i, j;
		for (i = 0; i<n; i++){
			for (j = 0; j<n; j++){
				a[i][j] = p[i][j];
			}
		}
	}
	myMatrix(int nn){
		n = nn;
		int i, j;
		for (i = 0; i<n; i++){
			for (j = 0; j<n; j++){
				a[i][j] = 0;
			}
		}
	}
	myMatrix operator *(const myMatrix &b){
		myMatrix t(n);
		int i, j, k;
		for (i = 0; i<n; i++){
			for (j = 0; j<n; j++){
				for (k = 0; k<n; k++){
					t.a[i][j] += a[i][k] * b.a[k][j];
				}
			}
		}
		return t;
	}
	void show(){
		int i, j;
		for (i = 0; i<n; i++){
			for (j = 0; j<n - 1; j++){
				cout << a[i][j] << ' ';
			}
			cout << a[i][j] << endl;
		}
	}
};
int main(){
	int t, n, a[20][20], b[20][20], i, j;
	cin >> t;
	cin >> n;
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			cin >> a[i][j];
		}
	}
	for (i = 0; i<n; i++){
		for (j = 0; j<n; j++){
			cin >> b[i][j];
		}
	}
	myMatrix aa(n, a), bb(n, b), c(n);
	c = aa*bb;
	c.show();
	return 0;
}
*/