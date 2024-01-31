#include <iostream> // for std::cout and std::endl
#include <vector> //for std::vector

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
	std::cout << "LearnCPP.com Progress Tracker v1.0\n";
	std::cout << "Current Chapter Number:\n";
	std::cin >> myChapter;
	std::cout << "Last Completed Lesson Number:\n";
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
	std::cout << "Total Chapters: " << allChapters << std::endl;
	std::cout << "Total Lessons: " << allLessons << std::endl;
	std::cout << "Completed Chapters: " << myChapter << std::endl;
	std::cout << "Completed Lessons: " << lessonsTotal << std::endl;
	std::cout << "Percent Complete: " << percentComplete << std::endl;

	return 0; //return 0 to indicate successful completion
}
