//
//  scenarios.cpp
//  321Test
//
//  Created by csci321ga2a on 2/07/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "scenarios.h"
#include "player_data.h"




void init_new_game(){


    char opt;
    cout << "Would You like to run the tutorial? " << endl;
    cin >> opt;
    
    if(opt == 'y'){
        run_tutorial();
    }
    if(opt == 'n'){
        //STUB
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


void print_game_screen(){
    int view = 3;
    string location = "Office of Swagomatics";
    int ene = 100;
    int aca = 100;
    int str = 100;
    
    
    cout << "----------------------------------------------------------------------------------------\n";
    cout << "Location: " << location << endl;
    cout << "View: " << view << endl;
    cout << "Energy: " << ene << endl;
    cout << "Stress: " << str << endl;
    cout << "Academic: " << aca << endl;
    cout << "----------------------------------------------------------------------------------------\n";

    
    
}

