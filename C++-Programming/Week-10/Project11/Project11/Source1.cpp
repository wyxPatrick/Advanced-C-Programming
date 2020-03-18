#include <functional>
template<class Key, class Val, class Pred = greater<Key> >
class MyMultimap :public multimap<Key, Val, Pred>
{
public:
	void Set(Key key, Val value)
	{
		typedef typename multimap<Key, Val, Pred>::iterator myIt;
		pair<myIt, myIt> bounds = this->equal_range(key);
		for (myIt it = bounds.first; it != bounds.second; it++)
		{
			it->second = value;
		}
	}
};

template<class T1, class T2>
ostream& operator<<(ostream& os, pair<T1, T2> p)
{
	cout << "(" << p.first << "," << p.second << ")";
	return os;
}