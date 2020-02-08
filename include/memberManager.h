#pragma once

#include "define.h"

class MemberManager
{
public:
    MemberManager();
    ~MemberManager();

    bool addMember(const memberInfo & member);
    bool delMember(int id);

    bool setRatio(int id, int ratio);
    bool setDepartmentRatio(string department, int ratio);
    bool setTeamRatio(string team, int ratio);

    const memberMap& getMemberMap();

private:
    memberMap members;
};
