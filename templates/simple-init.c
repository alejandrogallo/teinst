{
  LOG("%ld) Running [36m'Simple Test'[0m for [33m*_@FIELD_NAME@[0m functions\n",
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
  tensor_init_@FIELD_NAME@(&tsr, n, lens);
  LOG("\ttsr = <%p>\n", (void *)tsr);

  tensor_lengths_@FIELD_NAME@(tsr, n, _lenghts);
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
  tensor_free_@FIELD_NAME@(tsr);

  LOG("\n\n");
}
