class CType
{
public:
	int value;
	void setvalue(int n)
	{
		value = n;
	}
	CType operator++(int)
	{
		CType tmp = *this;
		value *= value;
		return tmp;
	}
	friend ostream& operator<<(ostream& os, const CType& t);
};

ostream& operator<<(ostream& os, const CType& t)
{
	os << t.value;
	return os;
}