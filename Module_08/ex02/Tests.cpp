/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gle-roux <gle-roux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:03:29 by gle-roux          #+#    #+#             */
/*   Updated: 2023/12/04 11:26:59 by gle-roux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "Tests.hpp"

void runTests() {
	srand(time(0));
	{
		TITLE( "\n--------------------- BASIC TESTS --------------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Copy test : Insert 5 elements - OK");
		TEST( "------------------------------------------------------");
		MutantStack<int> mstack;
		MutantStack<int> mstack_copy;

		for ( int i = 0; i < 5; i++ ) {
			mstack.push( rand() % 100 );
		}

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}

		cout << C_RED "\nmstack.copy = mstack\n" C_WHT << endl;
		mstack_copy = mstack;

		MutantStack<int>::iterator it_copy = mstack_copy.begin();
		MutantStack<int>::iterator ite_copy = mstack_copy.end();

		cout << C_BLU "mstack_copy content : " C_WHT << endl;
		while (it_copy != ite_copy) {
			cout << "  " << *it_copy << endl;
			++it_copy;
		}
	}
	{
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Deep copy test : Insert 5 elements - OK");
		TEST( "------------------------------------------------------");
		MutantStack<int> mstack;

		for ( int i = 0; i < 5; i++ ) {
			mstack.push( rand() % 100 );
		}

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}

		cout << C_RED "\nmstack.copy(mstack)\n" C_WHT << endl;
		MutantStack<int> mstack_copy( mstack );

		MutantStack<int>::iterator it_copy = mstack_copy.begin();
		MutantStack<int>::iterator ite_copy = mstack_copy.end();

		cout << C_BLU "mstack_copy content : " C_WHT << endl;
		while (it_copy != ite_copy) {
			cout << "  " << *it_copy << endl;
			++it_copy;
		}
	}
	{
		TITLE( "\n------------------- FUNCTIONS TESTS ------------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Push test : Insert 5 elements - OK");
		TEST( "------------------------------------------------------");
		MutantStack<int> mstack;

		for ( int i = 0; i < 5; i++ ) {
			mstack.push( rand() % 100 );
		}

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		cout << C_BLU "mlist content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
	}
	{
		TITLE( "\n----------------------- Test 2 -----------------------");
		TEST( "Top test : Access next element - OK");
		TEST( "------------------------------------------------------");
		MutantStack<int> mstack;

		for ( int i = 0; i < 3; i++ ) {
			mstack.push( rand() % 100 );
		}

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		cout << C_BLU "mlist content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}

		cout << C_BLU "mstack.top : " C_WHT << mstack.top() << endl;
	}
	{
		TITLE( "\n----------------------- Test 3 -----------------------");
		TEST( "Pop test : Remove top element - OK");
		TEST( "------------------------------------------------------");
		MutantStack<int> mstack;

		for ( int i = 0; i < 5; i++ ) {
			mstack.push( rand() % 100 );
		}

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}

		mstack.pop();

		it = mstack.begin();
		ite = mstack.end();
		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
	}
	{
		TITLE( "\n----------------------- Test 4 -----------------------");
		TEST( "Swap test : Swap contents - OK");
		TEST( "------------------------------------------------------");
		MutantStack<int> mstack, mswap;

		for ( int i = 0; i < 3; i++ ) {
			mstack.push( rand() % 100 );
		}

		for ( int i = 0; i < 2; i++ ) {
			mswap.push( rand() % 100 );
		}

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		MutantStack<int>::iterator it_swap = mswap.begin();
		MutantStack<int>::iterator ite_swap = mswap.end();

		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
		cout << C_BLU "mswap content : " C_WHT << endl;
		while (it_swap != ite_swap) {
			cout << "  " << *it_swap << endl;
			++it_swap;
		}

		cout << C_RED "\nmstack.swap( mswap )\n" C_WHT << endl;
		mstack.swap( mswap );

		it = mstack.begin();
		ite = mstack.end();
		it_swap = mswap.begin();
		ite_swap = mswap.end();

		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
		cout << C_BLU "mswap content : " C_WHT << endl;
		while (it_swap != ite_swap) {
			cout << "  " << *it_swap << endl;
			++it_swap;
		}
	}
		{
		TITLE( "\n----------------------- Test 5 -----------------------");
		TEST( "Size test - OK");
		TEST( "------------------------------------------------------");
		MutantStack<int> mstack;

		cout << C_BLU "Step 1. mstack size: " C_WHT << mstack.size() << endl;

		for ( int i = 0; i < 5; i++ ) {
			mstack.push(i);
		}

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}

		cout << C_BLU "Step 2. mstack size: " C_WHT << mstack.size() << endl;

		mstack.pop();

		cout << C_BLU "Step 3. mstack size: " C_WHT << mstack.size() << endl;
	}
	{
		TITLE( "\n---------------- CONTAINER TYPE TESTS ----------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Deque test - OK");
		deque<int> mdeque;
	
		mdeque.push_back(5);
		mdeque.push_back(17);

		cout << C_BLU "mdeque.back : " C_WHT << mdeque.back() << endl;

		mdeque.pop_back();

		cout << C_BLU "mdeque.size : " C_WHT << mdeque.size() << endl;

		mdeque.push_back(3);
		mdeque.push_back(5);
		mdeque.push_back(737);
		//[...]
		mdeque.push_back(0);

		deque<int>::iterator it = mdeque.begin();
		deque<int>::iterator ite = mdeque.end();

		++it;
		--it;
		cout << C_BLU "mdeque content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
		deque<int> s(mdeque);
	}
	{
		TITLE( "----------------------- Test 2 -----------------------");
		TEST( "Vector test - OK");
		vector<int> mvector;
	
		mvector.push_back(5);
		mvector.push_back(17);

		cout << C_BLU "mvector.back : " C_WHT << mvector.back() << endl;

		mvector.pop_back();

		cout << C_BLU "mvector.size : " C_WHT << mvector.size() << endl;

		mvector.push_back(3);
		mvector.push_back(5);
		mvector.push_back(737);
		//[...]
		mvector.push_back(0);

		vector<int>::iterator it = mvector.begin();
		vector<int>::iterator ite = mvector.end();

		++it;
		--it;
		cout << C_BLU "mvector content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
		vector<int> s(mvector);
	}
	{
		TITLE( "\n--------------------- TYPE TESTS --------------------");
		TITLE( "----------------------- Test 1 -----------------------");
		TEST( "Float test - OK");
		MutantStack<float> mstack;
	
		mstack.push(5.65);
		mstack.push(17.765);

		cout << C_BLU "mstack.top : " C_WHT << mstack.top() << endl;

		mstack.pop();

		cout << C_BLU "mstack.size : " C_WHT << mstack.size() << endl;

		mstack.push(3.534);
		mstack.push(5.23);
		mstack.push(737.65);
		//[...]
		mstack.push(0);

		MutantStack<float>::iterator it = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();

		++it;
		--it;
		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
		MutantStack<float> s(mstack);
	}
	{
		TITLE( "----------------------- Test 2 -----------------------");
		TEST( "Char test - OK");
		MutantStack<char> mstack;
	
		mstack.push('a');
		mstack.push('b');

		cout << C_BLU "mstack.top : " C_WHT << mstack.top() << endl;

		mstack.pop();

		cout << C_BLU "mstack.size : " C_WHT << mstack.size() << endl;

		mstack.push('c');
		mstack.push('d');
		mstack.push('e');
		//[...]
		mstack.push('f');

		MutantStack<char>::iterator it = mstack.begin();
		MutantStack<char>::iterator ite = mstack.end();

		++it;
		--it;
		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
		MutantStack<char> s(mstack);
	}
	{
		TITLE( "----------------------- Test 3 -----------------------");
		TEST( "String test - OK");
		MutantStack<string> mstack;
	
		mstack.push("allo");
		mstack.push("bonjour");

		cout << C_BLU "mstack.top : " C_WHT << mstack.top() << endl;

		mstack.pop();

		cout << C_BLU "mstack.size : " C_WHT << mstack.size() << endl;

		mstack.push("chat");
		mstack.push("dormir");
		mstack.push("encore");
		//[...]
		mstack.push("finale");

		MutantStack<string>::iterator it = mstack.begin();
		MutantStack<string>::iterator ite = mstack.end();

		++it;
		--it;
		cout << C_BLU "mstack content : " C_WHT << endl;
		while (it != ite) {
			cout << "  " << *it << endl;
			++it;
		}
		MutantStack<string> s(mstack);
	}
	TITLE( "\n--------------------- End Tests ----------------------");
}