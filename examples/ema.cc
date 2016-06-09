#include "../math/ema.hh"
#include <random>
#include <cstdio>
#include <ctime>
#define RANGE 10
#define TYPE double
int main() {
    srand(time(0));
    std::vector<TYPE> v;
    while (true) {
        size_t nmax = rand() % 100 +1;
        for (size_t x=0; x < nmax; ++x) {
            v.insert(v.end(), (rand() % 1024 +1));
            printf(":set[%d]=%d,", x, static_cast<int>(v[x]));
        }
        printf("\n+ema=%d\n\n", static_cast<int>(::gidway::math::ema<TYPE>(v, RANGE)));
        if (v.size() > nmax) v.erase(v.begin(), v.begin() + nmax);
    }
    return 0;
}
