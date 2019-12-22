#include <tuple>

template<typename T1, typename T2, typename T3>
std::tuple<T1, T2, T3> makeTriple(T1 t1, T2 t2, T3 t3){
  return std::tuple<T1, T2, T3>(t1, t2, t3);
}

int main(){

  auto trip1 = makeTriple(1, 5.4, true);

}
