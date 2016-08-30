#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<fstream.h>
#include<iomanip.h>
#include<ctype.h>
#include<stdio.h>
#include<process.h>
#include<string.h>

char name[10];
char genre[10][20];
int nosh=0,first=0,x=0,e=0;
class lib
{	int shelf;
	char lend[5],name[40],author[20],genre[20],code[10];
	public:
	char *rcode(){return code;}
	char *rname(){return name;}
	char *rauthor(){return author;}
	int rshelf(){return shelf;}
	int avail(int r)
	{	if(r==1)
		{if(strcmp(lend,"YES")==0)
		 {strcpy(lend,"NO");
		 return 1;}
		 else
		 {return 0;}
		}
		else
		{if(strcmp(lend,"NO")==0)
		{strcpy(lend,"YES");
		 return 1;}
		else
		{return 0;}
		}
	}
	void input()
	{	cout<<"name(.)=";
		gets(name);
		cout<<"author(.)=";
		gets(author);
		cout<<"code(.)=";
		gets(code);
		if(first!=0)
		{cout<<"genre=";
		gets(genre);
		getshelf();
		cout<<"shelf="<<shelf;
		}
		strcpy(lend,"YES");
	}
	void output()
	{
		cout<<setw(10)<<code<<'|';
		cout<<setw(20)<<name<<'|'
		<<setw(20)<<author<<'|';
		getshelf();
		cout<<setw(8)<<shelf<<'|'<<lend<<'\n';

	}void getshelf();
	void modify();
	}l;
	void lib::getshelf()
	{     	for(int i=0;i<nosh;i++)
		{	if(strcmp(::genre[i],genre)==0)
			{shelf=i+1;
			}
		}if(strcmp(genre,".")==0)
		{shelf=-1;}
	}
