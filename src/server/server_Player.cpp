#include "server_Player.h"

Player::Player(Armory* armory){
  this->armory = armory;
  selected_index = 0;
}

void Player::add_worm(Worm* worm){
  worms.push_back(worm);
}

Worm* Player::get_selected_worm(){
  if (worms.size() == 0) return NULL;
  return worms[selected_index];
}

bool Player::has_worms_alive(){
  for (size_t i = 0; i < worms.size(); i++){
    if (worms[i]->is_alive()) return true;
  }
  return false;
}

void Player::select_next_worm(){
  if (++selected_index == worms.size()) selected_index = 0;
}

bool Player::teletransport_actual_worm(int x, int y){
  return this->armory->use_teletransportation(get_selected_worm(), x, y);
}

size_t Player::get_teletransportation_munitions(){
  return this->armory->get_teletransportation_munitions();
}

bool Player::use_dynamite(){
  if (has_an_active_weapon()) return false;
  return this->armory->use_dynamite(get_selected_worm(), get_selected_worm()->\
                                                        is_facing_right());
}

size_t Player::get_dynamite_munitions(){
  return this->armory->get_dynamite_munitions();
}

void Player::discount_dynamite_time(float t){
  if (!is_dynamite_active()) return;
  this->armory->discount_dynamite_time(t);
}

bool Player::is_dynamite_active(){
  return this->armory->is_dynamite_active();
}

float Player::get_dynamite_horizontal_position(){
  return this->armory->get_dynamite_horizontal_position();
}

float Player::get_dynamite_vertical_position(){
  return this->armory->get_dynamite_vertical_position();
}

float Player::get_dynamite_time_to_explosion(){
  if (!is_dynamite_active()) return -1;
  return this->armory->get_dynamite_time_to_explosion();
}

bool Player::use_radiocontrolled(float x){
  if (has_an_active_weapon()) return false;
  return this->armory->use_radiocontrolled(x);
}

bool Player::is_radiocontrolled_active(){
  return this->armory->is_radiocontrolled_active();
}

std::vector<std::pair<float, float>> Player::get_radiocontrolled_positions(){
  return this->armory->get_radiocontrolled_positions();
}

void Player::check_radiocontrolled_explosions(){
  if (!is_radiocontrolled_active()) return;
  this->armory->check_radiocontrolled_explosions();
}

bool Player::has_an_active_weapon(){
  return is_radiocontrolled_active() || is_dynamite_active();
}

Player::~Player(){
  delete armory;
}