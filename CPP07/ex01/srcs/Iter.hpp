#pragma once

#include "def.hpp"

template <typename T>
void iter(T *tab, const t_uint size, void (*func)(T &val))
{
	for (t_uint i=0; i < size; i++)
		func(tab[i]);
}

// template <typename T>
// void iter(T *tab, const t_uint size, void (*func)(const T &val))
// {
// 	for (t_uint i=0; i < size; i++)
// 		func(tab[i]);
// }
