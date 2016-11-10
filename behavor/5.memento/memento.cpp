#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

typedef enum {
	WHITE,
	BLACK,
} background;

class Memento {
	const string text;
	const background color;

public:
	Memento (string text_, background color_) : text(text_), color(color_) {}

	string getText() { return text; }
	background getColor() { return color; }
};

class Editor {
private:
	string text;
	background color;

public:
	Editor (string text_, background color_) : text(text_), color(color_) {}

	string getText() { return text; }
	void setText(string text_) { text = text_; }
	background getColor() { return color; }
	void setColor(background color_) { color = color_; }

	void show() { printf("info: %s %d\n", text.c_str(), color); }

	Memento *saveToMemento() { return new Memento(text, color); }
	void restoreFromMemento(Memento *memento) {
		text = memento->getText();
		color = memento->getColor();
	}
};

int main()
{
	vector<Memento *> data;

	Editor *editor = new Editor("aaaaaaaaa", WHITE);
	editor->show();

	data.push_back(editor->saveToMemento());

	editor->setText("bbbbbbbbb");
	editor->setColor(BLACK);
	editor->show();

	editor->restoreFromMemento(data[0]);
	editor->show();

	return 0;
}

