/*
 * ruleta.cpp
 *
 *  compilieaza cu -std=c++11 -pthread
 *
 *  Created on: May 22, 2016
 *      Author: root
 */

#include "ruleta.h"

ruleta:: ruleta() {
	  srand(time(0));
	  this->ruleta_start();
}

int ruleta::get_random()
{
	int semn=rand()%2;

	if (semn==0)
		semn=-1;
	else
		semn=1;

	int val=rand()%max_money_loose;
	return val*semn;
}

ruleta::~ruleta()
{
   std::cout<<"Destructor called...  ";
   ruleta_stop();
}

bool ruleta:: get_is_closed()
{
	bool value;

     my_mutex.lock();
	      value=is_closed;
	my_mutex.unlock();

	return is_closed;
}

void ruleta::set_is_closed(bool val)
{
	my_mutex.lock();
        	is_closed=val;
    my_mutex.unlock();
}

void ruleta::ruleta_start()
{
    	if (get_is_closed()==false)
     	{
	    	std::cout<<"Roulette already started!!!!"<<std::endl;
	    	return;
     	}
    	else
    	{
    	  std::cout<<"The Roulette has started !!!!"<<std::endl;
          set_is_closed(false);
    	}

    this->my_thread=new std::thread(&ruleta::running_function,this);
}

void ruleta::ruleta_stop()
{
   if (is_closed==true)
   {
	   std::cout<<"Is already closed"<<std::endl;
	   return;
   }
   else
   {
      set_is_closed(true);
   }

   if (my_thread!=NULL)
   {
	   my_thread->join();
	   delete my_thread;
   }
}

void ruleta::running_function()
{
		
	while (true)
	{
	        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if (get_is_closed()==true)          
	        {
	     	    std::cout<<"Roulette has closed !!!"<<std::endl;
          	    //std::cout<<"YES"<<'\n';
	     	    return;
             }
             else
             {
            	  int value=get_random();
            	  last_results.push_back(value);
            	  std::cout<<value<<std::endl;
             }
	}
}



