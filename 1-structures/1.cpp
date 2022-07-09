#include <iostream>

struct Ratio {
private:
    int num, denom;
public:
    double to_double() const {
        return static_cast<double>(num)/denom;
    }
    
    Ratio(int num, int denom): num(num), denom(denom) {};

    int getNum()  const{
        return num;
    }

    int getDenom()  const{
        return denom;
    }

    Ratio operator/(const Ratio &other) const {
        return {num * other.denom, denom * other.num};
    }

    friend Ratio operator+(const Ratio &a, const Ratio &b);
    friend std::ostream& operator<<(std::ostream &os, const Ratio &a);

    Ratio& operator++() {
        num += denom;
        return *this;
    }
    Ratio operator++(int){
        Ratio old = *this;
        ++*this;
        return old;
    }
};

Ratio operator/(const Ratio &a, const Ratio &b) {
    return {a.getNum() * b.getDenom(), a.getDenom() * b.getNum()};
}

Ratio operator+(const Ratio &a, const Ratio &b) {
    return {a.num*b.denom + b.num*a.denom, a.denom*b.denom};
}

std::ostream& operator<<(std::ostream &os, const Ratio &a) {
    return os<<a.num<<'/'<<a.denom;
}

int main() {
    [[maybe_unused]]Ratio a1(10, 20);
    [[maybe_unused]]Ratio a2 = {1, 3};
    [[maybe_unused]]Ratio a3{1, 3};
    [[maybe_unused]]Ratio a4(1, 3);

    std::cout<<operator/(a1, a2)<<"\n";
    std::cout<<a1.operator/(a2)<<"\n";
    std::cout<<a1+a2<<"\n";
    std::cout<<++a1<<"\n";
    std::cout<<a1++<<"\n";
    std::cout<<a1<<"\n";
    return 0;
}
