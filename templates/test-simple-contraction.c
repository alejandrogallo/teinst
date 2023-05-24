{

  LOG("%ld) Running [36m'Simple Contraction'[0m for [33m*_@FIELD_NAME@[0m functions\n",
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

  @FIELD_CTYPE@
    alpha = 1,
    beta = 0;

  // init tensors
  assert(A == 0x0); assert(B == 0x0); assert(C == 0x0);
  tensor_init_@FIELD_NAME@(&A, dim_A, lens_A);
  tensor_init_@FIELD_NAME@(&B, dim_B, lens_B);
  tensor_init_@FIELD_NAME@(&C, dim_C, lens_C);
  assert(A != 0x0); assert(B != 0x0); assert(C != 0x0);
  LOG("\t- Inited tensors A<%p> B<%p> C<%p>\n",
      (void*)A, (void*)B, (void*)C);

  LOG("\t- Random filling\n");
  @FIELD_CTYPE@ f_min = 0, f_max = 1;
  tensor_fill_random_@FIELD_NAME@(A, &f_min, &f_max);
  tensor_fill_random_@FIELD_NAME@(B, &f_min, &f_max);
  tensor_fill_random_@FIELD_NAME@(C, &f_min, &f_max);

  tensor_norm_frobenius_@FIELD_NAME@(A, &norm_A);
  tensor_norm_frobenius_@FIELD_NAME@(B, &norm_B);
  tensor_norm_frobenius_@FIELD_NAME@(C, &norm_C);
  LOG("\t- Norms A<%f> B<%f> C<%f>\n",
      norm_A, norm_B, norm_C);

  LOG("\t- Summing A[abc] += 2 * A[abc]\n");
  @FIELD_CTYPE@ two = 2, zero = 0;
  tensor_sum_@FIELD_NAME@(&two, A, "abc", &zero, A, "abc");

  LOG("\t- Contracting C[a] = A[abc] * B[cb]\n");
  tensor_contract_@FIELD_NAME@(&alpha,
                               A,
                               "abc",
                               B,
                               "cb",
                               &beta,
                               C,
                               "a");


  LOG("\t- Freeing tensors\n");
  tensor_free_@FIELD_NAME@(A);
  tensor_free_@FIELD_NAME@(B);
  tensor_free_@FIELD_NAME@(C);
}
