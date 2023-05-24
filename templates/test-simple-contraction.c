#line 1 "simple-contraction-org-src"
{

  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_@FIELD_NAME@[0m functions\n",
      ++TEST_NUMBER);

  tensor_h A = 0x0, B = 0x0, C = 0x0;

  size_t
    lens_A[] = {20, 20, 30}, dim_A = 3,
    lens_B[] = {30, 20}, dim_B = 2,
    lens_C[] = {20}, dim_C = 1;

  @FIELD_CTYPE@
    alpha = { 1 },
    beta = { 0 };

  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_@FIELD_NAME@(&A, dim_A, lens_A);
  tensor_init_@FIELD_NAME@(&B, dim_B, lens_B);
  tensor_init_@FIELD_NAME@(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_@FIELD_NAME@(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               "a",
                               C);

}
