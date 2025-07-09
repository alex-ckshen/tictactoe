/*
AUTO input
verify double input
more functions
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
int game_state = 1; //1: game is ongoing, 0: game over
int replay = 0; //0: no need for replay, 1: replay
char new_input = 0;

int print_numberpad(int temp_message_state){
    char message0[] = "";
    char message1[] = "Spot Taken";
    char message2[] = "Game Over!";
    char message3[] = "Exit?";

    switch(temp_message_state){
        default:
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message0,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case 1:
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message1,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case 2:
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message2,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case 3:
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message3,
            numberpad1,numberpad2,numberpad3
            );
            break;

    }

}
int get_o(){
    if(replay == 0){            //first time
        print_numberpad(0);

        printf("Player Ｏ:");
        new_input = getche();
        printf("\n");
        replay = 0;
    }else if(replay == 1){      //replayed
        print_numberpad(1);

        printf("Player Ｏ:");
        new_input = getche();
        printf("\n");
        replay = 0;
    }
}
int get_x(){
    if (replay == 0) {            //first time
        print_numberpad(0);

        printf("Player Ｘ:");
        new_input = getche();
        printf("\n");
        replay = 0;
    } else if (replay == 1) {      //replayed
        print_numberpad(1);

        printf("Player Ｘ:");
        new_input = getche();
        printf("\n");
        replay = 0;
    }
}


int main(void){
    while(game_state == 1){

        if(current_player == 0){                    //Player Ｏ
            do{
                get_o();

                if(new_input == '1' && numberpad1 == '1'){
                    numberpad1 = 'O';
                } else if(new_input == '2' && numberpad2 == '2'){
                    numberpad2 = 'O';
                } else if(new_input == '3' && numberpad3 == '3'){
                    numberpad3 = 'O';
                } else if(new_input == '4' && numberpad4 == '4'){
                    numberpad4 = 'O';
                } else if(new_input == '5' && numberpad5 == '5'){
                    numberpad5 = 'O';
                } else if(new_input == '6' && numberpad6 == '6'){
                    numberpad6 = 'O';
                } else if(new_input == '7' && numberpad7 == '7'){
                    numberpad7 = 'O';
                } else if(new_input == '8' && numberpad8 == '8'){
                    numberpad8 = 'O';
                } else if(new_input == '9' && numberpad9 == '9'){
                    numberpad9 = 'O';
                } else{
                    replay = 1;
                }
            } while(replay == 1);

            current_player = 1;

        } else if(current_player == 1){              //Player Ｘ
            do {
                get_x();

                if (new_input == '1' && numberpad1 == '1') {
                    numberpad1 = 'X';
                } else if (new_input == '2' && numberpad2 == '2') {
                    numberpad2 = 'X';
                } else if (new_input == '3' && numberpad3 == '3') {
                    numberpad3 = 'X';
                } else if (new_input == '4' && numberpad4 == '4') {
                    numberpad4 = 'X';
                } else if (new_input == '5' && numberpad5 == '5') {
                    numberpad5 = 'X';
                } else if (new_input == '6' && numberpad6 == '6') {
                    numberpad6 = 'X';
                } else if (new_input == '7' && numberpad7 == '7') {
                    numberpad7 = 'X';
                } else if (new_input == '8' && numberpad8 == '8') {
                    numberpad8 = 'X';
                } else if (new_input == '9' && numberpad9 == '9') {
                    numberpad9 = 'X';
                } else {
                    replay = 1;
                }
            } while (replay == 1);

            current_player = 0;

        }

    }

return 0;
}
