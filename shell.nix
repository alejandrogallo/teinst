{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell rec {

  buildInputs = with pkgs; [ openblas scalapack clang-tools c2ffi ecl ccl gdb ];

  shellHook = "";

}
