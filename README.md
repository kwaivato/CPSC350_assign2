(Header) Name: Vidal Arroyo, ID: 2253413, Email: arroy118@mail.chapman.edu, Class: CPSC 350-02, Assignment: Assignment 2

(Brief Overview)
i. main.cpp: a main program used to run a public interface of the Game Of Life program.
ii. menu.cpp/menu.h: a menu interface used to facilitate a Game of Life program.
iii. config.cpp/config.h: a configuration parent class used to set the first array for a Game of Life program.
iv. randomConfig.cpp/randomConfig.h: a random configuration child class used to randomly set the first array for a Game of Life program.
v. fileConfig.cpp/fileConfig.h: a configuration child class used to set the first array from a map file for a Game of Life program.
vi. playStyle.cpp/playStyle.h: a play style parent class used to customize output for a Game of Life program.
vii. pausePlayStyle.cpp/pausePlayStyle.h: a play style child class used to customize output for a Game of Life program.
viii. enterPlayStyle.cpp/enterPlayStyle.h: a play style child class used to customize output for a Game of Life program.
ix. outPlayStyle.cpp/outPlayStyle.h: a play style child class used to customize output for a Game of Life program.
x. game.cpp/game.h: a game parent class used to play Game Of Life given an initial board.
xi. classicGame.cpp/classicGame.h: a game child class used to play Game Of Life on Classic mode given an initial board.
xii. doughnutGame.cpp/doughnutGame.h: a game child class used to play Game Of Life on Doughnut mode given an initial board.
xiii. mirrorGame.cpp/mirrorGame.h: a declared game child class used to play Game Of Life on Mirror mode given an initial board.

(Inline Comments) To run the programs in Docker using g++, type the following commands: 1) g++ *.cpp -o assign2 2) ./assign2

(Other Notes) I used inspiration from the following sources for the following topics:
1) Class Inheiritance: Absolute C++, pg. 483
2) Pressing enter for each round: https://stackoverflow.com/questions/42818899/detecting-enter-key-in-c
3) Timed delay: https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program
