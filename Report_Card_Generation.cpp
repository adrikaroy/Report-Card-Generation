// Project title Report Card Generation System
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>

// CLASS ITEM STORING THE STUDENT INFORMATION
class Student
{
   int admn;
   char sname[21];
   char cla[4];
   char sec;
   char fname[21];
   char dob[9];
   public:
     void input(int i);
     void display_one(void);
     void  display_all(void);
     int get_admn(void) { return admn; }
     char *get_sname(){return sname;}
     char *get_cla(){return cla;}
     char get_sec(){return sec;}
     char *get_fname(){return fname; }
     char *get_dob(){return dob; }
     void modify(void);
};

void Student::input(int i)
{
     admn=i;
     cout << "\nEnter name of student : "; gets(sname);
     cout << "\nEnter Class (XI/ XII) : "; gets(cla);
     cout << "\nEnter Section (A or B) : "; cin >> sec;
     cout << "\nEnter father's name : "; gets(fname);
     cout << "\nEnter date of birth(dd-mm-yy) : "; gets(dob);
}

void Student::display_one(void)
{
     cout << "\nAdmission No. : "<< admn;
     cout << "\nStudent Name : "<< sname;
     cout << "\nClass & Sec  : "<< cla<< "-"<<sec;
     cout << "\nFather's Name : " <<fname;
     cout << "\nDate of Birth : "<<dob;
}


void Student::display_all(void)
{
  cout <<"\n"<<admn<<"\t"<< sname << "\t" << cla <<"-" << sec<< "\t"<<dob<< "\t"<<fname;
}

void Student::modify(void)
{
   char op='y';
   int ch;
   while(op=='y' || op=='Y') {
      cout << "\n\nModification Item";
      cout << "\n1. Change name";
      cout << "\n2. Change class";
      cout << "\n3. Change section";
      cout << "\n4. Change fname";
      cout << "\n5. Change date of birth";
      cout << "\nEnter your option ? (1-5) ";
      cin >> ch;
      switch(ch)
      {
	 case 1: cout << "\nOld name : " << sname;
		 cout << "\nEnter the new name : "; gets(sname);
		 break;
	 case 2: cout << "\nOld Class : " << cla;
		 cout << "\nEnter new class (XI/ XII) : "; gets(cla);
		 break;
	 case 3: cout << "\nOld Section : " << sec;
		 cout << "\nEnter new section (A or B) : "; cin >> sec;
		 break;
	 case 4: cout << "\nOld Father's Name : " << fname;
		 cout << "\nEnter new father's name (A/ B) : "; gets(fname);
		 break;
	 case 5: cout << "\nOld date of birth : " << dob;
		 cout << "\nEnter new date of birth (dd-mm-yy) : "; gets(dob);
		 break;
      }
      cout << "\nDo you want to change any other information ? (y/n) : ";
      cin >> op;
   }
}

// Details of Marks
class Marks
{
   int admn;
   char tname[4];
   int m1,m2,m3,m4,m5;
   public:
      Marks() { m1=0;m2=0;m3=0;m4=0;m5=0; }
      void input(int c,char tname1[]);
      void display_one(char tname1[]);
      void display_all(char tname1[]);
      int get_admn(void) { return admn; }
      char *get_tname(void) { return tname; }
      int get_m1() {return m1;}
      int get_m2() {return m2;}
      int get_m3() {return m3;}
      int get_m4() {return m4;}
      int get_m5() {return m5;}
      void modify(void);
};

void Marks::input(int c,char tname1[])
{
	cout << "\nEnter the following marks:-\n";
	cout << "\nEnter marks of English "; cin >> m1;
	cout << "\nEnter marks of Maths "; cin >> m2;
	cout << "\nEnter marks of Physics "; cin >> m3;
	cout << "\nEnter marks of Chemistry "; cin >> m4;
	cout << "\nEnter marks of Computer Sc or Biology "; cin >> m5;
	admn=c;
	strcpy(tname,tname1);
}

void Marks::display_one(char tname1[])
{
   cout << "\nAdmission No. : "<< admn;
   cout << "\nName of Test : "<< tname1;
   cout << "\nMarks :-\n";
   cout << "\nEnglish : " << m1<< "\nMaths : " << m2;
   cout << "\nPhysics : " << m3<< "\nChemistry : " << m4;
   cout << "\nBiology/ Computer Sc : " << m5;
}

