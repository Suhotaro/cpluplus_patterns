#include <map>
#include <iostream>
#include <string>

using namespace std;

/* Flyweight */
class Character
{
public:
	virtual ~Character() {}
	virtual void display() const = 0;

protected:
	char mSymbol;
	int  mWidth;
	int  mHeight;
	int  mAscent;
	int  mDescent;
	int  mPointSize;
};

/* ConcreteFlyweight */
class ConcreteCharacter : public Character
{
public:
	ConcreteCharacter(char aSymbol, int aPointSize) {
		mSymbol = aSymbol;
		mWidth = 120;
		mHeight = 100;
		mAscent = 70;
		mDescent = 0;
		mPointSize = aPointSize;
	}

	/* From Character */
	virtual void display() const {
		std::cout << mSymbol << " ( PointSize:" << mPointSize << ", ptr:" << &(*this) << " )\n";
	}
};

/* Flyweight Factory */
template <int POINT_SIZE = 10>
class CharacterFactory {
	typedef std::map <char, const Character* > Characters;
	Characters mCharacters;

public:
	const Character& getCharacter (char aKey) {
		/* Uses "lazy initialization" */

		Characters::const_iterator it = mCharacters.find(aKey);
		if (mCharacters.end() == it) {
			const Character *character = new ConcreteCharacter(aKey, POINT_SIZE);
			mCharacters[aKey] = character;
			return *character;
		}
		else
		{
			return *it->second;
		}
	}

	virtual ~CharacterFactory() {
		for (Characters::const_iterator it = mCharacters.begin();
			 it != mCharacters.end(); it++) {
			delete it->second;
		}
	}
};

/* Client */
int main() {

	string document = "AAZZBBZB";

	CharacterFactory<12> characterFactory;
	for (string::const_iterator it = document.begin(); it != document.end(); it++) {
		const Character& character = characterFactory.getCharacter(*it);
		character.display();
	}

    return 0;
};

