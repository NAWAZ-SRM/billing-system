
#include <iostream>
#include <fstream>
using namespace std;
 

class shopping{
    private:
        int pcode;
        float price;
        float discount;
        string pname;
     
    public:
        void menu();
        void administrator();
        void list();
        void buyer();
        void add();
        void edit();
        void rem();
        void reciept();

};



void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t _____________________________________\n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t     supermarket main menu            \n";
    cout<<"\t\t\t\t                                      \n";
    cout<<"\t\t\t\t _____________________________________\n";
    cout<<"\t\t\t\t |      1) Administrator      |  \n";
    cout<<"\t\t\t\t |                            |  \n";
    cout<<"\t\t\t\t |      2)Buyer               |  \n";
    cout<<"\t\t\t\t |                            |  \n";
    cout<<"\t\t\t\t |      3)Exit                |  \n";
    cout<<"\n\t\t\t   Please select one option !  ";
    cin>>choice;

    switch(choice)
    {
        case 1:
        
        cout<<"\t\t\t Please Login !! \n";
        cout<<"\t\t\t Enter Email :  \n";
        cin>>email;
        cout<<"\t\t\t Enter Password :      \n";
        cin>>password;

        if(email=="funmail34@gmail.com"  && password=="nash@29042005")
        {
            administrator();
        }
        else{
            cout<<"Invalid email or password !! ";
        }
        break;

    


    case 2:
    {
        buyer();
    }
    

    case 3:
    {
        exit(0);
    }

    default :
    {
        cout <<"Select only from the given options !!";
    }

    }
    goto m;
}


void shopping :: administrator()
{
    m: 
    int choice;
    cout <<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t|    1) Add the product    |";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|   2) Mod the product     |";
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|   3) Delete the product  |"; 
    cout<<"\n\t\t\t|                          |";
    cout<<"\n\t\t\t|   4)Back to main menu    |";
    
    cout<<"\n\n\t Please enter your choice !!  ";
    cin>>choice;




    switch(choice)
    {
        case 1 :
            add();
            break;

        case 2 :
            edit();
            break;

        case 3:
            rem();
            break;


        case 4:
            menu();
            break;

        default :
            cout<<"Invalid choice !!";

    }


    goto m;


}



void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t       Buyer        \n";
    cout<<"\t\t\t                    \n";
    cout<<"\t\t\t 1) Buy Product     \n";
    cout<<" \t\t\t                   \n";
    cout<<"\t\t\t    2) Go back      \n";
    cout<<"\t\t\t  Enter your choice   \n";
    cin>>choice;


    switch(choice)
    {
        case 1 :
            reciept();
            break;
        
        case 2 :
            menu();
            break;

        default:

            cout<<"Invalid Choice !! ";
    }
    goto m ;
}


void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;



    cout<<"\n\n\t\t\t  Add new Product  ";
    cout<<"\n\n\t Product code of the product  ";
    cin>>pcode;
    cout<<"\n\n\t Name of the Product   ";
    cin>>pname;
    cout<<"\n\n\t Price of the product   ";
    cin>>price;
    cout<<"\n\n\t Discount offered   ";
    cin>>discount;


    data.open("database.txt",ios::in);


    if(!data)
    {
        data.open("database.txt",ios::app|ios::out); 
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;

        while (!data.eof())
        {
            if (c==pcode){
                token++ ;
            }
            data>>c>>n>>p>>d;
        }
       data.close(); 
    


    if(token==1)
    {
    goto m; 
    }
    else{
         data.open("database.txt",ios::app|ios::out); 
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    }

    cout<<"\n\n\t\t  Record inserted !";
}


void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;


    cout<<"\n\t\t\t Modify the Record";
    cout<<"\n\t\t\t  Product Code";
    cin>>pkey;


    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File Doesn't Exist !!";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\n\t Discount :";
                cin>>d;
                data1<<" "<< c <<" "<< n <<" "<< p << " " << d << "\n";
                cout<<"\n\n\t\t Record Edited";
                token++;


            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\n Record not found !!";
        }
    }
}




void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product Key : ";
    cin>>pkey;
    data.open("database.txt" , ios::in);
    if(!data)
    {
        cout<<" File Doesn't Exist ";
    }
    else
    {
        data1.open("database1.txt" , ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product Deleted successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
             data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");


        if(token==0)
        {
            cout<<"\n\n Record not found ";
        }


    }

}



void shopping :: list()
{
    fstream data;
    data.open("database.txt" , ios::in);
    cout<<"\n\n|__________________________________________\n";
    cout<<"ProNo \t\t Name \t\t Price \n";
    cout<<"\n\n|__________________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;
    }
    data.close();

}



void shopping :: reciept()
{
    fstream data;

    int i=0;
    int q;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
int total=0;


    cout<<"\n\n\t\t\t\t RECIEPT ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n EMPTY DATABASE";
    }
    else
    {
        data.close();


        list();
        cout<<"\n__________________________________\n";
        cout<<"\n|                                 \n";
        cout<<"\n      Please Place the order      \n";
        cout<<"\n|                                 \n";
        cout<<"\n__________________________________\n";
        do
        {   
            m:
            cout<<"\n\nEnter the Product Code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the Quantity :";
            cin>>arrq[q];
            for(i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code . Please try again";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do You Want To Buy Another Product ? if yes then press 1 else 0";
            cin>>choice;

        }while(choice==1);
        cout<<"\n\n\t\t\t____________________RECIEPT___________________\n";
        cout<<"\n\n Product number \t Product name \t Product Quantity \t Price Amount \t Amount without Discount\n";
        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;
            while(!data.eof())
            {
                if(pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*discount/100);
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<arrq[i]<<"\t\t\t"<<price<<"\t\t\t"<<amount<<"\t\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>discount;


            }
        }
        data.close();

    }
   
    cout<<"\n\n______________________________________________________________";
    cout<<"\n Total amount : "<< total ;

}



int main()
{
    shopping s;
    s.menu();
}
