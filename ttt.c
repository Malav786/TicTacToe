/*
Title: ADVANCED TicTacToe
Developer: Malav Champaneria
Description: This is a not-so-easy but fun to use C program! Making this program
             with the limitations of the C language is really fun and challenging
             at the same time! This TicTacToe game can be played either solo(vs CPU) or 
             with someone else.The layout has been set such that its more understandable 
             and user-friendly! Hope you will enjoy!
*/
#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 
#include <string.h>

//Global Variables==============//
int arr[]={1,2,3,4,5,6,7,8,9}, brr[]={0,0,0,0,0,0,0,0,0}, k=0; n;
char values[9];

struct arrays
{
    char arr_CPU[8];
};
//Main Function=================//
main()
{
    for(int l=0; l<9; l++) //This loop resets the values of global function if user 
    {                      //chooses to re-play the game.
        arr[l]=l+1;
        brr[l]=0;
        values[l]=32;
    }
    k=0;
    //This prints the reference layout of the board.
    printf("Layout Reference:\n\n1 | 2 | 3 \n——+———+——— \n4 | 5 | 6 \n——+———+——— \n7 | 8 | 9 \n");
    demo_main();
}

//This is a psuedo-main function. Acts as a juction before main()
//This function mainly asks user which kind of game they want to play and initiates-
//the function according to their selection.
//This function can also re-run itself if any invalid input is given.
void demo_main()
{   
    char selection[1];
    printf("\nWhat do you wanna play?\n1.Single Player(VS CPU)\n2.Two Player\n");
    scanf("%s",selection);
    if(strcmp(selection,"1")==0)
        SinglePlayer();
    else if(strcmp(selection,"2")==0)
        TwoPlayer();
    else
    {
        printf("\nPlease enter either '1' or '2'!\n");
        demo_main();
    }
}

//This function is initiated when user chooses to play a single player game (VS CPU)
void SinglePlayer()
{
    printf("\nYou are 'X' and CPU is 'O'\n");
    for(int i=1; i<=9; i++)
    {  
        int j=0;
        printf("\nAvailable positions are: ");   //Output will be different after every iteration
        while(j<=(9-i))                          //as per user's position selection.
        {
            printf("%d,",arr[j]);
            j++;
        }
        if(i%2!=0)
        {
            a:printf("\nYour turn: ");
            scanf("%d",&n);
            if(Availibilty(n)==1) //Sends the control to the Availibilty() function 
                Main_Logic(n,1,i); //If Availibilty() function returns the value 1, Main_Logic() is initiated.
            else                   //If user inputs invalid numerical input.
            {
                printf("\nYour entered number is either already used or out of range! ");
                goto a;
            }
        }
        else
        {
            CPU_Logic(i);
        }
    }
}

//This function is initiated when user chooses to play a Two player game (VS Human)
void TwoPlayer()
{
    printf("\nPlayer 1 is 'X' and Player 2 is 'O'\n");
    for(int i=1; i<=9; i++)
    {  
        int p=0;
        int j=0;
        printf("\nAvailable positions are: ");      
        while(j<=(9-i))
        {
            printf("%d,",arr[j]);
            j++;
        }
        if(i%2!=0)
        {
            a:printf("\nPlayer 1's turn: ");
            scanf("%d",&n);
            if(Availibilty(n)==1)
                Main_Logic(n,1,i,2);
            else
            {
                printf("\nYour entered number is either already used or out of range! ");
                goto a;
            }
        }
        else
        {
            b:printf("\nPlayer 2's turn: ");
            scanf("%d",&n);
            if(Availibilty(n)==1)
                Main_Logic(n,2,i);
            else
            {
                printf("\nYour entered position is either already used or out of range! ");
                goto b;
            }
        }
    }
}

//Checks if the number input by the user is available in the current array.
//Returns integer value 1 if TRUE
int Availibilty(int dn)
{
 for(int i=0; i<9; i++)
 {
     if(arr[i]==dn)
     {
         return 1;
     }
     else
         continue;
 }
 return 0;
}

