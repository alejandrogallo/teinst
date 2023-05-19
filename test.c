#include <assert.h>
#include <mpi.h>
#include <stdio.h>
#include <teinst.h>

int main(int argc, char **argv) {
  printf("TEINST TEST\n\n");
  MPI_Init(&argc, &argv);
  global_world_init();

  {
    size_t n = 4;
    size_t lens[] = {1UL, 2UL, 3UL, 4UL};
    size_t *_lenghts;
    tensor_h tsr;

    printf("\ttsr = <%p>\n", (void *)tsr);
    tensor_init_s(&tsr, n, lens);
    printf("\ttsr = <%p>\n", (void *)tsr);

    tensor_lengths_s(tsr, &_lenghts);
    printf("got lengths = {%ld %ld %ld %ld}\n", _lenghts[0], _lenghts[1],
           _lenghts[2], _lenghts[3]);
    size_t i = 0;
    assert(lens[i] == _lenghts[i]);
    i++;
    assert(lens[i] == _lenghts[i]);
    i++;
    assert(lens[i] == _lenghts[i]);
    i++;
    assert(lens[i] == _lenghts[i]);

    printf("Freeing <%p>\n", (void *)tsr);
    tensor_free_s(tsr);
  }

  global_world_free();
  MPI_Finalize();
  return 0;
}
