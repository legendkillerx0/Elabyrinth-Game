#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************************************************
 * File    : project.c
 * Author  : sandeep,aditya,anadi mishra,harsh vardhan,shivant
 * Date    : 27-Oct-2022
 * Purpose : design of maze game
 *         : An example of eylabyrinth game
*******************************************************************************/

#define MAX_ROW 25
#define MAX_COL 25   
#define LINE_BUFFER 400

int ans[MAX_ROW][MAX_COL];
int var=0, temp=0;
int row=0, col=0;
int mode=0, count=0, run=1, lock=0;
int a, b, type;
FILE *reportfile;


int max(int q,int r){
    if(q>r){
        return q;
    }
    return r;
}
void report(){
    reportfile = fopen("../reports/report.txt","w");
        if(reportfile == NULL)
        {
            printf("Error in opening the report file");   
            exit(1);             
        }
    return;
}
void printmaze(){
        printf("\nit's a %d*%d maze\n\n",var,temp) ; 
        
    for(int h=1;h<=var;h++){
    for(int q=1;q<=temp;q++){
        
     printf("%d ",ans[h][q]) ; 
    }
    printf("\n") ; 
   }

   printf("\n") ; 

}
int readMazeCSV(char* fileName)
{
    char buffer[LINE_BUFFER] ;
    char *record,*line;
   
    FILE *fstream = fopen(fileName,"r");
        if(fstream == NULL)
            {
                printf("\n File opening failed ");
                return -1 ;
            }

    row=1;
    col=0;
   
    while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
        {
            record = strtok(line,",");
            col++;
            
            while(record != NULL)
            {
                ans[row][col] = atoi(record) ;
                record = strtok(NULL,",");
                temp=max(col,temp);
                col++;
            }

            col=0;   
            var=max(row,var);
            row++;
        }

    return 0;
 }
void options(){

        printf("\n1-Easy maze\n");
        printf("2-Medium maze\n");
        printf("3-Hard maze\n");
        printf("9-Quit the game and exit\n\n");
        return ;
}
void square(){
        switch (mode)
            {
                case 1:
                if (EXIT_FAILURE ==  readMazeCSV("../data/square_easymaze.csv")){
                printf(" Easy maze.\n\n");
                }
                    printf("\nYou choose easy level , can do better \n");
                    break;

                case 2:
                if (EXIT_FAILURE ==  readMazeCSV("../data/square_mediummaze.csv")){
                printf("Medium maze.\n\n");
                }
                    printf("\nYou choose medium level (keep going:)\n");
                    break;

                case 3:
                if (EXIT_FAILURE ==  readMazeCSV("../data/square_hardmaze.csv")){
                printf("Hard maze.\n\n");
                }
                    printf("\nYou choose hard level wow\n");
                    break;

                case 9:
                EXIT_SUCCESS;
                exit(0);
		break;

                default:
               printf("invalid move\n enter the level u want to play");
	       scanf("%d",&mode);
		readfile();
                break;
            }
}
void rectangle(){
        switch (mode)
            {
                case 1:
                if (EXIT_FAILURE ==  readMazeCSV("../data/rectangle_easymaze.csv")){
                printf(" Easy maze.\n\n");
                }
                    printf("\nYou choose easy level (can do better:)\n");
                    break;

                case 2:
                if (EXIT_FAILURE ==  readMazeCSV("../data/rectangle_mediummaze.csv")){
               	    printf("Medium maze.\n\n");
                }
                    printf("\nYou choose medium level (keep going:)\n");
                    break;

                case 3:
                if (EXIT_FAILURE ==  readMazeCSV("../data/rectangle_hardmaze.csv")){
                printf("Hard maze.\n\n");
                }
                    printf("\nYou choose hardmaze level (keep it up:)\n");
                    break;

                case 9:
                EXIT_SUCCESS;
		exit(0);
                
		default:
               printf("invalid move\n enter the level u want to play");
	       scanf("%d",&mode);
		readfile();
		break;
            }
}
void readfile(){
        switch (type)
            {
            case 1:
            square();
            break;

            case 2:
            rectangle();
            break;

            default:
            break;
            }
    return;
}
void score(){
    if(a==var&&b==temp&&lock==0){
        printf("You have used %d number of moves to complete the game\n",count);
        }
    else{
        printf("You exitted out of the game - No score\n");
        }
}
void win(){
    if(a==var&&b==temp&&lock==0){
        printf("You have reached the end block but you dont have any key so go back and collect the key \n");
        }
    else if(a==var&&b==temp&&lock==1){
        printf("Congratulations you have won the game\n");
        exit(1);
        }
    return;
}
void hint(){
    printmaze();
}

