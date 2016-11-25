#include <memory>
#include <iostream>
#include <list>
#include <algorithm>

class IText; /* Component */

using namespace std;

class IText {
public:
	typedef shared_ptr<IText> SPtr;

	virtual ~IText() {}
	virtual void draw() = 0;
	virtual void add(const SPtr&) { throw runtime_error("IText: Can't add to a leaf"); }
	virtual void remove(const SPtr&) { throw runtime_error("IText: Can't remove from a leaf"); }
};

class CompositeText : public IText {
	list<SPtr> children;
public:
	void draw() {
		for (SPtr &sptr : children)
			sptr->draw();
	}

	void add(const SPtr& sptr) { children.push_back(sptr); }
	void remove(const SPtr& sptr) { children.remove(sptr); }
	void replace(const SPtr& oldValue, const SPtr& newValue) {
		std::replace(children.begin(), children.end(), oldValue, newValue);
	}
};

class Letter : public IText {
	char c;
public:
	Letter(char c_) : c(c_) {}
	virtual void draw() { cout << c; }
};

int main()
{
	IText::SPtr lSpace(new Letter(' '));
	IText::SPtr lExcl(new Letter('!'));
	IText::SPtr lComma(new Letter(','));
	IText::SPtr lNewLine(new Letter('\n'));

	IText::SPtr lH(new Letter('H'));
	IText::SPtr le(new Letter('e'));
	IText::SPtr ll(new Letter('l'));
	IText::SPtr lo(new Letter('o'));
	IText::SPtr lW(new Letter('W'));
	IText::SPtr lr(new Letter('r'));
	IText::SPtr ld(new Letter('d'));
	IText::SPtr li(new Letter('i'));

	IText::SPtr wHello(new CompositeText);
	wHello->add(lH);
	wHello->add(le);
	wHello->add(ll);
	wHello->add(ll);
	wHello->add(lo);

	IText::SPtr wWorld(new CompositeText);
	wWorld->add(lW);
	wWorld->add(lo);
	wWorld->add(lr);
	wWorld->add(ll);
	wWorld->add(ld);

	CompositeText sentence;
	sentence.add(wHello);
	sentence.add(lComma);
	sentence.add(lSpace);
	sentence.add(wWorld);
	sentence.add(lExcl);
	sentence.add(lNewLine);
	sentence.draw();

	IText::SPtr wHi(new CompositeText);
	wHi->add(lH);
	wHi->add(li);

	sentence.replace(wHello, wHi);
	sentence.draw();

	sentence.remove(wWorld);
	sentence.remove(lSpace);
	sentence.remove(lComma);
	sentence.draw();

    return 0;
}

