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
    std::cout << "=====DEBUG MENU=====\n";
    std::cout << "1.) Create New Game \n";
    std::cout << "2.) Save Game to Local \n";
    std::cout << "3.) Display Current Player \n";
    std::cout << "4.) Load Saves From File \n";
    std::cout << "5.) Load Local Save Game \n";
    std::cout << "6.) Display Local Save Games \n";
    std::cout << "7.) Save Games To File \n";
    std::cout << "8.) Print Menu Again \n";
    std::cout << "9.) Personality Quiz \n";
    std::cout << "10.) Return Global MB \n";
    std::cout << "11.) Delete Save From Local \n";
    std::cout << "12.) Exit \n";
    
    
}

int get_option(){
    int x;
    
    do{
        std::cin >> x;
        std::cout << "You Input " << x << "!\n";
    }while(x <= 0 || x > 12);
    
    
    return x;
}

void menu_action (int input){
    if(input == 1){
        menu_new_game();
    }else if (input == 2){
        menu_save_game();
        
    }else if (input == 3){
        menu_display_current();
        
    }else if (input == 4){
        menu_load_file();
        
    }else if (input == 5){
        menu_load_local();
        
    }else if (input == 6){
        menu_display_local();
        
    }else if (input == 7){
        menu_save_to_file();
        
    }else if (input == 8){
        menu_reprint();
        
    }
    else if (input == 9){
        MB_Global = start_quiz();
        current.set_MB(MB_Global);
        
    }else if (input == 10){
        cout << MB_Global << endl;
        
    }
    else if (input == 11){
        menu_delete_local_save();
        
    }
    else if (input >= 12){
        std::cout << "\n EXITING PROGRAM \n";
        exit(1);
    }
    
    
}



void menu_new_game(){
    //New Game Option From Menu
    //Sets the Current Player to a New One
    
    //Maybe Add prompt to save? ***
    
    current.create_new_player();
    
    
}

void menu_save_game(){
    //Save Game to Local
    //Saves the Current Game to the Local vector
    
    current.save_to_local();
}

void menu_display_current(){
    //Display CUrrent Player Option
    //Displays the Loaded Players Data
    
    current.display_current_player_data();
    
}

void menu_load_file(){
    //Loads Saves From a File into the Local Vector
    
    current.get_saves_from_file();
    
    
}
void menu_load_local(){
    //Load A Locally Saved Game into Current Player
    current.load_from_local();
    
}
void menu_display_local(){
    //Display All Local Saves stored in the Vector
    current.display_all_local_saves();
}
void menu_save_to_file(){
    //Save all the Files in the Vector to The File
    current.save_all_loaded_files();
}
void menu_delete_local_save(){
    //Delete a Local Save from the Vector
    current.delete_from_local();
}

void menu_reprint(){
    //Save the Current Player to local
    print_menu();
}




