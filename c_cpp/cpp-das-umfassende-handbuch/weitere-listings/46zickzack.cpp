    auto zickzack(size_t n, size_t count) {
        if(n==1) return count;
        else if(n%2==0) return zickzack(n/2, count+1);
        else return zickzack(n*3+1);
    }
