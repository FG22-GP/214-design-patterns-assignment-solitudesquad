#include <iostream>
#include <SDL.h>
#include "View/View.h"

int Observer::static_number_ = 0;

int main(int argc, char* args[])
{
	
	//TODO optimization
	Controller controller;
	KukiClickerModel cc;
	View view;
	
	view.RunGame(cc, controller);

	
	return 0;
}
