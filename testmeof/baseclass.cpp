#include "baseclass.h"

#include <algorithm>
#include <iterator>
#include <iostream>

cl_base::cl_base(cl_base* par_object, std::string object_name) {
	this->object_name = object_name;	//установка имени
	if (par_object) {
		this->par_object = par_object; //установка родителя
		par_object->sub_objects.push_back(this); //запись в данные родителя о текущем объекте
	}
	this->i_state = 0;
}
cl_base::~cl_base() {
	for (int i = 0; i < sub_objects.size(); i++) {//очищение памяти, динамически занятой потомками
		delete(sub_objects[i]);
	}
	//if(par_object)//если есть родитель - удаление данных о текущем объекте у родителя, неактивно ввиду отсутствия необходимости
	//	par_object -> sub_objects.erase(std::find(begin(par_object -> sub_objects), end(par_object -> sub_objects), this));
	//автоматическое очищение остальных полей
}
void cl_base::set_name(std::string object_name) {
	//установка имени
	this->object_name = object_name;
}
std::string cl_base::get_name() {
	//получение имени
	return object_name;
}
void cl_base::set_state(int i) {
	if (i != 0 && this->get_par_object() == nullptr) {
		this->i_state = i;
	}
	else if (i != 0 && (this->get_par_object()->get_state() != 0)) {
		this->i_state = i;
	}
	else if (i == 0) {
		this->i_state = 0;
		for (int ii = 0; ii < this->sub_objects.size(); ii++) {
			this->sub_objects[ii]->set_state(i);
		}
	}
}
int cl_base::get_state() {
	return i_state;
}
void cl_base::change_par_object(cl_base* new_par_object) {
	par_object->sub_objects.erase(std::find(begin(par_object->sub_objects),//удаление данных о текущем объекте у родителя
		end(par_object->sub_objects), this));
	this->par_object = new_par_object;//установка нового родителя
	par_object->sub_objects.push_back(this);//запись в данные нового родителя о текущем объекте
}
cl_base* cl_base::get_par_object() {
	return par_object;
}


void cl_base::sub_exe() {
	if (this->par_object == nullptr) {
		std::cout << this->get_name();
	}
	if (this->sub_objects.size() > 0) {
		std::cout << std::endl << this->get_name() << "  ";
		for (int i = 0; i < this->sub_objects.size(); i++) {
			std::cout << this->sub_objects[i]->get_name();
			if (i + 1 != this->sub_objects.size()) { std::cout << "  "; }
		}
		for (int i = 0; i < this->sub_objects.size(); i++) {
			this->sub_objects[i]->sub_exe();
		}
	}
}
void cl_base::sub_exe_visual_no_flags(int num_tabs) {
	if (this->par_object == nullptr) {
		std::cout << "Object tree";
	}
	std::cout << std::endl;
	if (num_tabs > 0) {
		std::string t; t.assign(num_tabs * 4, ' ');
		std::cout << t;
	}
	std::cout << this->get_name();
	for (int i = 0; i < this->sub_objects.size(); i++) {
		this->sub_objects[i]->sub_exe_visual_no_flags(num_tabs + 1);
	}
}
void cl_base::sub_exe_visual_with_flags(int num_tabs) {
	if (this->par_object == nullptr) {
		std::cout << std::endl << "The tree of objects and their readiness";
	}
	std::cout << std::endl;
	if (num_tabs > 0) {
		std::string t; t.assign(num_tabs * 4, ' ');
		std::cout << t;
	}
	std::cout << this->get_name();
	if (this->i_state == 0) { std::cout << " is not ready"; }
	else { std::cout << " is ready"; }
	for (int i = 0; i < this->sub_objects.size(); i++) {
		this->sub_objects[i]->sub_exe_visual_with_flags(num_tabs + 1);
	}
}
cl_base* cl_base::path_find(std::string path) {
	if (path[1] == '/') {
		if (this->par_object == nullptr)
			return this->gl_find_object(path.substr(2));
		else
			return this->par_object->path_find(path);
	}
	else if (path == ".") { return this; }
	else if (path == "/" || path == ".") {
		if (this->par_object == nullptr)
			return  this;
		else
			return this->par_object->path_find(path);
	}
	else if (path[0] == '/') {
		if (this->par_object == nullptr)
			return  this->path_find(path.substr(1));
		else
			return this->par_object->path_find(path);
	}
	else {
		int ind = -1;
		for (int i = 1; i < path.size(); i++) {
			if (path[i] == '/') { ind = i; }
		}
		std::string nw;
		if (ind == -1)
			nw = path;
		else
			nw = path.substr(0, ind);
		for (int i = 0; i < this->sub_objects.size(); i++) {
			//std::cout << this->sub_objects[i]->get_name()<<' ' << nw<<'\n';//debug
			if (this->sub_objects[i]->get_name() == nw) {
				if (ind == -1)
					return this->sub_objects[i];
				else
					return this->sub_objects[i]->path_find(path.substr(ind + 1));
			}
		}
	}

	return nullptr;
}
cl_base* cl_base::gl_find_object(std::string object_name) {
	if (object_name == this->get_name()) { return this; }
	else {
		cl_base* t = nullptr;
		cl_base* temp;
		for (int i = 0; i < sub_objects.size(); i++) {
			temp = sub_objects[i]->gl_find_object(object_name);
			if (temp != nullptr) { t = temp; break; }
		}
		return t;
	}
}