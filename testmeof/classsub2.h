#ifndef CLASSSUB2_H
#define CLASSSUB2_H
#include "baseclass.h"
#include "classapp.h"


class cl_s2 : public cl_base {
public:
	cl_s2(cl_base* par_object, std::string object_name = "Basic");
};

#endif