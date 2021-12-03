#include <iostream>

//lib developer
class Library{
	public:
		void Step1(){
			//do somethings
		}
		void Step3(){
			//do somethings
		}
		void Step5(){
			//do somethings
		}
};

//app developer
//step2/4 change frequently 
class Application{
	
public:
		bool Step2(){
			//do somethings
		}
		void Step4(){
			//do somethings
		}
};

/*
	main be wrote by developer
*/
int main()
{
	Library lib;
	Application app;
	
	lib.Step1();
	if(app.Step2())
	{
		lib.Step3();
	}
	
	for (int i=0;i<4;++i)
	{
		app.Step4();
	}
	lib.Step5();
	return 0;
}


