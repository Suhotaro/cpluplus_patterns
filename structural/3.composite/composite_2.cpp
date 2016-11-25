#include <memory>
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class AbstractFile {
public:
	virtual ~AbstractFile() {}
	virtual string list_files() = 0;
};

class VirtualFile : public AbstractFile {
	string name;
	string content;
public:
	VirtualFile(string name_, string content_) : name(name_), content(content_) {}

	string list_files() {
		return "file name:" + name + ": content " + content + " ";
	}
};

class VirtualDirectory : public AbstractFile {
	string name;
	list<AbstractFile *> children;

public:
	VirtualDirectory(string name_) : name(name_) {}

	void add(AbstractFile *af) { children.push_back(af); }

	string list_files() {
		string tmp;

		for ( AbstractFile *af : children ) {
			tmp += af->list_files();
		}

		return tmp;
	}
};

int main()
{
	VirtualFile *virtual_file = new VirtualFile("file1.txt", "abcdef");
	cout << "file 1: " << virtual_file->list_files() << endl;

	VirtualDirectory *dir = new VirtualDirectory("dir1");
	dir->add(new VirtualFile("file2.txt", "12345"));
	dir->add(new VirtualFile("file3.txt", "ghijkl"));
	cout << "dir 1: " << dir->list_files() << endl;

	VirtualDirectory *dir2 = new VirtualDirectory("dir2");
	dir2->add(new VirtualFile("file4.txt", "67890"));
	dir2->add(dir);
	cout << "dir 2: " << dir2->list_files() << endl;

    return 0;
}

