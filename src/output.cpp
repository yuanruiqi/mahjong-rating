#include "maj.h"

const std::string indexlink="./html/index.html";
const std::string outmd="./html/out.md";

bool cmp(person a,person b){
    return a.show_rating>b.show_rating;
}

const std::string poses[]={"东","南","西","北"};

namespace qua{
    std::string get_table(){
        // std::string opt="<meta charset=\"utf-8\">\n<script src=\"marked.min.js\"></script>";
        // std::string table="<div id=\"$m\" class=\"markdown-body\"></div><textarea id=\"$t\" style=\"display:none\">";
        std::string table="";
        std::vector<std::string>heads={"排名","姓名","rating","1位率","2位率","3位率","4位率","被飞率","平均顺位","放铳率","和牌率","平均打点","参加局数","平均终局点数","历史最值rating","段位"};
        auto player_output=players;
        std::sort(players.begin(),players.end(),cmp);
        for(auto x:heads){
            table+="|"+x;
        }
        table+="|\n";
        for(auto x:heads){
            table+="|------";
        }
        table+="|\n";
        i32 cnt=1;
        for(auto player:players){
            std::stringstream opt;
            opt<<"|"<<(cnt++);
            opt<<"|"<<player.name;
            opt<<"|"<<std::fixed<<' '<<std::setprecision(3)<<player.show_rating;
            i32 t=0;
            for(i32 i=0;i<=4;i++){
                t+=std::min(i+1,4)*player.rank_cnt[i];
                opt<<"|"<<std::fixed<<' '<<std::setprecision(1)<<player.rank_cnt[i]*100.0/std::max(1ll,player.event_cnt)<<'%';
            }
            opt<<"|"<<std::fixed<<' '<<std::setprecision(3)<<t*1.0/std::max(1ll,player.event_cnt);
            opt<<"|"<<std::fixed<<' '<<std::setprecision(1)<<player.crush_cnt*100.0/std::max(1ll,player.game_cnt)<<'%';
            opt<<"|"<<std::fixed<<' '<<std::setprecision(1)<<player.win_cnt*100.0/std::max(1ll,player.game_cnt)<<'%';
            opt<<"|"<<std::fixed<<' '<<std::setprecision(3)<<player.win_sum*1.0/std::max(1ll,player.win_cnt);
            opt<<"|"<<player.event_cnt;
            opt<<"|"<<std::fixed<<' '<<std::setprecision(3)<<player.event_sum*1.0/std::max(1ll,player.event_cnt);;
            opt<<"|"<<player.max_rating;
            opt<<"|"<<player.dan;
            opt<<"|\n";
            table+=opt.str();
        }
            players=player_output;
        return table;
        // table+=" </textarea>\n <script>$m.innerHTML = marked.parse($t.value);</script>";


    }

    std::string games_information(){
        // return "";
        std::string opt="";
        std::cerr<<-1<<std::endl;
        for(auto ev:db){
            std::string player_names="## ";
            for(i32 id=0;id<player_cnt;id++){
                player_names+=players[ev.per[id]].name;
                player_names+=' ';
            }
            std::vector<std::string>games_infor;
            i32 counter=0;
            i32 la=0;
            i32 pp=0;
            for(auto ga:ev.games){
                std::stringstream zz;
                if(ga.host==0&&ga.host!=la){
                    pp++;
                }
                la=ga.host;
                zz<<"### "<<poses[pp]<<ga.host+1<<' '<<counter<<"本场\n";
                for(i32 i=0;i<player_cnt;i++){
                    zz<<players[ev.per[i]].name<<' '<<stid2string[ga.stat[i]]<<'\n';
                }
                for(i32 i=0;i<player_cnt;i++){
                    zz<<players[ev.per[i]].name<<' ';
                    if(ga.delta[i]>0)zz<<'+';
                    zz<<ga.delta[i]<<'\n';
                }
                auto host=ga.host;
                if(ga.stat[host]==RON||ga.stat[host]==TSUMO||ga.stat[host]==TENPAI||ga.stat[host]==NOTEN)counter++;
                else counter=0;
                games_infor.push_back(zz.str());
            }
            std::stringstream final_score;
            for(i32 id=0;id<player_cnt;id++){
                final_score<<players[ev.per[id]].name<<' '<<ev.final_score[id]<<'\n';
            }

            opt+=player_names+'\n';
            for(auto z:games_infor){
                opt+=z;
            }
            opt+='\n';
            opt+=final_score.str();
            opt+='\n';
        }
        return opt;
    }
}

