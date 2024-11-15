#include "maj.h"
const std::string indexlink="./html/index.html";
void output(){
    std::string opt="<meta charset=\"utf-8\">\n<script src=\"marked.min.js\"></script>";
    std::string table="<div id=\"$m\" class=\"markdown-body\"></div><textarea id=\"$t\" style=\"display:none\">|姓名|rating|\n| ----------- | ----------- |\n";
    for(auto player:players){
        std::string outputpath="./html/";
        outputpath+=player.name+".html";
        std::cerr<<outputpath<<'\n';
        std::ofstream cout(outputpath.c_str(),std::ios_base::out);
        cout<<"<meta charset=\"utf-8\">\n";
        cout<<"<p>姓名："<<player.name<<"</p>\n";
        i32 t=0;
        for(i32 i=0;i<=4;i++){
            if(i==4)cout<<"被飞";
            else cout<<i+1<<"位";
            cout<<"率: "<<std::fixed<<' '<<std::setprecision(3)<<player.rank_cnt[i]*1.0/std::max(1ll,player.event_cnt)<<"</p>\n";
            t+=std::min(i+1,4)*player.rank_cnt[i];
        }
        cout<<"<p>平均顺位："<<std::fixed<<' '<<std::setprecision(3)<<t*1.0/std::max(1ll,player.event_cnt)<<"</p>\n";
        cout<<"<p>rating: "<<std::fixed<<' '<<std::setprecision(3)<<player.rating<<"</p>\n";
        cout<<"<p>放铳概率："<<std::fixed<<' '<<std::setprecision(3)<<player.crush_cnt*1.0/std::max(1ll,player.game_cnt)<<"</p>\n";
        cout<<"<p>平均打点："<<std::fixed<<' '<<std::setprecision(3)<<player.win_sum*1.0/std::max(1ll,player.win_cnt)<<"</p>\n";
        cout<<"<p>参加局数："<<player.event_cnt<<"</p>\n";
        opt+="<p><a href=\"./"+player.name+".html\">"+player.name+"</a></p>";
        std::stringstream row;
        row<<"|"+player.name+"|"<<std::fixed<<' '<<std::setprecision(3)<<player.rating<<"|\n";
        table+=row.str();
    }
    table+=" </textarea>\n <script>$m.innerHTML = marked.parse($t.value);</script>";
        std::ofstream cout(indexlink.c_str(),std::ios_base::out);
        cout<<opt<<table;
}