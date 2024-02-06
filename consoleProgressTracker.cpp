#include <iostream> // for std::cout and std::endl
#include <vector> //for std::vector
#include <string>
#include <iomanip>

//note: Chapters on learncpp.com start at 0 and end at 28, for a total of 29 chapters

int main()
{
	int allChapters { 29 };     //total chapters on learncpp.com
	int allLessons {};          //total lessons on learncpp.com
	int lessonsTotal {};        //total lessons user has completed
	size_t myChapter {};        //user's current chapter
	int myLesson {};            //user's current lesson
	double percentComplete {};  //calculated percentage of course completed
	

	//vector storing how many lessons are in each chapter (Chapter 0 to 28)
	std::vector<int> chapterLessons {12, 11, 13, 10, 12, 11, 7, 13, 15, 6, 9, 9, 14, 13, 16, 10, 12, 13, 4, 5, 7, 14, 7, 7, 9, 11, 6, 10, 7};
	
	//user interface to input current progress
	std::cout << "LearnCPP.com Progress Tracker v1.2\n\n";
	std::cout << "[Current Chapter Number] ";
	std::cin >> myChapter;
	std::cout << "[Last Completed Lesson Number] ";
	std::cin >> myLesson;

	//range-based for loop finding total number of lessons on learncpp.com
	for (int lessons : chapterLessons) {
		allLessons += lessons;
	}

	//calculate the total number of lessons completed by the user in completed chapters
	for (size_t chapterCount{ 0 }; chapterCount < myChapter; ++chapterCount) {
		
		lessonsTotal += chapterLessons[chapterCount];
	}
	lessonsTotal += myLesson; //add lessons completed in the current chapter

	//calculate the percentage of the course completed
	percentComplete = static_cast<double>(lessonsTotal) / allLessons * 100;

	//output the user's progress
	std::cout << "\n[Total Chapters] " << allChapters << " ";
	std::cout << "[Total Lessons] " << allLessons << "\n\n";
	std::cout << "[Completed Chapters] " << myChapter << " ";
	std::cout << "[Completed Lessons] " << lessonsTotal << "\n\n";
	std::cout << "[Percent Complete] " << percentComplete << "%\n\n";

	//progress bar
	const int progressBarLength { 100 };
	int completedLength = static_cast<int>(progressBarLength * percentComplete / 100);

	std::cout << "[Progress Bar]\n\n" << "[";
	for (int i = 0; i < progressBarLength; ++i) {
		if (i < completedLength)
			std::cout << '|'; //completed part
		else
			std::cout << ':'; //incomplete part
	}
	std::cout << "] " << percentComplete << "% Complete\n\n";

	//vector containing Chapter Titles
	std::vector<std::string> chapterTitles{ "Chapter 0 - Introduction / Getting Started", "Chapter 1 - C++ Basics", "Chapter 2 - C++ Basics: Functions and Files", "Chapter 3 - Debugging C++ Programs", "Chapter 4 - Fundamental Data Types", "Chapter 5 - Constants and Strings", "Chapter 6 - Operators", "Chapter 7 - Scope, Duration, and Linkage", "Chapter 8 - Control Flow", "Chapter 9 - Error Detection and Handling", "Chapter 10 - Type Conversion, Type Aliases, and Type Deduction", "Chapter 11 - Function Overloading and Function Templates", "Chapter 12 - Compound Types: References and Pointers", "Chapter 13 - Compound Types: Enums and Structs", "Chapter 14 - Introduction to Classes", "Chapter 15 - More on Classes", "Chapter 16 - Dynamic arrays: std::vector", "Chapter 17 - Fixed-size arrays: std::array and C-style arrays", "Chapter 18 - Iterators and Algorithms (under construction)", "Chapter 19 - Dynamic Allocation (under construction)", "Chapter 20 - Functions", "Chapter 21 - Operator Overloading", "Chapter 22 - Move Semantics and Smart Pointers", "Chapter 23 - Object Relationships", "Chapter 24 - Inheritance", "Chapter 25 - Virtual Functions", "Chapter 26 - Templates and Classes", "Chapter 27 - Exceptions", "Chapter 28 - Input and Output (I/O)" };

	//find max number of lessons per chapter
	size_t maxTitleLength = 0;
	for (const auto& title : chapterTitles) {
		if (title.length() > maxTitleLength) {
			maxTitleLength = title.length();
		}
	}

	//Finished Chapters Listed
	std::cout << "\n[COMPLETE]\n\n";
	for (size_t i = 0; i < myChapter; ++i) {
		std::cout << std::left << std::setw(static_cast<int>(maxTitleLength)) << chapterTitles[i] << " [";
		for (int j = 0; j < chapterLessons[i]; ++j) {
			std::cout << '|';
		}
		std::cout << "]\n";
	}
	//Unfinished Chapters Listed
	std::cout << "\n[INCOMPLETE]\n\n";
	for (size_t i = myChapter; i < chapterTitles.size(); ++i) {
		std::cout << std::left << std::setw(static_cast<int>(maxTitleLength)) << chapterTitles[i] << " [";
		for (int j = 0; j < chapterLessons[i]; ++j) {
			std::cout << '|';
		}
		std::cout << "]\n";
	}

	std::cout << "\nPress Enter to exit...";
	std::cin.get();//to clear the newline character from the input stream
	std::cin.get();//to wait for input

	return 0; //return 0 to indicate successful completion
}
