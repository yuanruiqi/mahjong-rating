#include "maj.h"

i32 main()
{
    input();
    #ifdef DEBUG
    std::cerr<<"Number of tri events:"<<tri::db.size()<<'\n';
    std::cerr<<"Number of qua events:"<<qua::db.size()<<'\n';
    std::cerr<<"Number of tri players:"<<tri::players.size()<<'\n';
    std::cerr<<"Number of qua players:"<<qua::players.size()<<'\n';
    #endif
    analysis(tri::db, tri::players, 3);
    analysis(qua::db, qua::players, 4);
    output();
    return 0;
}