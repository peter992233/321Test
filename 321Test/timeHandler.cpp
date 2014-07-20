//
//  timeHandler.cpp
//  321Test
//
//  Created by csci321ga2a on 20/07/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "timeHandler.h"


timehandler::timehandler(){
    hour = 0; //Time in 24hr Format (13.50 = 1:30PM)
    day = 0; // From 1-7 ( 1 = Monday to 7 = Sunday)
    week = 0;; // From 1-16 (6 weeks, 1 week break, 7 weeks, 1 week study, 1 week exams)
    semester = 0; //from 1-6 (alternating Autumn, Spring sessions)
    
}


void timehandler::newgame(){
    hour = 8.00; //Time in 24hr Format (13.50 = 1:30PM)
    day = 1; // From 1-7 ( 1 = Monday to 7 = Sunday)
    week = 1; // From 1-16 (6 weeks, 1 week break, 7 weeks, 1 week study, 1 week exams)
    semester = 1; //from 1-6 (alternating Autumn, Spring sessions)

}

int timehandler::retDay(){
    
    return day;
}

double timehandler::retTime(){
    
    return hour;
}



void timehandler::addtime(double moretime){
    
    double newtime = moretime + hour;
    if (newtime > 24.00){
        
        day++;
        newtime -= 24;
        
        if(day > 7){
            day = 1;
            week++;
            if(week == 7){
            //Mid Semester Break
            }else if(week == 13){
            //Study Week
            }else if(week == 14){
            //Exam Week
            }
            
        }
    }
    
}