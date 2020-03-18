class A
{
public:
	char name;
	int age;
	A(int n) :age(n)
	{
		name = 'A';
	}
};

class B :public A
{
public:
	B(int n) :A(n)
	{
		name = 'B';
	}
};

struct Comp
{
	bool operator()(A* a1, A* a2)
	{
		return a1->age < a2->age;
	}
};

void Print(A* a)
{
	cout << a->name << " " << a->age << endl;
}