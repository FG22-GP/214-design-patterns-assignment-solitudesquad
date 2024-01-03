#include <iostream>
#include <SDL.h>
#include "View/View.h"

int Observer::static_number_ = 0;

int main(int argc, char* args[])
{
	
	//TODO optimization
	KukiClickerModel cc{};
	Controller controller{};
	View view{};
	
	view.RunGame(cc, controller);

	
	return 0;
}
