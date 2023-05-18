define(`m4_instantiate_types',
`
$1(s, float)$2
$1(d, double)$2
$1(c, std::complex<float>)$2
$1(z, std::complex<double>)$2
')
