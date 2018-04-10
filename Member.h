#pragma once
#ifndef __member_H_INCLUDED__
#define __member_H_INCLUDED__
#include <deque>
class Member {
public:
	Member::Member();
	int numFollowers();
	int numFollowing();
	std::deque<Member> followerMembers();
	std::deque<Member> followingMembers();
	bool follow(Member *m);
	bool unfollow(Member *m);
	static int getAllMembersCount();
private:
	int numOfFollowers;
	int numOfFollowing;
	std::deque<Member> *following;
	std::deque<Member> *followers;
	int id;
	static int allMembersCount;
	static std::deque<Member> *allMembers;

	
};
#endif
