#pragma once
#include <algorithm>
#include <random>
#include <iterator>
#include <initializer_list>
#include "gtconio.h"
#ifdef _WIN32
#include <windows.h>
#elif __linux__
#include <unistd.h>
#endif



namespace gtl
{
#define lbrk '\n'
	typedef signed char sbyte;
	typedef unsigned char ubyte;

	inline int rand(int l, int r)
	{
		std::random_device rd;
		std::default_random_engine e(rd());
		std::uniform_int_distribution<int> u(l, r);
		return u(e);
	}

	inline bool rand()
	{
		std::random_device rd;
		std::default_random_engine e(rd());
		std::bernoulli_distribution b;
		return b(e);
	}

	template <typename Tp>
	inline void random_shuffle(Tp begin, Tp end)
	{
		std::random_device rd;
		std::default_random_engine e(rd());
		std::shuffle(begin, end, e);
	}

	inline void msleep(int ms)
	{
#ifdef _WIN32
		Sleep(ms);
#elif __linux__
		usleep(ms * 1000);
#endif
	}

#ifdef __linux__
	[[deprecated("It's not needed.")]]
#endif
	inline void Utf8_Console()
	{
		system("chcp 65001");
		gtl::clrscr();
	}
}