//This function runs the main logic of the program!
void Main_Logic(int n, int pl, int it)
{
    char dc;
    if(pl==1)//X for player 1
        dc='X';
    else     //O for player 2
        dc='O';
    List(n); //Initiates the List() function.
    switch(n)//Updates the character array values[] as per user input.
    {
        case 1: values[0]=dc;break;
        case 2: values[1]=dc;break;
        case 3: values[2]=dc;break;
        case 4: values[3]=dc;break;
        case 5: values[4]=dc;break;
        case 6: values[5]=dc;break;
        case 7: values[6]=dc;break;
        case 8: values[7]=dc;break;
        case 9: values[8]=dc;break;
    }
    Layout();//Initiates Layout() Function
    if(it==9)
    {
        check(dc,n);
        printf("\nMatch Tied!");
        Regame();
    }
    else if(it>=5)//Initiates check() function if the number of interation is 5 or more.
        check(dc,n);
}

//This function displays the latest state of the board after every positional input by user.
void Layout()
{
    printf("\n\n%c | %c | %c \n——+———+——— \n%c | %c | %c \n——+———+——— \n%c | %c | %c \n"
           ,values[0],values[1],values[2],values[3],
           values[4],values[5],values[6],values[7],values[8]);
}

void CPU_Logic(int it)
{
    if(it>3)
    {
        CPU_nextMove(it);
    }
    else
    {
        random_logic(it);
    }
}

void random_logic(int it)
{
    printf("\nIn random_logic");
    int randomIndex = rand()%(9-it);
    n=arr[randomIndex];
    printf("\nCPU's turn: %d",n);
    Main_Logic(n,2,it);
}
void CPU_nextMove(int it)
{
    struct arrays a[9];
    //printf("\nin CPU_nextMove");
    strcpy(a[0].arr_CPU,"abdegh");
    strcpy(a[1].arr_CPU,"bcjk");
    strcpy(a[2].arr_CPU,"acmnvw");
    strcpy(a[3].arr_CPU,"efpq");
    strcpy(a[4].arr_CPU,"gijlprvx");
    strcpy(a[5].arr_CPU,"noqr");
    strcpy(a[6].arr_CPU,"dfstwx");
    strcpy(a[7].arr_CPU,"klsu");
    strcpy(a[8].arr_CPU,"himotu");
    int h=0,f, g=brr[it-4], z=0;
    printf("\n%d",g);
    while(a[n-1].arr_CPU[h]!=NULL)
    {
        //printf("\nIn loop1");
        f=0;
        while(a[g-1].arr_CPU[f]!=NULL)
        {
            //printf("\nIn loop2\n");
            if(a[n-1].arr_CPU[h]==a[g-1].arr_CPU[f])
            {
                printf("\nIn If");
                z=1;
                CPU_cases(a[n-1].arr_CPU[h],it);
            }
            f++;
        }
        h++;
    }
    if(z==0)
        random_logic(it);
    //printf("\nOut of CPU_nextMove");
}

