#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<process.h>
using namespace std;
class book
{
	char bno[6];
	char bname[50];
	char aname[20];
  public:
	void create_book()
	{
		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nEnter The book no : ";
		cin>>bno;
        fflush(stdin);
		cout<<"\nEnter The Name of The Book : ";
		gets(bname);
        fflush(stdin);
		cout<<"\n\nEnter The Author's Name : ";
		gets(aname);
		cout<<"\n\n\nBook Created..";
	}

	void show_book()
	{
		cout<<"\nBook no. : "<<bno;
		cout<<"\nBook Name : ";
		puts(bname);
		cout<<"Author Name : ";
		puts(aname);
	}
	char* retbno()
	{
		return bno;
	}

	void report()
	{
	    cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
    }

};
class student
{
	char Rollno[10];
	char name[20];
    char password[10];
    char stbno[6];
	int token;
public:
	void create_student()
	{
		cout<<"\nNEW STUDENT ENTRY...\n";
        fflush(stdin);
		cout<<"\nEnter The Roll no : ";
		cin>>Rollno;
        fflush(stdin);
		cout<<"\n\nEnter The Name of The Student : ";
		gets(name);
        cout<<"\nEnter the password : ";
        int i = 0;
        char a;
        for(i=0;;)
        {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            password[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            --i;
        }
        if(a=='\r')
        {
            password[i]='\0';
            break;
        }
       }
		token=0;
		stbno[0]='\0';
		cout<<"\n\nStudent Record Created..";
	}

	void show_student()
	{
		cout<<"\nRoll no. : "<<Rollno;
		cout<<"\nStudent Name : ";
		puts(name);
		cout<<"\nNo of Book issued : "<<token;
		if(token==1)
			cout<<"\nBook No "<<stbno;
	}
	char* retRollno()
	{
		return Rollno;
	}
    char* retPass()
	{
		return password;
	}
	char* retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{token=1;}

	void resettoken()
	{token=0;}

	void getstbno(char t[])
	{
		strcpy(stbno,t);
	}

	void report()
	{
	    cout<<"\t"<<Rollno<<setw(20)<<name<<setw(10)<<token<<endl;
    }

};
fstream fp,fp1;
book bk;
student st;
void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\nDo you want to add more record..(y/n?) : ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void write_student()
{
	char ch;
	fp.open("student.dat",ios::out|ios::app);
	do
	{
		st.create_student();
		fp.write((char*)&st,sizeof(student));
		cout<<"\n\ndo you want to add more record..(y/n?) : ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}
void delete_book()
{
	char n[6];
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
	}

	fp2.close();
    	fp.close();
    	remove("book.dat");
    	rename("Temp.dat","book.dat");
    	cout<<"\n\n\tRecord Deleted ..";
    	getch();
}
void delete_student()
{
	char n[10];
	cout<<"\n\n\n\tDELETE STUDENT RECORD ...";
    fflush(stdin);
	cout<<"\n\nEnter The Roll no. of the Student You Want To Delete : ";
	cin>>n;
    fflush(stdin);
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retRollno(),n)!=0)
		{
			fp2.write((char*)&st,sizeof(student));
		}
	}
	fp2.close();
    	fp.close();
    	remove("student.dat");
    	rename("Temp.dat","student.dat");
    	cout<<"\n\n\tRecord Deleted ..";
    	getch();
}
void display_allb()
{
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
       		getch();
       		return;
     	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();
	}
    getche();
    fp.close();
}
void book_issue()
{
    char sn[10],bn[6],pass[10];
    int found=0,flag=0;
    cout<<"\n\nBOOK ISSUE ...";
    fflush(stdin);
    cout<<"\n\n\tEnter The student's Roll no : ";
    cin>>sn;
    fflush(stdin);
    fflush(stdin);
    cout<<"\n\nEnter Password : ";
    int i = 0;
    char a;
    for(i=0;;)
    {
    a=getch();
    if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
    {
        pass[i]=a;
        ++i;
        cout<<"*";
    }
    if(a=='\b'&&i>=1)
    {
        cout<<"\b \b";
        --i;
    }
    if(a=='\r')
    {
        pass[i]='\0';
        break;
    }
    }
    fp.open("student.dat",ios::in|ios::out);
        fp1.open("book.dat",ios::in|ios::out);
        while(fp.read((char*)&st,sizeof(student)) && found==0)
        {
        if(strcmpi(st.retRollno(),sn)==0 && strcmpi(st.retPass(),pass)==0)
        {
            found=1;
            if(st.rettoken()==0)
            {
                    cout<<"\n\n\tEnter the book no : ";
                cin>>bn;
                while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
                {
                    if(strcmpi(bk.retbno(),bn)==0)
                    {
                        bk.show_book();
                        flag=1;
                        st.addtoken();
                        st.getstbno(bk.retbno());
                            int pos=-1*sizeof(st);
                        fp.seekp(pos,ios::cur);
                        fp.write((char*)&st,sizeof(student));
                        cout<<"\n\n\t Book issued successfully\n\nPlease Note: Write the current date in backside of your book and submit within 15 days fine Rs. 1 for each day after 15 days period";
                    }
                    }
                if(flag==0)
                        cout<<"Book no does not exist";
            }
                else
                cout<<"You have not returned the last book ";

        }
    }
        if(found==0)
         cout<<"Student record not exist...";
    getche();
    fp.close();
    fp1.close();
}
void book_deposit()
{
    char sn[10],bn[6],pass[10];
    int found=0,flag=0,day,fine;
    cout<<"\n\nBOOK DEPOSIT ...";
    fflush(stdin);
    cout<<"\n\n\tEnter The student's Roll no : ";
    cin>>sn;
    fflush(stdin);
    cout<<"\n\nEnter Password : ";
    int i = 0;
    char a;
    for(i=0;;)
    {
    a=getch();
    if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
    {
        pass[i]=a;
        ++i;
        cout<<"*";
    }
    if(a=='\b'&&i>=1)
    {
        cout<<"\b \b";
        --i;
    }
    if(a=='\r')
    {
        pass[i]='\0';
        break;
    }
    }
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
	    if(strcmpi(st.retRollno(),sn)==0 && strcmpi(st.retPass(),pass)==0)
	    {
		    found=1;
		    if(st.rettoken()==1)
		    {
			while(fp1.read((char*)&bk,sizeof(book))&& flag==0)
			{
			   if(strcmpi(bk.retbno(),st.retstbno())==0)
			{
				bk.show_book();
				flag=1;
				cout<<"\n\nBook deposited in no. of days : ";
				cin>>day;
				if(day>15)
				{
				   fine=(day-15)*1;
				   cout<<"\n\nFine has to deposited Rs. "<<fine;
				}
					st.resettoken();
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&st,sizeof(student));
					cout<<"\n\n\t Book deposited successfully";
			}
		    }
		  if(flag==0)
		    cout<<"Book no does not exist";
		      }
		 else
			cout<<"No book is issued..please check!!";
		}
	   }
      if(found==0){
	    cout<<"Student record not exist...";
     }
     getche();
  fp.close();
  fp1.close();
  }
