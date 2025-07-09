/*
tie situations
output change
bug fix
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


int current_player = 0;   //0 for "Ｏ", 1 for "Ｘ"
int game_state = 1;       //0: game over, 1: game is ongoing, 2: EXITing

int replay = 0;           //0: no need for replay, 1: replay, 2: EXIT
int restart_game;
int input_count = 0;
char new_input = 0;

///////////////////////////
int print_numberpad(char temp_message_state){ //0:void, 1:spot taken, 2:game over, 3:EXIT
    char message[] = "";
    char message1[] = "*Spot Taken";
    char message2[] = " *Game Over";
    char message3[] = " *Exit?";

    char message_O[] = " *Ｏ wins!";
    char message_X[] = " *Ｘ wins!";
    char message_T[] = " *It's a Tie!";

    switch(temp_message_state){
        default:
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case '1':
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message1,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case '2':
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message2,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case '3':
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message3,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case 'O':
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message_O,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case 'X':
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message_X,
            numberpad1,numberpad2,numberpad3
            );
            break;
        case 'T':
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message_T,
            numberpad1,numberpad2,numberpad3
            );
            break;

    }

}

int get_o(){
    if(replay == 0){            //first time
        print_numberpad('0');

        printf("Player Ｏ:");
        new_input = getche();
        printf("\n");
        replay = 0;
    }else if(replay == 1){      //replayed
        print_numberpad('1');

        printf("Player Ｏ:");
        new_input = getche();
        printf("\n");
        replay = 0;
    }
}
int get_x(){
    if (replay == 0) {            //first time
        print_numberpad('0');

        printf("Player Ｘ:");
        new_input = getche();
        printf("\n");
        replay = 0;
    } else if (replay == 1) {      //replayed
        print_numberpad('1');

        printf("Player Ｘ:");
        new_input = getche();
        printf("\n");
        replay = 0;
    }
}

int set_as_winner(int game_winner){      //0 for "Ｏ", 1 for "Ｘ"
    game_state = 0;

    if(game_winner == 0){
        print_numberpad('O');
        input_count = 0;
    }else if(game_winner == 1){
        print_numberpad('X');
        input_count = 0;
    }else if(game_winner == 2){
        print_numberpad('T');
        input_count = 0;
    }

}
int find_winner(){

    if(current_player == 0){        //////winner player o/////

        current_player = 1;
        input_count++;

        if(numberpad7 == 'O' && numberpad8 == 'O' && numberpad9 == 'O'){  //7 8 9
            set_as_winner(0);
        } else if(numberpad7 == 'O' && numberpad5 == 'O' && numberpad3 == 'O'){  //7 5 3
            set_as_winner(0);
        } else if(numberpad7 == 'O' && numberpad4 == 'O' && numberpad1 == 'O'){  //7 4 1
            set_as_winner(0);
        } else if(numberpad9 == 'O' && numberpad6 == 'O' && numberpad3 == 'O'){  //9 6 3
            set_as_winner(0);
        } else if(numberpad9 == 'O' && numberpad5 == 'O' && numberpad1 == 'O'){  //9 5 1
            set_as_winner(0);
        } else if(numberpad8 == 'O' && numberpad5 == 'O' && numberpad2 == 'O'){  //8 5 2
            set_as_winner(0);
        } else if(numberpad4 == 'O' && numberpad5 == 'O' && numberpad6 == 'O'){  //4 5 6
            set_as_winner(0);
        } else if(numberpad1 == 'O' && numberpad2 == 'O' && numberpad3 == 'O'){  //1 2 3
            set_as_winner(0);
        } else if(input_count == 9){
            set_as_winner(2);
        } else if(game_state != 0){
            game_state = 1;
        }

    } else if(current_player == 1){  //////winner player x/////

        current_player = 0;

        input_count++;

        if(numberpad7 == 'X' && numberpad8 == 'X' && numberpad9 == 'X'){  //7 8 9
            set_as_winner(1);
        } else if(numberpad7 == 'X' && numberpad5 == 'X' && numberpad3 == 'X'){  //7 5 3
            set_as_winner(1);
        } else if(numberpad7 == 'X' && numberpad4 == 'X' && numberpad1 == 'X'){  //7 4 1
            set_as_winner(1);
        } else if(numberpad9 == 'X' && numberpad6 == 'X' && numberpad3 == 'X'){  //9 6 3
            set_as_winner(1);
        } else if(numberpad9 == 'X' && numberpad5 == 'X' && numberpad1 == 'X'){  //9 5 1
            set_as_winner(1);
        } else if(numberpad8 == 'X' && numberpad5 == 'X' && numberpad2 == 'X'){  //8 5 2
            set_as_winner(1);
        } else if(numberpad4 == 'X' && numberpad5 == 'X' && numberpad6 == 'X'){  //4 5 6
            set_as_winner(1);
        } else if(numberpad1 == 'X' && numberpad2 == 'X' && numberpad3 == 'X'){  //1 2 3
            set_as_winner(1);
        } else if(input_count == 9){
            set_as_winner(2);
        } else if(game_state != 0){
            game_state = 1;
        }

    }
}


int exit_game(){
    int set_exit;

    print_numberpad('3');
    printf("1 to Confirm:");
    set_exit = getche();

    if(set_exit == '1'){
        printf("\n");
        printf("Thanks for \n playing! \n");
        printf("\n");
        game_state = 0;
    }else{
        game_state = 1;
        printf("\n");
    }
}
//////////////////////////

int main(void){
    while(game_state != 2){

        if(game_state == 1){

            if(current_player == 0){                    //Player Ｏ
                do{
                    get_o();

                    if(new_input == '0'){               //exit
                        exit_game();
                    } else if(new_input == '1' && numberpad1 == '1'){
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
                }while(replay == 1);

                find_winner();
            } else if(current_player == 1){              //Player Ｘ
                do {
                    get_x();

                    if(new_input == '0'){                 //exit
                        exit_game();
                    } else if (new_input == '1' && numberpad1 == '1') {
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
                }while (replay == 1);

                find_winner();
            }



        }else if(game_state == 0){
            printf("1 to Restart:");
            restart_game = getche();
//            printf("\n");

            if(restart_game == '1'){
                game_state = 1;
                current_player = 0;
                printf("\n");

                numberpad1 = '1';
                numberpad2 = '2';
                numberpad3 = '3';
                numberpad4 = '4';
                numberpad5 = '5';
                numberpad6 = '6';
                numberpad7 = '7';
                numberpad8 = '8';
                numberpad9 = '9';
            }else{
//                break;
            }


        }
    }
return 0;
}

