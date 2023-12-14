[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)
# marczaku-214-design-patterns-assignment

It's a very simple cookie clicker game. By using the Model-View-Controller(MVC) and Observer pattern. 

First let's start with the Observer pattern 
[https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/4d4cd6f650df4517b8ad6c53ac168a040cdbf55d/GameEngine/Observer/Observer.h#L7C1-L7C44](https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/4d4cd6f650df4517b8ad6c53ac168a040cdbf55d/GameEngine/Observer/Observer.h#L7-L12)

Here I am initilizing KukiClickerModel class within the Observer constructor. The purpose of this is to simply count the number amount of clicks. 

Here I am initilizing a new KukiClicker class within Observer class at the start of the game https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/d568d09a6fe2cdca804fbb91dea871fdea0d7285/GameEngine/View/View.cpp#L94-L95

Then I use ccSubject variable to update the counter within the controller class as it handles the player inputs. 
[https://github.com/FG22-GP/214-design-patterns-assignmentsolitudesquad/blob/b07b79bcde2be36a294957d1309ff0270af66c4d/GameEngine/Controller/Controller.cpp#L41C1-L46C15](https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/48e281dc926a13c3429bbabba8daba3d09202a72/GameEngine/Controller/Controller.cpp#L41-L46)https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/48e281dc926a13c3429bbabba8daba3d09202a72/GameEngine/Controller/Controller.cpp#L41-L46

As you saw in the Observer class contructor. I attached it with a list of observers within KukiClickerModel class 
https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/d1cf54b7745222fae615eda66b6a7c549226eefd/GameEngine/Model/KukiClicker.h#L43-L46 

Whenever I update the number of counter/clicks I notify the observer https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/d1cf54b7745222fae615eda66b6a7c549226eefd/GameEngine/Model/KukiClicker.h#L53-L71

There is not much to say about the View class. Because all it does is showcasing the things the players sees on the screen. It Render two images at different points of clicks. And has a strange font resolution that displays the amount of clicks. Full RunGame method in View class https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/blob/6646d723edd6f2ea9fc600f8b009aaac03b99e2f/GameEngine/View/View.cpp#L89


Gameplay showcases. It only ever reaches to 6 clicks.

![KukiClickerGameGif](https://github.com/FG22-GP/214-design-patterns-assignment-solitudesquad/assets/14058950/e3eb2d05-aafe-41b1-8554-d85f6e7d1593)


