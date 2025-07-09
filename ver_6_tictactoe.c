/*
respond algorithm

fix:
---1. remove auto thru & auto exit
---2. output changes: AUTO and Responding visuals

next:
agent attack output
simplify code?
visuals?
merge modes?

target:
maybe change function value to use RETURN
-----change random
list respond block methods
            =>first move should be random ---> next to player
            =>second move--->block player
                -->unclear or win
*/

#include <stdio.h>
#include <stdlib.h>
//#include <time.h>


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

//////////////////////////////////////////////////////////////////////////////////////////////////

int print_numberpad(char temp_message_state){ //0:void, 1:spot taken, 2:game over, 3:EXIT
    char message[] = "";
    char message1[] = "*Taken";
    char message2[] = " *Game Over";
    char message3[] = " *Exit?";

    char message_AUTO[] = " *responding...";

    char message_O[] = " *Ｏ wins!";
    char message_X[] = " *Ｘ wins!";
    char message_T[] = " *Tie!";

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
        case 'A':
            printf(
            "%c %c %c\n"
            "%c %c %c %s\n"
            "%c %c %c\n",
            numberpad7,numberpad8,numberpad9,
            numberpad4,numberpad5,numberpad6,message_AUTO,
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

        printf("You (Ｏ):");
        new_input = getche();
        printf("\n");
        replay = 0;
    }else if(replay == 1){      //replayed
        print_numberpad('1');

        printf("You (Ｏ):");
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

//////////////////////////////////////////////////////////////////////////////////////////////////

int avaliable(int find_spot){

    char avaliable_list[8];
    int avaliable_count = 0;

    //reset list and countings
    for(int reset = 0 ; reset < avaliable_count ; reset++){ avaliable_list[reset] = '0' ;}
    avaliable_count = 0;        //starts from 0 !!!

    switch(find_spot){
        default:
            break;
        case '1':  // 2, 4, 5
            if(numberpad2 == '2'){ avaliable_list[avaliable_count] = '2' ; avaliable_count++ ; }
            if(numberpad4 == '4'){ avaliable_list[avaliable_count] = '4' ; avaliable_count++ ; }
            if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
            break;
        case '2':  // 1, 3, 4, 5, 6
            if(numberpad1 == '1'){ avaliable_list[avaliable_count] = '1' ; avaliable_count++ ; }
            if(numberpad3 == '3'){ avaliable_list[avaliable_count] = '3' ; avaliable_count++ ; }
            if(numberpad4 == '4'){ avaliable_list[avaliable_count] = '4' ; avaliable_count++ ; }
            if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
            if(numberpad6 == '6'){ avaliable_list[avaliable_count] = '6' ; avaliable_count++ ; }
            break;
        case '3':  // 2, 5, 6
            if(numberpad2 == '2'){ avaliable_list[avaliable_count] = '2' ; avaliable_count++ ; }
            if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
            if(numberpad6 == '6'){ avaliable_list[avaliable_count] = '6' ; avaliable_count++ ; }
            break;
        case '4':  // 1, 2, 5, 7, 8
            if(numberpad1 == '1'){ avaliable_list[avaliable_count] = '1' ; avaliable_count++ ; }
            if(numberpad2 == '2'){ avaliable_list[avaliable_count] = '2' ; avaliable_count++ ; }
            if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
            if(numberpad7 == '7'){ avaliable_list[avaliable_count] = '7' ; avaliable_count++ ; }
            if(numberpad8 == '8'){ avaliable_list[avaliable_count] = '8' ; avaliable_count++ ; }
            break;
        case '5':  // 1, 2, 3, 4, 6, 7, 8, 9
            if(numberpad1 == '1'){ avaliable_list[avaliable_count] = '1' ; avaliable_count++ ; }
            if(numberpad2 == '2'){ avaliable_list[avaliable_count] = '2' ; avaliable_count++ ; }
            if(numberpad3 == '3'){ avaliable_list[avaliable_count] = '3' ; avaliable_count++ ; }
            if(numberpad4 == '4'){ avaliable_list[avaliable_count] = '4' ; avaliable_count++ ; }
            if(numberpad6 == '6'){ avaliable_list[avaliable_count] = '6' ; avaliable_count++ ; }
            if(numberpad7 == '7'){ avaliable_list[avaliable_count] = '7' ; avaliable_count++ ; }
            if(numberpad8 == '8'){ avaliable_list[avaliable_count] = '8' ; avaliable_count++ ; }
            if(numberpad9 == '9'){ avaliable_list[avaliable_count] = '9' ; avaliable_count++ ; }
            break;
        case '6':  // 2, 3, 5, 8, 9
            if(numberpad2 == '2'){ avaliable_list[avaliable_count] = '2' ; avaliable_count++ ; }
            if(numberpad3 == '3'){ avaliable_list[avaliable_count] = '3' ; avaliable_count++ ; }
            if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
            if(numberpad8 == '8'){ avaliable_list[avaliable_count] = '8' ; avaliable_count++ ; }
            if(numberpad9 == '9'){ avaliable_list[avaliable_count] = '9' ; avaliable_count++ ; }
            break;
        case '7':  // 4, 5, 8
            if(numberpad4 == '4'){ avaliable_list[avaliable_count] = '4' ; avaliable_count++ ; }
            if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
            if(numberpad8 == '8'){ avaliable_list[avaliable_count] = '8' ; avaliable_count++ ; }
            break;
        case '8':  // 4, 5, 6, 7, 9
            if(numberpad4 == '4'){ avaliable_list[avaliable_count] = '4' ; avaliable_count++ ; }
            if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
            if(numberpad6 == '6'){ avaliable_list[avaliable_count] = '6' ; avaliable_count++ ; }
            if(numberpad7 == '7'){ avaliable_list[avaliable_count] = '7' ; avaliable_count++ ; }
            if(numberpad9 == '9'){ avaliable_list[avaliable_count] = '9' ; avaliable_count++ ; }
            break;
        case '9':  // 5, 6, 8
            if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
            if(numberpad6 == '6'){ avaliable_list[avaliable_count] = '6' ; avaliable_count++ ; }
            if(numberpad8 == '8'){ avaliable_list[avaliable_count] = '8' ; avaliable_count++ ; }
            break;
    }


    if(avaliable_count == 0){       //avaliable_list empty
        if(numberpad1 == '1'){ avaliable_list[avaliable_count] = '1' ; avaliable_count++ ; }
        if(numberpad2 == '2'){ avaliable_list[avaliable_count] = '2' ; avaliable_count++ ; }
        if(numberpad3 == '3'){ avaliable_list[avaliable_count] = '3' ; avaliable_count++ ; }
        if(numberpad4 == '4'){ avaliable_list[avaliable_count] = '4' ; avaliable_count++ ; }
        if(numberpad5 == '5'){ avaliable_list[avaliable_count] = '5' ; avaliable_count++ ; }
        if(numberpad6 == '6'){ avaliable_list[avaliable_count] = '6' ; avaliable_count++ ; }
        if(numberpad7 == '7'){ avaliable_list[avaliable_count] = '7' ; avaliable_count++ ; }
        if(numberpad8 == '8'){ avaliable_list[avaliable_count] = '8' ; avaliable_count++ ; }
        if(numberpad9 == '9'){ avaliable_list[avaliable_count] = '9' ; avaliable_count++ ; }
    }

    //these only avaliable in turbo c
        //randomize();
        //int random_serial_1 = random(avaliable_count-1);
    int random_serial_1 = rand() % (avaliable_count);
    //get the q of random, shoud be between [0,avaliable count-1] since {< avaliable count}

    return avaliable_list[random_serial_1];
}

int block(){
    char response_number[24];
    int combanation = 0;

     //reset list and countings
    for(int reset = 0 ; reset < combanation ; reset++){ response_number[reset] = '0' ;}
    combanation = 0;        //starts from 0 !!!


    if(numberpad1 == 'O' && numberpad2 == 'O' && numberpad3 == '3'){response_number[combanation] = '3',combanation++;}
    if(numberpad2 == 'O' && numberpad3 == 'O' && numberpad1 == '1'){response_number[combanation] = '1',combanation++;}
    if(numberpad1 == 'O' && numberpad3 == 'O' && numberpad2 == '2'){response_number[combanation] = '2',combanation++;}

    if(numberpad4 == 'O' && numberpad5 == 'O' && numberpad6 == '6'){response_number[combanation] = '6',combanation++;}
    if(numberpad5 == 'O' && numberpad6 == 'O' && numberpad4 == '4'){response_number[combanation] = '4',combanation++;}
    if(numberpad4 == 'O' && numberpad6 == 'O' && numberpad5 == '5'){response_number[combanation] = '5',combanation++;}

    if(numberpad7 == 'O' && numberpad8 == 'O' && numberpad9 == '9'){response_number[combanation] = '9',combanation++;}
    if(numberpad8 == 'O' && numberpad9 == 'O' && numberpad7 == '7'){response_number[combanation] = '7',combanation++;}
    if(numberpad7 == 'O' && numberpad9 == 'O' && numberpad8 == '8'){response_number[combanation] = '8',combanation++;}

    if(numberpad1 == 'O' && numberpad4 == 'O' && numberpad7 == '7'){response_number[combanation] = '7',combanation++;}
    if(numberpad4 == 'O' && numberpad7 == 'O' && numberpad1 == '1'){response_number[combanation] = '1',combanation++;}
    if(numberpad1 == 'O' && numberpad7 == 'O' && numberpad4 == '4'){response_number[combanation] = '4',combanation++;}

    if(numberpad2 == 'O' && numberpad5 == 'O' && numberpad8 == '8'){response_number[combanation] = '8',combanation++;}
    if(numberpad5 == 'O' && numberpad8 == 'O' && numberpad2 == '2'){response_number[combanation] = '2',combanation++;}
    if(numberpad2 == 'O' && numberpad8 == 'O' && numberpad5 == '5'){response_number[combanation] = '5',combanation++;}

    if(numberpad3 == 'O' && numberpad6 == 'O' && numberpad9 == '9'){response_number[combanation] = '9',combanation++;}
    if(numberpad6 == 'O' && numberpad9 == 'O' && numberpad3 == '3'){response_number[combanation] = '3',combanation++;}
    if(numberpad3 == 'O' && numberpad9 == 'O' && numberpad6 == '6'){response_number[combanation] = '6',combanation++;}

    if(numberpad1 == 'O' && numberpad5 == 'O' && numberpad9 == '9'){response_number[combanation] = '9',combanation++;}
    if(numberpad5 == 'O' && numberpad9 == 'O' && numberpad1 == '1'){response_number[combanation] = '1',combanation++;}
    if(numberpad1 == 'O' && numberpad9 == 'O' && numberpad5 == '5'){response_number[combanation] = '5',combanation++;}

    if(numberpad3 == 'O' && numberpad5 == 'O' && numberpad7 == '7'){response_number[combanation] = '7',combanation++;}
    if(numberpad5 == 'O' && numberpad7 == 'O' && numberpad3 == '3'){response_number[combanation] = '3',combanation++;}
    if(numberpad3 == 'O' && numberpad7 == 'O' && numberpad5 == '5'){response_number[combanation] = '5',combanation++;}



    /////
    if(combanation == 1){               //output to block
        return response_number[0];//use FIRST number in list
    }else if(combanation == 0){         //no block case
        return avaliable(new_input);
    }else{                              //more than one block case
        int random_serial_2 = rand() % (combanation);
    //get the q of random, shoud be between [0,combanation-1] since {< combanation}
        return response_number[random_serial_2];
    }


}

int algorithm_x(){
    if(input_count == 1){     //first time input
        new_input = avaliable(new_input);
    }else{
        new_input = block();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////

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
            } else if(current_player == 1){              //Player Ｘ AUTO respond
                do {
                    algorithm_x();

                    if(new_input == '0'){                 // !!! do not allow auto exit
                        //exit_game();
                        replay = 1;
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
