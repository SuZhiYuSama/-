#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
string trans(string x, int m);
int main() {
	int n;
	cin >> n;
	string a[n];
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++){
		cout << trans(a[i],sizeof(a[i])) << endl;
	}
	return 0;
}
string trans(string x,int m) {
	int prop1 , prop2 , i , b[m] = { 0 } , cntr = 0;
	string c;
	stack<int>stk;
	for (int i = 0; i < m; i++)b[i] = x[i]; 
	for (int i = 0; i < m; i++)if (b[i] != 0)b[cntr] = b[i], cntr++;
	cntr = 0, i = 0;
	while (b[i] != 0) {
		if ((b[i] >= 65 && b[i] <= 90) || (b[i] >= 97 && b[i] <= 122))c[cntr] = b[i], i++, cntr++;
		else {
			if (b[i] == 94 || b[i] == 42 || b[i] == 47 || b[i] == 43 || b[i] == 45 || b[i] == 35) {
				if (stk.empty())stk.push(b[i]),i++;
				else {
					switch (b[i]) {
					case 94:prop1 = 8;
					case 42:prop1 = 5;
					case 47:prop1 = 5;
					case 43:prop1 = 2;
					case 45:prop1 = 2;
					case 35:prop1 = 1;
					}
					switch (stk.top()) {
					case 94:prop2 = 8;
					case 42:prop2 = 5;
					case 47:prop2 = 5;
					case 43:prop2 = 2;
					case 45:prop2 = 2;
					case 35:prop2 = 1;
					}
					if (prop1 > prop2)stk.push(b[i]),i++;
					while (prop1 < prop2) {
						switch (b[i]) {
						case 94:prop1 = 8;
						case 42:prop1 = 5;
						case 47:prop1 = 5;
						case 43:prop1 = 2;
						case 45:prop1 = 2;
						case 35:prop1 = 1;
						}
						switch (stk.top()) {
						case 94:prop2 = 8;
						case 42:prop2 = 5;
						case 47:prop2 = 5;
						case 43:prop2 = 2;
						case 45:prop2 = 2;
						case 35:prop2 = 1;
						}
						if (prop1 > prop2)stk.push(b[i]),i++;
						else {
							c[cntr] = stk.top();
							stk.pop();
							cntr++;
						}
					}
				}
			}
			else if (b[i] == 40)stk.push(b[i]),i++;
			else if (b[i] == 41) {
				while (stk.top() != 40) {
					c[cntr] = stk.top(), stk.pop(), cntr++;
				}
				if (stk.top() == 40)stk.pop(), i++;
			}
			while (!stk.empty()) {
				c[cntr] = stk.top();
				stk.pop();
			}
		}
	}
	return c;
}
