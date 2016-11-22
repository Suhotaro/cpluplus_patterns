#include <iostream>

using namespace std;

class Stream
{
public:
    virtual ~Stream() {}
    virtual void open() = 0;
    virtual void send() = 0;
};
 
class FileStream : public Stream
{
public:
    void open() { printf("open a file\n"); }
    void send() { printf("send to the file\n"); }
};

class TCPStream : public Stream
{
public:
    void open() { printf("open a tcp\n"); }
    void send() { printf("send to tcp\n"); }
};

class StreamsFabric {
public:
    typedef enum {
        DEFAULT = 1,
        FILE,
        TCP,
    } stream_type;

    Stream *getStreamer( stream_type type ) {
        if ( FILE == type )
            return new FileStream();
        if ( TCP == type )
            return new TCPStream();
        if ( DEFAULT == type )
            return new FileStream();
    }
};


int main() {
    StreamsFabric stream_fabric;
    Stream *stream = stream_fabric.getStreamer(StreamsFabric::TCP);

    stream->open();
    stream->send();

    return 0;
}
