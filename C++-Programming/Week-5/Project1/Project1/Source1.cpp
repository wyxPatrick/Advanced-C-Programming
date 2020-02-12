class MyString : public string {
public:
    MyString() {};
    MyString(const char* ch) : string(ch) {};
    MyString(const MyString& ms) : string(ms) {};     //Copy constructor
    MyString operator+(MyString& str) {
        string str1 = *this;
        string str2 = str;
        string str3 = str1 + str2;
        return *new MyString(str3.c_str());
    }
    MyString operator+(const char* ch) {
        string str1 = *this;
        string str = str1 + ch;
        return *new MyString(str.c_str());
    }
    MyString operator()(int l, int r) {
        string str = substr(l, r);
        return *new MyString(str.c_str());
    }
};

MyString operator+(const char* ch1, MyString& ch2) {
    string str1 = ch2;
    string str = ch1 + str1;
    return *new MyString(str.c_str());
}