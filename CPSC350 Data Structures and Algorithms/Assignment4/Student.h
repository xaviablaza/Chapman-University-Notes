class Student {
	public:
		Student();
		~Student();

		// Constructor that specifies amount of minutes student needs at the window
		Student(int minsAtWindow);
		
		int minsNeeded;
};