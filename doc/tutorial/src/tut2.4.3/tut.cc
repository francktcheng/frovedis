#include <frovedis.hpp>

std::vector<int> duplicate(int i) {
  std::vector<int> v;
  v.push_back(i); v.push_back(i);
  return v;
}

int main(int argc, char* argv[]){
  frovedis::use_frovedis use(argc, argv);
  
  std::vector<int> v;
  for(size_t i = 1; i <= 8; i++) v.push_back(i);
  auto d1 = frovedis::make_dvector_scatter(v);
  auto d2 = d1.flat_map(duplicate);
  auto r = d2.gather();
  for(auto i: r) std::cout << i << std::endl;
}
