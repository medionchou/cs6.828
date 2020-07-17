#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  if(argc < 2){
    fprintf(2, "usage: sleep [nums]...\n");
    exit();
  }

  int s = atoi(argv[1]);

  sleep(s);

  exit();
}
