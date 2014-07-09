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
#include <vector>
#include <sstream>
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
    
    
    //Personality Profile Result
    string p_MB_result;
    
    
public:
    
    //Old Implentations
    player_data();
    
    //Menu = 0, Map View = 1, Outside View = 2, inside view = 3, dorm view = 4, phone/PDA view = 5
    int location;
    
    
    //previous location - for returning form the menu
    int prev;
    
    
    //Current Meter Levels
    double p_energy, p_academic, p_stress;
    
    //New Implementations
    void set_MB(string);
    void display_current_player_data();
    void create_new_player();
    void save_to_local();
    void get_saves_from_file();
    void display_all_local_saves();
    void save_all_loaded_files();
    void delete_from_local();
    void load_from_local();
    long ret_id();
    void edit_player_data();
    
};




#endif /* defined(___21Test__player_data__) */
