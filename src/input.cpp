#include "maj.h"

const std::string events_file="events.txt";
const std::string users_file="username.txt";
void read_users(){
    freopen(users_file.c_str(),"r",stdin);
    i32 maxid=0;
    i32 id;std::string name;
    std::vector<std::pair<i32,std::string>>zz;
    while(std::cin>>id>>name){
        zz.push_back({id,name});
        maxid=std::max(id,maxid);

    }
    players.resize(maxid+1);
    for(auto x:zz){
        person w;
        w.name=x.second;
        players[x.first]=w;
    }
    fclose(stdin);
}
void read_events(){
    freopen(events_file.c_str(),"r",stdin);
    i32 n;
    while(std::cin>>n){
        event crc;
        i32 ida,idb,idc,idd;
        std::cin>>ida>>idb>>idc>>idd;
        crc.per[0]=ida;
        crc.per[1]=idb;
        crc.per[2]=idc;
        crc.per[3]=idd;
        for(i32 i=1;i<=n;i++){
            game p;
            std::cin>>p.host;
            for(i32 j=0;j<=3;j++){
                i32 id;
                std::cin>>id;
                p.stat[j]=(state)id;
            }
            for(i32 j=0;j<=3;j++){
                std::cin>>p.delta[j];
            }
            crc.games.push_back(p);
        }
        db.push_back(crc);
    }
    fclose(stdout);
}
void input(){
    read_users();
    read_events();
}