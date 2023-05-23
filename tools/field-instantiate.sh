#!/usr/bin/env bash
# Copyright (C) 2023 by Alejandro Gallo <aamsgallo@gmail.com>

in=${1}

SED_EXPRESSIONS=(
  "s/@FIELD_NAME@/s/g; s/@FIELD_TYPE@/float/g"
  "s/@FIELD_NAME@/d/g; s/@FIELD_TYPE@/double/g"
  "s/@FIELD_NAME@/c/g; s/@FIELD_TYPE@/std::complex<float>/g"
  "s/@FIELD_NAME@/z/g; s/@FIELD_TYPE@/std::complex<double>/g"
)

for _sedexpr in "${SED_EXPRESSIONS[@]}"; do
  sed "${_sedexpr}" "${in}"
done
