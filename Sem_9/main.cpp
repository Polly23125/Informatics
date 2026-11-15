#include <vector>
#include <iostream>

int main(){
    std :: vector<int> vec(1,1);
    
    for (int i = 0; i < 100; i++){
        vec.push_back(1);
        std :: cout << i+1 << ": Size: " << vec.size() << "; Capacity: " << vec.capacity() << '\n';
    }

}