void admin_menu()
  {
  	system("CLS");
  	int ch2;
  	cout<<"\n\n\n\tADMINISTRATOR MENU";
  	cout<<"\n\n\t1.CREATE STUDENT RECORD";
  	cout<<"\n\n\t2.CREATE BOOK ";
  	cout<<"\n\n\t3.DISPLAY ALL BOOKS ";
  	cout<<"\n\n\t4.DELETE BOOK ";
    cout<<"\n\n\t5.DELETE STUDENT ";
  	cout<<"\n\n\t6.BACK TO MAIN MENU";
  	cout<<"\n\n\tPlease Enter Your Choice (1-6) : ";
  	cin>>ch2;
  	switch(ch2)
  	{
      		case 1: write_student();
                    break;
      		case 2: write_book();
                    break;
            case 3: display_allb();
                    break;
  			case 4: delete_book();
                    break;
            case 5: delete_student();
                    break;
       		case 6: return;
        		default:cout<<"\a";
     }
     admin_menu();
}
void student_menu()
  {
  	system("CLS");
    B:
    char ch2;
  	cout<<"\n\n\n\tSTUDENT MENU";
    cout<<"\n\n\t01. BOOK ISSUE";
    cout<<"\n\n\t02. BOOK DEPOSIT";
  	cout<<"\n\n\t03. BACK TO MAIN MENU";
  	cout<<"\n\n\tPlease Enter Your Choice (1-3) : ";
  	cin>>ch2;
  	switch(ch2)
    	{
            case '1': book_issue();
			   	      break;
		  	case '2': book_deposit();
			    	  break;
       		case '3': return;
        	default: cout<<"\a \nEnter Valid choice ";
                    goto B;
      }
      student_menu();
}
std::string getFileContents (std::ifstream& File)
{
    std::string Lines = "";
    if (File)
    {
	while (File.good ())
	{
	    std::string TempLine;
	    std::getline (File , TempLine);
	    TempLine += "\n";
	    Lines += TempLine;
	}
	return Lines;
    }
    else
    {
	return "ERROR File does not exist.";
    }
}
void intro()
{
    std::cout<<"\n\n";
	std::ifstream Reader ("Logo.txt");
	std::string Art = getFileContents (Reader);
	std::cout << Art << std::endl;
	Reader.close ();
	cout<<"\tMADE BY : BHARAT PATIDAR \n";
}
int main()
{
	char ch;
	do
	{
        system("CLS");
    	intro();
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. ADMINISTRATOR MENU";
		cout<<"\n\n\t02. STUDENT MENU";
	  	cout<<"\n\n\t03. EXIT";
	  	cout<<"\n\n\tPlease Select Your Option (1-3) : ";
	  	ch=getche();
	  	switch(ch)
	  	{
			case '1': admin_menu();
                      break;
		  	case '2':student_menu();
			    	 break;
		  	case '3':exit(0);
		  	default :cout<<"\a";
		}
       }while(ch!='3');
    	return 0;
}
