#include "server_GameThread.h"
#include <iostream>

int main(int argc, char* argv[]){
  std::cout << "Estoy en el servidor\n";

  GameThread gt(argv[1], string("../scenarios/scenario.yaml"), atoi(argv[2]));
  gt.start_connection();
  while (true){
      std::string input;
      std::cin >> input;
      if (input.length() == 1 && input.at(0) == 'q'){
        if (gt.is_alive()) gt.stop();
        break;
      }
  }
  if (gt.was_connected()) gt.join();
  return 0;
}