

struct S{ //всё по умолчанию публичное
public:
    int a;
    int b;
    bool method (int a){
        return true;
    }
};

class C{ //всё по умолчанию приватное
public:
    int a;
    int b;
    bool method (int a){
        return true;
    }
    S convert_to_structure(){
        S result;
        result.a = a;
        result.b = b;
    }
private:
    
};

int main(){
    S structure;
    C clas;

    clas.a = 10;
    clas.b = 20;

    S new_structure = clas.convert_to_structure();
}