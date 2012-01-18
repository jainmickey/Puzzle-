/**********************************************************************
* Its a Puzzle game you need to sort them to win the game.
* 
**********************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define ennum -1
#define enmem -2

int myRandom(int size)	//This function is used to get random values
{
    int i,n;
    static int numNums = 0;
    static int *numArr = NULL;
    if(size >=0)
    {
        if(numArr != NULL)
            free(numArr);
        if((numArr = malloc (sizeof(int) *size)) == NULL)
            return enmem;
        for(i=0; i<size; i++)
            numArr[i] = i;
        numNums = size;
    }
    if(numNums == 0)
        return ennum;
    n = rand() % numNums;
    i = numArr[n];
    numArr[n] = numArr[numNums - 1];
    numNums--;
    if(numNums == 0)
    {
        free(numArr);
        numArr = 0;
    }
    return i;
}

int main()
{
	system("clear");
	int choice;
	while(1)
	{
		printf("\t\tWELCOME TO PUZZLE\n\n\n\n");
	    	printf("\t\t\t\t1. NEW GAME\n");
	    	printf("\t\t\t\t2. EXIT\n");
	    	printf("Enter your choice:- ");
	    	scanf("%d",&choice);
	    	if(choice == 1)
		{
		        game();
		}
		else 
		{
		    exit(2);
		}
	}
        
}
print(int matrix[4][4])	//This function is used to print the game
{
	int x,y,u,v;	//Here x,y used for looping the matrix
	for(x=0;x<4;x++)
	{
		printf("\t\t\t");
		for(u=0;u<21;u++)     //Here u is used for looping "_"
			printf("_");
		printf("\n");
		printf("\t\t\t");
		printf("|");
		for(y=0;y<4;y++)
		{
			if(matrix[x][y]==0)
			{
				printf(" ");
				printf(" ");
				printf(" ");
				printf(" ");
				printf("|");

			}
			else
			{
				printf(" ");
				printf("%2d",matrix[x][y]);
				printf(" ");
				printf("|");

			}
		}
		printf("\n");
	}
	printf("\t\t\t");
	for(v=0;v<21;v++)	//Here also v is used for looping "_"
		printf("_");
	printf("\n");

}

int check(int matrix[4][4])
{
    int x,y,count=0;
    int check=1;
    for(x=0;x<4;x++)
    {
        for(y=0;y<4;y++)
        {
            if(matrix[x][y] == check)
            {
                count++;
                check++;
            }
            else
                check++;
        }
    }
    return count;
}

game()
{
    int x,y,choice,matrix[4][4],random,series[16],length;
	int counter = 0;
	int count = 0;
	int pos_x = 3;	//for getting x position of blank space
	int pos_y = 3;	//for getting y position of blank space
    system("clear");
    srand(time(NULL));
    random = myRandom(15);
    while(random >= 0)
    {
        if(random == 0)
        {
            series[count]=15;
            count++;
        }
        else
        {
            series[count] = random;
            count++;
        }
        random = myRandom(-1);
    }


    for(x=0;x<4;x++)
    {
        for(y=0;y<4;y++)
        {
            matrix[x][y] = series[counter];
            counter++;
        }
    }
    matrix[3][3] = 0;	//This is to print the blank at 3,3 position
    print(matrix);
    while(2)
    {
        printf("Enter the number you want to move or Press 0 to exit: ");
        scanf("%d",&choice);
        if(choice == 0)
            exit(1);
        else if(choice == matrix[pos_x+1][pos_y])
        {
            matrix[pos_x][pos_y] = choice;
            matrix[pos_x+1][pos_y] = 0;
            pos_x = pos_x+1;
            system("clear");
            print( matrix );
            length = check( matrix );
            if(length == 15)
            {
                printf("\t\t\tYOU WINS..");
                exit(1);
            }
        }
        else if(choice == matrix[pos_x][pos_y+1])
        {
            matrix[pos_x][pos_y] = choice;
            matrix[pos_x][pos_y+1] = 0;
            pos_y = pos_y+1;
            system("clear");
            print( matrix );
            length = check(matrix);
            if(length == 15)
            {
                printf("\t\t\tYOU WINS..");
                exit(1);
            }
        }
        else if(choice == matrix[pos_x-1][pos_y])
        {
            matrix[pos_x][pos_y] = choice;
            matrix[pos_x-1][pos_y] = 0;
            pos_x = pos_x-1;
            system("clear");
            print( matrix );
            length = check( matrix );
            if(length == 15)
            {
                printf("\t\t\tYOU WINS..");
                exit(1);
            }
        }
        else if(choice == matrix[pos_x][pos_y-1])
        {
            matrix[pos_x][pos_y] = choice;
            matrix[pos_x][pos_y-1] = 0;
            pos_y = pos_y-1;
            system("clear");
            print( matrix );
            length = check( matrix );
            if(length == 15)
            {
                printf("\t\t\tYOU WINS..");
                exit(1);
            }
        }
        else
        {
	    if(choice < 16)
		printf("You are far away..\n");
	    else
            	printf("You have given a invalid number\n");
            printf("Retry\n");
        }
    }

}

