{ pkgs ? import <nixpkgs> { } }:

let

  my-openblas = pkgs.openblas.override { blas64 = false; };

in
pkgs.mkShell rec {

  buildInputs = with pkgs; [ clang-tools c2ffi ecl ccl gdb my-openblas ];

  SCALAPACK_LD_LIBRARY_PATH = "${pkgs.scalapack}/lib";
  OPENBLAS_LD_LIBRARY_PATH = "${my-openblas}/lib";

  nativeBuildInputs = with pkgs; [
    my-openblas
    scalapack
    # buildInputs.gfortran
    lapack
    gcc
    openmpi
  ];

}
