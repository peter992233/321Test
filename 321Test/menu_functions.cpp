//
//  menu_functions.cpp
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "menu_functions.h"
#include "personalityquiz.h"

void print_menu(){
    std::cout << "=====MENU=====\n";
    std::cout << "1.) New Game \n";
    std::cout << "2.) Load Game \n";
    std::cout << "3.) Delete Game \n";
    std::cout << "4.) Settings \n";
    std::cout << "5.) Personality Quiz \n";
    std::cout << "6.) Exit \n";
    
    
}

int get_option(){
    int x;
    
    do{
        std::cin >> x;
        std::cout << "You Input " << x << "!\n";
    }while(x <= 0 || x > 6);
    
    
    return x;
}

void menu_action (int input){
    if(input == 1){
        menu_new_game();
    }else if (input == 2){
        menu_load_game();
        
    }else if (input == 3){
        menu_delete_game();
        
    }else if (input == 4){
        menu_settings();
        
    }else if (input == 5){
        start_quiz();
        
    }else if (input == 6){
        std::cout << "\n EXITING PROGRAM \n";
        return;
    }
    
    
}


void menu_new_game(){
    std::cout << "\n NEW GAME \n";
}

void menu_load_game(){
    std::cout << "\n LOAD GAME \n";
}

void menu_delete_game(){
    std::cout << "\n DELETE GAME \n";
}

void menu_settings(){
    std::cout << "\n GAME SETTINGS \n";
}

void menu_quiz(){
    std::cout << "\n PERSONALITY QUIZ \n";
}


