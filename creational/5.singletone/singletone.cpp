#include <iostream>

using namespace std;

class OnlyOne {
    string name;
    int age;

public:
    static OnlyOne& Instance() {
        static OnlyOne theSingleInstance("Bob", 25);
        return theSingleInstance;
    }

    void show() { cout << "name: " << name << " age:" << age << endl; }

private:
    OnlyOne(string name_, int age_) : name(name_), age(age_) {}
    OnlyOne(const OnlyOne &);
    OnlyOne& operator=(const OnlyOne &);
};

int main() {
    OnlyOne& one = OnlyOne::Instance();
    one.show();

    return 0;
}
