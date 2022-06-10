#ifndef CLASSSUB6_H
#define CLASSSUB6_H
#include "baseclass.h"
#include "classapp.h"

class cl_s6 : public cl_base {//новое
public:
	cl_s6(cl_base* par_object, std::string object_name = "Basic");
};

#endif