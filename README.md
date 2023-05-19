# LAN Party
LAN Party is a gaming competition organised by LSAC. The purpose of this program is to manage the teams and to create rankings and leaderboards.
The implementation is divided in 5 tasks. Each task has a .c and a .h file
<br> Full description of the assignment can be found [here](https://ocw.cs.pub.ro/courses/sda-ab/tema1). 
## Program overview
#### Main
Main function contains the declarations for the input and output files. An array is used here to help keep track of the tasks that are being tested at a time. The head of the list and the number of teams are also declared in main as they are needed throughout the whole program.
#### Task 1
Here, I create a list with data from the input files. Each list node contains the following information about a team: number of players, team name, team points and an array of players containing first name, second name and points. I use different functions to read a list node and the array of players for each team. Here we can also find the functions used to find memory allocation errors, to delete the list and to free the memory allocated in main. To complete the task, I've also included a function to create the output file. 
#### Task 2
For each team from the previous task I calculate team points based on individual points of the participants. I then calculate the maximum allowed number of teams and repeat the following until I reach the desired number: I locate the team with the lowest score , remove it from the list and then decrease the number of teams. For each operation described I use a separate function.
Finally, the same display function from Task 1 is used to rewrite the output files in order for them to contain only teams that do participate in the competition.
#### Task 3
First round is treated separately: I create the queue containing the maches, winner stack and loser stack, I recalculate the points for each winner team, print the winner stack and delete the loser stack. I then repeat those same steps until only the winner remains. Finally, I delete the queue, the winner stack and  the loser stack. 
#### Task 4
This function is called in task3.c to use less memory. With the information saved at the previous task, I create a binary search tree with the last 8 teams, which will act as a leader board once it is run though in inorder. The display and free memory functions for the BST are also called in task3.c for the same reason.
#### Task 5
This function is called in task3.c to use less memory. With the information saved at that point, I create a different BST with the last 8 teams, since that is the order in which teams must be inserteed in the AVL tree. The display function for the AVL is also called in task3.c for the same reason. Creating the AVL tree is similar with the BST, it additionally requires equilibrating the tree by rotating it.
## Personal opinion
It was really fun working on this assignment, this being the most complex program I've done so far. I am thankful for being entailed to learn some basic practices of a developer such as working with multiple files, the usage of Git, MakeFile, checkers and Readme.
