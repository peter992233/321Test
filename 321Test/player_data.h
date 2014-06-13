//
//  player_data.h
//  321Test
//
//  Created by csci321ga2a on 13/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#ifndef ___21Test__player_data__
#define ___21Test__player_data__

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class player_data{
    
    //ID
    long p_id;
    
    //Player Name As String
    string p_name;
    
    //Chosen Degree As String (May be Indexed Later)
    string p_degree;
    
    //Initial Player Stats Chosen
    int p_int, p_sta, p_soc, p_money;
    
    //Current Meter Levels
    double p_energy, p_academic, p_stress;
    
    //Personality Profile Result
    string p_MB_result;
    
public:
    player_data();
    void set_data(string);
    void display_data();
    void save_data();
    void load_data();
    int num_saves();
    void set_MB(string);
    
};




#endif /* defined(___21Test__player_data__) */
