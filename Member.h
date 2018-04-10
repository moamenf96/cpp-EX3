#pragma once

#ifndef MEMBER_HPP_
#define MEMBER_HPP_

#include <set>

class Member {
	static int totalUsers;//Number of all singed-up members

	std::set<Member*> followers;//List of followers for this member
	std::set<Member*> following;//List of following for this member

	void addToFollowers(Member& o);//Add to the list of following for this member

	void deleteFromFollowers(Member& o);//Remove from the list of following for this member

public:
	Member();

	~Member();

	void follow(Member& o);//Follows a member by using addToFollowers 

	void unfollow(Member& o);//Unfollow a member by using deletedeleteFromFollowers

	int numFollowers() const;//Return the numbers of followers & without modifying the member

	int numFollowing() const;//Return the numbers of following & without modifying the member

	static int count();//Return the number of total useres
};

#endif /* MEMBER_HPP_ */