namespace tri{
    std::string get_table(){
        // std::string opt="<meta charset=\"utf-8\">\n<script src=\"marked.min.js\"></script>";
        // std::string table="<div id=\"$m\" class=\"markdown-body\"></div><textarea id=\"$t\" style=\"display:none\">";
        std::string table="";
        std::vector<std::string>heads={"排名","姓名","rating","1位率","2位率","3位率","被飞率","平均顺位","放铳率","和牌率","平均打点","参加局数","平均终局点数","历史最值rating","段位"};
        auto player_output=players;
        std::sort(players.begin(),players.end(),cmp);
        for(auto x:heads){
            table+="|"+x;
        }
        table+="|\n";
        for(auto x:heads){
            table+="|------";
        }
        table+="|\n";
        i32 cnt=1;
        for(auto player:players){
            std::stringstream opt;
            opt<<"|"<<(cnt++);
            opt<<"|"<<player.name;
            opt<<"|"<<std::fixed<<' '<<std::setprecision(3)<<player.show_rating;
            i32 t=0;
            for(i32 i=0;i<=4;i++){
                if(i==3)continue;
                t+=std::min(i+1,4)*player.rank_cnt[i];
                opt<<"|"<<std::fixed<<' '<<std::setprecision(1)<<player.rank_cnt[i]*100.0/std::max(1ll,player.event_cnt)<<'%';
            }
            opt<<"|"<<std::fixed<<' '<<std::setprecision(3)<<t*1.0/std::max(1ll,player.event_cnt);
            opt<<"|"<<std::fixed<<' '<<std::setprecision(1)<<player.crush_cnt*100.0/std::max(1ll,player.game_cnt)<<'%';
            opt<<"|"<<std::fixed<<' '<<std::setprecision(1)<<player.win_cnt*100.0/std::max(1ll,player.game_cnt)<<'%';
            opt<<"|"<<std::fixed<<' '<<std::setprecision(3)<<player.win_sum*1.0/std::max(1ll,player.win_cnt);
            opt<<"|"<<player.event_cnt;
            opt<<"|"<<std::fixed<<' '<<std::setprecision(3)<<player.event_sum*1.0/std::max(1ll,player.event_cnt);;
            opt<<"|"<<player.max_rating;
            opt<<"|"<<player.dan;
            opt<<"|\n";
            table+=opt.str();
        }
            players=player_output;
        return table;
        // table+=" </textarea>\n <script>$m.innerHTML = marked.parse($t.value);</script>";
    }

