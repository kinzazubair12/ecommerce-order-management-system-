
#include <iostream>
#include <string>
using namespace std;

// ------------------ USER STRUCTURE ------------------
struct User {
    string username;
    string password;
    string role; // "admin" or "customer"
};

// ------------------ PRODUCT CLASS ------------------
class Product {
public:
    string name;
    float price;
    int quantity;

    void setProduct(string n, float p, int q) {
        name = n;
        price = p;
        quantity = q;
    }

    void display() {
        cout << "Product: " << name << ", Price: Rs." << price << ", Stock: " << quantity << endl;
    }
};

// ------------------ ORDER CLASS ------------------
class Order {
public:
    string customerName, address, contact;
    Product orderedProducts[20];
    int quantities[20];
    int orderCount = 0;
    float subtotal = 0, discount = 0, tax = 0, total = 0;

    void addItem(const Product& p, int qty) {
        if (qty <= 0) {
            cout << "Invalid quantity.\n";
            return;
        }

        orderedProducts[orderCount] = p;
        quantities[orderCount] = qty;
        float lineTotal = p.price * qty;
        subtotal = subtotal + lineTotal;
        orderCount++;

    }

    void calculateFinalCost() {
        if (subtotal > 10000)
            discount = 0.10f * subtotal;
        else if (subtotal > 5000)
            discount = 0.05f * subtotal;

        tax = 0.16f * (subtotal - discount);
        total = subtotal - discount + tax;
    }

    void displayBill() {
        cout << "\n===== ORDER RECEIPT =====\n";
        cout << "Customer: " << customerName << "\nAddress: " << address << "\nContact: " << contact << endl;
        for (int i = 0; i < orderCount; i++) {
            float itemTotal = orderedProducts[i].price * quantities[i];
            cout << orderedProducts[i].name << " x " << quantities[i] << " = Rs." << itemTotal << endl;
        }
        cout << "Subtotal: Rs." << subtotal << endl;
        cout << "Discount: Rs." << discount << endl;
        cout << "Tax (16%): Rs." << tax << endl;
        cout << "Total: Rs." << total << endl;
        cout << "\n======= THANKS . . =======\n";
        cout << "\n                V \n";

    }
};

// ------------------ GLOBALS ------------------

Product productList[50];
int productCount = 10;

//Ghost Account 

User users[50] = {
    {"admin", "1234", "admin"},
    {"customer", "5678", "customer"}
};
int userCount = 2;

// Preload products
void initializeProducts() {
    productList[0].setProduct("Shoes", 2000, 10);
    productList[1].setProduct("Bag", 3000, 5);
    productList[2].setProduct("Watch", 4000, 7);
    productList[3].setProduct("Notebook", 500, 15);
    productList[4].setProduct("Pen", 25, 100);
    productList[5].setProduct("Candle", 100, 5);
    productList[6].setProduct("Charger", 1500, 10);
    productList[7].setProduct("Pins", 5, 500);
    productList[8].setProduct("Fans", 2500, 9);
    productList[9].setProduct("Laptop Bag ", 1700, 33);
}

// ------------------ SIGN-UP FUNCTION ------------------
void signUp() {
    User newUser;
    cout << "\n===== SIGN UP =====\n";
    cout << "Choose a username: ";
    cin >> newUser.username;
    cout << "Choose a password: ";
    cin >> newUser.password;

    int roleChoice;
    cout << "Select role:\n1. Admin\n2. Customer\nChoice: ";
    cin >> roleChoice;
    newUser.role = (roleChoice == 1) ? "admin" : "customer";

    users[userCount++] = newUser;
    cout << "Account created successfully! You can now log in.\n";
}

// ------------------ LOGIN FUNCTION ------------------
bool login(string& role) {
    string uname, pass;
    cout << "\n===== LOGIN =====\n";
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pass;

    for (int i = 0; i < userCount; i++) {
        if (users[i].username == uname && users[i].password == pass) {
            role = users[i].role;
            return true;
        }
    }
    return false;
}

// ------------------ ADMIN PANEL ------------------
void adminPanel() {
    int choice;
    do {
        cout << "\n===== ADMIN PANEL =====\n";
        cout << "1. Add Product\n2. View Products\n3. Logout\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            float price;
            int qty;
            cin.ignore(); // Clear buffer
            cout << "Enter product name: ";
            getline(cin, name);
            cout << "Enter price: "; cin >> price;
            cout << "Enter quantity: "; cin >> qty;
            productList[productCount++].setProduct(name, price, qty);
            cout << "Product added!\n";
        }
        else if (choice == 2) {
            for (int i = 0; i < productCount; i++)
                productList[i].display();
        }
    } while (choice != 3);
}

// ------------------ CUSTOMER PANEL ------------------
void customerPanel() {
    Order order;
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, order.customerName);
    cout << "Enter your address: ";
    getline(cin, order.address);
    cout << "Enter your contact number: ";
    getline(cin, order.contact);

    int choice;
    do {
        cout << "\n===== CUSTOMER PANEL =====\n";
        cout << "1. View Products\n2. Place Order\n3. Checkout\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < productCount; i++)
                productList[i].display();
        }
        else if (choice == 2) {
            string pname;
            int qty;
            cin.ignore();
            cout << "Enter product name to order: ";
            getline(cin, pname);
            cout << "Enter quantity: "; cin >> qty;

            bool found = false;
            for (int i = 0; i < productCount; i++) {
                if (productList[i].name == pname) {
                    found = true;
                    if (productList[i].quantity >= qty) {
                        order.addItem(productList[i], qty);
                        productList[i].quantity -= qty;
                    }
                    else {
                        cout << "Not enough stock.\n";
                    }
                    break;
                }
            }
            if (!found) cout << "Product not found.\n";
        }
    } while (choice != 3);

    // Final checkout
    order.calculateFinalCost();
    order.displayBill();
}

// ------------------ MAIN FUNCTION ------------------
int main() {
    initializeProducts();

    while (true) {
        string role;
        int option;

        cout << "\n===== E-COMMERCE ORDER SYSTEM =====\n\n";
        cout << "====== Welcome To  Our Store ====== \n\n";
        cout << "===============================================================";
        cout << "\nNote:\n'if you don't want to SignUp , you can also use\nGhost Account login ID and password for admin\nand customer are admin 1234 and customer 5678\nrespectively\n\n";
        cout << "===============================================================\n\n";


        cout << "1. Sign Up\n2. Login\n3. Exit\nEnter choice: \n";


        cin >> option;

        if (option == 1) {
            signUp();
        }
        else if (option == 2) {
            if (login(role)) {
                if (role == "admin")
                    adminPanel();
                else
                    customerPanel();
            }
            else {
                cout << "Login failed! Please try again.\n";
            }
        }
        else if (option == 3) {
            cout << "Exiting system. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}

