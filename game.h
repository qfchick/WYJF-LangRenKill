#pragma once
#include <iostream>
#include <string>
#include <map>
#include "gametool.h"
using gtl::COLORS, gtl::textcolor, gtl::clrscr;
using gtl::sbyte, gtl::ubyte;
using std::cout;
#define wait Sleep(2500)
#define nxtl cout << lbrk
void slowsay(std::string s)
{
	for (auto l : s) {
		Sleep(20);
		cout << l;
	}
}
void idColor(sbyte id)
{
	switch (id)
	{
	case 0:
		textcolor(COLORS::RED);
		break;
	case 1:
		textcolor(COLORS::GREEN);
		break;
	default:
		textcolor(COLORS::BLUE);
		break;
	}
}

const std::vector<std::string> diffLst = { "6人局","9人局","12人局" };
const std::vector<std::string> itoId = {
	"狼人",
	"村民",
	"女巫",
	"预言家",
	"猎人"
};
std::map<sbyte, std::vector<sbyte>> ntoId = {
	{6,{}},
	{9,{
		0,0,0,
		1,1,1,
		2,3,4
	}},
	{12,{}}
};
class Game
{
private:
	sbyte Num, plPos;
	std::vector<std::pair<sbyte, bool>> gameId;

	void Welcome()
	{
		textcolor(COLORS::YELLOW);	cout << "欢迎游玩" << ' ';
		textcolor(COLORS::BLUE);	cout << "YSJFGame";
		textcolor(COLORS::YELLOW);	cout << '-';
		textcolor(COLORS::CYAN);	cout << "人机狼人杀" << ' ';
		textcolor(COLORS::RED);		cout << "！！！" << lbrk;

		textcolor(COLORS::YELLOW);	cout << "作者：" << ' ';
		textcolor(COLORS::MAGENTA);	cout << "启发鸡" << lbrk;

		textcolor(COLORS::WHITE);
		nxtl;
		for (int i = 0; i < 25; i++)
			cout << '-';
		nxtl;

		nxtl;
		textcolor(COLORS::BLACK);
		cout << "[按任意键开始游戏]" << lbrk;
		gtl::getch();
		clrscr();
	}

	void setDiff()
	{
		textcolor(COLORS::GREEN);
		slowsay("请选择游戏人数：");
		nxtl;
		for (int i = 0; i < diffLst.size(); i++)
		{
			textcolor(COLORS::BLACK);
			cout << i + 1 << ". ";
			textcolor(COLORS::WHITE);
			cout << diffLst.at(i) << '\t';
		}
		nxtl;
		
		char c;
		do
			c = gtl::getch();
		while (!isdigit(c) && c - '0' >= 1 && c - '0' <= 3);
		Num = (c - '0' + 1) * 3;

		clrscr();
	}

	void setId()
	{
		gameId.clear();
		for (int i = 0; i < ntoId[Num].size(); i++)
			gameId.push_back({ ntoId[Num][i],0 });
		plPos = gtl::rand(0, Num - 1);
		gtl::random_shuffle(gameId.begin(),gameId.end());

		textcolor(COLORS::YELLOW);
		slowsay("请稍等，正在抽取身份……");
		nxtl; nxtl;
		Sleep(2000);
		slowsay("抽取完成，您的身份是：");
		Sleep(500);

		sbyte id = gameId[plPos].first;
		idColor(id);
		cout << itoId[id] << lbrk;

		textcolor(COLORS::YELLOW);
		slowsay("您在");
		Sleep(500);
		idColor(id);
		cout << (int)plPos + 1;
		slowsay("号位");
		Sleep(1000);
		nxtl; nxtl;

		textcolor(COLORS::BLACK);
		cout << "[按任意键继续]" << lbrk;
		gtl::getch();
		clrscr();
	}

	ubyte checkGame()
	{
		bool cmd , smd, lrd;
		cmd = smd = lrd = true;
		for (auto [id,died] : gameId)
		{
			if (died)
				continue;
			switch (id)
			{
			case 0:
				cmd = false;
				break;
			case 1:
				lrd = false;
				break;
			default:
				smd = false;
				break;
			}
		}
		if (lrd)
			return 1;
		if (cmd || smd)
			return 2;
		return 0;
	}

