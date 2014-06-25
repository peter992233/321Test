//
//  player_data.cpp
//  321Test
//
//  Created by csci321ga2a on 13/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "player_data.h"
vector<string> playerlist;

//Initialize function
player_data::player_data(){
    
    
    
}






void player_data::display_current_player_data(){
    /*
     This Module is to output the Current Player Data
     that is loaded
     */
    cout << "\n===========CURRENT PLAYER===========\n";
    cout << "PID: " << p_id << endl;
    cout << "Name: " << p_name << endl;
    cout << "Degree: " << p_degree << endl;
    cout << "Stats\n INT: " << p_int << "\n STA: " << p_sta << "\n SOC: " <<p_soc << endl;
    cout << "Meters\n Energy: " << p_energy << "\n Stress: " ;
    cout << p_stress << "\n Academic: " <<p_academic << endl;
    cout << "MB Result: " << p_MB_result << endl << endl;

    
    
}



void player_data::set_MB(string inMB){
    p_MB_result = inMB;
}







void player_data::create_new_player(){
    /*
     This Module is to Create a new player by setting all the Stats
     to their default values and accepting a name.
     This loads the instance to be the currently selected player
     */
    
    p_id = playerlist.size() + 1;
    
    //Player Enters Their Name
    cout << "Enter Your Name: ";
    cin.get();
    getline(cin,p_name,'\n');
    
    
    //Default Values Are Set
    cout << "Creating New Player" << endl;
    p_degree = "General";
    p_int = 5;
    p_sta = 5;
    p_soc = 5;
    p_energy = 100;
    p_academic = 100;
    p_stress = 0;
    p_MB_result = "XXXX";
    
}

void player_data::get_saves_from_file(){
    
    /*
     This Module Gets the saves that are stored in the file and loads them into memory
     */
    
    
    //Delete Local Data
    playerlist.clear();
    
    
    //Load Data From File
    ifstream infile;
    infile.open("/Users/csci321ga2a/Desktop/321Test/321Test/player_data.txt", ios::in);
    
    //Check if file is good
    if (!infile){
        cout<<"Input file cannot be opened!"<<endl;
    }
    else
    {
        //Output the Loaded Players For Debugging Purposes
        cout<<"---------------------------------"<<endl;
        cout<<"List of Players:"<<endl;
        string wordLine;
        
        //Add the lines to the Global Vector and Output to Screen
        while (!infile.eof()){
            getline(infile,wordLine,'\n');
            playerlist.push_back(wordLine);
            cout << wordLine << endl;
        }
        cout << "---------------------------------" << endl << endl;
    }
    
    
    //Close the Input File
    infile.close();
    
}

void player_data::display_all_local_saves(){
    /*
     This Module Displays all the local save files in memory
     NOT the ones stored in the text file
     */
    
    cout<<"---------------------------------"<<endl;
    cout<<"List of Players:"<<endl;
    for (int looper = 0; looper < playerlist.size(); looper++) {
        cout << playerlist[looper] << endl;
    }
    cout << "---------------------------------" << endl << endl;

}

void player_data::save_all_loaded_files(){
    
    /*
     This Module Saves all the local save files in memory
     to the text file
     */
    
    
    
    ofstream myFile;
    myFile.open("/Users/csci321ga2a/Desktop/321Test/321Test/player_data.txt");
    for (int looper = 0; looper < playerlist.size(); looper++) {
        
        if(looper != 0){
            myFile << endl << playerlist[looper];
        }else{
            myFile << playerlist[looper];
        }
    }
    myFile.close();
    
}

void player_data::delete_from_local(){
    
    /*
     This Module Deletes a Single Element
     from the playerlist Vector which stores
     the local game saves
     */
    
    int todelete = 0;
    
    bool inputgood = false;
    
    while(inputgood == false){
        cout << "Enter the Save file You Wish to Delete(Or Enter 0 to Exit): ";
        cin >> todelete;
        
        if (todelete < 0 || todelete > playerlist.size()){
            cout << "\n\nBAD INPUT NOT IN RANGE \n\n";
        }else if(todelete == 0){
            cout << "Return to Menu" << endl;
            break;
        }else{
            inputgood = true;
            
            cout << "Deleting Save Number " << todelete << endl;
            
            playerlist[todelete-1].erase();
            
            for(int i = todelete - 1; i < playerlist.size(); i++)
            {
                playerlist[i] = playerlist[i+1];
            }
            playerlist.pop_back();
            cout << "Save " << todelete  << " Erased " << endl;
        }
    }
    
}



void player_data::load_from_local(){
    /*
     This Module Loads a Single Save State to the Current
     Game Save from the playerlist vector
     */
    int toload = 0;
    
    bool inputgood = false;
    
    display_all_local_saves();
    
    while(inputgood == false){
        cout << "Enter the Save file You Wish to Load: ";
        cin >> toload;
        
        
        if (toload < 0 || toload > playerlist.size()){
            cout << "\n\n BAD INPUT NOT IN RANGE \n\n";
        }else{
            inputgood = true;
            
            cout << "Loading Save Number " << toload << endl;
            
            stringstream ss(playerlist[toload-1]);
            
            ss >> p_id;
            ss.get();
            getline(ss,p_name,';');
            getline(ss,p_degree,';');
            ss >> p_int;
            ss.get();
            ss >> p_sta;
            ss.get();
            ss >> p_soc;
            ss.get();
            ss >> p_energy;
            ss.get();
            ss >> p_academic;
            ss.get();
            ss >> p_stress;
            ss.get();
            getline(ss,p_MB_result,';');
            
            
            cout << "Save File " << toload  << " Loaded " << endl;
        }
    }

    
    

}


void player_data::save_to_local(){
    /*
     This Module Loads a Single Save State to the Current
     Game Save from the playerlist vector
     */
    int in_id = 0;
    char overwrite = '\0';
    
    string compiledsave;
    
    
        cout << "Saving Current Player: ";
            
            for(int i = 0; i < playerlist.size();i++){
            stringstream ss(playerlist[i]);
            ss >> in_id;
                if(in_id == p_id){
                    cout << "Would You Like to Overwrite Previous Save? (y/n)" ;
                    cin >> overwrite;
                    
                    if(overwrite == 'n'){
                         //Push to the back and change p_id
                        stringstream outstring(compiledsave);
                        outstring << (playerlist.size()+1) << ";" << p_name << ";" << p_degree << ";" << p_int << ";" << p_sta << ";"<< p_soc << ";"<< p_energy << ";"<< p_academic << ";"<< p_stress << ";"<< p_MB_result << ";";
                        playerlist.push_back(outstring.str());
                        return;
                    }else if(overwrite == 'y'){
                        //Overwrite the variable in the same slot
                        stringstream outstring(compiledsave);
                        outstring << p_id << ";" << p_name << ";" << p_degree << ";" << p_int << ";" << p_sta << ";"<< p_soc << ";"<< p_energy << ";"<< p_academic << ";"<< p_stress << ";"<< p_MB_result << ";";
                        playerlist[p_id] = outstring.str();
                        return;
                        
                    }else{
                        cout <<"Bad Input, No Save For You!" << endl;
                        return;
                    }
                    
                }
                    
            }
        stringstream outstring(compiledsave);
        outstring << p_id << ";" << p_name << ";" << p_degree << ";" << p_int << ";" << p_sta << ";"<< p_soc << ";"<< p_energy << ";"<< p_stress << ";"<< p_academic << ";"<< p_MB_result << ";";
        playerlist.push_back(outstring.str());

    
    
}




