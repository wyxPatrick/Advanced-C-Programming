class A
{
public:
	int num;
	static int count;
	A() { count++; }
	A(int n) :num(n) { count++; }
	A(A& a) { count++; }
	virtual ~A()
	{
		count--;
		cout << "A::destructor" << endl;
	}
};

class B :public A
{
public:
	B() :A() {}
	B(int n) :A(n) {}
	~B()
	{
		cout << "B::destructor" << endl;
	}
};