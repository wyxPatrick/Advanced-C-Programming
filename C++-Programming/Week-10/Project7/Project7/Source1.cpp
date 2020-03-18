bool operator<(const A& a1, const A& a2)
{
	return a1.get_size() < a2.get_size();
}

struct Print
{
	void operator()(A& a)
	{
		cout << a << " ";
	}
};

template<class InIt, class Func>
void Show(InIt first, InIt last, Func func)
{
	for (; first != last; first++)
	{
		func(*first);
	}
}

template<class T>
struct MyLarge
{
	bool operator()(const T& t1, const T& t2)
	{
		return t1.get_name() < t2.get_name();
	}
};