void layout()
{	cout<<'\n'<<setw(11)<<"code"<<'|'
	    <<setw(20)<<"Title"<<'|'
	    <<setw(20)<<"Author"<<'|'
	    <<setw(8)<<"shelf no"<<'|'
	    <<"Available"<<'\n';
}
void lib::modify()
{	cout<<"\nEnter the new details=";
	char co[10],na[40],aut[20],gen[20];
	cout<<"\nBook code(to retain '.')=";
	gets(co);
	cout<<"Name(to retain '.')=";
	gets(na);
	cout<<"Author(to retain '.')=";
	gets(aut);
	cout<<"Genre(to retain '.')=";
	gets(genre);
	if(strcmp(co,"."))
	{strcpy(code,co);}
	if(strcmp(na,"."))
	{strcpy(name,na);}
	if(strcmp(aut,"."))
	{strcpy(author,aut);}
	if(strcmp(gen,"."))
	{strcpy(genre,gen);}

}
int check(char fe[])
{	if(strcmp(fe,"exit")==0)
	{e++; return 1;}
	else {return 0;}
}
void search(int w=0)
{       clrscr();
	int sh,choice,flag=0;  char ch;
	char co[10],na[40],aut[20],gen[20];   lib s;
	again:ifstream f1("library.dat",ios::binary);
	f1.seekg(0);
	cout<<"\t\tSearching"
	    <<"\n\t\t1.\tBy Name"
	    <<"\n\t\t2.\tBy Author"
	    <<"\n\t\t3.\tBy book Code";
	if(w==0)
	{cout<<"\n\t\t4.\tBy Genre" ;}
	cout<<"\n\n\tEnter option=";
	cin>>choice;
	cout<<"\t\t\t\t\t\tunknown data enter value in()\n"
	    <<"\t\t\t\t\t\tto exit search tpye 'exit'\n";
	wro:switch(choice)
	{	case 1:cout<<"\nEnter Name of book=";
		       gets(na);
		       if(check(na)==1)
		       {goto out;}
		       layout();
		       while(f1.read((char*)&l,sizeof(l)))
		       {if(strcmp(na,l.rname())==0)
			{ l.output();flag++;goto end;}
		       }
			break;
		case 3:cout<<"\nEnter Book Code=";
		       gets(co);
		       if(check(co)==1)
		       {goto out;}
		       layout();
		       while(f1.read((char*)&l,sizeof(l)))
			{if(strcmp(co,l.rcode())==0)
			{flag++;
			l.output(); goto end;}
			 }
		       break;
		case 2:cout<<"\nEnter Authorname=";
		       gets(aut);
		       if(check(aut)==1)
		       {goto out;}
		       layout();
		       while(f1.read((char*)&l,sizeof(l)))
			{if(strcmp(aut,l.rauthor())==0)
			{l.output();flag++;goto end;}
			}
		       break;
		case 4:if(w==0)
			{cout<<"Enter the genre type=";
			gets(gen);
			if(check(gen)==1)
			{goto out;}
			layout();
			for(int i=0;i<nosh;i++)
			{	if(strcmp(::genre[i],gen)==0)
				{sh=i+1;}
			}
			while(f1.read((char*)&l,sizeof(l)))
			{if(sh==l.rshelf())
			 {l.output();flag++;}
			}break;
			}
		default:cout<<"\nwrong choice";
			delay(1200);
			goto again;
	}
	if(flag==0)
	{ f1.close();
	cout<<"\n\t\tSorry\n\tTo try again Press any key.......\n";
	getch();clrscr();goto again;}
	end:cout<<"\nIs this the book(y/n)=";
	cin>>ch;
	if(ch!='y')
	{flag=0;goto wro;}
	out:      f1.close();
}
void all(int y=0)
{       int i,pos;
	lib l;
	char ch,user[10];
	switch(y)
	{	case 0:
		ifstream f1("library.dat",ios::binary);
		f1.seekg(0);
		again:clrscr();   i=0;
		layout();
		while(f1.read((char*)&l,sizeof(l)))
	{	if(strcmp(l.rname(),""))
		{l.output();
		i++;
		if(i==20)
		{cout<<"\nContinue Showing(y/n)=";
		 cin>>ch;
		 if(ch!='y')
		 {break;}
		 goto again;
	}	}
	}cout<<"\nPress any key....";
	getch();
	break;
	case 1:ifstream f8("user.dat");
	f8.seekg(0);
		con:clrscr();
		pos=0;
		cout<<"the members of this library=";
		while(!(f8.eof()))
		{    f8.getline(user,10);
			pos++;
			cout<<user<<'\n';
			if(pos==20)
			{	cout<<"Continue showing(y/n)=";
			cin>>ch;
			if(ch!='y')
			{break;}
			goto con;
			}
		}cout<<"\n\nPress any key...";
		getch();
		 f8.close();
		 break;
}       }

void rules()
{	clrscr();
	cout<<"\n\t\tWelcome to Lib 3.2.\n"
	    <<"\n1. The first time when you enter remember to give the details"
	    <<"   of the shelfs by going to library layout."
	    <<"\n2. Enter books available in the library by going to Enter Books"
	    <<"\n3. Enter name of members in Enter Member."
	    <<"\n4. The members can search, borrow and return"
	    <<"\n5. To modify books go to Modify"
	    <<"\n6. To delete members or books go to respective options.";
	cout<<"\n\nFor more details refer booklet."
	    <<"\nPress any key..";
	getch();

}
void Delete(int t)
{	char ch,us[10],user[10]; int flag=0;    lib s;
	clrscr();
	switch(t)
	{ case 1:de:search(1);
		if(e!=0)
		{break;} e=0;
		ifstream f1("library.dat",ios::binary);
		ofstream f2("tem.dat",ios::binary);
		while(f1.read((char*)&s,sizeof(s)))
		{	if(strcmp(s.rcode(),l.rcode())==0)
			{ cout<<"\nare you sure to delete this book=";
			  cin>>ch;
			  if(ch!='y')
			  {f2.write((char*)&s,sizeof(s));}
			  else{cout<<"\nDeleted"; }
			}
			else
			{f2.write((char*)&s,sizeof(s));}
		}
		f1.close();
		f2.close();
		remove("library.dat");
		rename("tem.dat","library.dat");
		cout<<"\nPress any key.....";
		getch();
		break;
	case 2:cout<<"enter member to be deleted=";
	       gets(us);
	       ifstream f3("user.dat");
	       ofstream f4("tem.dat");
	       while(!(f3.eof()))
	       {	f3.getline(user,10);
			if(strcmp(us,user)==0)
			{	cout<<"\nAre you sure to delete "<<user<<'\n';
				cin>>ch;
				if(ch!='y')
				{f4<<user<<'\n';}
				flag++;

			}
			else
			{f4<<user<<'\n';}
	       }
	       if(flag==0)
	       {cout<<"\nuser not found";
	       delay(1200);
	       break;}
	       f3.close();
	       f4.close();
	       remove("user.dat");
	       rename("tem.dat","user.dat");
	       all(1);
	       break;

	}

}

