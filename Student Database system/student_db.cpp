#include <iostream>
#include <regex>
#include <sqlite3.h>

using namespace std;

static bool isValid_name(const string name);
static bool isValid_id(const string id);
static bool isValid_email(const string& email);
static bool isValid_phone(const string number);
static int createDB(const char* s);
static int createTable(const char* s);
static int insertData(const char* s, string id, string name, string age, string email, string phone);
static int selectData(const char* s);
static int callback(void *NotUsed, int argc, char** argv, char** azColName);
static int searchTable_id(const char* s, string id);
static int deleteTable_name(const char* s, string name);
static int deleteTable_id(const char* s, string id);
static int updateTable_name(const char* s, string name, string id, string age, string email, string phone);

int main()
{
    const char* dir = "students.db";
    sqlite3* DB;

    //createDB(dir);
    //createTable(dir);

    int choice = 0;

    while (choice != 7)
    {
        cout << "\n\t\tEnter your choice" << endl;
        cout << "\t\t--------------------" << endl;
        cout << "\t\t1. Show list of all students." << endl;
        cout << "\t\t2. Add student." << endl;
        cout << "\t\t3. Update student." << endl;
        cout << "\t\t4. Remove student by name." << endl;
        cout << "\t\t5. Remove student by id." << endl;
        cout << "\t\t6. Search student by id." << endl;
        cout << "\t\t7. Quit Program.\n" << endl;
        cout << "\t\t--------------------" << endl;

        cin >> choice;

        switch (choice)
        {
            case 1: 
            {
                cout << endl;
                selectData(dir);
                cout << endl;
                break;
            }
            
            case 2:
            {
                string id, name, age, email, phone;

                cout << "Enter id of the student: ";
                cin >> id;
                while (!isValid_id(id))
                {
                    cout << "Invalid ID. Enter ID again: ";
                    cin >> id;
                }

                cout << "Enter name of the student: ";
                cin >> name;
                while (!isValid_name(name))
                {
                    cout << "Invalid name. Enter name again: ";
                    cin >> name;
                }

                cout << "Enter age of the student: ";
                cin >> age;
                while (!isValid_id(age))
                {
                    cout << "Invalid age. Enter age again: ";
                    cin >> age;
                }

                cout << "Enter email of the student: ";
                cin >> email;
                while (!isValid_email(email))
                {
                    cout << "Invalid Email. Enter Email again: ";
                    cin >> email;
                }

                cout << "Enter phone number of the student: ";
                cin >> phone;
                while (!isValid_phone(phone))
                {
                    cout << "Invalid Phone Number. Enter Phone Number again: ";
                    cin >> phone;
                }

                cout << endl;

                insertData(dir, id, name, age, email, phone);
                cout << endl;
                break;
            }

            case 3:
            {
                string name, id, age, email, phone;
                cout << "Enter the name of the student: ";
                cin >> name;
                cout << endl;

                cout << "Enter new id for " << name << " : ";
                cin >> id;
                while (!isValid_id(id))
                {
                    cout << "Invalid id. Enter id again: ";
                    cin >> id;
                }

                cout << "Enter new age for " << name << " : ";
                cin >> age;
                while (!isValid_id(age))
                {
                    cout << "Invalid age. Enter age again: ";
                    cin >> age;
                }

                cout << "Enter new Email for " << name << ": ";
                cin >> email;
                while (!isValid_email(email))
                {
                    cout << "Email is Invalid. Enter Email again: ";
                    cin >> email;
                }

                cout << "Enter new Phone number for " << name << ": ";
                cin >> phone;
                while (!isValid_phone(phone))
                {
                    cout << "Phone number is invalid. Enter Phone number again: ";
                    cin >> phone;
                }

 
                updateTable_name(dir, name, id, age, email, phone);
                cout << endl;
                break;
            }

            case 4:
            {
                string name;

                cout << "Enter the name of student to be deleted: ";
                cin >> name;
                while (!isValid_name(name))
                {
                    cout << "Invalid name. Enter name again: ";
                    cin >> name;
                }

                deleteTable_name(dir, name);
            }

            case 5:
            {
                string id;

                cout << "Enter the id of student to be deleted: ";
                cin >> id;
                while (!isValid_id(id))
                {
                    cout << "Invalid id. Enter id again: ";
                    cin >> id;
                }

                deleteTable_id(dir, id);
                break;
            }

            case 6:
            {
                string id;

                cout<< "Enter the id of student: ";
                cin >> id;
                while (!isValid_id(id))
                {
                    cout << "Invalid id. Enter id again: ";
                    cin >> id;
                }
                
                cout << endl;
                searchTable_id(dir, id);
                cout << endl;
                break;
            }

            case 7:
            {
                cout << "Exiting program..." << endl;
                break;
            }
            default:
            {
                cout << "Invalid INPUT! Enter again." << endl;
                break;
            }
        }
    }



    return 0;
    sqlite3_close(DB);

}

