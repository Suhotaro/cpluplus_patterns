#include <map>
#include <iostream>
#include <string>
#include <queue>
#include <memory>

using namespace std;

typedef enum {
	SUCCESS = 0,
	OUT_OF_BOUNDS,
} error;

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

struct chunck
{
	int size;
	std::unique_ptr<int[]> mem;

	explicit chunck(int size_) : size(size_), mem(new int[size_]) {

	}
	~chunck() = default;

	int get_at(int idx, error &err) {
		if ((idx-1) > size) {
			err = OUT_OF_BOUNDS;
			return 0;
		}

		err = SUCCESS;
		return mem[idx];
	}

	void set_at(int val, int idx, error &err) {
		if ((idx-1) > size) {
			err = OUT_OF_BOUNDS;
			return;
		}

		err = SUCCESS;
		mem[idx] = val;
	}

	int get_size() {
		return size;
	}

	void show_content() {
		printf("\n");
		for (int i = 0; i < size; i++)
			printf("%d ", mem[i]);
		printf("\n");
	}
};

class slub
{
private:
	int free_chuncks_num;
	int chunk_size;

	queue<std::unique_ptr<chunck> > free_chuncks;

public:
	explicit slub(int free_chuncks_num_, int chunk_size_) :
	free_chuncks_num(free_chuncks_num_), chunk_size(chunk_size_)
	{
		for (int i = 0; i < free_chuncks_num; i++)
			free_chuncks.push(make_unique<chunck> (chunk_size));
	}

	std::unique_ptr<chunck> get_chunck() {

		if (free_chuncks.empty()) {
			for (int i = 0; i < free_chuncks_num; i++) {
				free_chuncks.push(make_unique<chunck> (chunk_size));
			}
		}

		unique_ptr<chunck> return_chunk = std::move(free_chuncks.front());
		free_chuncks.pop();

		return return_chunk;
	}

	void show_num_chunks() {
		printf("size %lu\n", free_chuncks.size());
	}
};

int main() {

	slub s(3, 5);

	std::unique_ptr<chunck> c1 = s.get_chunck();
	s.show_num_chunks();

	std::unique_ptr<chunck> c2 = s.get_chunck();
	std::unique_ptr<chunck> c3 = s.get_chunck();
	s.show_num_chunks();

	std::unique_ptr<chunck> c4 = s.get_chunck();
	s.show_num_chunks();

    return 0;
};

