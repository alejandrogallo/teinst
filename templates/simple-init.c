{
  printf("%ld) Running 'Simple Test' for *_@FIELD_NAME@ functions\n",
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
  tensor_init_@FIELD_NAME@(&tsr, n, lens);
  printf("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_@FIELD_NAME@(tsr, &_lenghts);
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
  tensor_free_@FIELD_NAME@(tsr);

  printf("\n\n");
}
