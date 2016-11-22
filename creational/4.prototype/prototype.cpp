#include <iostream>

using namespace std;

class Meal {
public:
    virtual ~Meal() {}
    virtual void eat() = 0;
    virtual Meal *clone() const = 0;
};

class Spaghetti : public Meal {
    int portion = 450;

public:
    Spaghetti() = default;
    Spaghetti(const Spaghetti &spaghetti) = default;
    void eat() { printf("eat spaghetti: %d\n", portion); }
    Spaghetti *clone() const { return new Spaghetti(*this); }
};

int main() {
    Spaghetti s;
    s.eat();

    Spaghetti *s2 = s.clone();
    s2->eat();

    return 0;
}
