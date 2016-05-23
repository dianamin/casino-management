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

class ruleta {
public:

	ruleta();
	int get_random();
	void ruleta_start();
	void ruleta_stop();
	virtual ~ruleta();
	void running_function();
	bool get_is_closed();
	void set_is_closed(bool val);
private:
	bool is_closed=true;
	std::mutex my_mutex;
	std::thread* my_thread;
};

#endif /* RULETA_H_ */

