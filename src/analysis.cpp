#include "maj.h"

using pii = std::pair<i64, i64>;

constexpr f128 e = 2.718281828459045;
constexpr f128 pi = 3.141592653589793;
constexpr f128 phi = 1.618033988749895;

f128 poly(f128 r)
{
    return r / (10 * phi);
}

// f128 calc(i32 rk, i32 typ, f128 avg, f128 rate)
// {
//     if (typ == 3 && rk == 1) return 0;
//     if (typ == 3 && rk == 2) rk = 3;
//     if (!rk) return poly(avg);
//     if (rk == 3) return -poly(rate);
//     return poly(avg) * (rk == 1 ? 1 : -1) / e;
// }

const i32 ori[]={0,0,0,35000,25000};

f128 calc(i32 typ, i32 pos, i32 rank, std::vector<i32>scores, std::vector<f128>prating){
    const f128 S=rank==0?15:0;
    const f128 D=rank==typ-1?std::max<f128>(0ll,(prating[pos]-1500.0)/60.0):0.0;
    std::vector<f128>diff;
    if(typ==3)diff={+15,0,-15};
    else diff={+15,+5,-5,-15};
    f128 delta_base=diff[rank]+(scores[pos]-ori[typ])/1000.0-D;
    f128 E_rank=1;
    for(i32 i=0;i<typ;i++){
        if(i!=pos){
            E_rank+=1./(1.0+std::pow(2,(prating[pos]-prating[i])/200.0));
        }
    }
    f128 g=E_rank-rank;
    if(delta_base>0)delta_base*=pow(4.0/3.0,g);
    else delta_base*=pow(3.0/4.0,g);
    return delta_base+S;
}

constexpr f128 rate_delta[] = {-2000, -1000, -500, -250, 0};

void analysis(std::vector<event>& db, std::vector<person>& players, const i32 typ)
{
    for (event& ev : db)
    {
        for (i32 i = 0; i < typ; ++i)
        {
            i32 id = ev.per[i];
            ++players[id].event_cnt;
            players[id].game_cnt += ev.games.size();
        }
        i64 *score = ev.final_score;
        i64 ori = typ == 3 ? 35000 : 25000;
        std::fill(score, score + typ, ori);
        for (game g : ev.games)
        {
            for (i32 i = 0; i < typ; ++i)
            {
                i32 id = ev.per[i];
                score[i] += g.delta[i];
                if (g.stat[i] == TSUMO || g.stat[i] == RON)
                {
                    ++players[id].win_cnt;
                    players[id].win_sum += g.delta[i];
                }
                players[id].crush_cnt += g.stat[i] == CRUSH;
                if(g.stat[i] == CRUSH){
                    players[id].crush_sum += g.delta[i];
                }
            }
        }
        pii p[typ];
        i32 rk[typ];
        for (i32 i = 0; i < typ; ++i) p[i] = pii(-score[i], i);
        std::sort(p, p + typ);
        for (i32 i = 0; i < typ; ++i) rk[p[i].second] = i;//rk is from 0
        f128 avg = 0;
        for (i32 i = 0; i < typ; ++i) avg += players[ev.per[i]].rating;
        avg /= typ;
        std::vector<f128> prating;
        std::vector<i32>scores;
        for (i32 i = 0; i < typ; ++i){
            prating.push_back(players[i].rating);
            scores.push_back(score[i]);
        }
        for (i32 i = 0; i < typ; ++i)
        {
            i32 id = ev.per[i];
            players[id].event_sum += score[i];
            ++players[id].rank_cnt[rk[i]];
            players[id].rank_cnt[4] += score[i] < 0;
            // f128 delta = (score[i] - ori) / (100 * pi) + calc(rk[i], typ, avg, players[id].rating);
            f128 delta = calc(typ, i, rk[i], scores, prating);
            players[id].rating += delta;
            ev.rating_deltas[i] = delta;
            f128 rate = players[id].show_rating = players[id].rating + rate_delta[std::min(4ll, players[id].event_cnt)];
            players[id].max_rating = std::max(players[id].max_rating, rate);
            i64 k = ((i64) players[id].max_rating) / 200;
            if (k >= 10) players[id].dan = std::to_string(k - 9) + " Dan";
            else players[id].dan = std::to_string(10 - k) + " Kyu";
        }
        
        #ifdef DEBUG
        for (i32 i = 0; i < typ; ++i)
        {
            i32 id = ev.per[i];
            std::cerr << players[id].name << ':' << score[i] << '\n';
        }
        for (i32 i = 0; i < typ; ++i)
        {
            i32 id = ev.per[i];
            std::cerr << players[id].name << ':' << players[id].rating << '\n';
        }
        std::cerr << "----\n";
        #endif
    }
}