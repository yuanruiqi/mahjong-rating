//This file is to generate event to add in events.txt
#include"maj.h"
using std::string;
using std::map;
using std::ifstream;
using std::cin;
using std::cout;
using std::to_string;
using std::vector;
using std::stringstream;
#undef int
const std::string users_file="./data/username.txt";
signed main(){
    ifstream user;
    user.open(users_file);
    map<string,int>user2id;
    int id;string name;
    while(user>>id>>name){
        user2id[name]=id;
        user2id[to_string(id)]=id;
    }
    cout<<"Number of games and game type: ";
    int n,type;
    cin>>n>>type;
    assert(n>=0);
    assert(type==3||type==4);
    vector<int>ids;
    cout<<"Names or ids(in order): ";
    for(int i=0;i<type;i++){
        string name;
        cin>>name;
        assert(user2id.find(name)!=user2id.end());
        ids.push_back(user2id[name]);
    }
    stringstream opt;
    opt<<n<<' '<<type<<'\n';
    for(auto x:ids)opt<<x<<' ';
    opt<<'\n';
    for(int i=0;i<n;i++){
        cout<<"0=TSUMO,1=RON,2=CRUSH,3=SKIPPED,4=TENPAI,5=NOTEN\n";
        cout<<"Input host,state and score delta: ";
        int host;
        cin>>host;
        assert(host>=0&&host<type);
        opt<<host<<' ';
        for(int i=0;i<type;i++){
            int state;
            cin>>state;
            assert(state>=0&&state<=MAX_STATE);
            opt<<state<<' ';
        }
        for(int i=0;i<type;i++){
            int delta;
            cin>>delta;
            opt<<delta<<' ';
        }
        opt<<'\n';
    }
    cout<<"Put the following text after \"---\" into events.txt:\n------------\n"<<opt.str();
}