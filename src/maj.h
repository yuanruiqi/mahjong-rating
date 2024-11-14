// MAJ_H

#pragma once

#include <bits/stdc++.h>

using i32 = int;
using i64 = long long;
using f128 = long double;

#define int CE

struct person
{
    std::string name;
    i64 rank_cnt[5];
    i64 event_cnt, game_cnt, event_sum;
    i64 win_cnt, win_sum, crush_cnt;
    f128 rating;
    person() {}
};
std::vector<person> players;

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
};

struct event
{
    i32 per[4];
    std::vector<game> games;
};

std::vector<event> db;

void output();

void analysis();

void input();