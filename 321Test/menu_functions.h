//
//  menu_functions.h
//  Peter Brown
//
//  Created by Peter Brown on 11/06/2014.
//  Copyright (c) 2014 csci321ga2a. All rights reserved.
//

#ifndef ___21Test__menu_functions__
#define ___21Test__menu_functions__

#include <iostream>


//Menu Structure
void print_menu();
int get_option();
void menu_action(int);



//Menu Options - Intuitively Named for convenience
void menu_new_game();
void menu_save_game();
void menu_display_current();
void menu_load_file();
void menu_load_local();
void menu_display_local();
void menu_save_to_file();
void menu_delete_local_save();
void menu_reprint();

#endif /* defined(___21Test__menu_functions__) */
