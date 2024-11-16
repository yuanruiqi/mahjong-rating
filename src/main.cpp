#include "maj.h"

i32 main()
{
    input();
    analysis(tri::db, tri::players, 3);
    analysis(qua::db, qua::players, 4);
    output();
    return 0;
}