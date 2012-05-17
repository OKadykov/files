// меню 23.04.2012.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include<conio.h>
#include<stdio.h>
#include <fstream>
#include <assert.h>
using  namespace std;



struct link  											//один эллемент списка
{
	 string data;										//данные
	 link*next;											//указатель на следующую структуру
	 int id;
	
};

class linklist											//список
{
private:
	int num;
	link*first;
public:
	linklist()											//конструктор без параметров	
	{first=NULL;}	
	int n;//первого элемента пока нет
	void add( string d);								//добавление элемента
	void display(int n, int n1);						//показ данных
	void number(int p);
	void save();
	void addcenter(string d);
	void Showfromfirst();
	void load(linklist*name);
	void edit();
	void deletFROMcenter();
	//void DelAll();
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
   
   void linklist::loadcentr( linklist*name){
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
	   system("cls");
		int i=1;
		string value;
		link *current = first;
		link *newlink = new link;
	while(current==first){i++;current=current->next;}
	for(int j=0;j<(i/2+1);j++){current=current->next;}
	//delete first;
}
   void linklist::edit(){
	   system("cls");
		int i=1;
		string value;
		link *current = first;
		link *newlink = new link;
	while(current==first){i++;current=current->next;}
	for(int j=0;j<(i/2+1);j++){current=current->next;}
	cout<<"редактирование середины\n"<<"введите елемент";
	cin>>value;
	current->data=value;
	
	getch();
}
/*void linklist::DelAll()
{	link*current=first;
	if (first!=NULL)
	{
		if(first!=first->next)
		{
			current=first->next;	
			do 
			{		
				current=current->next;
				delete current;
			}
			while(current!=first);	
			delete first;
			first=NULL;
		}
		else 
		{
			delete first;
			first=NULL;
		}
	}
}*/




void linklist::add( string d)			//добавление элемнта
{		
	/*//добавление в начало списка
	link*newlink= new link;				//выделяем память
	newlink->data=d;					//запоминаем данные
	newlink->next=first;				//запоминаем значение first
	first=newlink;					//first указывает на новый элемент 
	*/
	//добавление в конец списка
		link *current = first;
		link *newlink = new link;
		if (first==NULL){//если первый добавляем
			first=newlink;
			newlink->next=NULL;
			newlink->data=d;
		}else{
			while (current->next!=NULL) {//идем до последнего
				current=current->next;
			}
			current->next=newlink;//последний теперь указывает на новый
			newlink->next=NULL;
			newlink->data=d;
	}
	
}
int a=0; 
void linklist:: addcenter(string d){ //добавление в центр
		link*current=first;
		link*newlink= new link;
		link*temporary= new link;
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
	cout<<"      "<<current->data<<endl;		//печатаем данные		
	current= current->next;
	}
}
void linklist::display (int n,int n1)					//вывод меню
{													
	link*current=first;									//начинаем с первого элемента
	int a=1;
	int f=0;
	while(a!=n){f++;
	if(f==n1){f=0;}
		cout<<"    "<<f<<"."<<current->data<<endl;		//печатаем данные
		current= current->next;
		a++;
	}
	f++;if(f==n1){f=0;}
	cout<<">"<<"   "<<f<<"."<<current->data<<endl;		//печатаем данные
		current= current->next;
	while(current){f++;if(f==n1){f=0;}
		cout<<"    "<<f<<"."<<current->data<<endl;		//печатаем данные
		current= current->next;							//сдвиг к следущему элементу
		
	}
}
void linklist:: Showfromfirst(){//вывод при доб в середину
		link *current = first;
		do {
			cout<<current->data<<"   "<<current->id<<endl;
			current=current->next;
		} while (current!=NULL);
	}
