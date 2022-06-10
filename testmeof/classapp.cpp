#include "classapp.h"
#include "classes.h"
#include <iostream>
#include <cstdio>
//#define create_class(X, par, name) new cl_s##X(par, name) - фокус не удался

cl_app::cl_app(cl_base * par_object, std::string object_name):cl_base(par_object, object_name){
//автоматически наследованный конструктор
}
void cl_app::build_tree_objects(){
	std::string name, path, next_name; int class_num;
	std::cin >> name; this -> set_name(name); //ввод имени корневого объекта
	cl_base * parent = this, * current = nullptr;// узелок и верёвка
	bool is_equel = false;
	while(!is_equel){
		std::cin >> path; 
		if(path=="endtree"){//это конец ввода?
			is_equel = true;
		}
		else{
			std::cin >> next_name >> class_num;
			parent = this -> path_find(path); 
			if(parent == nullptr){
				this -> sub_exe_visual_no_flags();
				std::cout << '\n' << "The head object " << path << " is not found";
				this -> set_state(9);
				return;
			}
			switch(class_num){
				case 2:{
					current = new cl_s2(parent, next_name);
					break;}
				case 3:{
					current = new cl_s3(parent, next_name);
					break;}
				case 4:{
					current = new cl_s4(parent, next_name);
					break;}
				case 5:{
					current = new cl_s5(parent, next_name);
					break;}				
				case 6:{
					current = new cl_s6(parent, next_name);
					break;}
				default:{
					std::cout << "EEEErRrR00o0o0RRRRRRRRRRRRRRRrrRrrR";
					return;}
			}
			//current = create_class(class_num, parent, next_name);//- готовилось для фокуса
		}
	}
}

/*int cl_app::execute_not_visual(){
	this -> sub_exe();//Вызов вывода
	return 0;
}*/

int cl_app::execute(){
//////////////////////////////////////////////////////////////////////////////
//Точно так же выводит дерево как cl_app::execute_not_visual, но с табуляцией(как в случае 
//построенного в условии дерева), помогает с читабельностью
//////////////////////////////////////////////////////////////////////////////
	if(this -> get_state()==9){
		return 9;
	}
	else{
		this -> sub_exe_visual_no_flags();
		std::string s1, s2;
		std::cin >> s1;
		cl_base * like_this = this; cl_base * temp;
		while(s1 != "END"){
			std::cout << '\n';
			std::cin >> s2;
			temp = like_this->path_find(s2);
			if(s1 == "SET"){
				if(temp==nullptr){
					std::cout << "Object is not found: " <<like_this->get_name() << " " << s2;
				}
				else{
					like_this = like_this->path_find(s2);
					std::cout << "Object is set: " << temp->get_name();
				}
			}
			else{
				if(like_this->path_find(s2)==nullptr){
					std::cout << s2 << "     Object is not found";
				}
				else{
					std::cout << s2 << "     Object name: " << temp->get_name();
				}
			}
			std::cin >> s1;
		}
		return 0;
	}
}
