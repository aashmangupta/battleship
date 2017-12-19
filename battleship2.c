/* Created by: Aashman Gupta on 12/19/2016.
 * This took about 8 hours to complete.


 * This code is supposed to be for the game battleship. In this version you play against the computer.
 * Im basically creating a grid for a user and the computer. 
 * After I ask the user to put in a coordinate where he wants to attack.
 * I then compare the grid of the user(FIRST) to the grid of the computer(gridOfComputer).
 * I'm also going to keep track of score by declaring a global variable "count", which counts every time the
   user enters a coordinate. 
 * To check if a ship has been sunk, run a for loop, to check if there are any "1's" int that row or column. */

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

/* Now I've to take ask user to input coordinates and compare them to the computers grid. 
 * Also dont forget about the score. */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Player {
					// Player grid structure
	int** grid;
	int score;

} Player;

Player FIRST;				// GLOBAL VARIABLE!! Declare the main player which stores his grid and his score.

void PrintGrid();
void AllocateSpace();
int** CompGrid();
void Legend();
void hitCalculation(int**);

int main() {
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("		~~~~~~~~~~~~~~~~~~~~Welcome to battle ship!~~~~~~~~~~~~~~~~~~~~\n\n");
	printf("		We are going to use a 9x9 grid and there are a total of 5 ships.\n");	
	printf("					DESTROY THEM!!!!\n\n\n");
	Legend();
	AllocateSpace();		// Primary functions to allocate space and print user grid.
	PrintGrid();
	
	int** gridOfComputer;		// Create a grid for the computer.
        gridOfComputer = CompGrid();
	hitCalculation(gridOfComputer);
	printf("Good job!! You defeated this laptop in battleship.\n\n");
	printf("The highest score possible is 1000. Your score was: %d\n\n", FIRST.score);
	printf("Created by: Aashman Gupta");
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

return 0;
}

void hitCalculation(int** gridOfComputer) {	// Probably the most important function.

	FIRST.score = 1017;
	int count = 0, userRow, userCol;
	int countOne = 0;
	int countTwo = 0;
	int countThree = 0;
	int countFour = 0;
	int countFive = 0;
	
while(count != 5) {
        printf("Enter the coordinates where you want to attack(x coordinate first, then seperate the y with a space): ");
        scanf("%d %d", &userCol, &userRow);

	if((userCol == 0) || (userRow == 0)) {
                printf("\nERROR: The coordinates have to be more than 0\n\n");
                printf("Enter the coordinates where you want to attack(x coordinate first, then seperate the y with a space): ");
                scanf("%d %d", &userCol, &userRow);
        }
	
	if((userCol > 9) || (userRow > 9)) {
		printf("\nERROR: The coordinates can't be more than 9\n\n");
		printf("Enter the coordinates where you want to attack(x coordinate first, then seperate the y with a space): ");
        	scanf("%d %d", &userCol, &userRow);
	}

        userRow = userRow - 1;
        userCol = userCol - 1;

	if (gridOfComputer[userRow][userCol] == 1) {
                FIRST.grid[userRow][userCol] = 1;
                printf("\n\n		=========HIT=========\n");
		printf("		=========HIT=========\n");
		printf("		=========HIT=========\n\n\n");
        	FIRST.score--;
	}

	else if(FIRST.grid[userRow][userCol] == 2) {
                printf("\n\n		You've already guessed this spot once\n\n\n");
        }

	else {
		FIRST.grid[userRow][userCol] = 2;
		printf("\n\n                =========MISS=========\n");
                printf("                =========MISS=========\n");
                printf("                =========MISS=========\n\n\n");
		FIRST.score--;
	}
        PrintGrid();



	if(countOne != 1) {
		if((FIRST.grid[8][8] == 1) && (FIRST.grid[8][7] == 1)) {		// Check if a ship 1 has been sunk.
                	printf("A ship has been destroyed!!!\n\n");
                	count = count + 1;
        		countOne = 1;
		}
	}
	
	if(countTwo != 1) {
		if((FIRST.grid[1][6] == 1) && (FIRST.grid[2][6] == 1) && (FIRST.grid[3][6] == 1)) {
			printf("Nice job!! a ship just got wrecked!\n\n");
			count = count + 1;
			countTwo = 1;
		}
	}

	if(countThree != 1) {
		if((FIRST.grid[7][3] == 1) && (FIRST.grid[7][4] == 1) && (FIRST.grid[7][5] == 1)) {	
			printf("A ship just got annihilated!!!\n\n");
			count = count + 1;
			countThree = 1;
		}
	}
	
	if(countFour != 1) {
		if((FIRST.grid[0][2] == 1) && (FIRST.grid[0][3] == 1) && (FIRST.grid[0][4] == 1) && (FIRST.grid[0][5] == 1)) {
			printf("A pretty big ship just went down.\n\n");
			count = count + 1;
			countFour = 1;
		}	
	}
	
	if(countFive != 1) {
		if((FIRST.grid[2][1] == 1) && (FIRST.grid[3][1] == 1) && (FIRST.grid[4][1] == 1) && (FIRST.grid[5][1] == 1) && (FIRST.grid[6][1] == 1)){
			printf("WOW!! you just took down the biggest ship!!\n\n");
			count = count + 1;
			countFive = 1;
		}
	}


	printf("Ships down: %d\n\n", count);
}

return;
}

void PrintGrid() {		// This Function can be used several times to print user grid
	int i, j;
	
	printf("X →");

        for(i = 0; i < 9; i++) {
                printf("%d ", i + 1);
        }
        printf("\n");

        printf("Y \n↓\n");
        for(i = 0; i < 9; i++) {
                printf("%d  ", i + 1);
        	for(j = 0; j < 9; j++) {
			printf("%d ", FIRST.grid[i][j]);	
		}       
	printf("\n");
        }
	printf("\n\n");
return;
}

void AllocateSpace() {

	int i, j;
	
	FIRST.grid = (int**)malloc(sizeof(int*) * 9); 		//Malloc
        for(i = 0; i < 9; i++) {
                FIRST.grid[i] = (int*)malloc(sizeof(int) * 9);
        }

	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			FIRST.grid[i][j] = 0;
		}
	}

return;
}

int** CompGrid() {

	int i, j;
	int** grid;
	
    //printf("\n-------------THE GRID BELOW IS TEMPORARY. THIS IS TO HELP SEE COMPUTER GRID. REMOVE THIS LATER--------\n\n");

	grid = (int**)malloc(sizeof(int*) * 9);
	
	for(i = 0; i < 9; i++) {
		grid[i] = (int*)malloc(sizeof(int) * 9);		
	}

	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
			grid[i][j] = 0;
		}
	}

	grid[8][8] = 1;	  grid[8][7] = 1;	// Place ship 1			


	for(i = 2; i < 7; i++) {		// Place ship 2
		grid[i][1] = 1;	
	}

	grid[1][6] = 1;  grid[2][6] = 1;  grid[3][6] = 1; // Place ship 3

	grid[7][3] = 1;  grid[7][4] = 1;  grid[7][5] = 1; // Place ship 4

	for(i = 2; i < 6; i++) {		// Place ship 5
		grid[0][i] = 1;
	}
return grid;
}

void Legend() {

	printf("LEGEND: \n");
	printf("0: Empty grid space.\n");
	printf("1: Signifies the location of the computer's ships.\n");
	printf("2: Shows the locations that you have attempted to attack.\n");
	printf("\n\n");

return;
}
