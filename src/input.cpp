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
    tri::players.resize(maxid+1);
    qua::players.resize(maxid+1);
    for(auto x:zz) {
        tri::players[x.first].name = x.second;
        qua::players[x.first].name = x.second;
    }
}
namespace tri{
    void read_event(i32 n,std::ifstream& cin){
            event crc;
            crc.type=3;
            for(i32 i=0;i<crc.type;i++){
                i32 x;
                cin>>x;
                crc.per[i]=(state)x;
            }
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
namespace qua{
    void read_event(i32 n,std::ifstream& cin){
            event crc;
            crc.type=4;
            for(i32 i=0;i<crc.type;i++){
                i32 x;
                cin>>x;
                crc.per[i]=(state)x;
            }
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
void read_events(){
    std::ifstream cin;
    cin.open(events_file.c_str());
    i32 n;
    while(cin>>n){
        i32 type;
        cin>>type;
        if(type==3)tri::read_event(n,cin);
        else if(type==4)qua::read_event(n,cin);
        else assert(0);
    }
}
void input(){
    read_users();
    read_events();
}