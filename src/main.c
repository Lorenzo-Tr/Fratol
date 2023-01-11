#include "main.h"

int main(int argc, char **argv){
  t_params params;
  
  if(argc != 4){
    printf("Invalid arguments\n");
    return(1);
  }

  params.height = (unsigned int) atoi(argv[1]);
  params.weight = atoi(argv[2]);
  params.name = argv[3];

  fractal(params);
  
  return (0);
}