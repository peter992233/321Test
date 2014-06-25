//
//  menu_functions.h
//  321Test
//
//  Created by csci321ga2a on 11/06/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#ifndef ___21Test__menu_functions__
#define ___21Test__menu_functions__

#include <iostream>


//Menuy Structure
void print_menu();
int get_option();
void menu_action(int);



//Menu Options
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