	void outStatus()
	{
		for (int i = 1; i <= Num; i++)
		{
			textcolor(COLORS::WHITE);	cout << i;
			textcolor(COLORS::BLACK);	cout << "号位";
			cout << '\t';
		}
		nxtl;

		for (auto [id, died] : gameId)
			if (died)
			{
				textcolor(COLORS::RED);
				cout << "死亡" << '\t';
			}
			else
			{
				textcolor(COLORS::GREEN);
				cout << "存活" << '\t';
			}
		nxtl;

		for (auto [id, died] : gameId)
		{
			idColor(id);
			cout << itoId[id] << '\t';
		}
		nxtl;
	}

	void goGame()
	{
		ubyte b;
		for (int day = 1; !(b = checkGame()); day++)
		{
			outStatus();
			textcolor(COLORS::YELLOW);
			slowsay("天黑请闭眼~~~"); nxtl; wait;
			slowsay("狼人请睁眼~~"); nxtl; wait;
			slowsay("请问你们今晚要杀谁？"); nxtl;
			Sleep(500);

			int yd;
			if (gameId[plPos].first == 0 && !gameId[plPos].second)
			{
				cout << "（输入座位号，0弃权）";
				char c;
				do
					c = gtl::getche();
				while (!isdigit(c) && c != '0' && c - '0' > Num && gameId[c - '0' - 1].second);
				yd = c - '0' - 1;
				nxtl;
			}
			else
			{
				do
					yd = gtl::rand(-1, Num-1);
				while (yd != -1 && gameId[yd].second && gameId[yd].first == 0);
				Sleep(2000);
			}
			slowsay("狼人请闭眼~~");
			Sleep(500);
			clrscr();

			outStatus();
			textcolor(COLORS::YELLOW);
			slowsay("女巫请睁眼~~"); nxtl; wait;
			if (yd != -1) {
				slowsay("今晚");
				cout << yd + 1;
				slowsay("号死了，你要救他吗？"); nxtl;
				if (gameId[plPos].first == 2 && !gameId[plPos].second)
				{
					cout << "1.救\t2.不救" << lbrk;
					char c;
					do
						c = gtl::getche();
					while (!isdigit(c) && c != '1' && c != '2');
					if (c == '1')
						yd = -1;
					Sleep(500);
					clrscr();
					outStatus();
					textcolor(COLORS::YELLOW);
				}
				else
				{
					if (gtl::rand())
						yd = -1;
					wait;
				}
			}

			slowsay("你要使用毒药吗？"); nxtl;
			int dd = -1;
			if (gameId[plPos].first == 2 && !gameId[plPos].second)
			{
				cout << "1.用\t2.不用" << lbrk;
				char c;
				do
					c = gtl::getche();
				while (!isdigit(c) && c != '1' && c != '2'); nxtl; wait;
				if (c == '1')
				{
					slowsay("请问你要毒谁？");
					nxtl << "（输入座位号）";
					char c;
					do
						c = gtl::getche();
					while (!isdigit(c) && c > '0' && c - '0' <= Num && c - '0' - 1 != plPos && gameId[c - '0' - 1].second);
					dd = c - '0' - 1;
					nxtl; wait;
				}
			}
			else
			{
				wait;
				if (gtl::rand())
				{
					slowsay("请问你要毒谁？");
					do
						dd = gtl::rand(0, Num - 1);
					while (gameId[dd].second && yd == plPos);
					nxtl; wait;
				}
			}
			slowsay("女巫请闭眼~~");
			clrscr();
			
			outStatus();
			textcolor(COLORS::YELLOW);
			slowsay("预言家请睁眼~~");
			nxtl; wait;
			slowsay("今晚你要查验谁的身份？");
			nxtl;
			if (gameId[plPos].first == 3 && !gameId[plPos].second)
			{
				cout << "（输入座位号，0弃权）";
				char c;
				do
					c = gtl::getche();
				while (!isdigit(c) && c != '0' && c - '0' > Num && gameId[c - '0' - 1].second); nxtl;
				int t = c - '0' - 1;
				cout << "Ta的身份是："; wait;
				idColor(gameId[t].first);
				cout << itoId[gameId[t].first] << lbrk;
			}
			wait;
			slowsay("预言家请闭眼~~");
			clrscr();

			if (~yd)
				gameId[yd].second = 1;
			if (~dd)
				gameId[dd].second = 1;
			clrscr();
			wait;
		}
	}
public:
	void Set()
	{
		Num = 9;
		gameId.clear();
		for (int i = 0; i < ntoId[Num].size(); i++)
			gameId.push_back({ ntoId[Num][i],0 });
		plPos = 6;
	}
	void start()
	{
		Welcome();
		setDiff();
		setId();
		//Set();
		goGame();
	}
};