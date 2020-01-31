#include <iostream>
using namespace std;
class A {
public:
	int val;
	A(int n = 0) { val = n; }
	//GetObj() is reference to val;
	int & GetObj() {
		return val;
	}
};

int main() {
	A a;
	cout << a.val << endl;
	a.GetObj() = 5;
	cout << a.val << endl;
	return 0;
}