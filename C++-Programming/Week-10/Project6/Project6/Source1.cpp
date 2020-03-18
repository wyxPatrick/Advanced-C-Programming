class MyString : public string
{
public:
	MyString() :string() {}
	MyString(char* str) :string(str) {}
	MyString(string str) :string(str) {}
	MyString(MyString& mystr) :string(mystr) {}
	MyString operator()(int start, int length)
	{
		return this->substr(start, length);
	}
};
