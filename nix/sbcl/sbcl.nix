{ stdenv, fetchFromGitHub }:

stdenv.mkDerivation rec {
  pname = "sbcl";
  version = "prepl";
  src = fetchFromGitHub {
    owner = "sbcl";
    repo = "sbcl";
    rev = "4eec3b341a77d173252c02c4b781f71f260d058b";
    sha256 = "sha256-zRgf/OJoTP9X7jg/YRv00ioYRj19t2tVKy+sRDnX4kU=";
  };

  buildInputs = [ sbcl zstd ];

  configurePhase = ''
    echo '"${version}"' > version.lisp-expr
  '';
  buildPhase = ''
    sh make.sh --prefix=$out \
      --fancy --with-sb-linkable-runtime --with-sb-dynamic-core
  '';
  testPhase = ''
    cd tests && sh run-tests.sh
  '';
  installPhase = ''
    sh install.sh
  '';

}
