//
//  newplayer.cpp
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "newplayer.h"


newplayer::newplayer(){
    
}

void newplayer::initplayer(string p_name,string p_degree){
    
    
    
    fstream file;
    file.open("players.txt");
    
    int numsaves = cin.get();
    numsaves += 1;
    
    file.close();
    
    
    
    cout << "Creating New Player" << endl;
    this->p_name = p_name;
    this->p_degree = p_degree;
    p_int = 5;
    p_sta = 5;
    p_soc = 5;
    p_energy = 100;
    p_academic = 100;
    p_stress = 0;
    p_MB_result = "XXXX";
    
    
    
    

}

void newplayer::saveplayer(){
    
}

void newplayer::showcurrent(){
    
    cout << "\n===========CURRENT PLAYER===========\n";
    cout << "PID: " << p_id << endl;
    cout << "Name: " << p_id << endl;
    cout << "Degree: " << p_id << endl;
    cout << "Stats\n INT: " << p_int << "\n STA: " << p_sta << "\n SOC: " <<p_soc << endl;
    cout << "Meters\n Energy: " << p_energy << "\n Stress: " << p_stress << "\n Academic: " <<p_academic << endl;
    cout << "MB Result: " << p_MB_result << endl << endl;
    
}