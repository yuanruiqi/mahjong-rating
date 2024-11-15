#include "maj.h"
const std::string indexlink="./html/index.html";
void output(){
    std::string opt="";
    for(auto player:players){
        std::string outputpath="./html/";
        outputpath+=player.name+".html";
        std::cerr<<outputpath<<'\n';
        std::ofstream cout(outputpath.c_str(),std::ios_base::out);
        cout<<"姓名："<<player.name<<'\n';
        i32 t=0;
        for(i32 i=0;i<=4;i++){
            if(i==4)cout<<"被飞";
            else cout<<i+1<<"位";
            cout<<"率: "<<std::fixed<<' '<<std::setprecision(3)<<player.rank_cnt[i]*1.0/std::max(1ll,player.event_cnt)<<'\n';
            t+=std::min(i+1,4)*player.rank_cnt[i];
        }
        cout<<"平均顺位："<<std::fixed<<' '<<std::setprecision(3)<<t*1.0/std::max(1ll,player.event_cnt)<<'\n';
        cout<<"rating: "<<std::fixed<<' '<<std::setprecision(3)<<player.rating<<'\n';
        cout<<"放铳次数："<<player.crush_cnt<<'\n';
        cout<<"平均荣/自摸点："<<std::fixed<<' '<<std::setprecision(3)<<player.win_sum*1.0/std::max(1ll,player.win_cnt)<<'\n';
        opt+="<p><a href=\"./"+player.name+".html\">"+player.name+"</a></p>";
    }
        std::ofstream cout(indexlink.c_str(),std::ios_base::out);
        cout<<opt;
}