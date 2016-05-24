/*
 * ruleta.h
 *   compileaza cu -std=c++11 -pthread
 *
 *  Created on: May 22, 2016
 *      Author: root
 */
#ifndef RULETA_H_
#define RULETA_H_

#define max_money_loose 100


#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <thread>
#include <mutex>
#include "Game.h"
#include "Expenditure.h"
#include <vector>

class ruleta :public Game {
public:

	ruleta();
	virtual ~ruleta();
	void running_function();

	 virtual void newBet(int b)
	 {

	 }

	virtual Expenditure play(int nr)
	{
		if (last_results.empty()==true) std::this_thread::sleep_for(std::chrono::milliseconds(1300));


          std::string won_or_not=(last_results.back()>0?"won":"lost");
          return Expenditure("ruleta",last_results.back(),won_or_not);
	}

private:

	bool is_closed=true;
	std::mutex my_mutex;
	std::thread* my_thread;
	std::vector<int> last_results;
	void ruleta_start();
	void ruleta_stop();
	int get_random();
	bool get_is_closed();
	void set_is_closed(bool val);
};

#endif /* RULETA_H_ */


