#include<iostream>
#include<fstream>
#include<iomanip>
#include<string.h>

using namespace std;

class appointment
{    public : 
	char name_doc[20], name_patient[20],address[20];
	int height,weight,date,time,age,ph;
	 
	 void readapp()
	     { 
	     	cout<<"\nEnter your name please\t";
	     	cin>>name_patient;
	     	cout<<"\nEnter the name of your doctor\t";
	     	cin>>name_doc;
	     	cout<<"\nYour age : \t";
	     	cin>>age;
	     	cout<<"\nYour height : \t";
	     	cin>>height;
	     	cout<<"\nYour weight : \t";
	     	cin>>weight;
	     	cout<<"\nDate of appointment\t";
	     	cin>>date;
	     	cout<<"\nTime of appointment\t";
	     	cin>>time;
	     	cout<<"\nEnter your phone number\t";
	     	cin>>ph;
	     	cout<<"\nEnter your address\n";
	     	cin>>address;
	     }
	     
};

class diagnosis : virtual public appointment
{    public : 
	int ch,imp;
	char area[20];
	char problem[10],action[10],extra[10];
		    
	    void treat();
		void getreason();
		void prob();
};
		
		void diagnosis :: getreason()
		{
			cout<<"\nKindly have a look at the list of departments and enter the number of department your illness would come under\n";
			cout<<"\n1. ENT\n";
			
			cout<<"\n2. Dermatology\n";
			cout<<"\n3. Oncology\n";
			cout<<"\n4. Neurology\n";
			cout<<"\nEnter your choice\t";
			cin>>ch;
			switch(ch)
			{
				case 1 : strcpy(area,"ENT");
				         prob();
				         break;
				case 2 : strcpy(area,"Dermatology");
				         prob();
				         break;
				case 3 : strcpy(area,"Oncology");
				         prob();
				         break;
				case 4 : strcpy(area,"Neurology");
				         prob();
				         break;
				default : cout<<"\nInvalid option\n";
				    
			}
		}
		
		void diagnosis :: prob()
		{  
		    
			cout<<"\nWELCOME TO THIS DEPARTMENT\n";
			cout<<"\nEnter the area you require help in\n";
			cin>>problem;
			cout<<"\nEnter the severity of your illness on a scale of 1(mild) to 5(highly severe)\n";
			cin>>imp;
			     switch(imp)
			     {
			     	case 1 : cout<<"\nYour doctor \t"<<name_doc<<"\twill meet you in an hours time\n";
			     	         break;
			     	case 2 : cout<<"\nYour doctor \t"<<name_doc<<"\twill meet you in an hours time\n";
			     	         break;
			     	case 3 : cout<<"\nYour doctor \t"<<name_doc<<"\twill meet you in 30 minutes\n";
			     	         break;
			     	case 4 : cout<<"\nYour doctor \t"<<name_doc<<"\twill meet you in 15 minutes\n";
			     	         break;
			     	case 5 : cout<<"\nYour doctor \t"<<name_doc<<"\twill meet you immediately\n";
			     	         break;
			     	default : cout<<"\nInvalid entry\n";
			     }
			
		}
	
			
		
		

void diagnosis :: treat()
{
	switch(imp)
	{
		case 1 : strcpy(action,"CONSULTANCY");
		         strcpy(extra,"NILL");
		         cout<<"\n1. \t"<<action;
		         cout<<"\n2. \t"<<extra;
		         break;
		case 2 : strcpy(action,"CONSULTANCY");
		         strcpy(extra,"FURTHER SCANS");
		         cout<<"\n1. \t"<<action;
		         cout<<"\n2. \t"<<extra;
		         break;
		case 3 : strcpy(action,"SCANS");
		         strcpy(extra,"NILL");
		         
		         cout<<"\n1. \t"<<action;
		         cout<<"\n2. \t"<<extra;
		         break;
		case 4 : strcpy(action,"SCANS");
		         strcpy(extra,"SURGERY");
		         cout<<"\n1. \t"<<action;
		         cout<<"\n2. \t"<<extra;
		         break;
		case 5 : strcpy(action,"SURGERY");
		         strcpy(extra,"ADMITTED");
		         cout<<"\n1. \t"<<action;
		         cout<<"\n2. \t"<<extra;
		         break;
		default : cout<<"\nInvalid choice\n";
	}
	
}

