//
//  personalityquiz.cpp
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "personalityquiz.h"



void start_quiz(){
    get_p_type();
}

void get_p_type()
{
    
    
    MB_Profile current_prof;

    
    
    std::ifstream quizfile;
    quizfile.open ("/Users/csci321ga2a/Desktop/321Test/321Test/quiz_questions.txt");
    
    std::string question;
    char code;
    int inscore;
    
    
    if (quizfile.is_open()){
    
        cout << "----RATE YOURSELF ON EACH QUESTION----" << std::endl;
        cout << "5 -- A Lot Like Me" << endl;
        cout << "4 -- A Bit Like Me" << endl;
        cout << "3 -- Halfway" << endl;
        cout << "2 -- Not Much Like Me" << endl;
        cout << "1 -- Not Like Me At All" << endl;
        
        char checker = '\0';
        bool endhelp = false;
        do{
            cout << "Are You Ready To Take The Quiz? (y/n): ";
            cin >> checker;
            if(checker == 'N' || checker == 'n'){
            cout << "Returning to Menu \n\n ";
                return;
            }
            if(checker == 'Y' || checker == 'y'){
                endhelp = true;
            }
        }while(endhelp != true);
        
        while(!quizfile.eof()){
            quizfile.get(code);
            quizfile.get();
            quizfile.get();
            getline(quizfile,question);
            cout << "QUESTION: " << question << std::endl;
            cout << "SCORE: ";
            cin >> inscore;
            current_prof.AddScore(code,inscore);
        }
    }else if(quizfile.fail()){
        std::cout << "BAD FILE, BAD TIMES\n";
        exit(1);
    }
    
    
    cout << "\n ===== YOUR PERSONALITY PROFILE IS ===== \n";
    cout << current_prof.MB_Result() << endl;
;
    
    quizfile.close();
}


void MB_Profile::AddScore(char q_code, int q_score){
    
    if(q_code == 'E'){
        score_E += q_score;
    }
    else if(q_code == 'I'){
        score_I += q_score;
    }
    else if(q_code == 'S'){
        score_S += q_score;
    }
    else if(q_code == 'N'){
        score_N += q_score;
    }
    else if(q_code == 'T'){
        score_T += q_score;
    }
    else if(q_code == 'F'){
        score_F += q_score;
    }
    else if(q_code == 'J'){
        score_J += q_score;
    }
    else if(q_code == 'P'){
        score_P += q_score;
    }
    
}



string MB_Profile::MB_Result(){
    string result;
    
    if(score_E > score_I){
        result.insert(0,"E");
    }else if(score_E < score_I){
        result.insert(0,"I");
    }else{
        result.insert(0,"X");
    }
    
    if(score_S > score_N){
        result.insert(1,"S");
    }else if(score_S < score_N){
        result.insert(1,"N");
    }else{
        result.insert(1,"X");
    }
    
    if(score_T > score_F){
        result.insert(2,"T");
    }else if(score_T < score_F){
        result.insert(2,"F");
    }else{
        result.insert(2,"X");
    }
    
    if(score_J > score_P){
        result.insert(3,"J");
    }else if(score_J < score_P){
        result.insert(3,"P");
    }else{
        result.insert(3,"X");
    }
    return result;
}


MB_Profile::MB_Profile(){

     score_E = 0;
     score_I = 0;
     score_S = 0;
     score_N = 0;
     score_T = 0;
     score_F = 0;
     score_J = 0;
     score_P = 0;
    
    
}











