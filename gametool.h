#pragma once
#include <algorithm>
#include <random>
#include <iterator>
#include <initializer_list>
#include <Windows.h>

namespace gtl
{
#define lbrk '\n'
	typedef signed char sbyte;
	typedef unsigned char ubyte;

	enum Color
	{
		Red = FOREGROUND_RED,
		Green = FOREGROUND_GREEN,
		Blue = FOREGROUND_BLUE,
		Yellow = Red | Green,
		Cyan = Green | Blue,
		Pink = Red | Blue,
		White = Red | Green | Blue,
		Black = 0
	};

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
	inline void random_shuffle(Tp begin,Tp end) {
		std::random_device rd;
		std::default_random_engine e(rd());
		std::shuffle(begin, end, e);
	}

	inline void setColor(std::initializer_list<Color> i)
	{
		int color = FOREGROUND_INTENSITY;
		for (auto c : i)
			color |= c;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	}

	inline void setColor(Color c)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | c);
	}

	inline void tdColor()
	{
		setColor(White);
	}

	inline void clrscr()
	{
		system("cls");
	}
}