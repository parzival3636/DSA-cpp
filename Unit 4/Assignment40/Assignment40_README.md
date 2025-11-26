# Assignment 40 - Deletion Operations in Product Inventory Using Search Tree

## Deleting Products from Inventory Managed by BST

This program implements deletion operations in the product inventory BST where each product node contains detailed information, including a unique product code. Deletions include removing a specific product by its unique code and bulk deletion of all expired products based on the current date.

### Product Information Per Node
- Unique Product Code (used for deletion)
- Product Name (BST is organized by product name)
- Price
- Quantity in Stock
- Date Received
- Expiration Date

### Operations Implemented
- **Delete by Product Code:** Search for the product node by unique code and delete it while maintaining BST structure. Deletion handles three cases: leaf node, node with one child, and node with two children (replace with inorder successor or predecessor).  
- **Delete Expired Products:** Recursively traverse the BST, compare expiration dates with the current date, and delete expired product nodes. This operation requires careful tree restructuring after each deletion.

### Key Concepts: BST Deletion and Conditional Bulk Deletion

- Deleting by unique product code requires traversing the BST while checking each node’s unique code, since the BST is organized by product name, not code.  
- Bulk deletion is performed via modified traversal that conditionally removes expired nodes, ensuring no memory leaks and tree integrity.

### Time Complexity
- Deletion by product code: worst-case $$O(n)$$ as searching by unique code may require full traversal.  
- Expired product deletion: $$O(n)$$ traversal with conditional node deletion.

### Example

Given current date as 2025-11-10 and products:

| Product Name | Product Code | Expiration Date |
|--------------|--------------|-----------------|
| Milk         | P1001        | 2025-11-01      |
| Bread        | P1002        | 2025-12-20      |
| Butter       | P1003        | 2025-10-15      |

- Delete product with code P1002 → Bread removed.  
- Delete expired products → Milk and Butter deleted since their expiration dates are before current date.

### Applications
- Real-time inventory management with product deletion by unique ID.  
- Automated removal of expired stock improving inventory quality.  
- Maintaining accurate and updated shop records in dynamic environments.



