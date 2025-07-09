/*
Basic Input/Output Capabilities
ENTER to input

*/
#include <stdio.h>

char numberpad1 = '1';
char numberpad2 = '2';
char numberpad3 = '3';
char numberpad4 = '4';
char numberpad5 = '5';
char numberpad6 = '6';
char numberpad7 = '7';
char numberpad8 = '8';
char numberpad9 = '9';


int current_player = 0; //0 for "Ｏ", 1 for "Ｘ"
int game_state = 0; //0: game is ongoing, 1: game over
char new_input = 0;


int main(void){
while(game_state == 0){
    printf(
        "%c %c %c\n"
        "%c %c %c\n"
        "%c %c %c\n",
        numberpad7,numberpad8,numberpad9,
        numberpad4,numberpad5,numberpad6,
        numberpad1,numberpad2,numberpad3
        );

    if(current_player == 0){                    //Player Ｏ
        printf("Player Ｏ:");
        new_input = getchar();
        getchar();

        if(new_input == '1' && numberpad1 == '1'){
            numberpad1 = 'O';
        }else if(new_input == '2' && numberpad2 == '2'){
            numberpad2 = 'O';
        }else if(new_input == '3' && numberpad3 == '3'){
            numberpad3 = 'O';
        }else if(new_input == '4' && numberpad4 == '4'){
            numberpad4 = 'O';
        }else if(new_input == '5' && numberpad5 == '5'){
            numberpad5 = 'O';
        }else if(new_input == '6' && numberpad6 == '6'){
            numberpad6 = 'O';
        }else if(new_input == '7' && numberpad7 == '7'){
            numberpad7 = 'O';
        }else if(new_input == '8' && numberpad8 == '8'){
            numberpad8 = 'O';
        }else if(new_input == '9' && numberpad9 == '9'){
            numberpad9 = 'O';
        }else{
            printf("The spot has been taken! \n");
        }
        current_player = 1;

    }else if(current_player == 1){              //Player Ｘ
        printf("Player Ｘ:");
        new_input = getchar();
        getchar();

        if(new_input == '1' && numberpad1 == '1'){
            numberpad1 = 'X';
        }else if(new_input == '2' && numberpad2 == '2'){
            numberpad2 = 'X';
        }else if(new_input == '3' && numberpad3 == '3'){
            numberpad3 = 'X';
        }else if(new_input == '4' && numberpad4 == '4'){
            numberpad4 = 'X';
        }else if(new_input == '5' && numberpad5 == '5'){
            numberpad5 = 'X';
        }else if(new_input == '6' && numberpad6 == '6'){
            numberpad6 = 'X';
        }else if(new_input == '7' && numberpad7 == '7'){
            numberpad7 = 'X';
        }else if(new_input == '8' && numberpad8 == '8'){
            numberpad8 = 'X';
        }else if(new_input == '9' && numberpad9 == '9'){
            numberpad9 = 'X';
        }else{
            printf("The spot has been taken! \n");
        }

        current_player = 0;

    }

}

}
