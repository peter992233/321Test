//
//  menu_functions.cpp
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "menu_functions.h"
#include "personalityquiz.h"
#include "player_data.h"
player_data current;
string MB_Global = "XXXX";

void print_menu(){
    std::cout << "=====MENU=====\n";
    std::cout << "1.) New Game \n";
    std::cout << "2.) Save Game \n";
    std::cout << "3.) Show Player \n";
    std::cout << "4.) Load Game \n";
    std::cout << "5.) Personality Quiz \n";
    std::cout << "6.) Return Global MB \n";
    
    std::cout << "10.) Exit \n";
    
    
}

int get_option(){
    int x;
    
    do{
        std::cin >> x;
        std::cout << "You Input " << x << "!\n";
    }while(x <= 0 || x > 10);
    
    
    return x;
}

void menu_action (int input){
    if(input == 1){
        menu_new_game();
    }else if (input == 2){
        menu_save_game();
        
    }else if (input == 3){
        menu_show_player();
        
    }else if (input == 4){
        menu_load_game();
        
    }else if (input == 5){
        MB_Global = start_quiz();
        
    }else if (input == 6){
        cout << MB_Global << endl;
    }
    else if (input == 10){
        std::cout << "\n EXITING PROGRAM \n";
        return;
    }
    
    
}


void menu_new_game(){
    std::cout << "\n NEW GAME \n";
    current.set_data(MB_Global);

}

void menu_save_game(){
    std::cout << "\n SAVE GAME \n";
    current.save_data();
}

void menu_show_player(){
    std::cout << "\n SHOW CURRENT PLAYER \n";
    current.display_data();
    
}

void menu_load_game(){
    std::cout << "\n LOAD PLAYER \n";
    current.load_data();
    
}

void menu_quiz(){
    std::cout << "\n PERSONALITY QUIZ \n";
}


