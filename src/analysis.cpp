#include "maj.h"

using pii = std::pair<i64, i64>;

constexpr f128 e = 2.718281828459045;
constexpr f128 pi = 2.718281828459045;
constexpr f128 phi = 1.618033988749895;

f128 poly(f128 r)
{
    return r / (10 * phi);
}
f128 calc(i32 rk, f128 avg, f128 rate)
{
    if (!rk) return poly(avg);
    if (rk == 3) return -poly(rate);
    return poly(avg) * (rk == 1 ? 1 : -1) / e;
}

void analysis()
{
    for (event ev : db)
    {
        for (i32 i = 0; i < 4; ++i)
        {
            i32 id = ev.per[i];
            ++players[id].event_cnt;
            players[id].game_cnt += ev.games.size();
        }
        i64 score[4];
        std::fill(score, score + 4, 25000);
        for (game g : ev.games)
        {
            for (i32 i = 0; i < 4; ++i)
            {
                i32 id = ev.per[i];
                score[i] += g.delta[i];
                if (g.stat[i] == TSUMO || g.stat[i] == RON)
                {
                    ++players[id].win_cnt;
                    players[id].win_sum += g.delta[i];
                }
                players[id].crush_cnt += g.stat[i] == CRUSH;
            }
        }
        assert(score[0] + score[1] + score[2] + score[3] == 100000);
        pii p[4];
        i32 rk[4];
        for (i32 i = 0; i < 4; ++i) p[i] = pii(score[i], i);
        std::sort(p, p + 4);
        for (i32 i = 0; i < 4; ++i) rk[p[i].second] = i;
        f128 avg = 0;
        for (i32 i = 0; i < 4; ++i) avg += players[ev.per[i]].rating;
        avg /= 4;
        for (i32 i = 0; i < 4; ++i)
        {
            i32 id = ev.per[i];
            players[id].event_sum += score[i];
            ++players[id].rank_cnt[rk[i]];
            players[id].rank_cnt[4] += score[i] < 0;
            f128 delta = (score[i] - 25000) / (100 * pi) + calc(rk[i], avg, players[id].rating);
            players[id].rating += delta;
        }
    }
}