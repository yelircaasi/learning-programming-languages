#include <atomic>
class SpinlockMutex {
  std::atomic_flag flag_;
public:
  SpinlockMutex()
  : flag_{ATOMIC_FLAG_INIT}
  {}
  void lock() {                                 // z. B. von lock_guard aufgerufen
    while(flag_.test_and_set(std::memory_order_acquire)) // hauptsächlich lesen
      { /* nothing */ }
  }
  void unlock() {
    flag_.clear(std::memory_order_release);              // Schreiboperation
  }
};

