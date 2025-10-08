#include  "./linear_comb.hpp"

int main() {
    auto e1 = Vector<double>::from({1., 0., 0.});
    auto e2 = Vector<double>::from({0., 1., 0.});
    auto e3 = Vector<double>::from({0., 0., 1.});

    auto result = linear_combination(
        {e1, e2, e3},
        {10., -2., 0.5}
    );

    result.print();

    auto v1 = Vector<double>::from({1., 2., 3.});
    auto v2 = Vector<double>::from({0., 10., -100.});

    auto res2 = linear_combination(
        {v1, v2},
        {10., -2.}
    );

    res2.print();

    auto ee1 = Vector<int>::from({1, 2, 3});
    auto ee2 = Vector<int>::from({3, 2, 2});
    auto ee3 = Vector<int>::from({5, 6, 5});

    auto res3 = linear_combination(
        {ee1, ee2, ee3},
        {2, 2, 1}
    );

    res3.print();
}