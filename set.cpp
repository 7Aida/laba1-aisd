#include "set.h"
#include <iostream>
std::ostream& operator<<(std::ostream& s, const se& o)
{
	for (int i = 0; i < o._size; ++i)
	{
		int k = i + 1;
		for (k; k < o._size; ++k)
			if (o._data[i] == o._data[k])
			{
				o._data[k] = NULL;
			}
	}
	for (int i = 1; i < o._size; ++i)
	{
		int t = 0;
		if (o._data[i] == NULL)
		{
			for (int k = i + 1; k < o._size; ++k)
			{
				if (o._data[k] != NULL && t == 0)
				{
					o._data[i] = o._data[k];
					o._data[k] = NULL;
					t = 1;
				}
			}
		}
	}

	s << "(";
	for (int i = 0; i < o._size; i++)
	{
		s << o._data[i];
		if (i != o._size - 1) s << ';';
	}
	s << ')';
	return s;
}
se::se()
{
	_size = 0;
	_data = NULL;
}
int se::get_size() const
{
	return _size;
}
se:: ~se()
{
	delete[] _data;
}
se::se(const int size)
{
	_size = size;
	_data = new int[_size];
}
se::se(int* _data, int _size)
{

	this->_size = _size;
	this->_data = new int[_size];

	for (int i = 0; i < _size; i++)
	{
		this->_data[i] = _data[i];
	}
}

se::se(const se& rhs)
{
	this->_size = rhs._size;

	this->_data = new int[rhs._size];

	for (int i = 0; i < _size; i++)
	{
		this->_data[i] = rhs._data[i];
	}
}

int& se::operator() (int col)
{
	if (col >= _size || col < 0)
		throw"incorrect size";
	return _data[col];
}
void se::operator() (int col, int val)
{
	if (col < 0 || col >= _size)
		throw"incorrect size";
	_data[col] = val;
}
se se:: operator%(int term)
{
	int a = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] == term)
		{
			++a;
			break;
		}
	}
	if (a == 0)
	{
		_data[_size] = term;
		++_size;
	}

	return *this;
}
se se:: operator/(int term)
{

	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] == term)
		{
			for (i; i < _size; ++i)
			{
				_data[i] = _data[i + 1];
				if (i == _size - 1)
				{
					_data[i] = NULL;
				}
			}
			break;
		}
	}
	//resize(_size - 1);
	return *this;
}
se se::operator+(se& obj2)
{
	int k = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] != NULL)
			k++;
	}
	for (int i = 0; i < obj2._size; ++i)
	{
		if (obj2._data[i] != NULL)
			k++;
	}
	int* a = new int[k];
	se obj3(a, k);
	int t = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (_data[i] != NULL)
		{
			obj3._data[t] = _data[i];
			t++;
		}
	}
	for (int i = 0; i < obj2._size; ++i)
	{
		if (obj2._data[i] != NULL)
		{
			obj3._data[t] = obj2._data[i];
			t++;
		}
	}

	return obj3;
}
se se::operator-(se& obj2)
{
	int* a = new int[_size];
	se obj3(a, _size);
	for (int i = 0; i < _size; ++i)
	{
		obj3._data[i] = _data[i];
	}
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < obj2._size; ++j)
		{
			if (obj3._data[i] == obj2._data[j])
			{
				obj3 / obj3._data[i];
			}
		}
	}
	return obj3;
}

se se::operator*(se& obj2)
{
	int k = 0;
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < obj2._size; ++j)
		{
			if (_data[i] == obj2._data[j] && _data[i] != NULL && obj2._data[i] != NULL)
			{
				k++;
			}
		}
	}
	int* a = new int[k];
	se obj3(a, k);
	int t = 0;
	for (int i = 0; i < _size; ++i)
	{
		for (int j = 0; j < obj2._size; ++j)
		{
			if (_data[i] == obj2._data[j] && _data[i] != NULL && obj2._data[i] != NULL)
			{
				obj3._data[t] = _data[i];
				t++;
			}
		}
	}
	return obj3;
}
