#include "maj.h"
const std::string indexlink="./html/index.html";
const std::string outmd="./html/out.md";
bool cmp(person a,person b){
    return a.show_rating>b.show_rating;
}
std::string get_table(){
    // std::string opt="<meta charset=\"utf-8\">\n<script src=\"marked.min.js\"></script>";
    // std::string table="<div id=\"$m\" class=\"markdown-body\"></div><textarea id=\"$t\" style=\"display:none\">";
    std::string table="";
    std::vector<std::string>heads={"排名","姓名","rating","1位率","2位率","3位率","4位率","被飞率","平均顺位","放铳率","和牌率","平均打点","参加局数","历史最值rating","段位"};
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
        opt<<"|"<<player.name;;
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
        opt<<"|"<<player.max_rating;
        opt<<"|"<<player.dan;
        opt<<"|\n";
        table+=opt.str();
    }
        players=player_output;
    return table;
    // table+=" </textarea>\n <script>$m.innerHTML = marked.parse($t.value);</script>";

}
void output(){
    std::ofstream cout(outmd.c_str(),std::ios_base::out);
    cout<<get_table()<<'\n';
    cout<<"[此处可以查看 rating 计算方式](https://github.com/yuanruiqi/mahjong-rating/blob/main/doc/plan.md)";
    
}