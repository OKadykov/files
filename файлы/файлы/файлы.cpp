// ���� 23.04.2012.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include<conio.h>
#include<stdio.h>
#include <fstream>
#include <assert.h>
using  namespace std;



struct link												//���� �������� ������
{
	 string data;										//������
	 link*next;											//��������� �� ��������� ���������
	 int id;
	
};

class linklist											//������
{
private:
	int num;
	link*first;
public:
	linklist()											//����������� ��� ����������	
	{first=NULL;}									//������� �������� ���� ���
	int n;
	void add(string d);								//���������� ��������
	void display(int n, int n1);						//����� ������
	void number(int p);
	void save();
	void addcenter(string d);
	void Showfromfirst();
	void load(linklist*name);
	void edit();
	void deletFROMcenter();
	void DelAll();
	void print();
};
void linklist::save(){
		link*current=first;
	ofstream outfile ("New List.dat", ios::binary);
	while(current){
		outfile<<"\n";
		outfile<<current->data<<"     ";
		
		current=current->next;
	}
}
   void linklist::load( linklist*name){
			ifstream fin;
			string str;
			string paststring="ololo";

			fin.open("New List.dat",ios::in);
			assert (!fin.fail( ));

		while (!fin.eof( )){
				fin >> str;
				if(str != paststring){
			name->add(str);
			paststring=str;
			}
		}
		fin.close( );
		//assert(!fin.fail( ));
	}
   
   
void linklist::deletFROMcenter(){
	/*   system("cls");
		int i=1;
		string value;
		link *current = first;
		link *newlink = new link;
	while(current==first){i++;current=current->next;}
	for(int j=0;j<(i/2+1);j++){current=current->next;}
	//delete first;*/
}
void linklist::edit(){
	   system("cls");
		int i=1;
		string value;
		link *current = first;
		while(current){i++;current=current->next;}
		first=NULL;
		current=NULL;
		for(int j=0;j<(i/2+1);j++) {current= current->next;}		
	cout<<"�������������� ��������\n"<<"������� �������";
	cin>>value;
	current->data=value;
	}
		

void linklist::DelAll()
{   while (first!= NULL){
	link *current=first;
    first=first->next;
    delete current;
    }
		first=NULL;
}



void linklist::add( string d)			//���������� �������
{		
	/*//���������� � ������ ������
	link*newlink= new link;				//�������� ������
	newlink->data=d;					//���������� ������
	newlink->next=first;				//���������� �������� first
	first=newlink;					//first ��������� �� ����� ������� 
	*/
	//���������� � ����� ������
		link *current = first;
		link *newlink = new link;
		if (first==NULL){//���� ������ ���������
			num=0;
			first=newlink;
			newlink->next=NULL;
			newlink->data=d;
			newlink->id=num;
			num++;
		}else{
			while (current->next!=NULL) {//���� �� ����������
				current=current->next;
			}
			current->next=newlink;//��������� ������ ��������� �� �����
			newlink->next=NULL;
			newlink->data=d;
			newlink->id=num;
			num++;
	}
	
}
int a=0; 
void linklist:: addcenter(string d){ //���������� � �����
		link*current=first;
		link*newlink= new link;
	//	link*temporary= new link;
		if(first == NULL)
		{
			num=0;
			newlink->data=d;
			newlink->id=num;
			newlink->next=NULL;
			first=newlink;
			num++;
		}
		else{
			int number_of_elements=0;
			while (current)
			{
				number_of_elements++;
				current=current->next;
			}
			current=first;
			int needed_el;
			if (number_of_elements%2==1){
				needed_el=number_of_elements/2;
			}
			else
			{
				needed_el=(number_of_elements-1)/2;
			}
			int shet=0;
			while(shet<needed_el+1)
			{
				if(shet == needed_el)
				{
					newlink->data=d;
					newlink->id=num;
					num++;
					newlink->next=current->next;
					current->next=newlink;
				}
				shet++;
				current=current->next;
			}
		}
}

void linklist::print(){
	link*current=first;
	while(current){
	cout<<"      "<<current->data<<"      "<<current->id<<endl;		//�������� ������		
	current= current->next;
	}
}
void linklist::display (int n,int n1)					//����� ����
{													
	link*current=first;									//�������� � ������� ��������
	int a=1;
	int f=0;
	while(a!=n){f++;
	if(f==n1){f=0;}
		cout<<"    "<<f<<"."<<current->data<<endl;		//�������� ������
		current= current->next;
		a++;
	}
	f++;if(f==n1){f=0;}
	cout<<">"<<"   "<<f<<"."<<current->data<<endl;		//�������� ������
		current= current->next;
	while(current){f++;if(f==n1){f=0;}
		cout<<"    "<<f<<"."<<current->data<<endl;		//�������� ������
		current= current->next;							//����� � ��������� ��������
		
	}
}
void linklist:: Showfromfirst(){//����� ��� ��� � ��������
		link *current = first;
		do {
			cout<<current->data<<"   "<<current->id<<endl;
			current=current->next;
		} while (current!=NULL);
	}
