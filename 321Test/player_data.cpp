//
//  player_data.cpp
//  321Test
//
//  Created by csci321ga2a on 13/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include "player_data.h"


//The Save files that are locally stored Go here
vector<string> playerlist;





//Initialize function
player_data::player_data(){
    
    //STUB
    
    p_id = -1;
    p_name = "BLANK";
    p_degree = "BLANK";
    p_int = 0;
    p_sta = 0;
    p_soc = 0;
    p_energy = 0;
    p_stress = 0;
    p_academic = 0;
    p_MB_result = "XXXX";
}






void player_data::display_current_player_data(){
    /*
     This Module is to output the Current Player Data
     that is loaded into memory
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
    
    /*
     Sets the Myers-Briggs Personality Type to the current Profile
     */
    
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
    
    
    
    int toload = 0; //The ID of the save state to be loaded
    
    bool inputgood = false; //Input is checked for validity
    
    
    display_all_local_saves();//Displays the Existing Saves
    
    
    //Loops until valid input is given
    while(inputgood == false){
        cout << "Enter the Save file You Wish to Load: ";
        cin >> toload;
        
        
        //If it does not exist in the list
        if (toload < 0 || toload > playerlist.size()){
            cout << "\n\n BAD INPUT NOT IN RANGE \n\n";
        }else{
            
            //If it does exist in the list it loads the data using a string stream into the
            //Currently active player
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
    
    
    
    int in_id = 0; //This is the check against the save games to see if there is an existing profile that contains the same save data
    char overwrite = '\0'; // This is an input option on whether or not to override the previous game
    
    string compiledsave; // This is a string variable which holds the newly compiled dave game data
    
    
        cout << "Saving Current Player: ";
    
    
        //loops until the end of the player_list vector size
    
            for(int i = 0; i < playerlist.size();i++){
                
            //Pulls in the ID from the first line of each in the list
            stringstream ss(playerlist[i]);
            ss >> in_id;
                
                //If there is an ID match
                if(in_id == p_id){
                    cout << "Would You Like to Overwrite Previous Save? (y/n)" ;
                    cin >> overwrite;
                    
                    if(overwrite == 'n'){
                        //If you do not wish to override and want to create a new save game from the data
                         //compiles the string and pushed it back while changing the p_id
                        stringstream outstring(compiledsave);
                        outstring << (playerlist.size()+1) << ";" << p_name << ";" << p_degree << ";" << p_int << ";" << p_sta << ";"<< p_soc << ";"<< p_energy << ";"<< p_academic << ";"<< p_stress << ";"<< p_MB_result << ";";
                        playerlist.push_back(outstring.str());
                        return;
                    }else if(overwrite == 'y'){
                        //If you do want to override and replace the save game from the current data
                        //compiles the string and writes over the existing string
                        stringstream outstring(compiledsave);
                        outstring << p_id << ";" << p_name << ";" << p_degree << ";" << p_int << ";" << p_sta << ";"<< p_soc << ";"<< p_energy << ";"<< p_academic << ";"<< p_stress << ";"<< p_MB_result << ";";
                        playerlist[p_id] = outstring.str();
                        return;
                        
                    }
                    else    //If there is No Matching ID in the list
                    {
                        cout <<"Bad Input, No Save For You!" << endl;
                        return;
                    }
                    
                }
                    
            }
    
        //If no return condition is hit we can assume there is no existing conflict and the save state can simply be added to the back of the list
        //without conflicting with any existing saves
        stringstream outstring(compiledsave);
        outstring << p_id << ";" << p_name << ";" << p_degree << ";" << p_int << ";" << p_sta << ";"<< p_soc << ";"<< p_energy << ";"<< p_stress << ";"<< p_academic << ";"<< p_MB_result << ";";
        playerlist.push_back(outstring.str());

    
    
}


long player_data::ret_id(){
    return p_id;
}


void player_data::edit_player_data(){
    
    player_data temp;
    double check;
    bool invalid = true;
    
    display_current_player_data();
    temp.p_id = p_id;
    cin.get();
    cout << "Enter The New Name (OLD = " << p_name << ")";
    getline(cin,temp.p_name,'\n');
    cout << "Enter the New Course (OLD = " << p_degree << ")";
    getline(cin,temp.p_degree,'\n');
    cout << "Enter the New Stamina (OLD = " << p_sta << ")";
    cin >> temp.p_sta;
    cout << "Enter the New Social (OLD = " << p_soc << ")";
    cin >> temp.p_soc;
    cout << "Enter the New Intelligence (OLD = " << p_int << ")";
    cin >> temp.p_int;
    
    
    char reset;
    cout << "Reset Meters? (y/n)" << endl;
    cin >> reset;
    if (reset == 'y'){
        temp.p_energy = 100;
        temp.p_academic = 100;
        temp.p_stress = 0;
    }else if (reset == 'n'){
        cout << "Energy: " << p_energy  << endl;;
        cout << "Academic: " << p_academic  << endl;;
        cout << "Stress: " << p_stress << endl;
        cout << "Keep Previous Levels? (y/n)";
        cin >> reset;
        if(reset == 'y'){
            temp.p_energy = p_energy;
            temp.p_academic = p_academic;
            temp.p_stress = p_stress;
        }
        else if(reset =='n'){
            while(invalid == true){
                cout << "Enter Energy (0-100)";
                cin >> check;
                if(check >= 0 && check < 101){
                    temp.p_energy = check;
                    invalid = false;
                }
            
            }
            invalid = true;
            while(invalid == true){
                cout << "Enter Academic (0-100)";
                cin >> check;
                if(check >= 0 && check < 101){
                    temp.p_academic = check;
                    invalid = false;
                }
                
            }
            invalid = true;
            while(invalid == true){
                cout << "Enter Stress (0-100)";
                cin >> check;
                if(check >= 0 && check < 101){
                    temp.p_stress = check;
                    invalid = false;
                }
                
            }
            invalid = true;
            
        }else{
            cout << "A Bad Input Has Occured, No Changes Were Made";
            return;
            
        }
        
    }else{
        cout << "A Bad Input Has Occured, No Changes Were Made";
        return;
    }
    
    
    cout << "Enter the New Personality Type ";
    cin >> temp.p_MB_result;
    
    *this = temp;
    
}

