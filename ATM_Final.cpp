#include<fstream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>

void printintromenu();
void printmainmenu();
void start();
void login();
void createaccount();
void mainfunc();

char menuinput;
int flag=0,pos=0;
float amt=0;

class user
{
	public:
	char username[80];
	char password[80];
	float balance;
	user()
	{
		strcpy(username,"NoName");
		strcpy(password,"NoPass");
		balance=0;
	}
}mainuser;

void main()
{
	clrscr();
	cout<<"Welcome to the Augmented Money Transfer Interface"<<endl;
	getch();
	start();
	getch();
}

void printintromenu()
{
	clrscr();
	cout<<"Please select an option from the menu below:"<<endl<<endl<<"L-> Login"<<endl<<"C-> Create account"<<endl<<"Q-> Quit"<<endl;
}

void printmainmenu()
{

	clrscr();
	cout<<"Please select an option from the menu below:"<<endl<<endl<<"D-> Deposit Money"<<endl<<"W-> Withdraw money"<<endl<<"R-> Request balance"<<endl<<"Q-> Quit to main menu"<<endl;
}

void start()
{
	clrscr();
	printintromenu();
	cin>>menuinput;
	switch(menuinput)
	{
		case ('L'):
		{	login();
			mainfunc();
			break;
		}
		case ('C'):
		{	createaccount();
			login();
			mainfunc();
			break;
		}
		case ('Q'): exit(0);
		default: exit(0);
	}
}

void createaccount()
{
	clrscr();
	ofstream fout("userdata.txt",ios::app|ios::binary);
	ifstream fin("userdata.txt",ios::in|ios::binary);
	user user1,user2;
	user_input:
	flag=0;
	cout<<endl<<"Enter username: ";
	gets(user1.username);
	while(!fin.eof())
	{
		fin.read((char*)&user2,sizeof(user2));
		if(!strcmp(user2.username,user1.username))
		{
			cout<<"Username is already taken! Please enter another username: ";
			flag=1;
			break;
		}
	}
	if(flag)
		goto user_input;
	else
	{	cout<<endl<<"Enter password: ";
		gets(user1.password);
		fout.write((char*)&user1,sizeof(user1));
	}
	fout.close();
	fin.close();
	cout<<"Your account has been created!"<<endl;
	getch();
}

void login()
{
	clrscr();
	flag=0;
	ofstream fout("userdata.txt",ios::app|ios::binary);
	ifstream fin("userdata.txt",ios::in|ios::binary);
	user user1,user2;
	cout<<"Enter your username: "<<endl;
	gets(user1.username);
	fin.seekg(0);
	while(!fin.eof())
	{
		fin.read((char*)&user2,sizeof(user2));
		if(!strcmp(user2.username,user1.username))
		{
			flag=1;
			pos=fin.tellg();
			break;
		}
	}
	if(!flag)
	{	cout<<"Sorry! Your username does not exist on our record! You will now be redirected to the signup page."<<endl;
		getch();
		fin.close();
		fout.close();
		start();
	}
	else
	{
		for(int i=0;i<=5;i++)
		{
			if(i==5)
			{
				clrscr();
				cout<<endl<<"Limit of incorrect attempts exceeded! You will now be locked out of the program";
				getch();
				exit(0);
			}
			password:
			cout<<"Enter Password: ";
			gets(user1.password);
			fin.seekg(pos-(sizeof(user2)));
			if(!strcmp(user1.password,user2.password))
			{	mainuser=user1;
				cout<<"ACCESS GRANTED!"<<endl;
				getch();
				fin.close();
				fout.close();
				break;
			}
			else
			{
				cout<<endl<<"Incorrect password! Please enter correct password";
			}
		}
	}
}

void mainfunc()
{
	while(1)
	{
		clrscr();
		printmainmenu();
		cin>>menuinput;
		switch(menuinput)
		{
			case 'D':
			{
				cout<<endl<<"Enter amount to be deposited: ";
				cin>>amt;
				mainuser.balance+=amt;
				cout<<endl<<"$"<<amt<<" has been deposited into your account";
				getch();
				break;
			}
			case 'W':
			{
				cout<<endl<<"Enter amount to be withdrawn: ";
				cin>>amt;
				if(amt<=mainuser.balance)
				{	mainuser.balance-=amt;
					cout<<endl<<"$"<<amt<<" has been withdrawn from your account";
					getch();
				}
				else
				{	clrscr();
					cout<<endl<<"Insufficient bank balance";
					getch();
				 }
				 break;
			}
			case 'R':
			{
				cout<<endl<<"Your current bank balance: $"<<mainuser.balance;
				getch();
				break;
			}
			case 'Q':
			{
				user tempuser;
				ifstream fin("userdata.txt",ios::in|ios::binary);
				ofstream fout("temp.txt)",ios::app|ios::binary);
				while(!fin.eof())
				{
					fin.	read((char*)&tempuser,sizeof(tempuser));
					if(tempuser.username==mainuser.username)
						fout.write((char*)&mainuser,sizeof(mainuser));
					else
						fout.write((char*)&tempuser,sizeof(tempuser));
				}
				fout.close();
				fin.close();
				start();
				break;
			}
		}
	}
}









