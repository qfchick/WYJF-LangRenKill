#include "game.h"
#include <windows.h>
int main()
{
	system("@chcp 65001");
	gtl::clrscr();
	
	Game game;
	while (game.start())
		;
	wait;
	return 0;
}