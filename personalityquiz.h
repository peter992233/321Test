//
//  personalityquiz.h
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#ifndef ___21Test__personalityquiz__
#define ___21Test__personalityquiz__

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class MB_Profile{
    
    int score_E;
    int score_I;
    int score_S;
    int score_N;
    int score_T;
    int score_F;
    int score_J;
    int score_P;
    
    public:
    MB_Profile();
    void AddScore(char,int);
    string MB_Result();
};




void start_quiz();
void get_p_type();

#endif /* defined(___21Test__personalityquiz__) */
