#include <iostream>


//lib developer
class Library{	
public :
		//stable
		void templateMethod()
		{
				Step1();
				if(Step2())	//support change
				{
					Step3();
				}
				
				for (int i=0;i<4;++i)
				{
					Step4();	//support change
				}
				Step5();	
		}
		virtual ~Library(){
			//do somethings
		}
protected:
		void Step1(){
			//do somethings
		}
		void Step3(){
			//do somethings
		}
		void Step5(){
			//do somethings
		}
		
	virtual bool Step2()=0;
	virtual void Step4()=0;		
};

//app developer
//step2/4 change frequently 
class Application :public Library{
	
public:
	virtual	bool Step2(){
			//do somethings
		}
	virtual	void Step4(){
			//do somethings
		}
	virtual ~Application()
	{
		//do something
	}	
};

// main is provided by library developer
int main()
{
	Library *lib = new Application();
	lib->templateMethod();
	delete lib;
	return 0;
}