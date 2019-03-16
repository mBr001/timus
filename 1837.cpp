#include <iostream>
#include <string>
#include <map>
#include <set>


std::map<std::string, int> rating;
std::map<std::string, std::set<std::string>> members;


void upTeammates(const std::string& name, int level) 
{
    auto teammates = members[name];

    bool modified = false;
    for (auto teammate : teammates) {
        if (level + 1 < rating[teammate]) {
            rating[teammate] = level + 1;
            modified = true;
        }
    }

    if (!modified) 
        return;

    for (auto teammate : teammates) {
        upTeammates(teammate, rating[teammate]);
    }
}


int main()
{
    int n;
    std::cin >> n;

    std::string m1, m2, m3;
    for (int i = 0; i < n; ++i) {

        std::cin >> m1 >> m2 >> m3;
        
        members[m1].insert(m2);
        members[m1].insert(m3);

        members[m2].insert(m1);
        members[m2].insert(m3);

        members[m3].insert(m1);
        members[m3].insert(m2);

        rating[m1] = 255;
        rating[m2] = 255;
        rating[m3] = 255;
    }

    if (rating.find("Isenbaev") != rating.end()) {
        rating["Isenbaev"] = 0;
        upTeammates("Isenbaev", 0);
    }

    for (auto r : rating) {
        std::cout << r.first << " ";
        if (r.second == 255)
            std::cout << "undefined";
        else
            std::cout << r.second;
        std::cout << std::endl;
    }

    return 0;
}