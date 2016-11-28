#include <iostream>
#include <cstring>

using namespace std;

class Musician
{
	const char *name;

public:
	Musician(const char *name_) : name(name_) {}
	virtual ~Musician() {}

protected:
	void output(const char *text) {
		cout << name << ": " << text << ".\n";
	}
};

class Vocalist : public Musician
{
public:
	Vocalist(const char *name) : Musician(name) {}

	void singCouplet (const int coupletNumber) {
		char *text = strdup("has sung a couplet #");
		strncat(text, std::to_string(coupletNumber).c_str(), 15);
		output(text);
	}

	void singChorus() {
		output("has sung Chours");
	}
};

class Guitarist: public Musician
{
public:
	Guitarist(const char *name) : Musician(name) {}

	void playCoolOpening() { output("starts with cool opening"); }
	void playCoolRiffs() { output("plays cool riffs"); }
	void playAnotherCoolRiffs() { output("plays other cool riffs"); }
	void playIncrediblyCoolSolo() { output("gives am amazing cool solo"); }
	void playFinalAccord() { output("finishes the song with cool chord"); }
};

class Bassist: public Musician {
public:
    Bassist(const char* name): Musician(name) {}

    void followTheDrums() { output("follows the drums"); }
    void stopPlaying() { output("stops playing"); }
    void changeRhythm(const char* type) {
    	char* text = strdup("moves to rythm ");
    	strncat(text,  type, 15);
    	strncat(text,  "a", 15);

    	output(text);
    }
};

class Drummer: public Musician {
public:
    Drummer(const char* name): Musician(name) {}

    void startPlaying() { output("starts playing"); }
    void stopPlaying() { output("stops playing"); }
};

class BlackSabbath {
	Vocalist *vocalist;
	Guitarist *guitarist;
	Bassist *bassist;
	Drummer *drummer;

public:
	BlackSabbath() {
		vocalist = new Vocalist("Ozzy Osbourne");
		guitarist = new Guitarist("Tony Iommi");
		bassist = new Bassist("Joseph Butler");
		drummer = new Drummer("William Ward");
	}

	void playCoolSong() {
		guitarist->playCoolOpening();
		drummer->startPlaying();
		bassist->followTheDrums();
		guitarist->playCoolRiffs();
		vocalist->singCouplet(1);
		bassist->changeRhythm("chorus");
		guitarist->playAnotherCoolRiffs();
		vocalist->singChorus();
		bassist->changeRhythm("couplet");
		guitarist->playCoolRiffs();
		vocalist->singCouplet(2);
		bassist->changeRhythm("chorus");
		guitarist->playAnotherCoolRiffs();
		vocalist->singChorus();
		bassist->changeRhythm("couplet");
		guitarist->playIncrediblyCoolSolo();
		guitarist->playCoolRiffs();
		vocalist->singCouplet(3);
		bassist->changeRhythm("chorus");
		guitarist->playAnotherCoolRiffs();
		vocalist->singChorus();
		bassist->changeRhythm("couplet");
		guitarist->playCoolRiffs();
		bassist->stopPlaying();
		drummer->stopPlaying();
		guitarist->playFinalAccord();
	}
};

int main() {
    std::cout << "OUTPUT:" << std::endl;
    BlackSabbath* band = new BlackSabbath();
    band->playCoolSong();

    return 0;
};

