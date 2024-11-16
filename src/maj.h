// MAJ_H

#pragma once

#ifndef MAJ_H

#define MAJ_H

#include <algorithm>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

using i32 = int;
using i64 = long long;
using f128 = long double;

#define int CE

struct person
{
    std::string name, dan;
    i64 rank_cnt[5];
    i64 event_cnt, game_cnt, event_sum;
    i64 win_cnt, win_sum, crush_cnt;
    f128 show_rating, rating, max_rating;
    person() {show_rating = max_rating = 0; rating = 2000;}
};

enum state
{
    TSUMO,      // 0
    RON,        // 1
    CRUSH,      // 2
    SKIPPED,    // 3
    TENPAI,     // 4
    NOTEN       // 5
};

struct game
{
    i32 host;
    state stat[4];
    i32 delta[4];
    game() {}
};

struct event
{
    i32 per[4];
    i32 type;//3 or 4
    std::vector<game> games;
};

void output();

void analysis(std::vector<event>, std::vector<person>, i32);

void input();

namespace tri
{
    extern std::vector<person> players;
    extern std::vector<event> db;
}
namespace qua
{
    extern std::vector<person> players;
    extern std::vector<event> db;
}

#endif