```cpp
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Product_sak {
    int code_sak;
    string name_sak;
    float price_sak;
    int quantity_sak;
    string dateReceived_sak;
    string expiryDate_sak;
    Product_sak *left_sak, *right_sak;
};

Product_sak* createNode_sak(int code, string name, float price, int qty, string rec, string exp) {
    Product_sak* newNode_sak = new Product_sak;
    newNode_sak->code_sak = code;
    newNode_sak->name_sak = name;
    newNode_sak->price_sak = price;
    newNode_sak->quantity_sak = qty;
    newNode_sak->dateReceived_sak = rec;
    newNode_sak->expiryDate_sak = exp;
    newNode_sak->left_sak = newNode_sak->right_sak = NULL;
    return newNode_sak;
}

Product_sak* insert_sak(Product_sak* root_sak, Product_sak* newNode_sak) {
    if (!root_sak)
        return newNode_sak;
    if (newNode_sak->code_sak < root_sak->code_sak)
        root_sak->left_sak = insert_sak(root_sak->left_sak, newNode_sak);
    else if (newNode_sak->code_sak > root_sak->code_sak)
        root_sak->right_sak = insert_sak(root_sak->right_sak, newNode_sak);
    else
        cout << "Duplicate Product Code not allowed!\n";
    return root_sak;
}

Product_sak* findMin_sak(Product_sak* node) {
    while (node && node->left_sak)
        node = node->left_sak;
    return node;
}

bool isExpired_sak(string expDate) {
    string current = "2025-11-02";
    return expDate < current;
}

Product_sak* deleteByCode_sak(Product_sak* root_sak, int code) {
    if (!root_sak) return NULL;

    if (code < root_sak->code_sak)
        root_sak->left_sak = deleteByCode_sak(root_sak->left_sak, code);
    else if (code > root_sak->code_sak)
        root_sak->right_sak = deleteByCode_sak(root_sak->right_sak, code);
    else {
        // Found node to delete
        if (!root_sak->left_sak && !root_sak->right_sak) {
            delete root_sak;
            return NULL;
        } else if (!root_sak->left_sak) {
            Product_sak* temp = root_sak->right_sak;
            delete root_sak;
            return temp;
        } else if (!root_sak->right_sak) {
            Product_sak* temp = root_sak->left_sak;
            delete root_sak;
            return temp;
        } else {
            Product_sak* temp = findMin_sak(root_sak->right_sak);
            root_sak->code_sak = temp->code_sak;
            root_sak->name_sak = temp->name_sak;
            root_sak->price_sak = temp->price_sak;
            root_sak->quantity_sak = temp->quantity_sak;
            root_sak->dateReceived_sak = temp->dateReceived_sak;
            root_sak->expiryDate_sak = temp->expiryDate_sak;
            root_sak->right_sak = deleteByCode_sak(root_sak->right_sak, temp->code_sak);
        }
    }
    return root_sak;
}

Product_sak* deleteExpired_sak(Product_sak* root_sak) {
    if (!root_sak) return NULL;

    root_sak->left_sak = deleteExpired_sak(root_sak->left_sak);
    root_sak->right_sak = deleteExpired_sak(root_sak->right_sak);

    if (isExpired_sak(root_sak->expiryDate_sak)) {
        cout << "Deleting expired product: " << root_sak->name_sak << " (" << root_sak->code_sak << ")\n";
        root_sak = deleteByCode_sak(root_sak, root_sak->code_sak);
    }
    return root_sak;
}

void inorder_sak(Product_sak* root_sak) {
    if (root_sak) {
        inorder_sak(root_sak->left_sak);
        cout << "\nCode: " << root_sak->code_sak
             << " | Name: " << root_sak->name_sak
             << " | Price: " << root_sak->price_sak
             << " | Quantity: " << root_sak->quantity_sak
             << " | Received: " << root_sak->dateReceived_sak
             << " | Expiry: " << root_sak->expiryDate_sak;
        inorder_sak(root_sak->right_sak);
    }
}

int main() {
    Product_sak* root_sak = NULL;
    int choice;
    do {
        cout << "\n--- Product Inventory Deletion Menu ---";
        cout << "\n1. Insert Product";
        cout << "\n2. Display All Products (Inorder)";
        cout << "\n3. Delete Product by Code";
        cout << "\n4. Delete All Expired Products";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            int code, qty;
            float price;
            string name, rec, exp;
            cout << "Enter Product Code: ";
            cin >> code;
            cout << "Enter Product Name: ";
            cin >> name;
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Date Received (YYYY-MM-DD): ";
            cin >> rec;
            cout << "Enter Expiration Date (YYYY-MM-DD): ";
            cin >> exp;
            root_sak = insert_sak(root_sak, createNode_sak(code, name, price, qty, rec, exp));
        }
        else if (choice == 2) {
            cout << "\nAll Products in Inventory (Inorder):\n";
            inorder_sak(root_sak);
        }
        else if (choice == 3) {
            int code;
            cout << "Enter Product Code to Delete: ";
            cin >> code;
            root_sak = deleteByCode_sak(root_sak, code);
            cout << "\nProduct Deleted Successfully!\n";
        }
        else if (choice == 4) {
            root_sak = deleteExpired_sak(root_sak);
            cout << "\nAll Expired Products Deleted Successfully!\n";
        }
    } while (choice != 5);
    return 0;
}
```
<img width="621" height="736" alt="image" src="https://github.com/user-attachments/assets/9cf4023c-0f00-4abc-81fe-15a68786b7d6" />
<img width="598" height="371" alt="image" src="https://github.com/user-attachments/assets/359c630c-25d4-4bde-8197-8ae629f823fe" />
