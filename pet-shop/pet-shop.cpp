/*
Магазин запчастей

*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class PetShop {
public:
    // Constructor
    PetShop() {

    }
    // Destructor
    ~PetShop() {

    }
    static char DisplayMenu() {
        system("cls");
        cout << "##############################" << endl;
        cout << "# 1. Add Currencies          #" << endl;
        cout << "# 2. Add Product Types       #" << endl;
        cout << "# 3. Add Product             #" << endl;
        cout << "# X. EXIT                    #" << endl;
        cout << "##############################" << endl;
        char input;
        const set<char> valid_inputs_ = { '1','2','3','x' };
        while (true) {
            cout << "PetShop:> ";
            cin >> input;
            input = static_cast<char>(tolower(static_cast<unsigned char>(input)));
            if (valid_inputs_.count(input)) {
                return input;
            }
            else {
                cout << "ERROR: Select valid command" << endl;
            }
        }
    }
private:
    
    struct ProductType {
        int id;
        string name;
    };
    struct Currency {
        int id;
        string name;
    };
    struct Price {
        int id;
        double amonut;
        int currency_id;
    };
    struct Product {
        int id;
        int product_type_id;
        string name;
        int price_id;
    };

    vector<Product> products_ {};
};

int main()
{

}