static int createDB(const char* s)
{
    sqlite3* DB;
    int exit = 0;

    exit = sqlite3_open(s, &DB);

    sqlite3_close(DB);

    return 0;
}

static int createTable(const char* s)
{
    sqlite3* DB;

    string sql = "CREATE TABLE IF NOT EXISTS STUDENTS("
    "ID INTEGER, "
    "NAME TEXT, "
    "AGE INTEGER, "
    "EMAIL TEXT, "
    "PHONE TEXT );";

    try
    {
        int exit = 0;
        exit = sqlite3_open(s, &DB);

        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK)
        {
            cerr << "Error Creating Table" << endl;
            sqlite3_free(messageError);
        }
        else
        {
            cout << "Table Created Successfully." << endl;
        }
        sqlite3_close(DB);
    }

    catch (const exception& e)
    {
        cerr << e.what();
    }

    return 0;

}

static int insertData(const char* s, string id, string name, string age, string email, string phone)
{
    sqlite3* DB;
    char* messageError;

    string foo = "(\'" + (string) id+ "\'" + ", " + "\'" + name + "\'" + ", " + "\'" + (string) age + "\', " + "\'" + email + "\', " + "\'" + phone + "\');";


    int exit = sqlite3_open(s, &DB);

    string sql1 = "INSERT INTO STUDENTS VALUES ";

    string sql = sql1 + foo;

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit!= SQLITE_OK)
    {
        cerr << "Error Inserting" << endl;
        sqlite3_free(&messageError);
    }
    else 
    {
        cout << "Record created Successfully!" <<endl;
    }

    return 0;
}

static int selectData(const char* s)
{
    sqlite3* DB;

    int exit = sqlite3_open(s, &DB);

    cout << "ID\t\t" << "Name\t\t" << "Age\t\t" << "Email\t\t\t\t\t" << "Phone Number" << endl;
    cout <<"-----\t\t-----\t\t-----\t\t-----\t\t\t\t\t-----"<< endl;

    string sql = "SELECT * FROM STUDENTS ORDER BY ID;";

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

  

    return 0;
}

static int callback(void *NotUsed, int argc, char** argv, char** azColName)
{
    for (size_t i = 0; i < argc-2; i++)
    {
        cout << argv[i] << "\t\t";
    }
    for(size_t i = argc-2; i < argc; i++)
    {
        cout << argv[i] << "\t\t\t";
    }
    cout << endl;

    return 0;
}

static int searchTable_id(const char* s, string id)
{
    sqlite3* DB;
    string ans;

    int exit = sqlite3_open(s, &DB);


    cout << "ID\t\t" << "Name\t\t" << "Age\t\t" << "Email\t\t" << "Phone Number" << endl;
    cout <<"-----\t\t-----\t\t-----\t\t-----\t\t-----"<< endl;


    string sql1 = ("SELECT * FROM STUDENTS WHERE ID = ");
    string sql = sql1 + "\'" + id +"\'" + ";";

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);



    return 0;
}

static int deleteTable_name(const char* s, string name)
{
    sqlite3* DB;
    
    int exit = sqlite3_open(s, &DB);

    string sql1 = "DELETE FROM STUDENTS WHERE NAME LIKE ";
    string sql = sql1 + "\'" + name +"\'" + ";";
    //cout << sql << endl;
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
    cout << "Record deleted!" << endl;

    return 0;
}

static int deleteTable_id(const char* s, string id)
{
    sqlite3* DB;

    int exit = sqlite3_open(s, &DB);

    string sql1 = "DELETE FROM STUDENTS WHERE ID = ";
    string sql = sql1 + "\'" + id +"\'" + ";";

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
    cout << "Record Deleted!" << endl;

    return 0;

}

static int updateTable_name(const char* s, string name, string id, string age, string email, string phone)
{
    sqlite3* DB;

    int exit = sqlite3_open(s, &DB);

    //UPDATE STUDENTS SET id = 5, age = 90 WHERE NAME LIKE 'ROHAN';

    string sql1 = "UPDATE STUDENTS SET id = ";
    string sql2 = ", age = ";
    string sql3 = ", email = ";
    string sql4 = ", phone = ";
    string sql5 = " WHERE NAME LIKE ";
    string sql = sql1 + id + sql2 + age + sql3 + email + sql4 + phone + sql5 + "\'" + name + "\'" + ";";

    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
    cout << sql << endl;
    cout << "Record Updated!" << endl;

    return 0;

}

static bool isValid_phone(const string number)
{
    const regex pattern ("(0|[+]91)?[7-9][0-9]{9}");

    return regex_match(number, pattern);
}

static bool isValid_email(const string& email)
{
    const regex pattern (
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    
    return regex_match(email, pattern);
}

static bool isValid_name(const string name)
{
    const regex pattern("[A-Za-z\\s]*");

    return regex_match(name, pattern);
}

static bool isValid_id(const string id)
{
    const regex pattern("[0-9]([0-9]*)?");
    return regex_match(id, pattern);
}
