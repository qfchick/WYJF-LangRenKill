#include "game.h"
#include <windows.h>
int main()
{
	gtl::Utf8_Console();

	Game game;
	while (game.start())
		;
	wait;
	return 0;
}