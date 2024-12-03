#include <iostream>
#include <set>

int main() {
    int A, B;
    std::cin >> A >> B;

    std::set<int> x_values;

    // (A, B, x) が等差数列
    // B - A = x - B  -> x = 2 * B - A
    x_values.insert(2 * B - A);

    // (A, x, B) が等差数列
    // x - A = B - x  -> x = (A + B) / 2 (A + B が偶数の場合)
    if ((A + B) % 2 == 0) {
        x_values.insert((A + B) / 2);
    }

    // (B, A, x) が等差数列
    // A - B = x - A  -> x = 2 * A - B
    x_values.insert(2 * A - B);

    // (B, x, A) が等差数列
    // x - B = A - x  -> x = (B + A) / 2 (B + A が偶数の場合)
    if ((B + A) % 2 == 0) {
        x_values.insert((B + A) / 2);
    }

    // (x, A, B) が等差数列
    // A - x = B - A  -> x = 2 * A - B
    x_values.insert(2 * A - B);

    // (x, B, A) が等差数列
    // B - x = A - B  -> x = 2 * B - A
    x_values.insert(2 * B - A);

    std::cout << x_values.size() << std::endl;

    return 0;
}
