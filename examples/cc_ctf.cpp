// [[file:../README.org::*CTF][CTF:1]]
#include <mpi.h>
#include <ctf.hpp>

template <typename F> using T = CTF::Tensor<F>;
template <typename F> using S = CTF::Scalar<F>;

template <typename F>
F ccEnergy(T<F> &t, T<F> &vhhpp) {
  S<F> energy;
  energy[""] = (0.25)
             * t["abij"]
             * vijab["ijab"]
             ;
  return energy.get_val();
}

int main() {

  int no(20)
    , nv(200)
    , order(4)
    , symmetries[] = {NS, NS, NS, NS}
    , lensT[] = {nv, nv, no, no}
    , lensV[] = {no, no, nv, nv}
    ;

  auto T<double>(order, symmetries, lensT, MPI_COMM_WORLD)
     , V<double>(order, symmetries, lensV, MPI_COMM_WORLD)
     ;

  double e(ccEnergy(T, V));
  std::cout << "Energy " << e << std::endl;

}
// CTF:1 ends here
