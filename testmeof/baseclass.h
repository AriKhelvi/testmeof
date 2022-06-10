#ifndef BASECLASS_H
#define BASECLASS_H

#include <string>
#include <vector>

class cl_base {
protected:
	std::string object_name = "";
	cl_base* par_object = nullptr;
	int i_state = 1;//due to lack of time and necessity actually isn`t used
	std::vector <cl_base*> sub_objects;
public:
	cl_base(cl_base* par_object, std::string object_name = "Base_object");
	~cl_base();
	void set_name(std::string object_name);
	std::string get_name();
	void set_state(int i);
	int get_state();
	void change_par_object(cl_base* new_par_object);
	cl_base* get_par_object();
	cl_base* gl_find_object(std::string object_name);
	cl_base* path_find(std::string path);
	void sub_exe_visual_no_flags(int num_tabs = 0);
	void sub_exe_visual_with_flags(int num_tabs = 0);
	void sub_exe();
};

#endif