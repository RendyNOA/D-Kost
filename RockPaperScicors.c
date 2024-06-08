#include<math.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int game(char,char);

void main(){
    char you,computer;
    int n,result;

    printf("Click 'P' to use Paper, Click 'S' to use Scicors, Click 'R' to use Rock\n");
    printf("Your choice: ");scanf("%c",&you);

    srand(time(NULL));
    n = rand() % 100;

    if(n<=33){
        computer='S';
    }
    else if(n>=33 && n<=66){
        computer='P';
    }
    else{
        computer='R';
    }

    result=game(you,computer);

    if(result==-1){
        printf("%c\n",computer);
        printf("You loose");
    }
    else if(result==0){
        printf("%c\n",computer);
        printf("Draw");
    }
    else{
        printf("%c\n",computer);
        printf("You won");
    }
}

int game(char you, char computer){
    if(you==computer){
        return 0;
    }
    if(you=='P' && computer=='R'){
        return 1;
    }
    else if(you=='R' && computer=='P'){
        return -1;
    }
    if(you=='S' && computer=='P'){
        return 1;
    }
    else if(you=='P' && computer=='S'){
        return -1;
    }
    if(you=='R' && computer=='S'){
        return 1;
    }
    else if(you=='S' && computer=='R'){
        return -1;
    }
}