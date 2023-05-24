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

  LOG("\t- tsr = <%p>\n", (void *)tsr);
  tensor_init_s(&tsr, n, lens);
  LOG("\t- tsr = <%p>\n", (void *)tsr);

  tensor_lengths_s(tsr, n, _lenghts);
  LOG("\t- got lengths = {%ld %ld %ld %ld}\n", /**/
      _lenghts[0], _lenghts[1],
      _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  LOG("\t- got name %s for <%p>\n", name, (void *)tsr);

  LOG("\t- Freeing <%p>\n", (void *)tsr);
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

  LOG("\t- tsr = <%p>\n", (void *)tsr);
  tensor_init_d(&tsr, n, lens);
  LOG("\t- tsr = <%p>\n", (void *)tsr);

  tensor_lengths_d(tsr, n, _lenghts);
  LOG("\t- got lengths = {%ld %ld %ld %ld}\n", /**/
      _lenghts[0], _lenghts[1],
      _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  LOG("\t- got name %s for <%p>\n", name, (void *)tsr);

  LOG("\t- Freeing <%p>\n", (void *)tsr);
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

  LOG("\t- tsr = <%p>\n", (void *)tsr);
  tensor_init_c(&tsr, n, lens);
  LOG("\t- tsr = <%p>\n", (void *)tsr);

  tensor_lengths_c(tsr, n, _lenghts);
  LOG("\t- got lengths = {%ld %ld %ld %ld}\n", /**/
      _lenghts[0], _lenghts[1],
      _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  LOG("\t- got name %s for <%p>\n", name, (void *)tsr);

  LOG("\t- Freeing <%p>\n", (void *)tsr);
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

  LOG("\t- tsr = <%p>\n", (void *)tsr);
  tensor_init_z(&tsr, n, lens);
  LOG("\t- tsr = <%p>\n", (void *)tsr);

  tensor_lengths_z(tsr, n, _lenghts);
  LOG("\t- got lengths = {%ld %ld %ld %ld}\n", /**/
      _lenghts[0], _lenghts[1],
      _lenghts[2], _lenghts[3]);
  size_t i = 0;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]); i++;
  assert(lens[i] == _lenghts[i]);

  tensor_name(tsr, &name);
  LOG("\t- got name %s for <%p>\n", name, (void *)tsr);

  LOG("\t- Freeing <%p>\n", (void *)tsr);
  tensor_free_z(tsr);

  LOG("\n\n");
}

#line 1 "simple-contraction-org-src"
{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_s[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20, 20, 30}, dim_A = 3,
    lens_B[] = {30, 20}, dim_B = 2,
    lens_C[] = {20}, dim_C = 1;

  float
    alpha = { 1 },
    beta = { 0 };

  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_s(&A, dim_A, lens_A);
  tensor_init_s(&B, dim_B, lens_B);
  tensor_init_s(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_s(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               "a",
                               C);

}
#line 1 "simple-contraction-org-src"
{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_d[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20, 20, 30}, dim_A = 3,
    lens_B[] = {30, 20}, dim_B = 2,
    lens_C[] = {20}, dim_C = 1;

  double
    alpha = { 1 },
    beta = { 0 };

  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_d(&A, dim_A, lens_A);
  tensor_init_d(&B, dim_B, lens_B);
  tensor_init_d(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_d(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               "a",
                               C);

}
#line 1 "simple-contraction-org-src"
{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_c[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20, 20, 30}, dim_A = 3,
    lens_B[] = {30, 20}, dim_B = 2,
    lens_C[] = {20}, dim_C = 1;

  _Complex float
    alpha = { 1 },
    beta = { 0 };

  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_c(&A, dim_A, lens_A);
  tensor_init_c(&B, dim_B, lens_B);
  tensor_init_c(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_c(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               "a",
                               C);

}
#line 1 "simple-contraction-org-src"
{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_z[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20, 20, 30}, dim_A = 3,
    lens_B[] = {30, 20}, dim_B = 2,
    lens_C[] = {20}, dim_C = 1;

  _Complex double
    alpha = { 1 },
    beta = { 0 };

  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_z(&A, dim_A, lens_A);
  tensor_init_z(&B, dim_B, lens_B);
  tensor_init_z(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_z(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               "a",
                               C);

}

global_world_free();
  MPI_Finalize();
  return 0;
} // main
