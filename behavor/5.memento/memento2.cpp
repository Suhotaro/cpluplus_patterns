#include <iostream>
using namespace std;

class Originator {
    int state;

public:
    Originator() : state(0) {}

    class Memento;

    Memento* getMemento() {
        Originator::Memento* m = new Originator::Memento();
        m->org = this;
        m->state = state;
        return m;
    }

    void setState(int s) { state = s; }
    void dumpState() { cout << "State: " << state << endl; }

    class Memento {
        friend class Originator;

    private:
        int state;
        Originator* org;

    public:
        Memento() : state(0) {}
        void restoreState() { org->state = state; }
    };
};

int main() {
    Originator org;
    org.setState(1);
    org.dumpState();

    Originator::Memento* m1 = org.getMemento();

    org.setState(2);
    org.dumpState();

    m1->restoreState();
    org.dumpState();

    return 0;
}
