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

{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_s[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20UL, 20UL, 30UL}, dim_A = 3,
    lens_B[] = {30UL, 20UL}, dim_B = 2,
    lens_C[] = {20UL}, dim_C = 1;

  double
    norm_A,
    norm_B,
    norm_C;

  float
    alpha = 1,
    beta = 0;

  // init tensors
  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_s(&A, dim_A, lens_A);
  tensor_init_s(&B, dim_B, lens_B);
  tensor_init_s(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);
  LOG("\t- Inited tensors A<%p> B<%p> C<%p>\n",
      (void*)A, (void*)B, (void*)C);

  LOG("\t- Random filling\n");
  float f_min = 0, f_max = 1;
  tensor_fill_random_s(A, &f_min, &f_max);
  tensor_fill_random_s(B, &f_min, &f_max);
  tensor_fill_random_s(C, &f_min, &f_max);

  tensor_norm_frobenius_s(A, &norm_A);
  tensor_norm_frobenius_s(B, &norm_B);
  tensor_norm_frobenius_s(C, &norm_C);
  LOG("\t- Norms A<%f> B<%f> C<%f>\n",
      norm_A, norm_B, norm_C);

  LOG("\t- Summing A[abc] += 2 * A[abc]\n");
  float two = 2, zero = 0;
  tensor_sum_s(&two, A, "abc", &zero, A, "abc");

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_s(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               C,
                               "a");


  LOG("\t- Freeing tensors\n");
  tensor_free_s(A);
  tensor_free_s(B);
  tensor_free_s(C);
}
{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_d[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20UL, 20UL, 30UL}, dim_A = 3,
    lens_B[] = {30UL, 20UL}, dim_B = 2,
    lens_C[] = {20UL}, dim_C = 1;

  double
    norm_A,
    norm_B,
    norm_C;

  double
    alpha = 1,
    beta = 0;

  // init tensors
  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_d(&A, dim_A, lens_A);
  tensor_init_d(&B, dim_B, lens_B);
  tensor_init_d(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);
  LOG("\t- Inited tensors A<%p> B<%p> C<%p>\n",
      (void*)A, (void*)B, (void*)C);

  LOG("\t- Random filling\n");
  double f_min = 0, f_max = 1;
  tensor_fill_random_d(A, &f_min, &f_max);
  tensor_fill_random_d(B, &f_min, &f_max);
  tensor_fill_random_d(C, &f_min, &f_max);

  tensor_norm_frobenius_d(A, &norm_A);
  tensor_norm_frobenius_d(B, &norm_B);
  tensor_norm_frobenius_d(C, &norm_C);
  LOG("\t- Norms A<%f> B<%f> C<%f>\n",
      norm_A, norm_B, norm_C);

  LOG("\t- Summing A[abc] += 2 * A[abc]\n");
  double two = 2, zero = 0;
  tensor_sum_d(&two, A, "abc", &zero, A, "abc");

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_d(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               C,
                               "a");


  LOG("\t- Freeing tensors\n");
  tensor_free_d(A);
  tensor_free_d(B);
  tensor_free_d(C);
}
{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_c[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20UL, 20UL, 30UL}, dim_A = 3,
    lens_B[] = {30UL, 20UL}, dim_B = 2,
    lens_C[] = {20UL}, dim_C = 1;

  double
    norm_A,
    norm_B,
    norm_C;

  _Complex float
    alpha = 1,
    beta = 0;

  // init tensors
  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_c(&A, dim_A, lens_A);
  tensor_init_c(&B, dim_B, lens_B);
  tensor_init_c(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);
  LOG("\t- Inited tensors A<%p> B<%p> C<%p>\n",
      (void*)A, (void*)B, (void*)C);

  LOG("\t- Random filling\n");
  _Complex float f_min = 0, f_max = 1;
  tensor_fill_random_c(A, &f_min, &f_max);
  tensor_fill_random_c(B, &f_min, &f_max);
  tensor_fill_random_c(C, &f_min, &f_max);

  tensor_norm_frobenius_c(A, &norm_A);
  tensor_norm_frobenius_c(B, &norm_B);
  tensor_norm_frobenius_c(C, &norm_C);
  LOG("\t- Norms A<%f> B<%f> C<%f>\n",
      norm_A, norm_B, norm_C);

  LOG("\t- Summing A[abc] += 2 * A[abc]\n");
  _Complex float two = 2, zero = 0;
  tensor_sum_c(&two, A, "abc", &zero, A, "abc");

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_c(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               C,
                               "a");


  LOG("\t- Freeing tensors\n");
  tensor_free_c(A);
  tensor_free_c(B);
  tensor_free_c(C);
}
{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_z[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20UL, 20UL, 30UL}, dim_A = 3,
    lens_B[] = {30UL, 20UL}, dim_B = 2,
    lens_C[] = {20UL}, dim_C = 1;

  double
    norm_A,
    norm_B,
    norm_C;

  _Complex double
    alpha = 1,
    beta = 0;

  // init tensors
  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_z(&A, dim_A, lens_A);
  tensor_init_z(&B, dim_B, lens_B);
  tensor_init_z(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);
  LOG("\t- Inited tensors A<%p> B<%p> C<%p>\n",
      (void*)A, (void*)B, (void*)C);

  LOG("\t- Random filling\n");
  _Complex double f_min = 0, f_max = 1;
  tensor_fill_random_z(A, &f_min, &f_max);
  tensor_fill_random_z(B, &f_min, &f_max);
  tensor_fill_random_z(C, &f_min, &f_max);

  tensor_norm_frobenius_z(A, &norm_A);
  tensor_norm_frobenius_z(B, &norm_B);
  tensor_norm_frobenius_z(C, &norm_C);
  LOG("\t- Norms A<%f> B<%f> C<%f>\n",
      norm_A, norm_B, norm_C);

  LOG("\t- Summing A[abc] += 2 * A[abc]\n");
  _Complex double two = 2, zero = 0;
  tensor_sum_z(&two, A, "abc", &zero, A, "abc");

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_z(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               C,
                               "a");


  LOG("\t- Freeing tensors\n");
  tensor_free_z(A);
  tensor_free_z(B);
  tensor_free_z(C);
}

global_world_free();
  MPI_Finalize();
  return 0;
} // main
