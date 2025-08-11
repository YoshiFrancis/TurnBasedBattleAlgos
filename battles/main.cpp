#include "BattleGround.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "hello world\n";
    auto teams_list_opt = tba::load_teams_file("build/files/battlegrounds/test1.json");
    assert(teams_list_opt.has_value() && "unable to load teams file");
    auto teams_list = teams_list_opt.value();
    tba::TeamContainer tc(teams_list);
    tba::BattleGround bg(tc);
    bg.begin_battle();
    while (bg.update_state()) {};
    return EXIT_SUCCESS;
}
