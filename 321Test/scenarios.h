//
//  scenarios.h
//  321Test
//
//  Created by csci321ga2a on 2/07/2014.
//  Copyright (c) 2014 csci321. All rights reserved.
//

#ifndef ___21Test__scenarios__
#define ___21Test__scenarios__

#include <iostream>
#include <sstream>
#include <string>
#include "player_data.h"


void init_new_game(player_data&);


//Progress Control for the Game, Handles movements between functions and views
//Will initialize once the game is loaded and must have a game_data with an initialized player_data
void gameloop(player_data&);


//Returns player data to the menu and ends all the game data
void ret_to_men(player_data&);

void gl_ingame_menu(player_data&); //Show ingame menu Options
void gl_map(player_data&); //Show Map Options
void gl_inside(player_data&); //Show Faculty building Options
void gl_outside(player_data&); //show Outside building Options
void gl_dorm(player_data&); // Show Dorm Building options
void gl_pda(player_data&); //Show PDA Options
void print_game_screen(player_data&); // Print Current Game Details


void run_tutorial();


#endif /* defined(___21Test__scenarios__) */
