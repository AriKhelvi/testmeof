#ifndef CLASSSUB3_H
#define CLASSSUB3_H
#include "baseclass.h"
#include "classapp.h"


class cl_s3 : public cl_base {
public:
	cl_s3(cl_base* par_object, std::string object_name = "Basic");
};

#endif