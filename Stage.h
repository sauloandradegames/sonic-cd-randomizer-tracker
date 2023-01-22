// Stage.h
// Header: Stage class

#ifndef STAGE_H
#define STAGE_H

class Stage
{
	private:
/*---------------------------- ATTRIBUTES ----------------------------*/
        int name; // Stage name identifier (Zone + Timezone)
        Stage *goal; // Destination if stage clear (goal)
        Stage *past; // Destination if time travel (past)
        Stage *future; // Destination if time travel (future)
		
	public:
/*--------------------------- CONSTRUCTORS ---------------------------*/
		Stage(); // Default constructor (empty)
		Stage(int i); // Default constructor (w/ values)
		
/*----------------------- METHODS: GET AND SET -----------------------*/
        int getName(); // Returns stage name identifier
        Stage* getGoal(); // Returns stage clear (goal) destination
        Stage* getPast(); // Returns time travel (past) destination
        Stage* getFuture(); // Returns time travel (future) destination
        void setName(int v); // Set stage name identifier
        void setGoal(Stage* destination); // Set stage clear (goal) destination
        void setPast(Stage* destination); // Set time travel (past) destination
        void setFuture(Stage* destination); // Set time travel (future) destination
};

#endif // STAGE_H