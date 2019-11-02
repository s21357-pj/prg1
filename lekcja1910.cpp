#include <iostream>
#include <random>
int main(int argc, char* argv[]){

    auto const N = std::stoi(argv[1]);
    int* an_array = new int[N];
    {
        std::random_device rd;
	std::uniform_int_distribution<int> generator(0,100);
	for (auto i = 0; i < N; i++) {
	    an_array[i] = generator(rd);
	}
    }
    for (auto i = 0; i < N; i++) {
        int* last = &an_array[i];     
        for (auto j = i; j < N; j++) {
	    if (an_array[j] < *last) {
	        last = &an_array[j];	       
            }
        }
    auto tmp = *last;
    *last = an_array[i];
    an_array[i] = tmp;
    }	
    std::cout << "sizeof(an_array): "<< sizeof(an_array) <<"\n";
    for (auto i = 0; i < N; i++) {
        std::cout << an_array[i] << "\n";
    }
       
    return 0;
}
