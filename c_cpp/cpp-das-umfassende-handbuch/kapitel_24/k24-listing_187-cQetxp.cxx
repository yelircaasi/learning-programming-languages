#include <stack>
template<typename STACKTYPE> void run(STACKTYPE data) { /* ... */ }
run(stack<int>{});              // Default: nutzt vector<int>
run(stack<int,vector<int>>{});  // wie der Default
run(stack<int,list<int>>{});    // nutzt list<int>

