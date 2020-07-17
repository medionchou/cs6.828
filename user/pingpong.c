#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char **argv)
{
  // for parent write
  int parent[2];
  // for child write
  int child[2];

  pipe(parent);
  pipe(child);

  int pid = fork();

  if (pid != 0) {
    close(parent[0]);
    close(child[1]);

    write(parent[1], "ping", 4);
    close(parent[1]);

    char s[5] = {0};
    read(child[0], s, 4);
    close(child[0]);

    printf("received %s\n", s);
    wait();
  } else {
    close(child[0]);
    close(parent[1]);

    char s[5] = {0};
    read(parent[0], s, 4);
    close(parent[0]);

    printf("recieved %s\n", s);

    write(child[1], "pong", 4);
    close(child[1]);
  }

  exit();
}
