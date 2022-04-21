struct Puffer {
  const char *data;
  explicit Puffer(unsigned sz): data(new char[sz]) {}
  ~Puffer() { delete[] data; }
  Puffer(const Puffer&) = delete;
  Puffer& operator=(const Puffer&) = delete;
};

