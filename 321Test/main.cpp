//
//  main.cpp
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#include <iostream>
#include "menu_functions.h"

int main(int argc, const char * argv[])
{
    
    
    
    //MAIN MENU
    //Functions Used stored in menu_funtions.cpp & .h
    
    //Variables
    int menu_input;
    
    //Mainline
    print_menu();
    do{
        
        menu_input = get_option();
        menu_action(menu_input);
        
    }while(menu_input != 10);
    
    
    
    
    return 0;
    
}

