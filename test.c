#include <assert.h>
#include <mpi.h>
#include <stdio.h>
#include <teinst.h>

#define LOG(...) if (!rank) printf(__VA_ARGS__);

int main(int argc, char **argv) {
  MPI_Init(&argc, &argv);
  int rank, np;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  LOG("[31mTEINST TEST[0m (:np %d :rank %d)\n\n", np, rank);
  global_world_init();

  size_t TEST_NUMBER = 0;

{
  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_s[0m functions\n",
      ++TEST_NUMBER);

  size_t n = 4;
  size_t _lenghts[4];
  size_t lens[] = {1UL + TEST_NUMBER,
                   2UL + TEST_NUMBER,
                   3UL + TEST_NUMBER,
                   4UL + TEST_NUMBER};
  char *name;
  tensor_h tsr;

  LOG("\ttsr = <%p>\n", (void *)tsr);
  tensor_init_s(&tsr, n, lens);
  LOG("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_s(tsr, n, _lenghts);
  LOG("got lengths = {%ld %ld %ld %ld}\n", /**/
      _lenghts[0], _lenghts[1],
      _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  LOG("got name %s for <%p>\n", name, (void *)tsr);

  LOG("Freeing <%p>\n", (void *)tsr);
  tensor_free_s(tsr);

  LOG("\n\n");
}
{
  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_d[0m functions\n",
      ++TEST_NUMBER);

  size_t n = 4;
  size_t _lenghts[4];
  size_t lens[] = {1UL + TEST_NUMBER,
                   2UL + TEST_NUMBER,
                   3UL + TEST_NUMBER,
                   4UL + TEST_NUMBER};
  char *name;
  tensor_h tsr;

  LOG("\ttsr = <%p>\n", (void *)tsr);
  tensor_init_d(&tsr, n, lens);
  LOG("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_d(tsr, n, _lenghts);
  LOG("got lengths = {%ld %ld %ld %ld}\n", /**/
      _lenghts[0], _lenghts[1],
      _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  LOG("got name %s for <%p>\n", name, (void *)tsr);

  LOG("Freeing <%p>\n", (void *)tsr);
  tensor_free_d(tsr);

  LOG("\n\n");
}
{
  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_c[0m functions\n",
      ++TEST_NUMBER);

  size_t n = 4;
  size_t _lenghts[4];
  size_t lens[] = {1UL + TEST_NUMBER,
                   2UL + TEST_NUMBER,
                   3UL + TEST_NUMBER,
                   4UL + TEST_NUMBER};
  char *name;
  tensor_h tsr;

  LOG("\ttsr = <%p>\n", (void *)tsr);
  tensor_init_c(&tsr, n, lens);
  LOG("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_c(tsr, n, _lenghts);
  LOG("got lengths = {%ld %ld %ld %ld}\n", /**/
      _lenghts[0], _lenghts[1],
      _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  LOG("got name %s for <%p>\n", name, (void *)tsr);

  LOG("Freeing <%p>\n", (void *)tsr);
  tensor_free_c(tsr);

  LOG("\n\n");
}
{
  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_z[0m functions\n",
      ++TEST_NUMBER);

  size_t n = 4;
  size_t _lenghts[4];
  size_t lens[] = {1UL + TEST_NUMBER,
                   2UL + TEST_NUMBER,
                   3UL + TEST_NUMBER,
                   4UL + TEST_NUMBER};
  char *name;
  tensor_h tsr;

  LOG("\ttsr = <%p>\n", (void *)tsr);
  tensor_init_z(&tsr, n, lens);
  LOG("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_z(tsr, n, _lenghts);
  LOG("got lengths = {%ld %ld %ld %ld}\n", /**/
      _lenghts[0], _lenghts[1],
      _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  LOG("got name %s for <%p>\n", name, (void *)tsr);

  LOG("Freeing <%p>\n", (void *)tsr);
  tensor_free_z(tsr);

  LOG("\n\n");
}

global_world_free();
  MPI_Finalize();
  return 0;
} // main
