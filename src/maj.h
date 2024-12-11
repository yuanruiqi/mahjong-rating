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
#include <map>
#include <cmath>

using i32 = int;
using i64 = long long;
using f128 = long double;

#define int CE

struct person
{
    std::string name, dan;
    i64 rank_cnt[5];
    i64 event_cnt, game_cnt, event_sum;
    i64 win_cnt, win_sum, crush_cnt ,crush_sum;
    f128 show_rating, rating, max_rating;
    person() {
        show_rating = max_rating = 0; rating = 2000;
        rank_cnt[0]=rank_cnt[1]=rank_cnt[2]=rank_cnt[3]=rank_cnt[4]=0;
        event_cnt = 0;
        game_cnt=event_sum=win_cnt=win_sum=crush_cnt=0;
    }
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

const static std::string stid2string[]={"自摸","荣和","放铳","无关","听牌","没听牌"};

const i32 MAX_STATE = 5;

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
    i64 final_score[4];
    f128 rating_deltas[4];
    std::vector<game> games;
};

void output();

void analysis(std::vector<event>&, std::vector<person>&, const i32);

void input();

namespace tri
{
    const static i32 player_cnt=3;
    extern std::vector<person> players;
    extern std::vector<event> db;
}

namespace qua
{
    const static i32 player_cnt=4;
    extern std::vector<person> players;
    extern std::vector<event> db;
}

#endif