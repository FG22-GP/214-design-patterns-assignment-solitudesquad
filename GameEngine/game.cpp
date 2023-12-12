//Using SDL and standard IO
#include <iostream>
#include <SDL.h>
// #include "Controller/Controller.h"
// #include "Observer/Observer.h"
#include "View/View.h"

int Observer::static_number_ = 0;

void TestObserverCode();

int main(int argc, char* args[])
{
	// TestObserverCode();
	
	//TODO optimization
	Controller controller;
	KukiClicker cc;
	View view;
	
	view.RunGame(cc, controller);

	
	// controller.RunGame(cc, view); 
	return 0;
}

void TestObserverCode() {
	// Subject *subject = new Subject;
	// Observer *observer1 = new Observer(*subject);

	KukiClicker *cc = new KukiClicker;
	Observer *observer = new Observer(*cc);

	cc->IncrementCounter();
	
	// subject->CreateMessage("My new car is great!");

	observer->RemoveMeFromTheList();

	// observer1->RemoveMeFromTheList();

	
	delete cc;
	delete observer;
	// delete observer1;
	// delete subject;
}