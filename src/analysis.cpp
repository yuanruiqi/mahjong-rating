#include "maj.h"

using pii = std::pair<i64, i64>;

void analysis()
{
    for (event e : db)
    {
        for (i32 i = 0; i < 4; ++i)
        {
            ++players[e.per[i]].event_cnt;
            players[e.per[i]].game_cnt += e.games.size();
        }
        i64 score[4];
        std::fill(score, score + 4, 25000);
        for (game g : e.games)
        {
            for (i32 i = 0; i < 4; ++i)
            {
                i32 id = e.per[i];
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
        for (i32 i = 0; i < 4; ++i)
        {
            i32 id = e.per[i];
            players[id].event_sum += score[i];
            ++players[id].rank_cnt[rk[i]];
            players[id].rank_cnt[4] += score[i] < 0;
        }
    }
}