//
//  newplayer.cpp
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "newplayer.h"


newplayer::newplayer(int){
    
}

void newplayer::saveplayer(){
    
    ofstream myfile ("players.txt");
    if (myfile.is_open())
    {
        myfile << p_id << "\n";
        myfile << p_name << "\n";
        myfile << p_degree << "\n";
        myfile << p_int << "\n";
        myfile << p_soc << "\n";
        myfile << p_sta << "\n";
        myfile << p_money << "\n";
        myfile << p_energy << "\n";
        myfile << p_academic << "\n";
        myfile << p_stress << "\n";
        myfile << p_MB_result << "\n";
        
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }
    
    
}