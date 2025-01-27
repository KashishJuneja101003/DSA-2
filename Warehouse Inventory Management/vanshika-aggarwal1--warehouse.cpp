#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Product class to represent a single product
class Product {
public:
    string name;
    int quantity;

    Product(string name, int quantity) {
        this->name = name;
        this->quantity = quantity;
    }
};

// WarehouseInventory class to manage inventory operations
class WarehouseInventory {
private:
    unordered_map<int, Product*> inventory;

public:
    // Add or update a product in the inventory
    void addProduct(int id, string name, int quantity) {
        // To be implemented
        if (inventory.count(id) != 0) {
            Product* product = inventory[id];
            product->quantity = quantity;
            return;
        }

        Product* newProduct = new Product(name, quantity);
        inventory[id] = newProduct;
    }

    // Remove a product or reduce its quantity
    void removeProduct(int id, int quantity) {
        // To be implemented
        if (inventory.count(id) == 0) {
            cout << "Product not found" << endl;
            return;
        }

        Product* product = inventory[id];
        product->quantity -= quantity;
    }

    // Search for a product by ID
    string searchProduct(int id) {
        // To be implemented
        if (inventory.count(id) == 0) {
            return "Product not found";
        }

        Product* product = inventory[id];
        string name = product->name;
        string quantity = to_string(product->quantity);

        return name + " " + quantity;
    }
};

int main() {
    WarehouseInventory warehouse;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int operation;
        cin >> operation;

        if (operation == 1) { // Add a product
            int id, quantity;
            string name;
            cin >> id >> name >> quantity;
            warehouse.addProduct(id, name, quantity);

        } else if (operation == 2) { // Remove a product
            int id, quantity;
            cin >> id >> quantity;
            warehouse.removeProduct(id, quantity);

        } else if (operation == 3) { // Search a product
            int id;
            cin >> id;
            cout << warehouse.searchProduct(id) << endl;
        }
    }

    return 0;
}