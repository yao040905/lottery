#pragma once

#include <vector>
#include "memberManager.h"

class Lottery
{
public:
    Lottery();
    ~Lottery();

    bool addMember(const memberInfo & member) { return memberManager.addMember(member); }
    bool delMember(int id) { return memberManager.delMember(id); }

    bool setRatio(int id, int ratio) { return memberManager.setRatio(id, ratio); }
    bool setDepartmentRatio(string department, int ratio) { return memberManager.setDepartmentRatio(department, ratio); }
    bool setTeamRatio(string team, int ratio) { return memberManager.setTeamRatio(team, ratio); }

    bool normalDraw( int drawCount, bool putback = false);
    bool departmentDraw(string department,  int drawCount, bool putback = false);
    bool teamDraw(string team,  int drawCount, bool putback = false);

private:
    const memberMap& getMemberMap() { return memberManager.getMemberMap(); }

    bool draw(const memberMap & drawMembers,  int drawCount, bool putback = false);

    MemberManager memberManager;
};
