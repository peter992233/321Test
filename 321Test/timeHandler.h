//
//  timeHandler.h
//  321Test
//
//  Created by csci321ga2a on 20/07/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#ifndef ___21Test__timeHandler__
#define ___21Test__timeHandler__

#include <iostream>

class timehandler{

public:
    
    //Time Variables
    double hour; //Time in 24hr Format (13.50 = 1:30PM)
    int day; // From 1-7 ( 1 = Monday to 7 = Sunday)
    int week; // From 1-16 (6 weeks, 1 week break, 7 weeks, 1 week study, 1 week exams)
    int semester; //from 1-6 (alternating Autumn, Spring sessions)
    
    void newgame();
    int retDay();
    double retTime();
    void addtime(double);
    timehandler();
    double sleep();
    
};






#endif /* defined(___21Test__timeHandler__) */
