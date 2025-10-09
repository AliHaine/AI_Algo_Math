#ifndef LINEAR_COMB_HPP
#define LINEAR_COMB_HPP

#include  "../libs/vector.hpp"

template<typename K>
Vector<K> linear_combination(const initializer_list<Vector<K>>& vectors, const initializer_list<K>& coefs) {
    Vector<K> res;

    if (vectors.size() != coefs.size())
        fatalError("linear combination vector size mismatch");

    for (size_t y = 0; y < coefs.size(); y++) {
        K coef = coefs.begin()[y];
        Vector<K> vecTarget = vectors.begin()[y];
        for (size_t x = 0; x < vecTarget.getSize(); x++) {
            K scalarRes = coef * vecTarget.at(x);
            if (y == 0)
                res.vec.push_back(scalarRes);
            else
                res.at(x) = res.at(x) + scalarRes;
        }
    }

    return res;
}

#endif