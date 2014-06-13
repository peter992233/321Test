//
//  player_data.cpp
//  321Test
//
//  Created by csci321ga2a on 13/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "player_data.h"

//Initialize function
player_data::player_data(){
    
    
    
}



void player_data::set_data(string MB_in){
   
    cout << "Enter Your Name: ";
    cin.get();
    getline(cin,p_name,'\n');
    cout << "Creating New Player" << endl;
    p_degree = "General";
    p_int = 5;
    p_sta = 5;
    p_soc = 5;
    p_energy = 100;
    p_academic = 100;
    p_stress = 0;
    p_MB_result = MB_in;
}



void player_data::display_data(){
    
    cout << "\n===========CURRENT PLAYER===========\n";
    cout << "PID: " << p_id << endl;
    cout << "Name: " << p_name << endl;
    cout << "Degree: " << p_degree << endl;
    cout << "Stats\n INT: " << p_int << "\n STA: " << p_sta << "\n SOC: " <<p_soc << endl;
    cout << "Meters\n Energy: " << p_energy << "\n Stress: " ;
    cout << p_stress << "\n Academic: " <<p_academic << endl;
    cout << "MB Result: " << p_MB_result << endl << endl;

    
    
}


void player_data::save_data(){
    
    int numsaves = 0;
    
    //Get the number of Saves that exist and Add 1
    ifstream file;
    file.open ("/Users/csci321ga2a/Desktop/321Test/321Test/global_data.txt");
    if (file.is_open()){
        file >> numsaves;
        cout << "\nNumber Of Saves: " << numsaves << endl;
    }else{
        cout << "File[1] Fail" << endl;
    }
    
    
    numsaves++;
    
    
    ofstream file2;
    file2.open ("/Users/csci321ga2a/Desktop/321Test/321Test/global_data.txt");
    if (file2.is_open()){
        file2 << numsaves;
    }else{
        cout << "File[2] Fail" << endl;
    }
    
    
    
    file.close();
    
    fstream savefile;
    savefile.open ("/Users/csci321ga2a/Desktop/321Test/321Test/savefile.txt", ios::app | ios::out | ios::app);
    if (savefile.is_open()){
        p_id = numsaves;
        savefile << p_id << ";" << p_degree << ";";
        savefile << p_int << ";" << p_sta << ";" << p_soc << ";";
        savefile << p_energy << ";" << p_academic << ";" << p_stress << ";" ;
        savefile << p_MB_result << ";" << endl;
    }else{
        cout << "File[3] Fail" << endl;
    }
    savefile.close();
    
}


void player_data::load_data(){
    
}

int player_data::num_saves(){
    
    fstream infile;
    infile.open ("/Users/csci321ga2a/Desktop/321Test/321Test/global_data.txt");
    int numsaves;
    infile >> numsaves;
    cout << "\nNumber Of Saves: " << numsaves;
    infile.close();
    return numsaves;
}

