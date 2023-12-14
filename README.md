[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)
# marczaku-214-design-patterns-assignment

It's a very simple cookie clicker game. By using the Model-View-Controller(MVC) and Observer pattern. 

First let's start with the Observer pattern 
https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/4d4cd6f650df4517b8ad6c53ac168a040cdbf55d/GameEngine/Observer/Observer.h#L7C1-L7C44

Here I am initilizing KukiClickerModel class within the Observer constructor. The purpose of this is to simply count the number amount of clicks. 

Here I am initilizing a new KukiClicker class within Observer class at the start of the game https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/d568d09a6fe2cdca804fbb91dea871fdea0d7285/GameEngine/View/View.cpp#L94-L95
