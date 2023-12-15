/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/10/30 12:05:40 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Tests.hpp"

int main() {
	{
		TITLE( "\n-------------------- Subject Test --------------------");
		TITLE( "\n----------------------- Test 1 -----------------------");
		TEST( "MutantStack test - OK");
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);

		cout << C_BLU "mstack.top : " C_WHT << mstack.top() << endl;

		mstack.pop();

		cout << C_BLU "mstack.size : " C_WHT << mstack.size() << endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite)
		{
			cout << "  " << *it << endl;
			++it;
		}
		stack<int> s(mstack);
	}
	{
		TITLE( "\n----------------------- Test 2 -----------------------");
		TEST( "List test - OK");
		list<int> mlist;
	
		mlist.push_back(5);
		mlist.push_back(17);

		cout << C_BLU "mlist.back : " C_WHT << mlist.back() << endl;

		mlist.pop_back();

		cout << C_BLU "mlist.size : " C_WHT << mlist.size() << endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);

		list<int>::iterator it = mlist.begin();
		list<int>::iterator ite = mlist.end();

		++it;
		--it;
		cout << C_BLU "mlist content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
		list<int> s(mlist);
	}
	runTests();
	return 0;
}