    std::string games_information(){
        // return "";
        std::string opt="";
        std::cerr<<-1<<std::endl;
        for(auto ev:db){
            std::string player_names="## ";
            for(i32 id=0;id<player_cnt;id++){
                player_names+=players[ev.per[id]].name;
                player_names+=' ';
            }
            std::vector<std::string>games_infor;
            i32 counter=0;
            i32 la=0;
            i32 pp=0;
            for(auto ga:ev.games){
                std::stringstream zz;
                if(ga.host==0&&ga.host!=la){
                    pp++;
                }
                la=ga.host;
                zz<<"### "<<poses[pp]<<ga.host+1<<' '<<counter<<"本场\n";
                for(i32 i=0;i<player_cnt;i++){
                    zz<<players[ev.per[i]].name<<' '<<stid2string[ga.stat[i]]<<'\n';
                }
                for(i32 i=0;i<player_cnt;i++){
                    zz<<players[ev.per[i]].name<<' ';
                    if(ga.delta[i]>0)zz<<'+';
                    zz<<ga.delta[i]<<'\n';
                }
                auto host=ga.host;
                if(ga.stat[host]==RON||ga.stat[host]==TSUMO||ga.stat[host]==TENPAI||ga.stat[host]==NOTEN)counter++;
                else counter=0;
                games_infor.push_back(zz.str());
            }
            std::stringstream final_score;
            for(i32 id=0;id<player_cnt;id++){
                final_score<<players[ev.per[id]].name<<' '<<ev.final_score[id]<<'\n';
            }

            opt+=player_names+'\n';
            for(auto z:games_infor){
                opt+=z;
            }
            opt+='\n';
            opt+=final_score.str();
            opt+='\n';
        }
        return opt;
    }
}

std::string how_rating_counts(){
    return "[此处可以查看 rating 计算方式](https://github.com/yuanruiqi/mahjong-rating/blob/main/doc/plan.md)";
}

std::string score_table(){
    std::string opt=R"(|    :     |           １番           |           |           ２番           |           |               ３番           |               |          ４番                |               |
| :------: | :----------------------: | :-----------: | :----------------------: | :-----------: | ------------------------ | ------------- | ------------------------ | ------------- |
|   符數   | 自摸 閒家需付－ 莊家需付 | 銃和 放銃者付 | 自摸 閒家需付－ 莊家需付 | 銃和 放銃者付 | 自摸 閒家需付－ 莊家需付 | 銃和 放銃者付 | 自摸 閒家需付－ 莊家需付 | 銃和 放銃者付 |
|  ２０符  |                          |               |         400-700          |               | 700-1300                 |               | 1300-2600                |               |
|  ２５符  |                          |               |                          |     1600      | 800-1600                 | 3200          | 1600-3200                | 6400          |
|  ３０符  |         300-500          |     1000      |         500-1000         |     2000      | 1000-2000                | 3900          | 2000-3900                | 7700          |
|  ４０符  |         400-700          |     1300      |         700-1300         |     2600      | 1300-2600                | 5200          | 滿貫                     | 滿貫          |
|  ５０符  |         400-800          |     1600      |         800-1600         |     3200      | 1600-3200                | 6400          | 滿貫                     | 滿貫          |
|  ６０符  |         500-1000         |     2000      |        1000-2000         |     3900      | 2000-3900                | 7700          | 滿貫                     | 滿貫          |
|  ７０符  |         600-1200         |     2300      |        1200-2300         |     4500      | 滿貫                     | 滿貫          | 滿貫                     | 滿貫          |
|  ８０符  |         700-1300         |     2600      |        1300-2600         |     5200      | 滿貫                     | 滿貫          | 滿貫                     | 滿貫          |
|  ９０符  |         800-1500         |     2900      |        1500-2900         |     5800      | 滿貫                     | 滿貫          | 滿貫                     | 滿貫          |
| １００符 |         800-1600         |     3200      |        1600-3200         |     6400      | 滿貫                     | 滿貫          | 滿貫                     | 滿貫          |
| １１０符 |                          |     3600      |        1800-3600         |     7100      | 滿貫                     | 滿貫          | 滿貫                     | 滿貫          |)";
    return opt;
}

void output(){
    std::cerr<<-1<<std::endl;
    std::ofstream cout(outmd.c_str(),std::ios_base::out);
    cout<<qua::get_table()<<'\n';
    cout<<tri::get_table()<<'\n';
    cout<<how_rating_counts()<<'\n';;
    cout<<'\n';
    cout<<score_table()<<'\n';
    cout<<"# 4 麻\n";
    cout<<qua::games_information()<<'\n';
    cout<<"# 3 麻\n";
    cout<<tri::games_information()<<'\n';
}