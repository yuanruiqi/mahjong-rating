#include "maj.h"

const std::string events_file="./data/events.txt";
const std::string users_file="./data/username.txt";
void read_users(){
    std::ifstream cin;
    cin.open(users_file.c_str());
    i32 maxid=0;
    i32 id;std::string name;
    std::vector<std::pair<i32,std::string>>zz;
    while(cin>>id>>name){
        zz.push_back({id,name});
        maxid=std::max(id,maxid);

    }
    players.resize(maxid+1);
    for(auto x:zz) players[x.first].name = x.second;
}
void read_events(){
    std::ifstream cin;
    cin.open(events_file.c_str());
    i32 n;
    while(cin>>n){
        event crc;
        cin>>crc.type;
        i32 ida,idb,idc,idd;
        cin>>ida>>idb>>idc>>idd;
        crc.per[0]=ida;
        crc.per[1]=idb;
        crc.per[2]=idc;
        crc.per[3]=idd;
        for(i32 i=1;i<=n;i++){
            game p {};
            cin>>p.host;
            for(i32 j=0;j<crc.type;j++){
                i32 id;
                cin>>id;
                p.stat[j]=(state)id;
            }
            for(i32 j=0;j<crc.type;j++){
                cin>>p.delta[j];
            }
            crc.games.push_back(p);
        }
        db.push_back(crc);
    }
}
void input(){
    read_users();
    read_events();
}