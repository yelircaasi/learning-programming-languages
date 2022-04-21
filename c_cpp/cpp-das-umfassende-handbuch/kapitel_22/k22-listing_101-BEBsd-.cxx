class GzWriteStream {                         // RAII-Wrapper
public:
    gzFile gz_ ;                              // C-Struct aus zlib.h

    explicit GzWriteStream(const string& filename)
        : gz_{gzopen(filename.c_str(),"wb9")} // 'w': write, 'b':binary, '9':level
    {
        if(gz_==NULL) throw std::runtime_error(std::strerror(errno));
    }

    ~GzWriteStream() {
        gzclose(gz_);
    }

    GzWriteStream& operator<<(const vector<char> &data) {
        write(data.data(), data.size());
        return *this;
    }

private:
    void write(const char* data, size_t len) {
        auto res = gzwrite(gz_, data, len);
        if(res==0) throw std::runtime_error("Fehler beim Schreiben");
    }

    GzWriteStream(const GzWriteStream&) = delete;            // keine Kopie
    GzWriteStream& operator=(const GzWriteStream&) = delete; // keine Zuweisung
};

