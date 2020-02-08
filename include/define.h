#pragma once

#include <stdio.h>
#include <map>
#include <string>

using namespace std;

#define PRINTLOG(format, ...) printf("[%s][%d]:" format "\n", __FUNCTION__, __LINE__, ##__VA_ARGS__)

struct memberInfo
{
    int id;
    string name;
    string department;
    string team;
    int ratio;

    memberInfo(int memberId, string memberName, string memberDepartment, string memberTeam, int memberRatio = 1)
    {
        id = memberId;
        name = memberName;
        department = memberDepartment;
        team = memberTeam;
        ratio = memberRatio;
    }

    memberInfo()
    {

    }
};

typedef map<int ,memberInfo> memberMap;
