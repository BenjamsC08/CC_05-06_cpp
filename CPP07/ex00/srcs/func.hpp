# pragma once

template<typename T>
void	swap(T &value0, T &value1)
{
	T tmp;
	tmp = value0;
	value0 = value1;
	value1 = tmp;
}

template<typename T>
T	min(T value0, T value1)	{	return (value0 > value1) ? value1 : value0;	}

template<typename T>
T	max(T value0, T value1)	{	return (value0 > value1) ? value0 : value1;	}
