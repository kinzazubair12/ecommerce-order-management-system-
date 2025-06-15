#  E-Commerce Order Management System

This is a console-based C++ application simulating a small-scale e-commerce platform. It allows admins to manage products and customers to place orders, calculate totals with tax and discounts, and generate a detailed bill.

---

## ✅ Features

--> 👥 User Roles

  * Admin
  * Customer
  

-->🔐 Authentication

  * Sign-up and Login for both roles
  * Ghost/default accounts included:

    * Admin → `admin / pakistan`
    * Customer → `customer / karachi`

--> 🛍️ Product Management (Admin)

  * Add products
  * View product list

--> 📦 Order Placement (Customer)

  * View available products
  * Place an order (with stock check)
  * Provide name, address, and contact info
  * Automatic discount application
  * 16% Sales tax included

  -->🧾 Billing

  * Detailed bill summary with subtotal, discount, tax, and total cost

---

## 🧮 Discount Rules

* 5% off for orders over Rs. 5000
* 10% off for orders over Rs. 10000
* +16% Sales Tax after discount

---

## ▶️ Working

 1. Launch the Program

* On startup, users are prompted to **Sign Up** or **Login**.

 2. Admin Role

* Login using admin credentials.
* Options to:

  * Add new products (name, price, quantity)
  * View existing products

 3. Customer Role

* Login or sign up as a customer.
* Options to:

  * View all products
  * Place orders with desired quantities
  * System checks stock, applies discounts, calculates tax
  * Order receipt is generated with full summary

---

🧑‍💻 How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/kinzazubair12/ecommerce-order-management-system.git
   cd ecommerce-order-management-system
   ```

2. Compile and run the program:

   ```bash
   g++ -o ecommerce main.cpp
   ./ecommerce
   ```

---

## 👩‍💻 Author

**Kinza Zubair**
2nd Semester Electrical Engineering Student
Developed as an open-ended lab assignment with team.
---

