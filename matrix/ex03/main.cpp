#include  "../libs/vector.hpp"

int main() {
    auto u = Vector<double>::from({0., 0.});
    auto v = Vector<double>::from({1., 1.});
    cout << u.dot(v) << endl;

    auto u2 = Vector<double>::from({1., 1.});
    auto v2 = Vector<double>::from({1., 1.});
    cout << u2.dot(v2) << endl;

    auto u3 = Vector<double>::from({-1., 6.});
    auto v3 = Vector<double>::from({3., 2.});
    cout << u3.dot(v3) << endl;

    auto u4 = Vector<double>::from({5., 10.});
    auto v4 = Vector<double>::from({5., 3.});
    cout << u4.dot(v4) << endl;

    return 0;
}