/*This function shows the keys used for navigation, hint, and to exit the game*/

void showdirections(){
    printf("0-top\n");
    printf("1-bottom\n");
    printf("2-left\n");
    printf("3-right\n");
    printf("4-exit\n");
    printf("5-hint\n\n");
}

/*This fucntion shows the directions available for the player to move and the walls around him*/

void printdirections(){
    
    printf("\nYou have the following ways\n");
    printf("\n");
    printf("  ");
        if(ans[a][b]%2==0){
            printf("   ^ ");
        }
        else{
        printf("   o ");
        }

    printf("  \n");
    printf("\n");
    printf("     O\n");

        if(ans[a][b]%5==0){
            printf("< ");
        }
        else{
            printf("o ");
        }

    printf("  /");
    printf("|");
    printf("\\  ");

        if(ans[a][b]%7==0){
        printf(" >\n");
        }
        else{
        printf(" o\n");
        }

    printf("  ");
    printf("  /");
    printf("|");
    printf("\\  ");

    printf("\n");
    printf("\n");
    printf("  ");
        if(ans[a][b]%3==0){
        printf("   V \n");
        }
        else{
        printf("   o \n");
        }

    printf("\nEnter the direction you want to move :: \n");
    return;
}
void key(){
    
    if(ans[a][b]%13==0&&lock==0){
        printf("You have got the key");
        lock=1;
    }
    return;
}

/*This function will warn the player if there is a bomb one move away from him*/

void bombsuggest(){
    int run=ans[a][b];
        if(run%19==0){
        printf("\nCAUTIOUS !!! Bomb a head");
        }
    return;
}
void dead(){
    if(ans[a][b]%11==0){
        printf("\nYou have touched the bomb - You failed the game");
        exit(0);
    }
}
void move(){
    int choice;
    scanf("%d",&choice);

    int x=a;
    int y=b;
    int value=ans[x][y];
    
    switch (choice)
        {
        case 0:
            if(value%2==0){
            x=x-1;
            }
            else{
                printf("Invalid move");
            }
        break;

        case 1:
            if(value%3==0){
            x=x+1; 
            }
            else{
                printf("invalid move");
            }
        break;

        case 2:
            if(value%5==0){
            y=y-1;
            }
            else{
                printf("Invalid move");
            }
        break;

        case 3:
            if(value%7==0){
            y=y+1;
            }
            else{
                printf("Invalid move");
            }
        break;

        case 4:
            exit(1);
        

        case 5:
            hint();
            printf("Use this hint to go further\n");
        break;

        default:
                printf("Wrong choice\n");
        break;
}
        a=x;
        b=y; 
        return ;
}
void mazetype(){

        printf("Choose the maze type you want to play");
        printf("\nSquare maze - 1\n");
        printf("Rectangular maze - 2\n");
        scanf("%d",&type);

    switch (type)
        {
        case 1:
            printf("\nYou choose square maze");
        break;

        case 2:
            printf("\nYou choose rectangular maze");
        break;

        default:
            printf("Invalid input");
            mazetype();
            break;
        }
}
void rungame(){
    a=1;
    b=1;

    while(1){
        printf("\nYou are currently at position of %d,%d",a,b);

        key();
        bombsuggest();
        printdirections();
        showdirections();
        move();
        dead();
        win();
        printf("   \n\n\n     ---------    \n\n    ");
        count++;
       }

}
int main()
{
       report();
       mazetype();
       options();
       printf("\nEnter the level you want to play \n");
       fprintf(reportfile, "\nEnter the level you want to play \n");
       scanf("%d",&mode);
       readfile();
       printmaze();
       rungame();
       score();
       fclose(reportfile);
       return 0;
}
