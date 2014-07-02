//
//  menu_functions.cpp
//  Peter Brown
//
//  Created by Peter Brown on 11/06/2014.
//  Copyright (c) 2014 csci321ga2a. All rights reserved.
//

#include "menu_functions.h"
#include "personalityquiz.h"
#include "player_data.h"



//Currently Loaded Player Profile
player_data current;


//The Global Setting for Personality
string MB_Global = "XXXX";




//Function to Print the Menu
void print_main_menu(){
    
    
    //New Menu As Of 2/7/14 for more compact display and modularisation of menu
    
    std::cout << "=====321 TEST MAIN MENU=====\n";
    std::cout << "1.) Player Data Menu " << std::endl;
    std::cout << "2.) Personality Quiz Menu " << std::endl;
    std::cout << "3.) Status Display Menu " << std::endl;
    std::cout << "4.) Scenario Menu " << std::endl;
    std::cout << "5.) Minigame Menu " << std::endl;
    std::cout << "6.) Exit Game " << std::endl;
}


void run_menu(){
    
    
    //Selection Loop For the Main Menu
    
    int input = 0;
    
    do{
        print_main_menu();
        cout << "Menu Input: ";
        cin >> input;
        
        
        if(input == 1){
            player_data_menu();
        }
        else if(input == 2){
            player_quiz_menu();
        }
        else if(input == 3){
            //Status Display Menu
            stat_display_menu();
        }
        else if(input == 4){
            //Scenario Menu
             cout << "\n!!!!!Unimplemented!!!!!" << endl;
        }
        else if(input == 5){
            //Minigame Menu
             cout << "\n!!!!!Unimplemented!!!!!" << endl;
        }
        
        
        
    }while(input != 6);
    
    
}



void player_data_menu(){
    
    /*A Secondary Loop That is instantiated by selecting option 1 from the main menu
     This Gives Further Options for the users which relate to the Player Data
     Aspects of the Program such as loading and saving players.
     */
    int input;
    
    do{
        cout << "===== This is The Player Data Menu ===== " << endl;
        cout << "1.) Create New Player " << endl;
        cout << "2.) Save Current Player to Local" << endl;
        cout << "3.) Load Player From Local " << endl;
        cout << "4.) Save All to File " << endl;
        cout << "5.) Load All From File" << endl;
        cout << "6.) Delete From Local " << endl;
        cout << "7.) Display Current Player " << endl;
        cout << "8.) Display All Local Saves " << endl;
        cout << "9.) Edit Current Player Data " << endl;
        cout << "10.) Return To Main Menu " << endl;
        cout << endl;
        cout << "Menu Input: ";
        cin >> input;
        cout << endl;
        
        
        
        //The Redirection Options for each selection to their relevant functions
        
        
        if(input == 1){
            create_new_player();
        }
        else if(input == 2){
            save_to_local();
        }
        else if(input == 3){
            load_from_local();
        }
        else if(input == 4){
            save_to_file();
        }
        else if(input == 5){
            load_from_file();
        }
        else if(input == 6){
            delete_local_player();
        }
        else if(input == 7){
            display_current_player();
        }
        else if(input == 8){
            display_all_local();
        }
        else if(input == 9){
            edit_current_data();
        }

        
        
        
        
    }while(input != 10);
    
    cout << "Returning to Main Menu " << endl << endl;
    
};




void player_quiz_menu(){
    
    /*A Secondary Loop That is instantiated by selecting option 2 from the main menu
    This Gives Further Options for the users which relate to the personality quiz
    Aspects of the Program.
    */
    
    int input;
    
    do{
        cout << "\n===== This is The Personality Quiz Menu ===== " << endl;
        cout << "1.) Take Personality Quiz" << endl;
        cout << "2.) Enter Your Own Quiz Result" << endl;
        cout << "3.) See Recommended Courses " << endl;
        cout << "4.) See Recommended Starting Stats " << endl;
        cout << "5.) Return To Main Menu " << endl;
        cout << endl;
        cout << "Menu Input: ";
        cin >> input;
        cout << endl;
        
        
        if(input == 1){
            take_p_quiz();
        }
        else if(input == 2){
            set_personality_profile();
        }
        else if(input == 3){
            display_recomm_courses();
        }
        else if(input == 4){
            display_recomm_stats();
        }else{
            cout << " An Incorrect input has occurred (Press 5 to return to main menu or try again)" << endl;
        }

        
    }while(input != 5);
    
    cout << "Returning to Main Menu " << endl << endl;
    
};




void stat_display_menu(){
    
    int input;
    
    do{
        cout << "===== This is The Display Menu ===== " << endl;
        cout << "1.) Current Player Data" << endl;
        cout << "2.) Scenarios List" << endl;
        cout << "3.) Minigames List " << endl;
        cout << "4.) Highscores " << endl;
        cout << "5.) List of Save Games " << endl;
        cout << endl;
        cout << "Menu Input: ";
        cin >> input;
        cout << endl;
        
        
        
        
    }while(input != 5);
    
    cout << "Returning to Main Menu " << endl << endl;
    
};










void create_new_player(){
    //New Game Option From Menu
    //Player chooses to save the current 
    
    
    if(current.ret_id() == -1){
        cout << "Any Unsaved Changes to the Current Player will be Discarded " << endl;
        cout << "Save Current Player (y/n): ";
        char opt;
        cin >> opt;
        
        if(opt == 'n' || opt == 'N'){
            current.create_new_player();
        }else if (opt == 'y' || opt == 'Y'){
            current.save_to_local();
            cout << "Player Has Been Saved " << endl;
            current.create_new_player();
            
        }else{
            cout << "Incorrect Input, Returning to Player Menu" << endl << endl;
        }
    }else{
         current.create_new_player();
    }
    
}



void save_to_local(){
    //Save the Player to the local storage
    current.save_to_local();
    cout << "Player Has Been Saved " << endl;
    
}


void load_from_local(){
    //Load A Locally Saved Game into Current Player
    current.load_from_local();
    cout << "Player Has Been Loaded " << endl;
}


void save_to_file(){
    //Update the file with the locally saved games
    current.save_all_loaded_files();
    
}

void load_from_file(){
    //Load the saves that are stored int he file
    current.get_saves_from_file();
    
}


void delete_local_player(){
    //Delete a Save from the local storage
    current.delete_from_local();
    
}


void display_current_player(){
    //Displays the Loaded Players Data
    current.display_current_player_data();
    
}

void display_all_local(){
    //Displays all the Locally saved Players Data
    current.display_all_local_saves();
    
}

void edit_current_data(){
    //Edit the loaded players Data freely
    cout << "To Be Implemented" << endl;
    current.edit_player_data();
    
}

void take_p_quiz(){
    //Starts the Personality Quiz function
    start_quiz();
}


void set_personality_profile(){
    //Sets the Personality Profile to a custom one
    
    //Needs a check against valid profile codes but im too lazy atm
    
    
    
    cout << "Enter a Profile Code: " ;
    string newprof;
    cin.get();
    getline(cin,newprof,'\n');
    MB_Global = newprof;
    
    char opt;
    cout << "Would you like to Set this to the Current Profile? (y/n) " << endl;
    cin >> opt;
    if(opt == 'y'){
        current.set_MB(newprof);
    }else if(opt == 'n'){
        cout << "Current Profile Unchanged " << endl;
    }
    
}

void display_recomm_courses(){
    
}

void display_recomm_stats(){

    
}

