{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell rec {

  buildInputs = with pkgs; [
    openblas scalapack clang-tools
  ];

  shellHook = ''
  '';

}
