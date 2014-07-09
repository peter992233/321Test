//
//  scenarios.cpp
//  321Test
//
//  Created by csci321ga2a on 2/07/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//


#include "scenarios.h"

//NOTES
//Menu = 0, Map View = 1, Outside View = 2, inside view = 3, dorm view = 4, phone/PDA view = 5


void init_new_game(player_data loaded){


    char opt;
    cout << "Would You like to run the tutorial? " << endl;
    cin >> opt;
    
    if(opt == 'y'){
        run_tutorial();
    }
    if(opt == 'n'){
        gameloop(loaded);
    }
}


void run_tutorial(){
    
    ifstream infile;
    infile.open("/Users/csci321ga2a/Desktop/321Test/321Test/tutorial.txt", ios::in);
    string para;
    char next;
    
    bool cont = true;
    while (!infile.eof()){
        if(cont == true){
            getline(infile,para,'#');
            cout << para;
            cont = false;
        }
        
        cout << endl << "Next > ";
        cin >> next;
        if(next == 'n'){
            cont = true;
        }
        else{
            cont = false;
            cout << "Incorrect input (Enter n to continue) : ";
            cout << endl;
        }
        
    }
    
    
    infile.close();
    
    cout << endl << "Run Successful" << endl;
    

}


void print_game_screen(player_data loaded){

    
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Location: " << loaded.location << endl;
    cout << "Energy: " << loaded.p_energy << endl;
    cout << "Stress: " << loaded.p_stress  << endl;
    cout << "Academic: " << loaded.p_academic  << endl;
    cout << "----------------------------------------------------------------------------------------\n";

    
    
}





//Dictates Where the game is at and which function is relevant for option choices
//such as changing locations
void gameloop(player_data loaded){
    
    bool endgame = false;
    while(endgame != true){
        
        
        //Prints the Current Game Character Data
        print_game_screen(loaded);
        
        cout << "OPTIONS" << endl;
        
        if(loaded.location == 0){
            gl_ingame_menu(loaded);
        }else if(loaded.location == 1){
            gl_map(loaded);
        }else if(loaded.location == 2){
            gl_outside(loaded);
        }else if(loaded.location == 3){
            gl_inside(loaded);
        }else if(loaded.location == 4){
            gl_dorm(loaded);
        }else if(loaded.location == 5){
            gl_pda(loaded);
        }else{
            cout << "BAD INPUT " << endl;
        }
        
    }
    
    
    
    
}





//Returns player data to the menu and ends all the game data
void ret_to_men(player_data loaded){
    
    loaded.save_to_local();
    loaded.save_all_loaded_files();
    exit(1);
}


//Show ingame menu Options
void gl_ingame_menu(player_data loaded){
    
    int option;
    
    cout << "1) Save & Quit" <<endl;
    cout << "2) Exit Without Saving" <<endl;
    cout << "3) Return to Game" <<endl;
    cin >> option;
    
    if(option == 1){
        
    }else if(option == 2){
        exit(1);
    }else if(option == 3){
        loaded.location = loaded.prev;
    }else{
        cout << "Incorrect Input" << endl;
    }
}


//Show Map Options
void gl_map(player_data loaded){
     int option;
    cout << "1) Open Menu" <<endl;
    cout << "2) Go To Dorm" <<endl;
    cout << "3) Go To Outside" <<endl;
    cout << "4) Go To PDA" <<endl;
    cin >> option;
    
    if(option == 1){
        loaded.location = 0;
    }else if(option == 2){
        loaded.location = 4;
    }else if(option == 3){
        loaded.location = 2;
    }else if(option == 4){
        loaded.location = 5;
    }else{
        cout << "Incorrect Input" << endl;
    }

    
}

//Show Faculty building Options
void gl_inside(player_data loaded){

    
    
}

//show Outside building Options
void gl_outside(player_data loaded){

    
    
}

// Show Dorm Building options
void gl_dorm(player_data loaded){

    
    
}

//Show PDA Options
void gl_pda(player_data loaded){

    
    
}










