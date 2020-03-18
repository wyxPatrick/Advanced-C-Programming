struct CMy_add
{
	int& sum;
	CMy_add(int& s) :sum(s) {}
	void operator()(int val)
	{
		sum += (val & 7);
	}
};