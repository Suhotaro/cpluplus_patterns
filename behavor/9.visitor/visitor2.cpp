#include <iostream>
#include <string>

template<typename TYPE, size_t COUNT>
inline size_t lenof(TYPE(&)[COUNT]){return COUNT;}

class Foo;
class Bar;
class Baz;
 
class Visitor {
public:
    virtual void visit(Foo& ref) = 0;
    virtual void visit(Bar& ref) = 0;
    virtual void visit(Baz& ref) = 0;
};
 
class Element {
public:
    virtual void accept(Visitor& v) = 0;
};
 
class Foo: public Element {
public:
    void accept(Visitor& v) { v.visit(*this); }
};
 
class Bar: public Element {
public:
    void accept(Visitor& v) { v.visit(*this); }
};
 
class Baz:public Element{
public:
    void accept(Visitor& v) { v.visit(*this); }
};
 
class GetType: public Visitor{
public:
    std::string value;

public:
    void visit(Foo& ref) { value="Foo"; }
    void visit(Bar& ref) { value="Bar"; }
    void visit(Baz& ref) { value="Baz"; }
};
 
int main()
{
    Foo foo;
    Bar bar;
    Baz baz;
    Element* elements[] = { &foo, &bar, &baz};

    for(size_t i = 0; i < lenof(elements); i++) {
        GetType visitor;
        elements[i]->accept(visitor);
        std::cout<<visitor.value<<std::endl;
      }

    return 0;
}


