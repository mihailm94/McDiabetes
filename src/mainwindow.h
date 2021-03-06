#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "database.h"

#include <QMainWindow>

//include for error box at try..catch.. statement
#include <QMessageBox>

//for the current time
#include <QDateTime>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //variable to store index of item that has been clicked on in tableViewMain/Side/etc..
    static QString itemRowString;

    //variable to store item options index (for qtableview)
    static QString itemOptionsRowString;

    //current logged in user
    static QString currentUser;

    //variable to store the current order summary choice
    static QString orderInfoString;

    //variable to store selected user info in the admin screen (for editing their info)
    static QString selectedUser;
    static QString selectedUserUserName;
    static QString selectedUserFirstName;
    static QString selectedUserLastName;
    static QString selectedUserStreet;
    static QString selectedUserStreetNr;
    static QString selectedUserCity;
    static QString selectedUserPlz;
    static QString selectedUserEmail;

    //variables to store selected item name & size in the admin "list menu" functionality
    static QString selectedItemName;
    static QString selectedItemSize;

    //variables to store new item info
    static QString newItemCategory;
    static QString newItemType;
    static QString newItemName;
    static double newItemPrice;

    //variables to store hour&minute for the order
    static int hour;
    static int minute;



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool isConnected(); //returns true when DB connection successful

private slots:

    //"global" logout func
    void on_buttonLogout_clicked(); //logout button on admin screen


    //PAGE 0 - DB CONNECTION
    void on_checkBox_stateChanged(int arg1); //checkbox to change database settings
    void on_buttonConnectDB_clicked(); //database connection
    void on_buttonLoginStart_clicked(); //big login button on page 0
    void on_buttonNewUser_clicked(); //big new user button on page 0


    //PAGE 1 - Login screen
    void on_buttonLogin_clicked(); //login button


    //PAGE 2 - Admin screen
    void on_buttonListAllMenu_clicked(); //list all menu items
    void on_buttonListOrders_clicked(); //list all orders so far
    void on_tableAllOrdersTimestampAdmin_clicked(const QModelIndex &index); //list all orders incl. usernames
    void on_buttonListUsers_clicked(); //list all users
    void on_buttonEditSelectedUser_clicked(); //edit user info
    void on_tableAllUsersAdmin_clicked(const QModelIndex &index); //all users that are not admins
    void on_buttonSubmitChangesAdmin_clicked(); //save user data change
    void on_buttonCancelChangesAdmin_clicked(); //revert user data to last known
    void on_buttonDeleteSelectedUser_clicked(); //delete selected user from DB
    void on_tableListAllMenuItems_clicked(const QModelIndex &index); //full menu items of all categories
    void on_buttonDeleteItemAdmin_clicked(); //delete selected item
    void on_buttonAddItemAdmin_clicked(); //add new item
    void on_sizeRegular_stateChanged(int arg1); //if checked, no other sizes are available
    void on_buttonCreateNewItem_clicked(); //create new item
    void on_buttonCancelNewItem_clicked(); //no new item


    //PAGE 3 - User screen
    void setTime(); //sets time to the users wished time
    int getHour(); //returns set hour value
    void on_buttonNewOrder_clicked(); //new order for user
    void on_buttonShowPrevOrders_clicked(); //show previous orders for this user
    void on_tableViewPrevOrderTimestamps_clicked(const QModelIndex &index); //all orders for this user only
    void on_buttonUserInfo_clicked(); //user info + editing
    void on_checkBoxEditUserInfo_stateChanged(int arg1); //if checked enables fields for input
    void on_buttonCancelInfoChangeUser_clicked(); //reverts to last known info
    void on_buttonSubmitInfoChangeUser_clicked(); //submits changes to user info
        //NewOrder
    void updateTimeLabel(); //sets the QtimeEdit to current hour
    void on_pushButtonSetTime_clicked(); //sets time to preset time
    void on_checkBoxSetTime_stateChanged(int arg1); //enables changing of time value
    void on_tableViewAllMains_clicked(const QModelIndex &index); //list mains according to hour
    void on_tableViewAllSides_clicked(const QModelIndex &index); //list sides according to hour
    void on_tableViewAllDrinks_clicked(const QModelIndex &index); //list drinks according to hour
    void on_tableViewAllDesserts_clicked(const QModelIndex &index); //list desserts according to hour
    void on_tableViewItemOptions_clicked(const QModelIndex &index); //regular, small, medium, large?
    void on_buttonAddToCart_clicked(); //adds to cart table
    void on_buttonClearCart_clicked(); //deletes cart
    void on_buttonToCheckout_clicked();//next page, order summary
    void on_buttonCancelOrder_clicked();
    void on_buttonConfirmOrder_clicked();


    //PAGE 4 - New user
    void clearNewUserInput(); //clears all the fields
    void on_buttonClearUserFields_clicked(); //clear fields
    void on_buttonSubmitNewUser_clicked(); //submit new user information
    void on_buttonToLoginNewUserSuccess_clicked(); //if successful, inserts into table and u can log in


private:
    Ui::MainWindow *ui;

    Database *db;

    QTimer *countdownConnect;
};



#endif // MAINWINDOW_H
