//
//  newplayer.h
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#ifndef ___21Test__newplayer__
#define ___21Test__newplayer__

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class newplayer{
    
    //ID
        int p_id;
    
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
        newplayer(int);
        void saveplayer();
    
};






#endif /* defined(___21Test__newplayer__) */
