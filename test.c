#include <assert.h>
#include <mpi.h>
#include <stdio.h>
#include <teinst.h>

int main(int argc, char **argv) {
  printf("TEINST TEST\n\n");
  MPI_Init(&argc, &argv);
  global_world_init();

  size_t TEST_NUMBER = 0;

{
  printf("%ld) Running 'Simple Test' for *_s functions\n",
         ++TEST_NUMBER);

  size_t n = 4;
  size_t lens[] = {1UL + TEST_NUMBER,
                   2UL + TEST_NUMBER,
                   3UL + TEST_NUMBER,
                   4UL + TEST_NUMBER};
  size_t *_lenghts;
  char *name;
  tensor_h tsr;

  printf("\ttsr = <%p>\n", (void *)tsr);
  tensor_init_s(&tsr, n, lens);
  printf("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_s(tsr, &_lenghts);
  printf("got lengths = {%ld %ld %ld %ld}\n", _lenghts[0], _lenghts[1],
         _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  printf("got name %s for <%p>\n", name, (void *)tsr);

  printf("Freeing <%p>\n", (void *)tsr);
  tensor_free_s(tsr);

  printf("\n\n");
}
{
  printf("%ld) Running 'Simple Test' for *_d functions\n",
         ++TEST_NUMBER);

  size_t n = 4;
  size_t lens[] = {1UL + TEST_NUMBER,
                   2UL + TEST_NUMBER,
                   3UL + TEST_NUMBER,
                   4UL + TEST_NUMBER};
  size_t *_lenghts;
  char *name;
  tensor_h tsr;

  printf("\ttsr = <%p>\n", (void *)tsr);
  tensor_init_d(&tsr, n, lens);
  printf("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_d(tsr, &_lenghts);
  printf("got lengths = {%ld %ld %ld %ld}\n", _lenghts[0], _lenghts[1],
         _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  printf("got name %s for <%p>\n", name, (void *)tsr);

  printf("Freeing <%p>\n", (void *)tsr);
  tensor_free_d(tsr);

  printf("\n\n");
}
{
  printf("%ld) Running 'Simple Test' for *_c functions\n",
         ++TEST_NUMBER);

  size_t n = 4;
  size_t lens[] = {1UL + TEST_NUMBER,
                   2UL + TEST_NUMBER,
                   3UL + TEST_NUMBER,
                   4UL + TEST_NUMBER};
  size_t *_lenghts;
  char *name;
  tensor_h tsr;

  printf("\ttsr = <%p>\n", (void *)tsr);
  tensor_init_c(&tsr, n, lens);
  printf("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_c(tsr, &_lenghts);
  printf("got lengths = {%ld %ld %ld %ld}\n", _lenghts[0], _lenghts[1],
         _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  printf("got name %s for <%p>\n", name, (void *)tsr);

  printf("Freeing <%p>\n", (void *)tsr);
  tensor_free_c(tsr);

  printf("\n\n");
}
{
  printf("%ld) Running 'Simple Test' for *_z functions\n",
         ++TEST_NUMBER);

  size_t n = 4;
  size_t lens[] = {1UL + TEST_NUMBER,
                   2UL + TEST_NUMBER,
                   3UL + TEST_NUMBER,
                   4UL + TEST_NUMBER};
  size_t *_lenghts;
  char *name;
  tensor_h tsr;

  printf("\ttsr = <%p>\n", (void *)tsr);
  tensor_init_z(&tsr, n, lens);
  printf("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_z(tsr, &_lenghts);
  printf("got lengths = {%ld %ld %ld %ld}\n", _lenghts[0], _lenghts[1],
         _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  printf("got name %s for <%p>\n", name, (void *)tsr);

  printf("Freeing <%p>\n", (void *)tsr);
  tensor_free_z(tsr);

  printf("\n\n");
}

  global_world_free();
  MPI_Finalize();
  return 0;
} // main
