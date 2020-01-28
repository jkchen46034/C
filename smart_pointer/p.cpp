#include <chrono>
#include <iostream>
#include <memory>

int f1(int* a)
{
   *a = *a+1;
}

int f2(std::shared_ptr<int> a)
{
   *a = *a+1;
}

static const long long numInt= 1000000000;

int main(){
  auto start = std::chrono::system_clock::now();

  for ( long long i=0 ; i < numInt; ++i){
    //int* tmp(new int(i));
    //f1(tmp);
    //delete tmp;
    std::shared_ptr<int> tmp(std::make_shared<int>(i));
    f2(tmp);
  }

  std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
  std::cout << "time native: " << dur.count() << " seconds" << std::endl;
}

/* Test: using raw pointer:
jk:pointer$g++ -O 
jk:pointer$time ./a.out
time native: 12.3017 seconds

real	0m12.303s
user	0m12.298s
sys	0m0.004s

/* Test: using shared pointer with make-shared:
   replace the body of the loop with the following:
   {
    std::shared_ptr<int> tmp(std::make_shared<int>(i));
    f2(tmp);
   }

jk:pointer$g++ -O p.cpp
jk:pointer$time ./a.out
time native: 19.4247 seconds

real	0m19.429s
user	0m19.424s
sys	0m0.004s
*/
