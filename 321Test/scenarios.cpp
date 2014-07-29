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


void init_new_game(player_data &loaded){

        char opt;
        cout << "Would You like to run the tutorial? " << endl;
        cin >> opt;
        
        if(opt == 'y'){
            run_tutorial();
            loaded.TH.newgame();
        }
        if(opt == 'n'){
            loaded.TH.newgame();
        }
    
    cout << "Beginning Game " << endl;
    gameloop(loaded);
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


void print_game_screen(player_data &loaded){

    
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Time: " << loaded.TH.retTime() << endl;
    cout << "Day: " << loaded.TH.retDay() << endl;
    cout << "Location: " << loaded.location << endl;
    cout << "Energy: " << loaded.p_energy << endl;
    cout << "Stress: " << loaded.p_stress  << endl;
    cout << "Academic: " << loaded.p_academic  << endl;
    cout << "----------------------------------------------------------------------------------------\n";

    
    
}





//Dictates Where the game is at and which function is relevant for option choices
//such as changing locations
void gameloop(player_data &loaded){
    
    
    if(loaded.TH.week == 0){
        init_new_game(loaded);
    }
    
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
void ret_to_men(player_data &loaded){
    
    loaded.save_to_local();
    loaded.save_all_loaded_files();
    exit(1);
}


//Show ingame menu Options
void gl_ingame_menu(player_data &loaded){
    
    int option;
    
    cout << "1) Save & Quit" <<endl;
    cout << "2) Exit Without Saving" <<endl;
    cout << "3) Enter Map " << endl;
    cout << "4) Return to Game" <<endl;
    cin >> option;
    
    if(option == 1){
        
    }else if(option == 2){
        exit(1);
    }else if(option == 3){
        loaded.location = 1;
        cout << "loaded.location " << loaded.location << endl;
    }else if(option == 4){
        loaded.location = loaded.prev;
    }
    else{
        cout << "Incorrect Input" << endl;
    }
}


//Show Map Options
void gl_map(player_data &loaded){
    int option = 0;
    cout << "1) Open Menu" <<endl;
    cout << "2) Go To Dorm" <<endl;
    cout << "3) Go To Outside" <<endl;
    cout << "4) Go To PDA" <<endl;
    cin >> option;
    loaded.prev = 1;
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
void gl_inside(player_data &loaded){
    int option = 0;
    cout << "1) Open Menu" <<endl;
    cout << "2) Go Outside" <<endl;
    cout << "3) Go To Lecture" <<endl;
    cout << "4) Go To Tutorial" <<endl;
    cout << "5) Go To Office" <<endl;
    cout << "6) Go To Notice board" <<endl;
    cin >> option;
        loaded.prev = 3;
    if(option == 1){
        loaded.location = 0;
    }else if(option == 2){
        loaded.location = 0;
    }else if(option == 3){
        //Attend Lecture
    }else if(option == 4){
        //Attend Tutorial
    }else if(option == 5){
        //Go To Office
    }else if(option == 6){
        //Display Noticeboard
    }else{
        cout << "Incorrect Input" << endl;
    }

    
    
}

//show Outside building Options
void gl_outside(player_data &loaded){
    
    
    
    //Generate RNG
    //Compare RNG to Available Events
    //Display One Event if it falls in the given range
    
    
    int option = 0;
    cout << "1) Open Menu" <<endl;
    cout << "2) Go Inside" <<endl;
    cout << "3) Go To Map" <<endl;
    cout << "4) NPC/Event (optional RNG)" <<endl;
    cin >> option;
      loaded.prev = 2;
    if(option == 1){
        loaded.location = 0;
    }else if(option == 2){
        loaded.location = 3;
    }else if(option == 3){
        loaded.location = 1;
    }else if(option == 4){
        //Interact With Event/NPC
    }else{
        cout << "Incorrect Input" << endl;
    }

    
    
}

// Show Dorm Building options
void gl_dorm(player_data &loaded){

    
    int option = 0;
    cout << "1) Open Menu" <<endl;
    cout << "2) Go To Map" <<endl;
    cout << "3) Play A VideoGame (Reduce Stress, Uses Time)" <<endl;
    cout << "4) Study (Uses Academic for ++ in Course Content)" <<endl;
    cout << "5) Sleep (Ends Current Day)" <<endl;
    cout << "6) Go For A Run (Increases Stamina Gain, Uses Energy)" <<endl;
    cout << "7) Open PDA" <<endl;
    
    cin >> option;
    loaded.prev = 4;
    if(option == 1){
        loaded.location = 0;
    }else if(option == 2){
        loaded.location = 1;
    }else if(option == 3){
        //Play Videogame
        cout << " You Played A VideoGame " << endl;
        loaded.TH.addtime(1.00);
    }else if(option == 4){
        //Study
        cout << " You Studied For an Hour " << endl;
        loaded.TH.addtime(1.00);
    }else if(option == 5){
        //Sleep
        double howmuchsleep;
        howmuchsleep = loaded.TH.sleep();
        if(howmuchsleep < 6){
            loaded.p_energy += 50;
        }else if(howmuchsleep > 6){
            loaded.p_energy += 100;
        }
        if(loaded.p_energy > 100){
            loaded.p_energy = 100;
        }
        
        
    }else if(option == 6){
        //Go For Run
        if(loaded.p_energy < 2){
            cout << "You Do Not Have enough Energy To Go For A Run " << endl;
        }
    }else if(option == 7){
        loaded.location = 5;
    }else{
        cout << "Incorrect Input" << endl;
    }

    
}

//Show PDA Options
void gl_pda(player_data &loaded){

    int option = 0;
    cout << "1) Open Menu" <<endl;
    cout << "2) Go To Map" <<endl;
    cout << "3) View Subjects" <<endl;
    cout << "4) View Objectives" <<endl;
    cout << "5) PDA Home Screen" <<endl;
    cout << "6) View Progress" <<endl;
    cout << "7) Exit PDA" <<endl;
    
    cin >> option;
    loaded.prev = 5;
    
    if(option == 1){
        loaded.location = 0;
    }else if(option == 2){
        loaded.location = 1;
    }else if(option == 3){
        //View Subjects and Progress
    }else if(option == 4){
        //View Objectives
    }else if(option == 5){
        //View PDA Home Screen
    }else if(option == 6){
        //View Game Progress/Stats
    }else if(option == 7){
        loaded.location = loaded.prev;
    }else{
        cout << "Incorrect Input" << endl;
    }

    
}










