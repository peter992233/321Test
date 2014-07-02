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



void print_menu();
void run_menu();
void player_data_menu();
void player_quiz_menu();
void stat_display_menu();




void create_new_player();
void save_to_local();
void load_from_local();
void save_to_file();
void load_from_file();
void delete_local_player();
void display_current_player();
void display_all_local();
void edit_current_data();
void take_p_quiz();
void set_personality_profile();
void display_recomm_courses();
void display_recomm_stats();


/*Menu Structure
void print_menu();
int get_option();
void menu_action(int);
void run_menu();


//Menu Options - Intuitively Named for convenience
void menu_new_game();
void menu_save_game();
void menu_display_current();
void menu_load_file();
void menu_load_local();
void menu_display_local();
void menu_save_to_file();
void menu_delete_local_save();
void menu_reprint();*/


#endif /* defined(___21Test__menu_functions__) */
