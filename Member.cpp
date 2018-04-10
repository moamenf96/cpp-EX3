//#include "stdafx.h"
#include "Member.h"
#include<iostream>
using namespace std;



Member::Member()
{
	Member::allMembersCount = 0;
	Member::allMembers = new std::deque<Member>();
	this->id = Member::allMembersCount;
	this->followers = new std::deque<Member>();
	this->following = new std::deque<Member>();
	this->numOfFollowers = 0;
	this->numOfFollowing = 0;
	Member::allMembersCount++;
	Member::allMembers->push_back(*this);
}

int Member::numFollowers()
{
	return this->numOfFollowers;
}

int Member::numFollowing()
{
	return this->numOfFollowing;
}

std::deque<Member> Member::followerMembers()
{
	return *(this->followers);
}

std::deque<Member> Member::followingMembers()
{
	return *(this->following);
}

bool Member::follow(Member other)
{
	Member *tmp = NULL;
	bool followed = false;
	for (int i = 0; i < this->numFollowing(); i++) {
		*tmp = this->following->front();
		this->following->pop_front();
		if (tmp->id == other.id)
			followed = true;
		this->following->push_back(*tmp);
	}
	if (followed)
		return false;
	else {
		this->following->push_back(other);
		this->numOfFollowing++;
		other.followers->push_back(*this);
		other.numOfFollowers++;
		return true;
	}
}

bool Member::unfollow(Member other)
{
	Member *tmp = NULL;
	bool followed = false;
	for (int i = 0; i < this->numFollowing(); i++) {
		*tmp = this->following->front();
		this->following->pop_front();
		if (tmp->id == other.id) {
			followed = true;
			this->numOfFollowing--;
			for (int j = 0; j < other.numOfFollowers; j++) {
				*tmp = other.followers->front();
				other.followers->pop_front();
				if (other.id != this->id)
					other.followers->push_back(*tmp);
			}
			other.numOfFollowers--;
		}
		else {
			this->following->push_back(*tmp);
		}
	}
	if (!followed)
		return false;
	return true;
}

int Member::count()
{
	return Member::allMembersCount;
}

