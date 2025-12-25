#include <iostream>
#include <string>
using namespace std;

class Medicine
{
private:
    int id;
    string name;
    int stock;
    int sold;
    float price;
    string expiry;

public:
    void addMedicine()
    {
        cout << "Enter Medicine ID: ";
        cin >> id;
        cin.ignore();

        cout << "Enter Medicine Name: ";
        getline(cin, name);

        cout << "Enter Stock: ";
        cin >> stock;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Sold Quantity: ";
        cin >> sold;

        cout << "Enter Expiry Date (MM/YYYY): ";
        cin >> expiry;

        cout << "Medicine Added Successfully!\n";
    }

    void viewMedicine()
    {
        cout << "\n--- Medicine Details ---\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Stock: " << stock << endl;
        cout << "Sold: " << sold << endl;
        cout << "Price: " << price << endl;
        cout << "Expiry: " << expiry << endl;
    }

    int getId()
    {
        return id;
    }

    void updateStock(int newStock)
    {
        stock = newStock;
        cout << "Stock Updated Successfully!\n";
    }
};

int main()
{
    Medicine m[10];
    int count = 0;
    int choice, sid, newStock;
    bool found;

    do
    {
        cout << "\n===== Medical Information System =====\n";
        cout << "1. Add Medicine\n";
        cout << "2. View All Medicines\n";
        cout << "3. Search Medicine by ID\n";
        cout << "4. Update Stock\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            if (count < 10)
            {
                m[count].addMedicine();
                count++;
            }
            else
            {
                cout << "Medicine limit reached!\n";
            }
            break;

        case 2:
            if (count == 0)
            {
                cout << "No medicine available!\n";
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    m[i].viewMedicine();
                }
            }
            break;

        case 3:
            cout << "Enter Medicine ID to search: ";
            cin >> sid;
            found = false;
            for (int i = 0; i < count; i++)
            {
                if (m[i].getId() == sid)
                {
                    m[i].viewMedicine(); // expiry yahin show hogi
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Medicine Not Found!\n";
            }
            break;

        case 4:
            cout << "Enter Medicine ID: ";
            cin >> sid;
            found = false;
            for (int i = 0; i < count; i++)
            {
                if (m[i].getId() == sid)
                {
                    cout << "Enter new stock: ";
                    cin >> newStock;
                    m[i].updateStock(newStock);
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Medicine Not Found!\n";
            }
            break;

        case 5:
            cout << "Thank You! Exiting...\n";
            break;
        1 default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
