#pragma once
#include<iostream>
using namespace std;
template<typename T>auto Find_precise( T *a, T Value,T x)
{
	int *p;
	p=find(a, a + Value, x);
	if (p != a + Value)
	{
		cout << "Find it" <<"下标为："<<p-a<< endl ;
	}
	else cout << "未找到该元素";
}
template<typename T>auto Find_perhaps(T *a, T Value,T min,T max)
{
	int *x;
	x = find_if(a, a + Value, [](int x) {return x > 40 && x < 90; });
		if (x != a+Value)
		{
			cout << "Find it" << "下标为：" << x - a << endl;
		}
		else cout << "未找到该元素";
}
template<typename T>void Rand(T *a, T seed, T Value, T maxedge, T minedge)
{
	srand(seed);
	for (int i = 0; i < Value; i++)
	{
		a[i] = rand() % (maxedge - minedge + 1) + minedge;
	}
}


template<typename T>void Show(T *a, T Value)
{
	for (int i = 0; i < Value; i++)
	{
		cout << a[i] << ",";
	}
	cout << endl;
}
template<typename T>void Sort_byfabs(T *a, T Value)
{
	sort(a, a + Value, [](int x, int y) {return fabs(x) < fabs(y); });
}

template<class ts>class SequencedList
{
public:
  SequencedList(int Max_size)
	  {
	size = Max_size;
	base = new ts[size];
	length = 0;
}
public:
	bool Isempty() { return length == 0 };
	void Showlist();
	auto Length() { return length };
	void destory();
	auto Serarch(ts &character) const;
	void Push_back(ts a);
	void Push_head(ts a);
	void Pop_back();
	void Pop_head();
	int insert_pos(ts pos, const ts &x);
	void insert_val(const ts &x);
	int delete_pos(ts pos, const ts &x);
	void delete_val(const ts &x);
	void clear();
	void reserv();
private:
	ts length;
	ts *base;
	int size;
};

template<class ts>
void SequencedList<ts>::destory()
{
	delete base;
	base = NULL;
	size = 0;
	length = 0;
}
template<class ts>
auto SequencedList<ts>::Serarch(ts &character)const
{
	for (int i = 0; i < length; i++)
	{
		if (base[i] == character)
			return i;
	}
	return false;
}
template<class ts>
void SequencedList<ts>::Push_head(ts a)
{

	length++;
	for (int i = length - 1; i >0; i--)
	{
		base[i] = base[i - 1];
	}
	base[0] = a;
}
template<class ts>
void SequencedList<ts>::Push_back(ts a)
{
	length++;
	for (int i = 0; i <length; i++)
	{
		base[i] = base[i + 1];
	}
	base[length - 1] = a;
}
template<class ts>
void SequencedList<ts>:: Pop_back()
{
	if (!Isempty())
	{
		length--;
		base[length] = NULL;
	}
}
	template<class ts>
	void SequencedList<ts>::Pop_head()
	{
		if (!Isempty());
		{
			for (int i = 0; i < length; i++)
			{
				base[i] = base[i + 1];
			}
			length--;
		}
	}
	template<class ts>
	int SequencedList<ts>::insert_pos(ts pos, const ts &x)
	{
		if (pos > length)
		{
			return false;
		}
		for (int i = length; i > pos - 1; i--)
		{
			base[i] = base[i - 1];
		}
		base[pos - 1] = x;
		length++;
	}
template<class ts>
void SequencedList<ts>::insert_val(const ts &x)
{
		base[length] = x;
		sort(base, base + length - 1);
		length++;
}
template<class ts>
int SequencedList<ts>::delete_pos(ts pos, const ts &x)
{
	if (pos >= length)
	{
			return false;
	}
	for (int i = pos - 1; i < length; i++)
	{
			base[i] = base[i + 1];
	}
length--;
return 1;
}
template<class ts>
void SequencedList<ts>::delete_val(const ts &x)
{
for (int i = 0; i < length; i++)
{
if (base[i] == x)
{
	basep[i] = NULL;
		length--;
			}
	}
		sort(base, base + length - 1);
}
	template<class ts>
	void SequencedList<ts>::reserv()
	{
		int i = 0;
		int m = size - 1;
		for (; i <= ((size - 1) / 2); ++i)
		{
			int tmp = base[i];
			base[i] = base[m];
			base[m] = tmp;
			m--;
		}
	}
	template<class ts>
	void SequencedList<ts>::clear()
	{
		for (int x = 0; x < length;x++)
		{
			x = NULL;
		}
	}
	template<class ts>
	void SequencedList<ts>::Showlist()
	{
		if (length)
		{
			for (int i = 0; i < length;i++)
			{
				cout << base[i]<< " ";
			}
		}
		cout << endl;
	}