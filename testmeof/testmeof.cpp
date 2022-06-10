﻿#include "classes.h"
int main()
{
	cl_app  ob_cl_app(nullptr);
	ob_cl_app.build_tree_objects();  // построение дерева объектов
	return ob_cl_app.execute();
}

//TEST:     //NOTE: add tests, even if this test cover all needs
/*
root
/ object_1 3
/ object_2 2
/object_2 object_4 3
/object_2 object_5 4
/ object_3 3
/object_2 object_3 6
/object_1 object_7 5
/object_2/object_4 object_7 3
endtree
FIND object_2/object_4
SET /object_2
FIND //object_5
FIND /object_15
FIND .
FIND object_4/object_7
END
*/
