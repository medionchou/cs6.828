#include "kernel/types.h"
#include "user/user.h"


void sieve(int pipe[2])
{
  close(pipe[1]);
  int v = 0;
  int cnt = 0;
  // create a dynamic array
  // and insert data 
  while ((cnt = read(pipe[0], &v, sizeof(int))) > 0) {
    printf("v: %d\n", v);
  }
  close(pipe[0]);


  // test if it is not empty
  // then fork
  // otherwise terminate


}

int
main(int argc, char **argv)
{
  int p[2];
  pipe(p);
  int pid = fork();

  if (pid != 0) {
    close(p[0]);
    for (int i = 2; i <= 35; ++i) {
      if (i % 2 != 0) {
        write(p[1], &i, sizeof(int));
      }
    }
    close(p[1]);

    wait();
  } else {
    sieve(p);
  }

  exit();
}
