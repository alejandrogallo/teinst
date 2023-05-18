#include <teinst.h>
#include <mpi.h>
#include <stdio.h>

int main() {

  MPI_Init(0, NULL);

  size_t order = 4;
  size_t lens[] = {10, 10, 10, 10};
  size_t syms[] = {0, 0, 0, 0};
  char *name;

  DTensor *t = make_tensor(order, lens, syms);
  tensor_name(t, &name);
  printf("c name %s\n", name);


  MPI_Finalize();
  return 0;
}
