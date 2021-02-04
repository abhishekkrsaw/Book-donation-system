#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include<windows.h>
using namespace std;
class bookdata
{
	string name,aut;
	public:
		void head()
		{   
		    system("cls");
			cout<<setfill('*');
	        cout<<"\n\n\t"<<setw(60)<<" Library Management System ";
	        cout<<setw(40)<<'*'<<"\n\n";
		}
		void write()
		{
			cout<<"\t Enter the name of the book : ";
			cin>>name;
			cout<<"\n\t Enter author's name        : ";
			cin>>aut;
		}
		void add()
		{
			char a;
			ofstream data("data.txt",ios::app);
			write();
			data<<"\t "<<name<<"\t\t "<<aut<<endl;
			data.close();
			cout<<"\n\n\t Your book is added successfully\n";
			Beep(500,1600);
			head();
		}
		void display()
		{
			char c;
			ifstream read("data.txt");
			cout<<"\tBook Name ";
			cout<<"\tAuthor's Name\n\n";
			while(read)
			{
				read.get(c);
				cout<<c;
			}
			cout<<"\n\n";
			
		}
		void search()
		{
			int count=0;
			char p[60];
			string s,t;
			cout<<"\t Enter the book name you want to search : ";
			cin>>s;
			fstream search("data.txt",ios::in);
			search.seekg(0,ios::beg);
			while(search)
			{
				search>>t;
				if(t==s)
				{
					count++;
					break;
				}
			}
			if(count==0)
			{
				cout<<"\n\t No such book is there with this name. Try Again! \n\n\n";
				Beep(10,2000);
			}
			else
			{
			cout<<"\n\t Book Name ";
			cout<<"\t Author's Name\n\n";
			cout<<"\t "<<s;
			search.getline(p,30);
			cout<<p<<"\n\n";
			Beep(10,2000);
		    }
		}
		void del()
		{
			int count=0,p=-1;
			string s,t,u;
			cout<<"\t Enter the book name you want to delete : ";
			cin>>s;
			ofstream file("file.txt");
			fstream dele("data.txt",ios::in);
			dele.seekg(0,ios::beg);
			while(dele)
			{
				dele>>t;
				count++;
				if(t==s)
				{		
				    p=count;			
					continue;
				}
				
				if(count!=p+1 && u!=t)
				{
				file<<"\t"<<t<<"\t";
			    }
				if(count%2==0 && count!=p+1)
				{
					file<<"\n";
				}
				u=t;
			}
			file.close();
			dele.close();
			remove("data.txt");
			rename("file.txt","data.txt");
				
		}
};
int main()
{
	int n;
	string pass,user;
	bookdata b;
	cout<<setfill('*');
	cout<<"\n\n\t"<<setw(60)<<" Library Management System ";
	cout<<setw(40)<<'*'<<"\n\n";
	cout<<"\t Enter Username: ";
	cin>>user;
	cout<<"\n\t Enter password: ";
	cin>>pass;
	if(pass=="aks")
	{
		b.head();
	cout<<"\t\t\t\t\t\t    Welcome "<<user<<"! \n";
	cout<<"\t\t\t\t\t\t   ``````````````````` \n\n";
	while(1)
	{
	cout<<"\t Choose the option from the list :-\n\n";
	cout<<"\t 1. Add Book \n";
	cout<<"\t 2. Display Books \n";
	cout<<"\t 3. Search Book \n";
	cout<<"\t 4. Delete Book \n";
	cout<<"\t 5. Exit \n\n";
	cout<<"\t Enter your option: ";
	cin>>n;
	
    switch(n)
    {
    	case 1:
    		b.head();
    		b.add();
    		break;
    	case 2:
    		b.head();
    		b.display();
    		break;
    	case 3:
    		b.head();
    		b.search();
    		break;
    	case 4:
    		b.head();
    		b.del();
    		break;
    	case 5:
		    b.head();
			exit(0);
			 break;
		default:
		    b.head();
			Beep(800,800);		
    }
	}
    }
	else
	{
		cout<<"\n\t Sorry! your password is incorrect";
	}
}
