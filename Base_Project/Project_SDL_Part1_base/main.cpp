#include "Project_SDL1.h"
#include <stdio.h>
#include <string>

int main(int argc, char* argv[]) {

  std::cout << "Starting up the application" << std::endl;

  if (argc != 4)
    throw std::runtime_error("Need three arguments - "
                             "number of sheep, number of wolves, "
                             "simulation time\n");

  if (std::stoul(argv[1]) + std::stoul(argv[2]) <= 0)
    throw std::runtime_error("We need at least one animal in our zoo! \n");

  init();

  std::cout << "Done with initialization" << std::endl;

  application my_app(std::stoul(argv[1]), std::stoul(argv[2]));

  std::cout << "Created window" << std::endl;

  int ret_val = my_app.loop(std::stoul(argv[3]));

  std::cout << "Exiting application with code " << ret_val << std::endl;

  return ret_val;
}