class bills : virtual public diagnosis
{   public : 
	int amount;
	    void roomrent();
		void generate();
		

};

void bills :: generate()
{
	switch(imp)
	{
		case 1 : amount = 500;
		         
		         break;
		case 2 : amount = 1000;
		         
		         break;
		case 3 : amount = 2000;
		         
		         break;
		case 4 : amount = 4000;
		         
		         break;
		case 5 : amount = 50000;
		         
		         break;
		default : cout<<"\nInvalid choice\n";
		
	}
}



template<class T1, class T2>
class temp
{
	T1 a;
	T2 b;
	public :
		temp(T1 x, T2 y)
		{
			a=x;
			b=y;
		}
		void show()
		{
			cout<<"\n"<<a<<"\n"<<b;
		}
};
	
class report : virtual public appointment, virtual public diagnosis, virtual public bills
{
	public :
		
		void output()
		{
			
	     	cout<<"\n\n\nName\t"<<name_patient;
	     	cout<<"\nName of doctor\t"<<name_doc;
	     	cout<<"\nAge\t"<<age;
	     	cout<<"\nHeight\t"<<height;
	     	cout<<"\nWeight\t"<<weight;
	     	cout<<"\nDate of appointment\t"<<date;
	     	cout<<"\nTime of appointment\t"<<time;
	     	cout<<"\nPhone number\t"<<ph;
	     	cout<<"\nAddress\t";
	     	cout<<address<"\n";
	     	cout<<"\nYour department code is\t"<<ch;
	     	cout<<"\nYour department is \t"<<area;
	     	cout<<"\nYour require help in \t"<<problem;
	     	cout<<"\nThe severity of your illness is \t"<<imp;
	     	cout<<"\nThe following services were offered to you\n";
	     	cout<<"1.\t"<<action<<"\n2.\t"<<extra;
	     	cout<<"\nThe bill for the following services amounted to\t"<<amount;
	     	cout<<"\n\n\nTHANK YOU FOR CHOOSING GREY'S HOSPITAL\n";
	     	
	     	
		}
		
};

class taxes : virtual public diagnosis
{
	public:
		int tax;
		taxes()
		{
			
		}
		taxes(int g)
		{
			tax=g;
		}
		taxes operator+(taxes);
		void disp();
};

taxes taxes :: operator+(taxes ob)
{
	taxes obj;
	obj.tax=tax+ob.tax;
}

void taxes :: disp()
{
	cout<<"\nThe taxes are\t"<<tax;
}
	
		
int main()

{   int code;
    
    report r;

    
    cout<<"\nWELCOME TO GREY'S HOSPITAL.\n";
	cout<<"\nWhere every illness and ailments are resolved in moments.\n";
	cout<<"\n\nBecause we believe that your health is our primary concern\n\n";  
	appointment ap;
	
	diagnosis d;
	
	
	fstream file;
	file.open("project",ios :: in | ios :: out );
	 
	  cout<<"\nEnter your details now to get an appointment\n";
	  r.readapp();
	  
	  cout<<"\nEnter any one digit code ( DO NOT INCLUDE ZERO )\n";
	  cin>>code;
	  try
	  {
	  	if(code!=0)
	  	{
	  	  cout<<"\nVALID CODE\n";	
	  	}
	  	
	  	else
	  	{
	  		throw(code);
	  	}
	  	
	  	
	  }
	  
	  catch(int i)
	  {
	  	cout<<"\nEXCEPTION CAUGHT; CODE CANNOT BE ZERO\n";
	  	
	  }
	  
	  
	  
	  r.getreason();
	  r.prob();   
	 
	  r.treat();
	  
	  r.generate();
	  file.write((char*)& r,sizeof(r));
	  file.seekg(0);
	  file.read((char*)&r ,sizeof(r));
	  r.output();
	  
	  temp<char*,int>bog("\nThank you for choosing us\n",1);
	  bog.show();
	  file.close();
	  taxes object1(5000);
	  
	  if(r.imp>3)
	  {
	  	taxes object2(2000);
	  	taxes object3;
	  	object3=object1+object2;
	  	object3.disp();
	  }
	  else
	  {
	  	object1.disp();
	  }
	  return 0;
	  
}