void liblay(int q=2)
{       char ch; int count=0;
	ifstream f1("library.dat",ios::binary);
	while(f1.read((char*)&l,sizeof(l)))
		count++;
	cout<<"\nNumber of books="<<count;
	f1.close();
	beg:count=0;
	ifstream f2("genre.dat");
	cout<<"\nAvailable Genre=\nShelf No";
	while(!(f2.eof()))
	{     f2.getline(genre[count],20);
	      count++;
		cout<<'\n'<<count<<".\t"<<genre[count-1];
	}f2.close();
	cout<<"\nNumber of shelf="<<--count;
	nosh=count;
	if(q!=0)
	{do
	{  cout<<"\nWant to make add or remove shelfs(y/n)=";
	   cin>>ch;
	   if(ch!='y')
	   {break;}
	   ofstream f3("genre.dat");
	   cout<<"\nNumber of Shelfs(max:10)=";
	   cin>>nosh;             x++;
	   cout<<"Enter genre=\n";
	   for(int i=0;(i<nosh)&&(i<10);i++)
	   {	cout<<"Shelf "<<i+1<<".=";
		gets(genre[i]);
		f3<<genre[i]<<'\n';
	   }
	   f3.close();
	   clrscr();
	   goto beg;
	}while(ch!='y');
	}  clrscr();

}
void modi()
{	int sr,pos;   char ch;  x++;  lib s; e=0;
	mod:clrscr();
	search(1);
	if(e==0)
	{
	fstream fio("library.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&s,sizeof(s)))
	{	pos=(fio.tellg()-sizeof(s));
		if(strcmp(s.rcode(),l.rcode())==0)
		{
		s.modify();
		fio.seekg(pos);
		fio.write((char*)&s,sizeof(s));
		ch='y';
		break;
	}	}
	fio.close();
	if(ch!='y')
	{cout<<"\nBook not found...\nWant to try again...\n";
	cin>>ch;
	if(ch=='y')
	{goto mod;} }
	else{cout<<"\nthe modified data=";
	layout();
	s.output();
	cout<<"\nPress any key...";
	getch();
}	}
}
void finish()
{	lib s; int i=1; x=0;
	clrscr();
	gotoxy(5,10);
	layout();
	ifstream f1("library.dat",ios::binary);
	ofstream f2("tem.dat",ios::binary);
	check:
	f1.seekg(0);
	while(f1.read((char*)&s,sizeof(s)))
	{s.output();if(s.rshelf()==i)
	 {f2.write((char*)&s,sizeof(s));}
	} f1.close();
	f2.close();
	if(i<=nosh)
	{i++;f1.open("library.dat",ios::binary);
	f2.open("tem.dat",ios::binary|ios::app);
	goto check;}
	remove("library.dat");
	rename("tem.dat","library.dat");
}
void admin()
{
	int choice,sr;	lib l;	char ch,user[10];
	start:clrscr();
	cout<<"\n\n\n\n\t\tWELCOME Admin"<<'\n';
	cout<<"\n\t\t1.\tLibrary layout\n"
	    <<"\t\t2.\tSearch\n"
		  <<"\t\t3.\tEnter new book\n"
		  <<"\t\t4.\tEnter new member\n"
		  <<"\t\t5.\tModify a book\n"
		  <<"\t\t6.\tDelete a book\n"
		  <<"\t\t7.\tDelete a member\n"
		  <<"\t\t8.\tInstructions\n"
		  <<"\t\t9.\tView all books\n"
		  <<"\t\t10.\tView all users\n"
		  <<"\t\t11.\tExit\n";
	cout<<"\n\tEnter your choice(1-11)=";
	cin>>choice;
	switch(choice)
	{       case 1:liblay();   break;
		case 2:search();
		break;
		case 4:ofstream f2("user.dat",ios::app);
			cout<<"\n\tNew member name=";
			gets(user);
			f2<<'\n'<<user;
			cout<<"Member "<<user<<" included";
			delay(1200);
			f2.close();
			break;
		case 5:modi(); break;
		case 6:Delete(1); break;
		case 7:Delete(2); break;
		case 11:if(x!=0){finish();}
			goto out;
		case 3: cout<<"\n\t\tNew Books\n";
			ofstream f1("library.dat",ios::binary|ios::app);
			do{first++;    x++;
			l.input();
			f1.write((char*)&l,sizeof(l));
			cout<<"\n\tWant to enter more=";
			cin>>ch;
			}while(ch=='y');
		first=0; f1.close(); break;
		case 8:rules();
			break;
		case 9:all();
			break;
		case 10:all(1);
			 break;
		default:cout<<"wrong choice..";delay(1200);
	}goto start; out:
}
void NEW()
{	rules();
	cout<<"\n\t\tWelcome  :Admin"
	    <<"\nPlease enter all these details=";
	ofstream f1("genre.dat");
	cout<<"\nNumber of shelfs(max:10)=";
	cin>>nosh;
	for(int i=0;i<nosh;i++)
	{ cout<<"shelf "<<i+1<<".enter genre=";
	  gets(genre[i]);
	  f1<<genre[i]<<'\n';
	}
	f1.close();
	char ch;    first++;
	ofstream f2("library.dat",ios::binary);
	do{
	   cout<<"\nenter details of book:\n";
	   l.input();
	   f2.write((char*)&l,sizeof(l));
	   cout<<"\nWant to enter more(y/n)=";
	   cin>>ch;
	}while(ch=='y');
	f2.close();
	cout<<"\nthe details of all the books entered=\n";
	delay(1200);
	first=0;
	all();
}
void borrow()
{	clrscr(); char ch;    lib s;  int pos;
	again:
	search(1);
	if(e==0)
	{
	cout<<"\nBorrowing...";
	fstream f2("library.dat",ios::binary|ios::in|ios::out);
	f2.seekg(0); pos=f2.tellg();
	while(f2.read((char*)&s,sizeof(lib)))
	{	if(strcmp(s.rcode(),l.rcode())==0)
		{ if(s.avail(1)==0)
		  {cout<<"\nSorry.\nBook not available.";delay(400);break;}
		   f2.seekg(pos);
		  f2.write((char*)&s,sizeof(s));
		  cout<<"\nSuccessful";
		  ofstream f1(name,ios::binary|ios::app);
		  f1.write((char*)&s,sizeof(s));
		  f1.close();
		  break;
		}pos=f2.tellg();
	}
	f2.close();
	cout<<"\nWant to borrow another book=";
	cin>>ch;
	if(ch=='y')
	{goto again;}}
}
void Return()
{	lib s;  char ch;   int pos=0,flag=0,i=0;
	again:clrscr();
	cout<<"\nBooks to return=";
	cout<<'\t';
	layout();
	ifstream f1(name,ios::binary);
	while(f1.read((char*)&l,sizeof(l)))
	{cout<<i<<". \t";
	 l.output();flag++;i++;}
	f1.close();
	if(flag==0)
	{cout<<"\nNo books to return\n";
	cout<<"Press any key..";
	getch();goto out;
	}
	else{flag=0;
	cout<<"\nEnter the no beside the book that is to be returned=";
	 cin>>i;
	 cout<<"\nreturning..";     delay(1000);
	 ifstream f2(name,ios::binary);
	 ofstream f3("tem.dat",ios::binary);
	 f2.seekg(i*sizeof(lib),ios::beg);
	 f2.read((char*)&l,sizeof(l));
	 f2.seekg(0);
	 while(f2.read((char*)&s,sizeof(s)))
	 {	if(strcmp(l.rcode(),s.rcode())==0)
		{ layout();
		  l.output(); flag++;
		}
		else
		{f3.write((char*)&s,sizeof(s));}
	 }
	 if(flag!=0)
	 {f2.close();
	 f3.close();
	 remove(name);
	 rename("tem.dat",name);
	 fstream f4("library.dat",ios::binary|ios::in|ios::out);
	 pos=f4.tellg();
	 while(f4.read((char*)&s,sizeof(lib)))
	 {	if(strcmp(s.rcode(),l.rcode()))
		{	s.avail(2);
			f4.seekg(pos);
			f4.write((char*)&s,sizeof(s));
			break;
		}  pos=f4.tellg();
	 }
	f4.close();     delay(300);
	cout<<"\nSuccessful\n";    delay(1000);
	}else{cout<<"not succesful";delay(1000);}}
	out:   flag=0;
}
void member()
{       got:clrscr();
	cout<<"\n\n\n\n\t\tWELCOME: "<<name<<'\n';
	int choice;
	cout<<"\t\t1.\tSearch for a book\n"
	    <<"\t\t2.\tBorrow a book\n"
	    <<"\t\t3.\tReturn a book\n"
	    <<"\t\t4.\tExit\n";
	    cout<<"\n\tEnter your choice(1-4)=";
	cin>>choice;
	switch(choice)
	{	case 1:search();goto got;
		case 2:borrow();goto got;
		case 3:Return();goto got;
		case 4:break;
		default:cout<<"Wrong choice...";
		delay(1200);
	}

}
void logo()
{      clrscr();
gotoxy(1,8);
cout<<"\n\t\t\t    /^\\ |_______| /^\\     " ;
delay(300);
cout<<"\n\t\t\t   //^\\\\   | |   //^\\\\    " ;
delay(300);
cout<<"\n\t\t\t  //___\\\\  | |  //___\\\\   "  ;
delay(300);
cout<<"\n\t\t\t //-----\\\\ | | //-----\\\\  "   ;
delay(300);
cout<<"\n\t\t\t//       \\\\| |//       \\\\ ";
delay(300);
char sen[30]={"TECHNOLOGIES"};
cout<<"\n\t\t\t ";
for(int k=0;sen[k]!='\0';k++)
{   cout<<sen[k]<<" ";
delay(100);}
delay(1000);
for(int i=0;i<5;i++)
{    gotoxy((24+i),(13-i));
for(int j=0;j<(30-2*i);j++)
{cout<<" ";
delay(20);}
}
delay(100);
clrscr();
}
void main()
{       char namec[10];
	int choice;
	start:clrscr();
	logo();
	cout<<"\n\n\n\n\n\n\t\tW E L C O M E  T O  L I B 3.2\n";
	ifstream f1("user.dat");
	if(f1)
	{	cout<<"\n\n\t\tNAME:";
		gets(name);
		while(!(f1.eof()))
		{f1.getline(namec,10);
			if(strcmp(name,namec)==0)
			{	goto got;
			}
		}
		if(check(name)==1)
		{exit(0);}
		else
		cout<<"wrong username.....";
		delay(1200);
		goto start;
	}
	else{ofstream f2("user.dat");
	cout<<"Creating a new Name:Admin";
	strcpy(name,"Admin");
	f2<<name;
	delay(1200);
	first++;
	f2.close();
	}
	got:clrscr();
	f1.close();
	if(strcmp(name,"Admin")==0)
	{	if(first!=0)
		{NEW();}
		liblay(0);
		admin();
		goto start;
	}
	liblay(0);
	member();
	goto start;

}