void linklist::number(int p)//меню
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
	linklist *d = new linklist;         //создаем переменную-список

	d->add("Работа с файлами");
	d->add("Генерация списка");
	d->add("Просмотр");
	d->add("Добавление элемента");
	d->add("Редактирование");
	d->add("Выход");
	
	
	d->display (n,6);	
	linklist *d1 = new linklist;
	d1->add("Сохранить список");
	d1->add("загрузить список");
	d1->add("Назад в главное меню");
	
	linklist *d2 = new linklist;
	d2->add("Да");
	d2->add("Нет");
	d2->add("Назад в главное меню");

	linklist *d3 = new linklist;
	d3->add("Да");
	d3->add("Нет");
	d3->add("Назад в главное меню");
	
	linklist *d4 = new linklist;
	d4->add("Добавление в середину");
	d4->add("Назад в главное меню");
	
	linklist *d5 = new linklist;
	d5->add("Редактировать средний элемент");
	d5->add("Назад в главное меню");
	
	linklist *d6 = new linklist;
	d6->add("да");
	d6->add("нет");
	int z=1;
	int dir=1,x=1;
	while(x==1){
		int dir=1;
		z=0;
		n=p;
		while(dir!=13)
		{	
			dir=getch();
			
			if (dir<55 && dir>48) {n=(dir-48);}
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
				if(dir<51 && dir>48){n=(dir-48);}
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
							cout<<"список успешно сохранен"<<endl;
							system("pause");
							n=3;
						}
						if (n==2){tes->load(tes);
							cout<<"список успешно загружен"<<endl;
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
			d2->display(n,3);
			while(dir !=13){
				if (dir==27){system("cls");d->display(2,6);break;}
				dir=getch();
				if(dir<51 && dir>48){n=(dir-48);}
				if(dir==80){n++;}
				if(dir==72){n--;}
				if(n==0){n=3;}
				if(n==4){n=1;}
				if(dir==48){n=3;}
				if (n>0 && n<4){system("cls");
					d->number(p);
					d2->display(n,3);
					if(dir==13 ){
						if(n==1){
							tes->add("привет1");
							tes->add("приффет2");
							tes->add("привет3");
							tes->add("привет4");
							tes->add("привет5");
							tes->add("привет6");
							tes->add("привет7");
							cout<<"список успешно создан"<<endl;
							system("pause");
							n=3;
						}
						if(n==2){//tes->deletFROMcenter()
							cout<<"список пуст или загружен из файла"<<endl;
							system("pause");
							n=3;}
						if(n==3){
							system("cls");n = 2; d->display(n,6);
						}
					}
				}
			}
		}
		/////////////////////////////////////////////////////
		if(z==3){
			n=1;
			d->number(p);
			int dir=1;
			d3->display(n,3);
			while(dir !=13){
				dir=getch();
				if (dir==27){system("cls");d->display(3,6);break;}
				if(dir<51 && dir>48){n=(dir-48);}
				if(dir==80){n++;}
				if(dir==72){n--;}
				if(n==0){n=3;}
				if(n==4){n=1;}
				if(dir==48){n=3;}
				if (n>0 && n<4){
					system("cls");
					d->number(p);	
					d3->display(n,3);
					if(dir==13 ){
						if(n==1){
							system("cls");
							tes->print();
						}
						if(n==2){n=3;
						
						}
						if( n==3){
							system("cls");n = 3; d->display(n,6);
						}
					}	
				}
			}
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
				if(dir<51 && dir>48){n=(dir-48);}
				if(dir==80){n++;}
				if(dir==72){n--;}
				if(n==0){n=2;}
				if(n==3){n=1;}
				if(dir==48){n=2;}
				if (n>0 && n<4){system("cls");
					d->number(p);
					d4->display(n,2);
					if(dir==13 ){
						if(n==1 ){
							while(true){
								cout<<"spisok\n vedite stroki";
								string stroka;
								cin>>stroka;
								system("cls");
								addcentr->addcenter(stroka);
								addcentr->Showfromfirst();
							}
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
				if(dir<51 && dir>48){n=(dir-48);}
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
						tes->edit();
						}
						if( n==2){
							system("cls");n = 5; d->display(n,6);
						}
					}
				}
			}
		}
		///////////////////////////////////
		if(z==6){
			n=1;
			d->number(p);
			int dir=1;
			d6->display(n,3);
			while(dir !=13){	
				dir=getch();
				if (dir==27){system("cls");d->display(6,6);break;}
				if(dir<51 && dir>48){n=(dir-48);}
				if(dir==80){n++;}
				if(dir==72){n--;}
				if(n==0){n=2;}
				if(n==3){n=1;}
				if(dir==48){n=2;}
				if (n>0 && n<3){system("cls");
					d->number(p);	
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


	/*//добавление в центр
	while(true){
							cout<<"spisok\n vedite stroki";
							string stroka;
							cin>>stroka;
							system("cls");
							addcentr->addcenter(stroka);
							addcentr->Showfromfirst();
						}*/