void Marks::display_all(char tname1[])
{
     cout << endl<< admn << "\t" << tname1 << "\t"<<m1 << "\t"<< m2<< "\t"<< m3 << "\t"<<m4 << "\t" << m5;
}

void Marks::modify(void)
{
   char op='y';
   int ch;
   while(op=='y' || op=='Y') {
     cout << "\n\nModification Item";
     cout << "\n1. English Mark";
     cout << "\n2. Maths Mark ";
     cout << "\n3. Physics Mark";
     cout << "\n4. Chemistry Mark ";
     cout << "\n5. Bio/ CS Mark";
     cout << "\nEnter your option ? (1-5) ";
     cin >> ch;
     switch(ch)
     {
	case 1: cout << "\nOld English Mark  : " << m1;
		cout << "\nEnter new English Mark : "; cin >> m1;
		break;
	case 2: cout << "\nOld Maths Mark  : " << m2;
		cout << "\nEnter new Maths Mark : "; cin >> m2;
		break;
	case 3: cout << "\nOld Physics Mark  : " << m3;
		cout << "\nEnter new Physics Mark : "; cin >> m3;
		break;
	case 4: cout << "\nOld Chemistry Mark  : " << m4;
		cout << "\nEnter new Chemistry Mark : "; cin >> m4;
		break;
	case 5: cout << "\nOld Bio or CS Mark  : " << m5;
		cout << "\nEnter new Bio or CS Mark : "; cin >> m5;
		break;
      }
      cout << "\nDo you want to change any other information ? (y/n) : ";
      cin >> op;
   }
}

