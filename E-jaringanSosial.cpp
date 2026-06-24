#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class SocialNetwork {
    map<string, vector<string>> network;
public:
    void addFriendship(string p1, string p2) {
        network[p1].push_back(p2);
        network[p2].push_back(p1);
    }
    void showNetwork() {
        for(auto const& [person, friends] : network) {
            cout << person << " berteman dengan: ";
            for(auto const& f : friends) cout << f << " ";
            cout << endl;
        }
    }
};

int main() {
    SocialNetwork sn;
    sn.addFriendship("Andi", "Budi");
    sn.addFriendship("Budi", "Citra");
    sn.showNetwork();
    return 0;
}