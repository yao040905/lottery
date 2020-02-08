#include "lottery.h"
#include <random>

Lottery::Lottery()
{
	
}

Lottery::~Lottery()
{

}

bool Lottery::draw(const memberMap & drawMembers,  int drawCount, bool putback)
{
	if(drawCount <= 0)
	{
		PRINTLOG("draw count %d error", drawCount);
		return false;
	}

	int validMemberCount = 0;
	vector<memberInfo> realMemberVec;
	for(auto memberPair : drawMembers)
	{
		auto member = memberPair.second;
		for(int i = 0; i < member.ratio; ++i)
		{
			realMemberVec.push_back(member);
		}

		if(member.ratio > 0)
			++validMemberCount;
	}

	if(validMemberCount < drawCount)
	{
		PRINTLOG("validMemberCount %d < draw count %d", validMemberCount, drawCount);
		return false;
	}

	PRINTLOG("start, draw count %d putback %d", drawCount, putback);

	random_device  rand;
	int randNum;

	for(int i = 0; i < drawCount; ++i)
	{
		randNum = rand() % realMemberVec.size();

		PRINTLOG("draw usr %d %s %s %s", realMemberVec[randNum].id, realMemberVec[randNum].name.c_str(), realMemberVec[randNum].department.c_str(), realMemberVec[randNum].team.c_str());

		int delId = realMemberVec[randNum].id;
		for(auto itr = realMemberVec.begin(); itr != realMemberVec.end();)
		{
			if(itr->id == delId)
			{
				itr = realMemberVec.erase(itr);
			}
			else
			{
				++itr;
			}
		}

		if(!putback)
		{
			delMember(delId);
		}
	}

	return true;
}

bool Lottery::normalDraw( int drawCount, bool putback)
{
	const memberMap & drawMembers = getMemberMap();
	
	return draw(drawMembers, drawCount, putback);
}

bool Lottery::departmentDraw(string department,  int drawCount, bool putback)
{
	const memberMap & members = getMemberMap();
	memberMap drawMembers;
	for(auto memberPair : members)
	{
		auto member = memberPair.second;

		if(member.department == department)
		{
			drawMembers.insert(memberPair);
		}
	}

	return draw(drawMembers, drawCount, putback);
}

bool Lottery::teamDraw(string drawTeam,  int drawCount, bool putback)
{
	const memberMap & members = getMemberMap();
	memberMap drawMembers;
	for(auto memberPair : members)
	{
		auto member = memberPair.second;

		if(member.team == drawTeam)
		{
			drawMembers.insert(memberPair);
		}
	}

	return draw(drawMembers, drawCount, putback);
}