void main()
{
  clrscr();
  int op,flag,choice,c,admn1;long pos; Student S; Marks M; char pass[8],ch='Y',tname1[4];
  ifstream f3,fin,f1;
  ofstream f2,fout;
  fstream f;
  void entry_screen(void);
  void validity(void);
  entry_screen();
  validity();
  cout << "\nREPORT CARD GENERATION SYSTEM\n";
  while(ch=='Y' || ch=='y') {
     clrscr();
     gotoxy(37,2);cout << "MAIN MENU";
     gotoxy(11,4);cout << "1. Entry of new student information";
     gotoxy(11,6);cout << "2. Modification of student information";
     gotoxy(11,8);cout << "3. Deletion of student information";
     gotoxy(11,10);cout << "4. Entry of marks for specific test";
     gotoxy(11,12);cout << "5. Modification of marks of specific test";
     gotoxy(11,14);cout << "6. Removal of mark details of student";
     gotoxy(11,16);cout << "7. Display of details of specific student";
     gotoxy(11,18);cout << "8. Display of details of all students";
     gotoxy(11,20);cout << "9. Display of marks details of specific student in specific test";
     gotoxy(11,22);cout << "10. Display of marks details of all students in specific test";
     gotoxy(11,24);cout << "11. Generation of report card ";
     gotoxy(11,26);cout << "12. Display student list failed in specific subject";
     gotoxy(11,28);cout << "13. Exit.........";
     gotoxy(25,30);cout << "Enter your option : "; cin >> op;
     switch(op)
     {
       case 1: clrscr();
	       flag=1;
	       fin.open("s.dat",ios::binary | ios::in);
	       cout << "\nEnter the admission no. :";
	       cin >> admn1;
	       if(fin) {
		  while(!fin.eof()) {
		    fin.read((char *)&S,sizeof(S));
		    if(fin.eof()) break;
		    if(admn1==S.get_admn()){
		       cout << "\nAlready exist ........";
		       flag=0;
		       break;
		    }
		  }
		  fin.close();
		}
		if(flag!=0) {
		    fout.open("s.dat",ios::binary | ios::app);
		    S.input(admn1);
		    fout.write((char *)&S,sizeof(S));
		    fout.close();
		}
		break;
       case 2:  clrscr();
		f.open("s.dat",ios::binary | ios::in | ios::out);
		cout << "\nEnter admisison no. whose data to be changed : ";
		cin >> admn1;
		while(1) {
		 pos=f.tellg();
		 f.read((char *)&S,sizeof(S));
		 if(f.eof()) break;
		 if(S.get_admn()==admn1) {
		   clrscr();
		   S.display_one();
		   S.modify();
		   f.seekp(pos);
		   f.write((char *)&S,sizeof(S));
		   flag=1;
		 }
	       }
	       if(flag==0) cout << "Invalid admisison no...........";
	       f.close();
	       break;
       case 3: clrscr();
	       ch='n';
	       cout<< "\nEnter the admission no. to be removed : "; cin >> admn1;
	       f1.open("s.dat",ios::binary | ios::in);
	       f2.open("temp.dat",ios::binary | ios::out);
	       while(1) {
		 flag=0;
		 f1.read((char *)&S,sizeof(S));
		 if(f1.eof()) break;
		 if(S.get_admn()==admn1) {
		     clrscr();
		     S.display_one();
		     cout << "\n\nAre you sure? (Y/N) : ";
		     cin >> ch;
		     if(ch=='Y' || ch=='y') flag=1;
		 }
		 if(flag==0) f2.write((char *)&S,sizeof(S));
	       }
	       f1.close(); f2.close();
	       remove("s.dat");
	       rename("temp.dat","s.dat");
	       break;
      case 4:  clrscr();
	       fin.open("m.dat",ios::binary | ios::in);
	       flag=1;
	       cout << "\nEnter the admisision no. : ";
	       cin >> admn1;
	       cout << "\nEnter the test name (UT1/ UT2/ HY/ AN) :" ; gets(tname1);
	       if(fin) {
		 while(!fin.eof()) {
		   fin.read((char *)&M,sizeof(M));
		   if(fin.eof()) break;
		   if(admn1==M.get_admn() && strcmpi(tname1,M.get_tname())==0) {
		      flag=0;
		      cout << "\nAlready exist......";
		      break;
		   }
		 }
		 fin.close();
	       }
	       if(flag!=0) {
		  fout.open("m.dat",ios::binary | ios::app);
		  M.input(admn1,tname1);
		  fout.write((char *)&M,sizeof(M));
		  fout.close();
	       }
	       break;
       case 5: clrscr();
	       f.open("m.dat",ios::binary | ios::in | ios::out);
	       cout << "\nEnter Admission No. whose marks to be changed : ";
	       cin >> admn1;
	       cout << "\nEnter Test Name (UT1/ UT2/ HY/ An) : "; gets(tname1);
	       while(1) {
		 pos=f.tellg();
		 f.read((char *)&M,sizeof(M));
		 if(f.eof()) break;
		 if(admn1==M.get_admn() && strcmpi(tname1,M.get_tname())==0) {
		   clrscr();
		   M.display_one(tname1);
		   M.modify();
		   f.seekp(pos);
		   f.write((char *)&M,sizeof(M));
		   flag=1;
		 }
	       }
	       if(flag==0) cout << "Invalid Admission No or Test Name...........";
	       f.close();
	       break;
       case 6: clrscr();
	       ch='n';
	       cout << "\nEnter the Admission No. whose record to be removed : "; cin >> admn1;
	       cout << "\nEnter Test Name (UT1/ UT2/ HY/ An) : "; gets(tname1);
	       f1.open("m.dat",ios::binary | ios::in);
	       f2.open("temp.dat",ios::binary | ios::out);
	       while(1) {
		 flag=0;
		 f1.read((char *)&M,sizeof(M));
		 if(f1.eof()) break;
		 if(admn1==M.get_admn() && strcmpi(tname1,M.get_tname())==0) {
		    clrscr();
		    M.display_one(tname1);
		    cout << "\n\nAre you sure to remove ? (Y/N) : ";
		    cin >> ch;
		    if(ch=='Y' || ch=='y') flag=1;
		  }
		  if(flag==0) f2.write((char *)&M,sizeof(M));
	       }
	       f1.close(); f2.close();
	       remove("m.dat");
	       rename("temp.dat","m.dat");
	       break;
       case 7: clrscr();
	       flag=0;
	       fin.open("s.dat",ios::binary | ios::in);
	       cout << "\nEnter admission no. whose details to be displayed : ";
	       cin >> admn1;
	       while(1) {
		 fin.read((char *)&S,sizeof(S));
		 if(fin.eof()) break;
		 if(S.get_admn()==admn1) {
		    clrscr();
		    cout << "Student Details\n";
		    S.display_one();
		    flag=1;
		    break;
		 }
	       }
	       if(flag==0) cout << "\nInvalid Admission No........";
	       fin.close();
	       break;
       case 8: clrscr();
	       fin.open("s.dat",ios::binary | ios::in);
	       cout << "All Students details\n";
	       cout << "\n"<< "ADMN" << "\t"<< "SNAME" << "\t\t" << "CLASS" <<"-" << "SEC"<< "\t"<<"Date of Birth"<< "\t"<<"FNAME";
	       while(1) {
		 fin.read((char *)&S,sizeof(S));
		 if(fin.eof()) break;
		 S.display_all();
	       }
	       fin.close();
	       break;
       case 9: clrscr();
	       flag=0;
	       f1.open("m.dat",ios::binary | ios::in);
	       cout << "\nEnter Admisison No. whose details to be displayed : ";
	       cin >> admn1;
	       cout << "\nEnter Test Name (UT1/ UT2/ HY/ AN) "; gets(tname1);
	       while(1) {
		 f1.read((char *)&M,sizeof(M));
		 if(f1.eof()) break;
		 if(admn1==M.get_admn() && strcmpi(tname1,M.get_tname())==0) {
		    clrscr();
		    cout << "Marks Details of specific student\n";
		    M.display_one(tname1);
		    flag=1;
		    break;
		 }
	       }
	       if(flag==0) cout << "\nInvalid Admission No. or Test Name....";
	       f1.close();
	       break;
      case 10: clrscr();
	       f1.open("m.dat",ios::binary | ios::in);
	       cout << "\nEnter Test Name (UT1/ UT2/ HY/ AN) "; gets(tname1);
	       cout << "All Student's details of "<<tname1<< ":-\n";
	       cout << "ADMN" << "\t"<< "TNAME"<<"\t"<< "ENG"<< "\t"<< "MATHS" << "\t"<< "PHYS" << "\t" << "CHEM"<< "\t" << "BIO/ CS\n";
	       while(1) {
		 f1.read((char *)&M,sizeof(M));
		 if(f1.eof()) break;
		 if(strcmpi(M.get_tname(),tname1)==0)
		    M.display_all(tname1);
	       }
	       f1.close();
	       break;
      case 11: clrscr();
	       float t1=0,t2=0,t3=0,t4=0,t5=0;
	       cout << "\nEnter admission no. : "; cin >> admn1;
	       f1.open("s.dat",ios::binary | ios::in);
	       while(1) {
		  flag=1;
		  f1.read((char *)&S,sizeof(S));
		  if(f1.eof()) break;
		  if(S.get_admn()==admn1) {
		      flag=0;
		      clrscr();
		      f3.open("m.dat",ios::binary|ios::in);
		      gotoxy(1,3);cout << "D.A.V. PUBLIC SCHOOL";
		      gotoxy(1,4);cout << "Duckbunglow Road, Midnapore";
		      gotoxy(1,5);cout << "--------------------------------------------------------\n";
		      gotoxy(1,7);cout << "Admission No.: "<< admn1 ;
		      gotoxy(1,8);
		      cout << "Name : " << S.get_sname() << "\t\tFather's Name : "<<S.get_fname();
		      gotoxy(1,9);cout << "Class & Sec: " << S.get_cla() <<"-" << S.get_sec();
		      gotoxy(1,10);cout << "Date of Birth : " << S.get_dob();
		      gotoxy(1,11);cout << "========================================================";
		      break;
		  }
		  if(flag==1) cout << "\nInvalid admission no.......";
	       }
	       gotoxy(1,13);cout << "\nMarks Details:-\n";
	       gotoxy(1,15);cout << "Test\tEng\tMaths\tPhys\tChem\tSub-5\n";
	       while(1)
	       {
		   f3.read((char *)&M,sizeof(M));
		   if(f3.eof()) break;
		   if(M.get_admn()==admn1) {
		       cout << "\n|"<<M.get_tname()<<"\t|"<<M.get_m1()<<"\t|"<<M.get_m2()<<"\t|"<<M.get_m3()<<"\t|"<<M.get_m4()<<"\t|"<<M.get_m5()<<"\t|";
		       if(strcmpi(M.get_tname(),"UT1")==0 || strcmpi(M.get_tname(),"UT2")==0) {
			  t1=t1+0.10*M.get_m1(); t2=t2+0.10*M.get_m2();
			  t3=t3+0.10*M.get_m3(); t4=t4+0.10*M.get_m4();
			  t5=t5+0.10*M.get_m5();
		       }
		       if(strcmpi(M.get_tname(),"HY")==0) {
			  t1=t1+0.20*M.get_m1(); t2=t2+0.20*M.get_m2();
			  t3=t3+0.20*M.get_m3(); t4=t4+0.20*M.get_m4();
			  t5=t5+0.20*M.get_m5();
		       }
		       if(strcmpi(M.get_tname(),"AN")==0) {
			  t1=t1+0.60*M.get_m1(); t2=t2+0.60*M.get_m2();
			  t3=t3+0.60*M.get_m3(); t4=t4+0.60*M.get_m4();
			  t5=t5+0.60*M.get_m5();
		       }
		    }
	       }
	       if(t1>=33 && t2>=33 && t3>=33 && t3>=33 && t5>=33)
		   cout << "\n\nQualified........";
	       else
		   cout << "\n\nNot qualified.........";
	       f1.close();
	       f3.close();
	       break;
     case 12:  clrscr();
	       char sub[6];
	       f1.open("m.dat",ios::binary | ios::in);
	       cout << "\nEnter the subject(ENG/ MATHS/ PHYS/ CHEM/ SUB5 : "; gets(sub);
	       cout << "\nAdmisison No. of students failed in "<<sub<< "\n";
	       if(strcmpi(sub,"ENG")==0)
               {
                  while(1) {
		     f1.read((char *)&M,sizeof(M));
		     if(f1.eof()) break;
                     if(M.get_m1()<13) 
		        cout << M.get_admn();
	          }
	          f1.close();
               }
               if(strcmpi(sub,"MATHS")==0)
               {
                  while(1) {
		     f1.read((char *)&M,sizeof(M));
		     if(f1.eof()) break;
                     if(M.get_m2()<13) 
		        cout << M.get_admn();
	          }
	          f1.close();
               }
               if(strcmpi(sub,"PHYS")==0)
               {
                  while(1) {
		     f1.read((char *)&M,sizeof(M));
		     if(f1.eof()) break;
                     if(M.get_m3()<13) 
		        cout << M.get_admn();
	          }
	          f1.close();
               }
               if(strcmpi(sub,"CHEM")==0)
               {
                  while(1) {
		     f1.read((char *)&M,sizeof(M));
		     if(f1.eof()) break;
                     if(M.get_m4()<13) 
		        cout << M.get_admn();
	          }
	          f1.close();
               }
               if(strcmpi(sub,"SUB5")==0)
               {
                  while(1) {
		     f1.read((char *)&M,sizeof(M));
		     if(f1.eof()) break;
                     if(M.get_m5()<13) 
		        cout << M.get_admn();
	          }
	          f1.close();
               }
	       break;            
     case 13:  clrscr();gotoxy(30,11);cout << "Thank you for using me!!!!!";
	       getch();exit(1);
    }
    cout << "\n\n\n\nDo you want to continue (Y/N) ? ";
    cin >> ch; clrscr();
  }
}

void entry_screen(void)
{
   int i;
   gotoxy(25,13);for(i=1;i<=20;i++) cout << "*-";
   gotoxy(32,15);cout << "REPORT CARD GENERATION SYSTEM\n";
   gotoxy(31,17);cout << "Designed by Adrika Roy \n";
   gotoxy(38,19);cout << "Session 2016-20\n";
   gotoxy(25,21);for(i=1;i<=20;i++) cout << "*-";
   getch();
   clrscr();
}

void validity(void)
{
   char pass1[7],a;int i;
   gotoxy(25,10);for(i=1;i<=20;i++) cout << "*-";
   gotoxy(32,11);cout << "CHECK FOR AUTHENTICATION";
   gotoxy(32,12);cout << "Userid : admn";
   gotoxy(25,14);for(i=1;i<=20;i++) cout << "*-";
   gotoxy(32,13);cout << "Enter your password:";
   for(i=0;i<6;i++) {
    a=getch();
    pass1[i]=a;
   }
   pass1[i]='\0';
   if(strcmp(pass1,"janina") !=0) {
    gotoxy(37,17);cout << "\n\nSorry incorrect password......";
    getch();
    exit(1);
   }
   clrscr();
}
