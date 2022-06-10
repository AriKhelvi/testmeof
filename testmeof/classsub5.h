#ifndef CLASSSUB1_H
#define CLASSSUB1_H
#include "baseclass.h"
#include "classapp.h"	

class cl_s5 : public cl_base {
public:
	cl_s5(cl_base* par_object, std::string object_name = "Basic");
};
#endif