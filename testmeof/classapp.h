#ifndef CLASSAPP_H
#define CLASSAPP_H
#include "baseclass.h"
#include "classes.h"

class cl_app : public cl_base {
public:
	cl_app(cl_base* par_object, std::string object_name = "Base_object");
	void build_tree_objects();
	int execute();
	//int execute_not_visual();
};

#endif