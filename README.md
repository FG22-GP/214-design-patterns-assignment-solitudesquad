# Kuki Clicker

<img width="200" src="https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/assets/14058950/e3eb2d05-aafe-41b1-8554-d85f6e7d1593"/>

[Click me](http://google.com)

## Overview
- Cookie Clicker Game
- C++, SDL, Windows
- Observer Pattern

It's a very simple cookie clicker game. By using the Model-View-Controller(MVC) and Observer pattern. 

First, let's start with the Observer pattern 

## Model

https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/4d4cd6f650df4517b8ad6c53ac168a040cdbf55d/GameEngine/Observer/Observer.h#L7-L12

Here I am initializing `KukiClickerModel` class within the Observer constructor. The purpose of this is to count the number amount of clicks. 

Here I am initilizing a new KukiClicker class within Observer class at the start of the game 

https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/d568d09a6fe2cdca804fbb91dea871fdea0d7285/GameEngine/View/View.cpp#L94-L95

## Controller

Then I use `ccSubject` variable to update the counter within the controller class as it handles the player inputs. 

https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/48e281dc926a13c3429bbabba8daba3d09202a72/GameEngine/Controller/Controller.cpp#L41-L46

## View

As you saw in the Observer class constructor. I attached it with a list of observers within KukiClickerModel class 
https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/d1cf54b7745222fae615eda66b6a7c549226eefd/GameEngine/Model/KukiClicker.h#L43-L46 

Whenever I update the number of counter/clicks I notify the observer https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/d1cf54b7745222fae615eda66b6a7c549226eefd/GameEngine/Model/KukiClicker.h#L53-L71

The View class's responsibility is show-casing the things the players see on the screen. It renders two images at different points of clicks. And has a strange font resolution that displays the amount of clicks. Full RunGame method in View class https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/6646d723edd6f2ea9fc600f8b009aaac03b99e2f/GameEngine/View/View.cpp#L89

## Media

Gameplay showcases. It only ever reaches to 6 clicks.
![image](https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/assets/14058950/63390ded-7d04-48ae-9fed-e72ea00efeed)

![image](https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/assets/14058950/bda2122b-2243-4e4f-a0cf-12a68f91c2bd)


![KukiClickerGameGif](https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/assets/14058950/e3eb2d05-aafe-41b1-8554-d85f6e7d1593)


