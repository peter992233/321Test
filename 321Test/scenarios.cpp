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
    
    
}