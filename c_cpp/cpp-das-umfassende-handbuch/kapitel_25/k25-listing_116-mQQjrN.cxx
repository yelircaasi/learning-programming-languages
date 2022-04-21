template<typename It, typename Func>
void adjacent_pair(It begin, It end, Func func) {
    if(begin != end) {
        It prev = begin;    // erstes Argument
        ++begin;            // zweites Argument
        for(; begin != end; ++begin, ++prev) {
            func(*prev, *begin);
        }
    }
}

