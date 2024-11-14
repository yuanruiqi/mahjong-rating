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
    // f128 rank[5];
    // i64 count;
};

enum state
{
    TSUMO,
    RON,
    CRUSH,
    SKIPPED,
    TENPAI,
    NOTEN
};

struct game
{
    i32 host;
    state stat[4];
    i32 delta[4];
};

struct event
{
    person* per[4];
    std::vector<game> games;
};

void output();

void analysis();

void input();