void CPU_cases(char c, int it)
{
    printf("\nIn CPU_cases: c = %c",c);
    switch(c)
    {
        case 'a': case 'l':
            {
                if(values[1]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 2",n);
                    Main_Logic(2,2,it);
                    break;
                }  
                break;
            }break;
        case 'b': case 'o': case 'x':
            {
                if(values[2]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 3",n);
                    Main_Logic(3,2,it);
                    break;
                }  
                break;
            }break;
        case 'c': case 'f': case 'i':
            {
                if(values[0]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 1",n);
                    Main_Logic(1,2,it);
                    break;
                }  
                break;
            }break;
        case 'd': case 'r':
            {
                if(values[3]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 4",n);
                    Main_Logic(4,2,it);
                    break;
                }  
                break;
            }break;
        case 'e': case 'u': case 'v':
            {
                if(values[6]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 7",n);
                    Main_Logic(7,2,it);
                    break;
                }  
                break;
            }break;
        case 'g': case 'n': case 's':
            {
                if(values[8]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 9",n);
                    Main_Logic(9,2,it);
                    break;
                }  
                break;
            }break;
        case 'h': case 'k': case 'q': case 'w':
            {
                if(values[4]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 5",n);
                    Main_Logic(5,2,it);
                    break;
                } 
                break;
            }break;
        case 'j': case 't':
            {
                if(values[7]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 8",n);
                    Main_Logic(8,2,it);
                    break;
                }   
                break;
            }break;
        
        case 'm': case 'p':
            {
                if(values[5]=='O')
                {
                    random_logic(it);
                    break;
                }
                else
                {
                    printf("\nCPU's turn: 6",n);
                    Main_Logic(6,2,it);
                    break;
                }   
                break;
            }break;
    }
}
//This function checks if any valid patterns are forming or not.
//This function is only initiated from the 5th iteration.
void check(char dc, int n)
{
    switch(n-1)//Here n-1 is the index of the positions
    {
     case 0:
        {
            if((values[0]==dc&&values[1]==dc&&values[2]==dc)
            ||(values[0]==dc&&values[3]==dc&&values[6]==dc)
            ||(values[0]==dc&&values[4]==dc&&values[8]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();       
            }
            break;
        }
     case 1:
        {
            if((values[0]==dc&&values[1]==dc&&values[2]==dc)
            ||(values[1]==dc&&values[4]==dc&&values[7]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();
            }
            break;
        }
     case 2:
        {
            if((values[0]==dc&&values[1]==dc&&values[2]==dc)
            ||(values[2]==dc&&values[5]==dc&&values[8]==dc)
            ||(values[2]==dc&&values[4]==dc&&values[6]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();
            }
            break;
        }
     case 3:
        {
            if((values[3]==dc&&values[4]==dc&&values[5]==dc)
            ||(values[0]==dc&&values[3]==dc&&values[6]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();
            }
            break;
        }
     case 4:
        {
            if((values[0]==dc&&values[4]==dc&&values[8]==dc)
            ||(values[2]==dc&&values[4]==dc&&values[6]==dc)
            ||(values[1]==dc&&values[4]==dc&&values[7]==dc)
            ||(values[3]==dc&&values[4]==dc&&values[5]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();
            }
            break;
        }
     case 5:
        {
            if((values[2]==dc&&values[5]==dc&&values[8]==dc)
            ||(values[3]==dc&&values[4]==dc&&values[5]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();
            }
            break;
        }
     case 6:
        {
            if((values[6]==dc&&values[7]==dc&&values[8]==dc)
            ||(values[0]==dc&&values[3]==dc&&values[6]==dc)
            ||(values[2]==dc&&values[4]==dc&&values[6]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();
            }
            break;
        }
     case 7:
        {
            if((values[1]==dc&&values[4]==dc&&values[7]==dc)
            ||(values[6]==dc&&values[7]==dc&&values[8]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();
            }
            break;
        }
     case 8:
        {
            if((values[2]==dc&&values[5]==dc&&values[8]==dc)
            ||(values[6]==dc&&values[7]==dc&&values[8]==dc)
            ||(values[0]==dc&&values[4]==dc&&values[8]==dc))
            {
                printf("\n\n%c is the winner!",dc); 
                Regame();
            }
            break;
        }
    }
    
}

//This function asks user if the want to replay on end the game.
//This function is initiated as soon as a valid winning pattern is detected.
//This function can also recall itself on any invalid input
void Regame()
{
    char b[3];
    printf("\nDo you wish to play again?(y/n)");
    scanf("%s",b);
    if(strcasecmp(b,"y")==0||strcasecmp(b,"yes")==0)
        main();//New Game
    else if(strcasecmp(b,"n")==0||strcasecmp(b,"no")==0)
        exit(0);
    else
    {
        printf("Invalid input! Please try again!");
        Regame();
    }
}

//This function updates the array as per user's action and shows the remaing available inputs.
//This is initiated after every iteration.
//This is one of the most important function of this program.
void List(int n)
{
   for(int i=1; i<=9; i++)//Primary Iteration
    {
        for(int j=0; j<=(9-i); j++)//This loop iterates only 9-i times
        {
            if(arr[j]==n)          //The function begins its core operation
            {                      //from the index on which the value of n is found(matching index).
                brr[k]=n;
                k++;
                while(j<=(9-i))
                {
                    if(j==(9-i))   //9-i will always be the last index of the ith iteration.
                    {
                        arr[j]=NULL;//Deletes the value on last index.
                        break;
                    }
                    else
                    {
                        arr[j]=arr[j+1];//Updates every index from the matching index with  
                        j++;            //the value of its successing index.
                    }
                }
            }
        }
    } 
}
