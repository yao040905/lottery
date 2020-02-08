#include "memberManager.h"

MemberManager::MemberManager()
{

}

MemberManager::~MemberManager()
{

}

bool MemberManager::addMember(const memberInfo & member)
{
	int id = member.id;

	if(id <= 0)
	{
		PRINTLOG("member id %d error", id);
		return false;
	}

	auto itr = members.find(id);
	if(itr != members.end())
	{
		PRINTLOG("member id %d exist", id);
		return false;
	}

	members[id] = member;

	return true;
}

bool MemberManager::delMember(int id)
{
	auto itr = members.find(id);
	if(itr == members.end())
	{
		PRINTLOG("can not find members id %d", id);
		return false;
	}

	members.erase(itr);

	return true;
}

bool MemberManager::setRatio(int id, int ratio)
{
	auto itr = members.find(id);
	if(itr == members.end())
	{
		PRINTLOG("member id %d exist", id);
		return false;
	}

	members[id].ratio = ratio;

	return true;
}

bool MemberManager::setDepartmentRatio(string department, int ratio)
{
	bool setFlag = false;

	for(auto memberPair : members)
	{
		auto member = memberPair.second;

		if(member.department == department)
		{
			setRatio(member.id, ratio);
			
			if(!setFlag)
				setFlag = true;
		}
	}

	return setFlag;
}

bool MemberManager::setTeamRatio(string team, int ratio)
{
	bool setFlag = false;

	for(auto memberPair : members)
	{
		auto member = memberPair.second;

		if(member.team == team)
		{
			setRatio(member.id, ratio);

			if(!setFlag)
				setFlag = true;
		}
	}

	return setFlag;
}

const memberMap& MemberManager::getMemberMap()
{
	return members;
}
