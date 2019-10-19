#include <iostream>
#include <random>
int main(){

    auto const N = 15;
    int an_array[N];
    {
        std::random_device rd;
	std::uniform_int_distribution<int> generator(0,100);
	for (auto i = 0; i < N; i++) {
	    an_array[i] = generator(rd);
	}
    }
    for (auto i = 0; i < N; i++) {
        auto last = an_array[i];
        auto index = i;
        for (auto j = i; j < N; j++) {
	    if (an_array[j] < last) {
	        last = an_array[j];
	        index = j;
            }
        }
    an_array[index] = an_array[i];
    an_array[i] = last;
    }	
    std::cout << "sizeof(an_array): "<< sizeof(an_array) <<"\n";
    for (auto i = 0; i < N; i++) {
        std::cout << an_array[i] << "\n";
    }
       
    return 0;
}