void linklist::number(int p)//����
{	int b=1;
	link*current=first;
	while(b!=p){
	current= current->next;
	b++;
	}
	cout<<"*****"<<current->data<<"*****"<<endl;

	
};
int main()
{	setlocale(LC_ALL,"Russian");
	linklist *tes=new linklist;
	linklist *addcentr=new linklist;
	int n=1;
	int p=1;
	int sp=0;
	linklist *d = new linklist;         //������� ����������-������

	d->add("������ � �������");
	d->add("��������� ������");
	d->add("��������");
	d->add("���������� ��������");
	d->add("��������������");
	d->add("�����");
	
	
	d->display (n,6);	
	linklist *d1 = new linklist;
	d1->add("��������� ������");
	d1->add("��������� ������");
	d1->add("����� � ������� ����");
	
	linklist *d4 = new linklist;
	d4->add("���������� � ��������");
	d4->add("����� � ������� ����");
	
	linklist *d5 = new linklist;
	d5->add("������������� ������� �������");
	d5->add("����� � ������� ����");
	
	linklist *d6 = new linklist;
	d6->add("��");
	d6->add("���");
	int z=1;
	int dir=1,x=1;
	while(x==1){
		int dir=1;
		z=0;
		n=p;
		while(dir!=13)
		{	
			dir=getch();
			
			if (dir<54 && dir>48) {n=(dir-48);}
			if(dir==72){n--;}
			if(dir==80){n++;}
			if(n==7){n=1;}
			if(n==0){n=6;}
			if(dir==48){n=6;}
			if (n>0 && n<7){system("cls");
				d->display(n,6);
				z=n;
				p=n;
				if (dir==27){z=6;dir=13;}
		
			}
		}
		system("cls");
		////////////////////////////////////////
		if(z==1){
			n=1;
			d->number(p);
			int dir=1;
			d1->display(n,3);
			int h1=1;
			while(dir !=13){
				dir=getch(); 
				if (dir==27){system("cls");d->display(1,6);break;}
				if(dir<50 && dir>48){n=(dir-48);}
				if(dir==80){n++;}
				if(dir==72){n--;}
				if(n==0){n=3;}
				if(n==4){n=1;}
				if(dir==48){n=3;}
				if (n>0 && n<4){system("cls");
					d->number(p);
					d1->display(n,3);
					if(dir==13 ){
						if(n==1){tes->save();
							cout<<"������ ������� ��������"<<endl;
							system("pause");
							n=3;
						}
						if (n==2){tes->DelAll();
							tes->load(tes);sp=1;
							cout<<"������ ������� ��������"<<endl;
							system("pause");
							n=3;
						}
						if(n==3){
							system("cls");n = 1; d->display(n,6);
						}
					}
				}
			}
		}
		//////////////////////////////////////////////
		if(z==2){
			n=1;
			d->number(p);
			int dir=1;
			//dir=getch();
			system("cls");
			d->number(p);if(sp==1){cout<<"������ ��� ������";}
			else{
			sp=1;
			tes->add("a");
			tes->add("b");
			tes->add("c");
			tes->add("d");
			tes->add("e");
			tes->add("f");
			cout<<"\n\n\n\n\n������ ������� ������"<<endl;}
			system("pause");
			system("cls");n = 2; d->display(n,6);
		}
		/////////////////////////////////////////////////////
		if(z==3){
			n=1;
			d->number(p);
			tes->print();
			if(sp==0){cout<<endl<<"������ ����";}
			int dir=1;
			dir=getch();
			system("cls");
			n = 3; 
			d->display(n,6);
					
		}
		////////////////////////////////////////////////////////////
		if(z==4){
			n=1;
			d->number(p);
			int dir=1;
			d4->display(n,2);
			while(dir !=13){
				dir=getch();
				if (dir==27){system("cls");d->display(4,6);break;}
				if(dir<50 && dir>48){n=(dir-48);}
				if(dir==80){n++;}
				if(dir==72){n--;}
				if(n==0){n=2;}
				if(n==3){n=1;}
				if(dir==48){n=2;}
				if (n>0 && n<4){system("cls");
					d->number(p);
					d4->display(n,2);
					if(dir==13 ){
						if(n==1 ){system("cls");
								
								
								string stroka;
								cout<<"vedite stroki";
								cin>>stroka; 
								system("cls");
								tes->addcenter(stroka);
							//	tes->Showfromfirst();
								cout<<"vedite stroki";
								sp=1;
								
								
							
							n=2;
						}
						if( n==2){
							system("cls");n = 4; d->display(n,6);
						}
					}	
				}
			}
		}
		////////////////////////////////////////////////////
		if(z==5){
			n=1;
			d->number(p);
			int dir=1;
			d5->display(n,2);
			while(dir !=13){
				if (dir==27){system("cls");d->display(5,6);break;}
				dir=getch();
				if(dir<50 && dir>48){n=(dir-48);}
				if(dir==80){n++;}
				if(dir==72){n--;}
				if(n==0){n=2;}
				if(n==3){n=1;}
				if(dir==48){n=2;}
				if (n>0 && n<3){system("cls");
					d->number(p);	
					d5->display(n,2);
					if(dir==13 ){
						if(n==1){
						tes->edit();n=2;
						}
						if( n==2){
							system("cls");n = 5; d->display(n,6);
						}
					}
				}
			}
		}
		///////////////////////////////////////////
		if(z==6){
			n=1;
			d->number(6);
			int dir=1;
			d6->display(n,3);
			while(dir !=13){	
				dir=getch();
				if (dir==27){system("cls");d->display(6,6);break;}
				if(dir<50 && dir>48){n=(dir-48);}
				if(dir==80){n++;}
				if(dir==72){n--;}
				if(n==0){n=2;}
				if(n==3){n=1;}
				if(dir==48){n=2;}
				if (n>0 && n<3){system("cls");
					d->number(6);	
					d6->display(n,3);	
					if(dir==13){
						if(n==1){exit(0);}
						if( n==2){
							system("cls");n = 6; d->display(n,6);
						}
					}	
				}
			}	
		}		
	}
		
	std::system("pause");
	return 0;
	}


	